"use strict";
const $ = (id) => document.getElementById(id);
const hex = (a) => "0x" + Number(a).toString(16).padStart(8, "0");

function post(path, body) {
  return fetch(path, {
    method: "POST", credentials: "same-origin",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify(body || {}),
  }).then((r) => r.json().then((j) => (r.ok ? j : Promise.reject(j))));
}

function show(me) {
  $("signed-in").classList.remove("hidden");
  $("login").textContent = me.login.replace(/^dev:/, "");
  $("display").value = me.display;
  $("terms-todo").classList.toggle("hidden", me.accepted_terms);
  $("terms-done").classList.toggle("hidden", !me.accepted_terms);
  $("origin").textContent = location.origin;
  const tb = $("claims"); tb.textContent = "";
  if (!me.claims.length) {
    const tr = document.createElement("tr"); const td = document.createElement("td");
    td.colSpan = 4; td.className = "empty"; td.textContent = "No active claims.";
    tr.appendChild(td); tb.appendChild(tr);
  }
  for (const c of me.claims) {
    const tr = document.createElement("tr");
    for (const [v, cls] of [[hex(c.addr), "addr"], [c.worker, ""], [c.size, "num"],
                            [new Date(c.expires * 1000).toLocaleTimeString(), ""]]) {
      const td = document.createElement("td"); td.textContent = v; if (cls) td.className = cls; tr.appendChild(td);
    }
    tb.appendChild(tr);
  }
}

function load() {
  fetch("/api/me", { credentials: "same-origin" }).then((r) => {
    if (r.status === 401) { $("signed-out").classList.remove("hidden"); return; }
    return r.json().then(show);
  });
}

$("accept").addEventListener("click", () => post("/api/terms").then(load));
$("save-display").addEventListener("click", () =>
  post("/api/display", { display: $("display").value }).then((j) => {
    $("display-msg").textContent = j.display ? "Saved." : "Saved: you'll appear as anonymous.";
  }));
$("new-token").addEventListener("click", () =>
  post("/api/token").then((j) => {
    $("token").textContent = j.token;
    $("token-box").classList.remove("hidden");
  }));
$("logout").addEventListener("click", () => post("/api/logout").then(() => location.assign("/")));
$("logout-all").addEventListener("click", () => {
  if (confirm("Sign out of every browser where you're signed in? Your CLI token keeps working."))
    post("/api/logout-all").then(() => location.assign("/"));
});
load();
