"use strict";
// civ5decomp dashboard: renders /api/stats into the report. No libraries.
const $ = (id) => document.getElementById(id);
const NS = "http://www.w3.org/2000/svg";
const n0 = (n) => Number(n || 0).toLocaleString("en-US");
const kb = (b) => (b / 1000).toLocaleString("en-US", { maximumFractionDigits: 1 });
function size(b) {
  if (b >= 1e6) return (b / 1e6).toFixed(2) + " MB";
  if (b >= 1e3) return (b / 1e3).toFixed(1) + " KB";
  return n0(Math.round(b)) + " B";
}
function big(n) {
  if (n >= 1e9) return (n / 1e9).toFixed(1) + " B";
  if (n >= 1e6) return (n / 1e6).toFixed(1) + " M";
  if (n >= 1e3) return (n / 1e3).toFixed(1) + " K";
  return n0(n);
}
const pct = (a, b, d = 2) => (b ? (100 * a / b) : 0).toFixed(d) + "%";

// one colour per model, stable across every chart
const modelColour = (() => {
  const seen = new Map();
  return (m) => {
    if (!seen.has(m)) seen.set(m, `var(--m${Math.min(seen.size, 7)})`);
    return seen.get(m);
  };
})();

function el(tag, attrs, text) {
  const e = document.createElement(tag);
  for (const [k, v] of Object.entries(attrs || {})) e.setAttribute(k, v);
  if (text !== undefined) e.textContent = text;
  return e;
}
function svg(tag, attrs) {
  const e = document.createElementNS(NS, tag);
  for (const [k, v] of Object.entries(attrs || {})) e.setAttribute(k, v);
  return e;
}
function fillRows(tbody, rows, cols, emptyText) {
  // -> the <tr> of each row (none when empty)
  tbody.textContent = "";
  if (!rows.length) {
    const tr = el("tr"); tr.appendChild(el("td", { colspan: cols, class: "empty" }, emptyText));
    tbody.appendChild(tr); return [];
  }
  const out = [];
  for (const cells of rows) {
    const tr = el("tr");
    for (const c of cells) {
      const td = el("td", c.cls ? { class: c.cls } : {});
      if (c.swatch) { const s = el("i", { class: "swatch" }); s.style.background = c.swatch; td.appendChild(s); }
      td.appendChild(document.createTextNode(c.t));
      tr.appendChild(td);
    }
    tbody.appendChild(tr); out.push(tr);
  }
  return out;
}
// ---------- tooltip ----------
// One floating box for the whole page. tip(el, fn): hovering (or tapping, or focusing)
// el shows fn()'s content: {title, rows: [{swatch?, label, value}], note?}. Built with
// text nodes only: display names are user input.
const tipBox = el("div", { class: "tip", role: "tooltip", hidden: "" });
document.body.appendChild(tipBox);
let tipOwner = null;
function tipFill(c) {
  tipBox.textContent = "";
  if (c.title) tipBox.appendChild(el("div", { class: "tip-title" }, c.title));
  for (const r of c.rows || []) {
    const line = el("div", { class: "tip-row" });
    const l = el("span", { class: "tip-label" });
    if (r.swatch) { const s = el("i", { class: "swatch" }); s.style.background = r.swatch; l.appendChild(s); }
    l.appendChild(document.createTextNode(r.label));
    line.append(l, el("span", { class: "tip-value" }, r.value));
    tipBox.appendChild(line);
  }
  if (c.note) tipBox.appendChild(el("div", { class: "tip-note" }, c.note));
}
function tipPlace(x, y) {
  const m = 14, w = tipBox.offsetWidth, h = tipBox.offsetHeight;
  const vw = document.documentElement.clientWidth, vh = window.innerHeight;
  let left = x + m, top = y + m;
  if (left + w > vw - 8) left = Math.max(8, x - m - w);
  if (top + h > vh - 8) top = Math.max(8, y - m - h);
  tipBox.style.left = left + "px"; tipBox.style.top = top + "px";
}
function tipShow(owner, fn, x, y) {
  tipOwner = owner; owner.classList.add("tip-on");
  tipFill(fn()); tipBox.hidden = false; tipPlace(x, y);
}
function tipHide(owner) {
  if (owner && owner !== tipOwner) return;
  if (tipOwner) tipOwner.classList.remove("tip-on");
  tipOwner = null; tipBox.hidden = true;
}
function tip(target, fn) {
  target.addEventListener("pointerenter", (e) => { if (e.pointerType === "mouse") tipShow(target, fn, e.clientX, e.clientY); });
  target.addEventListener("pointermove", (e) => { if (tipOwner === target) tipPlace(e.clientX, e.clientY); });
  target.addEventListener("pointerleave", (e) => { if (e.pointerType === "mouse") tipHide(target); });
  target.addEventListener("click", (e) => {               // touch: tap to show, tap again to hide
    if (tipOwner === target && e.pointerType !== "mouse") return tipHide(target);
    tipShow(target, fn, e.clientX, e.clientY); e.stopPropagation();
  });
  if (target.tagName === "TR" || target.classList.contains("tierbar")) {
    target.tabIndex = 0;
    target.addEventListener("focus", () => {
      const r = target.getBoundingClientRect(); tipShow(target, fn, r.left + 24, r.bottom - 10);
    });
    target.addEventListener("blur", () => tipHide(target));
  }
}
document.addEventListener("click", () => tipHide());
document.addEventListener("keydown", (e) => { if (e.key === "Escape") tipHide(); });
window.addEventListener("scroll", () => tipHide(), { passive: true });

