"use strict";
const $ = (id) => document.getElementById(id);
const fmt = (n) => Number(n || 0).toLocaleString("en-US");
const hex = (a) => "0x" + Number(a).toString(16).padStart(8, "0");

function cell(tr, text, cls) {
  const td = document.createElement("td");
  td.textContent = text;
  if (cls) td.className = cls;
  tr.appendChild(td);
}

function emptyRow(tbody, cols, text) {
  const tr = document.createElement("tr");
  const td = document.createElement("td");
  td.colSpan = cols; td.className = "empty"; td.textContent = text;
  tr.appendChild(td); tbody.appendChild(tr);
}

function render(s) {
  const pct = s.bytes ? (100 * s.matched_bytes / s.bytes) : 0;
  $("pct").firstChild.nodeValue = pct < 1 ? pct.toFixed(3) : pct.toFixed(2);
  $("meter").style.width = Math.max(pct, 0.4) + "%";
  $("pct-sub").textContent = `${fmt(s.matched_bytes)} of ${fmt(s.bytes)} bytes · ${fmt(s.matched)} of ${fmt(s.functions)} functions`;
  $("k-matched").textContent = fmt(s.matched);
  $("k-reported").textContent = fmt(s.reported);
  $("k-claimed").textContent = fmt(s.claimed);
  $("k-ready").textContent = fmt(s.ready);
  $("k-people").textContent = fmt(s.contributors);

  const b = $("buckets"); b.textContent = "";
  for (const k of s.buckets) {
    const row = document.createElement("div"); row.className = "row";
    const l = document.createElement("span"); l.textContent = k.label;
    const m = document.createElement("div"); m.className = "meter";
    const i = document.createElement("i"); i.style.width = (k.total ? 100 * k.matched / k.total : 0) + "%";
    m.appendChild(i);
    const r = document.createElement("span"); r.textContent = `${fmt(k.matched)}/${fmt(k.total)}`;
    row.append(l, m, r); b.appendChild(row);
  }

  const board = $("board"); board.textContent = "";
  if (!s.leaderboard.length) emptyRow(board, 3, "No verified matches yet.");
  for (const r of s.leaderboard) {
    const tr = document.createElement("tr");
    cell(tr, r.who); cell(tr, fmt(r.functions), "num"); cell(tr, fmt(r.bytes), "num");
    board.appendChild(tr);
  }

  const recent = $("recent"); recent.textContent = "";
  if (!s.recent.length) emptyRow(recent, 3, "Nothing verified yet.");
  for (const r of s.recent) {
    const tr = document.createElement("tr");
    cell(tr, hex(r.addr), "addr"); cell(tr, r.name || "(unnamed)", "name"); cell(tr, fmt(r.size), "num");
    tr.title = `${r.who} · ${new Date(r.ts * 1000).toLocaleString()}`;
    recent.appendChild(tr);
  }

  drawTrend(s.trend);
}

function drawTrend(points) {
  const svg = $("trend");
  svg.textContent = "";
  if (points.length < 2) {
    $("trend-sub").textContent = points.length ? `${fmt(points[0].matched)} matched on ${points[0].day}` : "Updated after each verify run.";
    return;
  }
  const max = Math.max(...points.map((p) => p.matched), 1);
  const xs = (i) => (i / (points.length - 1)) * 400;
  const ys = (v) => 115 - (v / max) * 105;
  let d = "";
  points.forEach((p, i) => { d += (i ? "L" : "M") + xs(i).toFixed(1) + "," + ys(p.matched).toFixed(1); });
  const ns = "http://www.w3.org/2000/svg";
  const area = document.createElementNS(ns, "path");
  area.setAttribute("class", "area"); area.setAttribute("d", d + `L400,120L0,120Z`);
  const line = document.createElementNS(ns, "path");
  line.setAttribute("class", "line"); line.setAttribute("d", d);
  svg.append(area, line);
  const last = points[points.length - 1];
  $("trend-sub").textContent = `${points[0].day} → ${last.day}: ${fmt(last.matched)} functions`;
}

fetch("/api/stats").then((r) => r.json()).then(render).catch(() => {
  $("pct-sub").textContent = "Could not load progress.";
});
