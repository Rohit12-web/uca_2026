const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {

    if (event.data.error) {
        usersDiv.textContent = event.data.error;
        return;
    }

    usersDiv.innerHTML = "";

    event.data.forEach(function (user) {

        const p = document.createElement("p");

        p.textContent = user.name + " - Active";

        usersDiv.appendChild(p);

    });

};

worker.onerror = function () {

    usersDiv.textContent = "An error occurred.";

};