function emptyChart(s, msg) {
  s.textContent = "";
  const vb = s.viewBox.baseVal;
  s.setAttribute("viewBox", `0 0 ${vb.width} 60`);          // collapse: no big empty box
  const t = svg("text", { x: vb.width / 2, y: 34, "text-anchor": "middle" });
  t.textContent = msg; s.appendChild(t);
}

// ---------- charts ----------
function axes(s, W, H, pad, maxY, fmtY) {
  for (let i = 0; i <= 4; i++) {
    const y = pad.t + (H - pad.t - pad.b) * (1 - i / 4);
    s.appendChild(svg("line", { class: i ? "gridline" : "axis", x1: pad.l, x2: W - pad.r, y1: y, y2: y }));
    const t = svg("text", { x: pad.l - 6, y: y + 3, "text-anchor": "end" });
    t.textContent = fmtY(maxY * i / 4); s.appendChild(t);
  }
}
function lineChart(s, points, key, fmtY, tipFor) {
  s.textContent = "";
  if (!points.length) return emptyChart(s, "No verified matches yet");
  const vb = s.viewBox.baseVal, W = vb.width, H = vb.height, pad = { l: 56, r: 12, t: 10, b: 26 };
  const maxY = Math.max(...points.map((p) => p[key]), 1) * 1.1;
  axes(s, W, H, pad, maxY, fmtY);
  const n = points.length;
  const x = (i) => pad.l + (n === 1 ? (W - pad.l - pad.r) / 2 : (i / (n - 1)) * (W - pad.l - pad.r));
  const y = (v) => pad.t + (H - pad.t - pad.b) * (1 - v / maxY);
  let d = "";
  points.forEach((p, i) => { d += (i ? "L" : "M") + x(i).toFixed(1) + "," + y(p[key]).toFixed(1); });
  if (n > 1) {
    s.appendChild(svg("path", { class: "area", d: `${d}L${x(n - 1)},${H - pad.b}L${x(0)},${H - pad.b}Z` }));
    s.appendChild(svg("path", { class: "line", d }));
  }
  points.forEach((p, i) => {
    s.appendChild(svg("circle", { class: "dot", cx: x(i), cy: y(p[key]), r: n > 40 ? 0 : 3 }));
  });
  const step = Math.max(1, Math.ceil(n / 6));
  points.forEach((p, i) => {
    if (i % step && i !== n - 1) return;
    const t = svg("text", { x: x(i), y: H - 8, "text-anchor": "middle" }); t.textContent = p.day.slice(5); s.appendChild(t);
  });
  // a full-height hover strip per day, with a guide line and a marker on the point
  const half = n === 1 ? (W - pad.l - pad.r) / 2 : (W - pad.l - pad.r) / (n - 1) / 2;
  points.forEach((p, i) => {
    const g = svg("g", { class: "hit" });
    g.appendChild(svg("line", { class: "guide", x1: x(i), x2: x(i), y1: pad.t, y2: H - pad.b }));
    g.appendChild(svg("circle", { class: "mark", cx: x(i), cy: y(p[key]), r: 4.5 }));
    const left = Math.max(pad.l, x(i) - half), right = Math.min(W - pad.r, x(i) + half);
    g.appendChild(svg("rect", { x: left, y: pad.t, width: right - left, height: H - pad.t - pad.b, fill: "transparent" }));
    if (tipFor) tip(g, () => tipFor(p));
    s.appendChild(g);
  });
}
function stackedDaily(s, rows, legend, dayFns) {
  s.textContent = ""; legend.textContent = "";
  if (!rows.length) return emptyChart(s, "No verified matches yet");
  const days = [...new Set(rows.map((r) => r.day))];
  const models = [...new Set(rows.map((r) => r.model))];
  const val = new Map(rows.map((r) => [r.day + "|" + r.model, r.bytes]));
  const totals = days.map((d) => models.reduce((a, m) => a + (val.get(d + "|" + m) || 0), 0));
  const vb = s.viewBox.baseVal, W = vb.width, H = vb.height, pad = { l: 56, r: 12, t: 10, b: 26 };
  const maxY = Math.max(...totals, 1) * 1.1;
  axes(s, W, H, pad, maxY, (v) => kb(v) + "K");
  const slot = (W - pad.l - pad.r) / days.length, bw = Math.min(28, slot * 0.7);
  days.forEach((d, i) => {
    let acc = 0;
    const x0 = pad.l + slot * i + (slot - bw) / 2;
    const g = svg("g", { class: "hit bars" });
    g.appendChild(svg("rect", { x: pad.l + slot * i, y: pad.t, width: slot, height: H - pad.t - pad.b, fill: "transparent" }));
    for (const m of models) {
      const v = val.get(d + "|" + m) || 0;
      if (!v) continue;
      const h = (H - pad.t - pad.b) * v / maxY;
      const r = svg("rect", { x: x0, width: bw, y: H - pad.b - acc - h, height: h });
      r.style.fill = modelColour(m);
      g.appendChild(r); acc += h;
    }
    const parts = models.map((m) => [m, val.get(d + "|" + m) || 0]).filter(([, v]) => v).sort((a, b) => b[1] - a[1]);
    const fns = (dayFns && dayFns.get(d)) || 0;
    tip(g, () => ({
      title: `${d} · +${size(totals[i])}` + (fns ? `, +${n0(fns)} fns` : ""),
      rows: parts.map(([m, v]) => ({ swatch: modelColour(m), label: m, value: `${size(v)} · ${pct(v, totals[i], 0)}` })),
    }));
    s.appendChild(g);
    if (days.length <= 14 || i % Math.ceil(days.length / 10) === 0) {
      const t = svg("text", { x: x0 + bw / 2, y: H - 8, "text-anchor": "middle" }); t.textContent = d.slice(5); s.appendChild(t);
    }
  });
  for (const m of models) {
    const sp = el("span"); const sw = el("i", { class: "swatch" }); sw.style.background = modelColour(m);
    sp.append(sw, document.createTextNode(m)); legend.appendChild(sp);
  }
}
function hbars(s, items, fmtV) {
  // items: [{label, parts:[{v, colour}], tip: () => tooltip content}]
  s.textContent = "";
  if (!items.length) return emptyChart(s, "Nothing yet");
  const vb = s.viewBox.baseVal, W = vb.width;
  const rowH = 30, labelW = 170, pad = 8;
  const H = items.length * rowH + 2 * pad;
  s.setAttribute("viewBox", `0 0 ${W} ${H}`);
  const max = Math.max(...items.map((it) => it.parts.reduce((a, p) => a + p.v, 0)), 1);
  items.forEach((it, i) => {
    const y = pad + i * rowH;
    const g = svg("g", { class: "hit bars" });
    g.appendChild(svg("rect", { x: 0, y, width: W, height: rowH, fill: "transparent" }));
    const t = svg("text", { x: labelW - 10, y: y + rowH / 2 + 3, "text-anchor": "end" });
    t.textContent = it.label.length > 24 ? it.label.slice(0, 23) + "…" : it.label; g.appendChild(t);
    let x = labelW;
    for (const p of it.parts) {
      const w = (W - labelW - 90) * p.v / max;
      const r = svg("rect", { x, y: y + 6, width: Math.max(w, p.v ? 1 : 0), height: rowH - 12, rx: 2 });
      r.style.fill = p.colour;
      g.appendChild(r); x += w;
    }
    const v = svg("text", { x: x + 8, y: y + rowH / 2 + 3 });
    v.textContent = fmtV(it.parts.reduce((a, p) => a + p.v, 0)); g.appendChild(v);
    if (it.tip) tip(g, it.tip);
    s.appendChild(g);
  });
}

