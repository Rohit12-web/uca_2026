const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {

    if (event.data.error) {
        console.error(event.data.error);
        return;
    }

    event.data.forEach(function (user) {

        console.log(user.name + " - Active");

    });

};

worker.onerror = function () {

    console.error("Worker Error");

};