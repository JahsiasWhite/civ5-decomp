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
  tbody.textContent = "";
  if (!rows.length) {
    const tr = el("tr"); tr.appendChild(el("td", { colspan: cols, class: "empty" }, emptyText));
    tbody.appendChild(tr); return;
  }
  for (const cells of rows) {
    const tr = el("tr");
    for (const c of cells) {
      const td = el("td", c.cls ? { class: c.cls } : {});
      if (c.swatch) { const s = el("i", { class: "swatch" }); s.style.background = c.swatch; td.appendChild(s); }
      td.appendChild(document.createTextNode(c.t));
      tr.appendChild(td);
    }
    tbody.appendChild(tr);
  }
}
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
function lineChart(s, points, key, fmtY) {
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
    const c = svg("circle", { class: "dot", cx: x(i), cy: y(p[key]), r: n > 40 ? 0 : 3 });
    const tt = svg("title"); tt.textContent = `${p.day}: ${fmtY(p[key])}`; c.appendChild(tt);
    s.appendChild(c);
  });
  const step = Math.max(1, Math.ceil(n / 6));
  points.forEach((p, i) => {
    if (i % step && i !== n - 1) return;
    const t = svg("text", { x: x(i), y: H - 8, "text-anchor": "middle" }); t.textContent = p.day.slice(5); s.appendChild(t);
  });
}
function stackedDaily(s, rows, legend) {
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
    for (const m of models) {
      const v = val.get(d + "|" + m) || 0;
      if (!v) continue;
      const h = (H - pad.t - pad.b) * v / maxY;
      const r = svg("rect", { x: x0, width: bw, y: H - pad.b - acc - h, height: h });
      r.style.fill = modelColour(m);
      const tt = svg("title"); tt.textContent = `${d} · ${m}: ${size(v)}`; r.appendChild(tt);
      s.appendChild(r); acc += h;
    }
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
  // items: [{label, parts:[{v, colour, title}]}]
  s.textContent = "";
  if (!items.length) return emptyChart(s, "Nothing yet");
  const vb = s.viewBox.baseVal, W = vb.width;
  const rowH = 30, labelW = 170, pad = 8;
  const H = items.length * rowH + 2 * pad;
  s.setAttribute("viewBox", `0 0 ${W} ${H}`);
  const max = Math.max(...items.map((it) => it.parts.reduce((a, p) => a + p.v, 0)), 1);
  items.forEach((it, i) => {
    const y = pad + i * rowH;
    const t = svg("text", { x: labelW - 10, y: y + rowH / 2 + 3, "text-anchor": "end" });
    t.textContent = it.label.length > 24 ? it.label.slice(0, 23) + "…" : it.label; s.appendChild(t);
    let x = labelW;
    for (const p of it.parts) {
      const w = (W - labelW - 90) * p.v / max;
      const r = svg("rect", { x, y: y + 6, width: Math.max(w, p.v ? 1 : 0), height: rowH - 12, rx: 2 });
      r.style.fill = p.colour;
      const tt = svg("title"); tt.textContent = p.title; r.appendChild(tt);
      s.appendChild(r); x += w;
    }
    const v = svg("text", { x: x + 8, y: y + rowH / 2 + 3 });
    v.textContent = fmtV(it.parts.reduce((a, p) => a + p.v, 0)); s.appendChild(v);
  });
}

// ---------- sections ----------
let boardRows = [], boardKey = "bytes", boardDir = -1;
function renderBoard() {
  const rows = [...boardRows].sort((a, b) => {
    const x = a[boardKey], y = b[boardKey];
    return (typeof x === "string" ? x.localeCompare(y) : x - y) * boardDir;
  });
  fillRows($("board-table").tBodies[0], rows.map((r, i) => [
    { t: String(i + 1), cls: "rank" }, { t: r.who }, { t: n0(r.functions), cls: "num" },
    { t: size(r.bytes), cls: "num" },
    { t: r.since ? new Date(r.since * 1000).toISOString().slice(0, 10) : "–", cls: "num" },
  ]), 5, "No verified matches from contributors yet. Be the first.");
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
  lineChart($("ch-bytes"), s.trend, "bytes", (v) => size(v));
  lineChart($("ch-fns"), s.trend, "functions", (v) => n0(Math.round(v)));
  stackedDaily($("ch-daily"), s.trend_by_model, $("lg-daily"));

  // squad
  hbars($("ch-squad"), s.squad.all.map((r) => ({
    label: r.model, parts: [{ v: r.bytes, colour: modelColour(r.model), title: `${r.model}: ${size(r.bytes)}` }] })),
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
    const st = el("div", { class: "stack", title: `${n0(k.matched)} matched · ${n0(k.open)} tried, open · ${n0(k.untried)} never tried` });
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
      { v: r.input / 1e6, colour: "var(--m0)", title: `input ${big(r.input)}` },
      { v: r.output / 1e6, colour: "var(--m1)", title: `output ${big(r.output)}` },
      { v: r.cached / 1e6, colour: "var(--m7)", title: `cached ${big(r.cached)}` }] })),
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