// ---------- sections ----------
let boardRows = [], boardKey = "bytes", boardDir = -1;
function renderBoard() {
  const rows = [...boardRows].sort((a, b) => {
    const x = a[boardKey], y = b[boardKey];
    return (typeof x === "string" ? x.localeCompare(y) : x - y) * boardDir;
  });
  const trs = fillRows($("board-table").tBodies[0], rows.map((r, i) => [
    { t: String(i + 1), cls: "rank" }, { t: r.who }, { t: n0(r.functions), cls: "num" },
    { t: size(r.bytes), cls: "num" },
    { t: r.since ? new Date(r.since * 1000).toISOString().slice(0, 10) : "–", cls: "num" },
  ]), 5, "No verified matches from contributors yet. Be the first.");
  trs.forEach((tr, i) => {
    const r = rows[i];
    if (r.bands) tip(tr, () => ({
      title: `${r.who} · by size band`,
      rows: r.bands.filter((b) => b.functions).map((b) => ({
        label: b.label, value: `${n0(b.functions)} fns · ${size(b.bytes)} · ${pct(b.bytes, r.bytes, 0)}` })),
      note: `${n0(r.functions)} functions · ${size(r.bytes)} verified`,
    }));
  });
}
for (const th of document.querySelectorAll("#board-table th.sortable")) {
  th.addEventListener("click", () => {
    const k = th.dataset.k;
    boardDir = boardKey === k ? -boardDir : (k === "who" ? 1 : -1);
    boardKey = k;
    for (const o of document.querySelectorAll("#board-table th")) o.removeAttribute("aria-sort");
    th.setAttribute("aria-sort", boardDir < 0 ? "descending" : "ascending");
    renderBoard();
  });
}

