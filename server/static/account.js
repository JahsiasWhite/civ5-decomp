"use strict";
const $ = (id) => document.getElementById(id);
const hex = (a) => "0x" + Number(a).toString(16).padStart(8, "0");
// each module's binary, shown when hovering its label
const MOD_FILES = { exe: "CivilizationV_DX11.exe", db: "CvGameDatabaseWin32Final Release.dll",
                    loc: "CvLocalizationWin32Final Release.dll" };

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
  const tb = $("claims"); tb.textContent = "";
  if (!me.claims.length) {
    const tr = document.createElement("tr"); const td = document.createElement("td");
    td.colSpan = 4; td.className = "empty"; td.textContent = "No active claims.";
    tr.appendChild(td); tb.appendChild(tr);
  }
  for (const c of me.claims) {
    const tr = document.createElement("tr");
    // the function as module:addr with its module's coloured label
    const m = c.module || "exe", fn = document.createElement("td"), tag = document.createElement("span");
    tag.className = `mod mod-${m}`; tag.textContent = m; tag.title = MOD_FILES[m] || m;
    fn.className = "addr fn"; fn.append(tag, document.createTextNode(`${m}:${hex(c.addr)}`)); tr.appendChild(fn);
    for (const [v, cls] of [[c.worker, ""], [c.size, "num"],
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
    $("login-cmd").textContent =
      `python tools/c5d.py remote login --server ${location.origin} --token ${j.token}`;
    $("token-box").classList.remove("hidden");
  }));

function legacyCopy(text) {
  const ta = document.createElement("textarea");
  ta.value = text; ta.setAttribute("readonly", ""); ta.style.position = "fixed"; ta.style.opacity = "0";
  document.body.appendChild(ta); ta.select();
  let ok = false;
  try { ok = document.execCommand("copy"); } catch (e) { ok = false; }
  ta.remove();
  return ok;
}

function copyText(text) {
  const viaApi = navigator.clipboard && window.isSecureContext
    ? navigator.clipboard.writeText(text) : Promise.reject(new Error("no clipboard API"));
  return viaApi.catch(() => (legacyCopy(text) ? undefined : Promise.reject(new Error("copy failed"))));
}

function selectContents(el) {
  const r = document.createRange(); r.selectNodeContents(el);
  const sel = getSelection(); sel.removeAllRanges(); sel.addRange(r);
}

for (const b of document.querySelectorAll("button.copy")) {
  const label = b.textContent;
  b.addEventListener("click", () => {
    copyText($(b.dataset.copy).textContent).then(
      () => { b.textContent = "Copied ✓"; },
      () => { selectContents($(b.dataset.copy)); b.textContent = "Press Ctrl+C"; });
    clearTimeout(b._t);
    b._t = setTimeout(() => { b.textContent = label; }, 2000);
  });
}
$("logout").addEventListener("click", () => post("/api/logout").then(() => location.assign("/")));
$("logout-all").addEventListener("click", () => {
  if (confirm("Sign out of every browser where you're signed in? Your CLI token keeps working."))
    post("/api/logout-all").then(() => location.assign("/"));
});
load();
