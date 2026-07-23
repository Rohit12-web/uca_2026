self.onmessage = async function () {

    try {

        const response = await fetch("https://jsonplaceholder.typicode.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users.");
        }

        const users = await response.json();

        if (users.length === 0) {
            throw new Error("No users found.");
        }

        self.postMessage(users);

    }
    catch (error) {

        self.postMessage({
            error: error.message
        });

    }

};