function render(s) {
  const upd = new Date(s.updated * 1000);
  $("updated").textContent = "Updated " + upd.toISOString().slice(0, 16).replace("T", " ") + " UTC";

  // stat cards
  $("c-bytes").textContent = size(s.matched_bytes);
  $("c-bytes-foot").textContent = `of ${size(s.bytes)} in scope · ${pct(s.matched_bytes, s.bytes, 3)}`;
  $("c-bytes-meter").style.width = Math.max(100 * s.matched_bytes / (s.bytes || 1), 0.5) + "%";
  $("c-fn").textContent = n0(s.matched);
  $("c-fn-foot").textContent = `of ${n0(s.functions)} in scope · ${pct(s.matched, s.functions)}`;
  $("c-todo").textContent = n0(s.todo);
  $("c-todo-foot").textContent = `functions · ${size(s.todo_bytes)} left · ${n0(s.ready)} ready, ${n0(s.claimed)} claimed`;
  $("c-today").textContent = "+" + n0(s.matched_today);
  $("c-today-foot").textContent = `functions · +${size(s.matched_today_bytes)} · ${n0(s.models_on_board)} model${s.models_on_board === 1 ? "" : "s"} on the board`;
  const t = s.tokens, tt = t.input + t.output + t.cached;
  $("c-tok").textContent = big(tt);
  $("c-tok-foot").textContent = tt ? `${big(t.output)} generated · ${pct(t.cached, tt, 0)} cached re-reads` : "reported with each submission";

  boardRows = s.leaderboard; renderBoard();

  // trend
  const dayTip = (p) => ({
    title: p.day,
    rows: [{ label: "total", value: `${n0(p.functions)} functions · ${size(p.bytes)}` },
           { label: "that day", value: `+${n0(p.new_functions || 0)} fns · +${size(p.new_bytes || 0)}` }],
    note: `${pct(p.bytes, s.bytes, 3)} of the bytes in scope`,
  });
  lineChart($("ch-bytes"), s.trend, "bytes", (v) => size(v), dayTip);
  lineChart($("ch-fns"), s.trend, "functions", (v) => n0(Math.round(v)), dayTip);
  stackedDaily($("ch-daily"), s.trend_by_model, $("lg-daily"),
    new Map(s.trend.map((p) => [p.day, p.new_functions || 0])));

  // squad
  const tries = new Map(s.squad.tries.map((r) => [r.model, r]));
  const today = new Map(s.squad.day.map((r) => [r.model, r]));
  hbars($("ch-squad"), s.squad.all.map((r) => ({
    label: r.model, parts: [{ v: r.bytes, colour: modelColour(r.model) }],
    tip: () => {
      const rows = [{ swatch: modelColour(r.model), label: "matched", value: `${n0(r.functions)} fns · ${size(r.bytes)}` },
                    { label: "share", value: (100 * r.share).toFixed(1) + "%" },
                    { label: "avg size", value: size(r.bytes / (r.functions || 1)) }];
      const d = today.get(r.model), t = tries.get(r.model);
      if (d) rows.push({ label: "last 24 h", value: `+${n0(d.functions)} fns · +${size(d.bytes)}` });
      if (t) rows.push({ label: "hit rate", value: `${n0(t.matches)} / ${n0(t.reports)} reports · ${pct(t.matches, t.reports, 0)}` });
      return { title: r.model, rows };
    } })),
    (v) => kb(v) + " KB");
  fillRows($("t-squad-all").tBodies[0], s.squad.all.map((r) => [
    { t: r.model, swatch: modelColour(r.model) }, { t: n0(r.functions), cls: "num" },
    { t: kb(r.bytes), cls: "num" }, { t: (100 * r.share).toFixed(1) + "%", cls: "num" }]), 4, "No matches yet.");
  fillRows($("t-squad-day").tBodies[0], s.squad.day.map((r) => [
    { t: r.model, swatch: modelColour(r.model) }, { t: n0(r.functions), cls: "num" },
    { t: kb(r.bytes), cls: "num" }]), 3, "Nothing verified in the last 24 hours.");
  fillRows($("t-squad-tries").tBodies[0], s.squad.tries.map((r) => [
    { t: r.model, swatch: modelColour(r.model) }, { t: n0(r.reports), cls: "num" },
    { t: n0(r.matches), cls: "num" }, { t: pct(r.matches, r.reports, 0), cls: "num" }]), 4, "No reports yet.");
  fillRows($("t-runs").tBodies[0], s.squad.runs.map((r) => [
    { t: r.day, cls: "mono" }, { t: n0(r.kept), cls: "num" }, { t: kb(r.kept_bytes), cls: "num" },
    { t: n0(r.rejected), cls: "num" }]), 4, "No verification run has matched or rejected anything yet.");

  // map
  const tiers = $("tiers"); tiers.textContent = "";
  for (const k of s.tiers) {
    const row = el("div", { class: "tierbar" });
    row.appendChild(el("span", {}, k.label));
    const st = el("div", { class: "stack" });
    tip(row, () => ({
      title: `${k.label} functions`,
      rows: [{ swatch: "var(--brass)", label: "matched", value: `${n0(k.matched)} · ${size(k.matched_bytes)}` },
             { swatch: "var(--bad)", label: "tried, open", value: n0(k.open) },
             { swatch: "var(--rule)", label: "never tried", value: n0(k.untried) }],
      note: `${pct(k.matched, k.total, 1)} done · ${size(k.bytes - k.matched_bytes)} left of ${size(k.bytes)}`,
    }));
    for (const [cls, v] of [["k-matched", k.matched], ["k-open", k.open], ["k-untried", k.untried]]) {
      const sp = el("span", { class: cls }); sp.style.width = (k.total ? 100 * v / k.total : 0) + "%"; st.appendChild(sp);
    }
    row.appendChild(st);
    row.appendChild(el("span", { class: "figs" }, `${n0(k.matched)} / ${n0(k.total)} · ${size(k.bytes - k.matched_bytes)} left`));
    tiers.appendChild(row);
  }

  // cost
  hbars($("ch-tokens"), s.cost.ledger.map((r) => ({
    label: r.source, parts: [
      { v: r.input / 1e6, colour: "var(--m0)" },
      { v: r.output / 1e6, colour: "var(--m1)" },
      { v: r.cached / 1e6, colour: "var(--m7)" }],
    tip: () => {
      const all = r.input + r.output + r.cached;
      return { title: r.source, rows: [
        { swatch: "var(--m0)", label: "input", value: `${big(r.input)} · ${pct(r.input, all, 0)}` },
        { swatch: "var(--m1)", label: "output", value: `${big(r.output)} · ${pct(r.output, all, 0)}` },
        { swatch: "var(--m7)", label: "cached", value: `${big(r.cached)} · ${pct(r.cached, all, 0)}` }],
        note: `${big(all)} tokens in all` };
    } })),
    (v) => v.toFixed(2) + " M");
  fillRows($("t-ledger").tBodies[0], s.cost.ledger.map((r) => {
    const all = r.input + r.output + r.cached;
    return [{ t: r.source, swatch: modelColour(r.source) }, { t: big(r.input), cls: "num" },
      { t: big(r.output), cls: "num" }, { t: pct(r.cached, all, 0), cls: "num" }];
  }), 4, "No token reports yet.");
  const spend = s.cost.spend.map((r) => [{ t: r.day, cls: "mono" }, { t: r.source }, { t: "$" + r.dollars.toFixed(2), cls: "num" }]);
  if (spend.length) spend.push([{ t: "Total", cls: "mono" }, { t: "" }, { t: "$" + s.cost.total_dollars.toFixed(2), cls: "num" }]);
  fillRows($("t-spend").tBodies[0], spend, 3, "No spend recorded yet.");

  // log
  const log = $("log-list"); log.textContent = "";
  if (!s.log.length) log.appendChild(el("li", { class: "empty" }, "No milestones yet."));
  for (const m of s.log) {
    const li = el("li"); li.append(el("time", { datetime: m.day }, m.day), el("span", {}, m.text)); log.appendChild(li);
  }
}

fetch("/api/stats").then((r) => r.json()).then(render).catch(() => {
  $("updated").textContent = "Could not load the report";
});
