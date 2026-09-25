const net = require("net");

const { Store } = require("./build/Release/phonestore");

const store = new Store();

// Store inventory
store.addPhone("Samsung", 100, 5);
store.addPhone("iPhone", 200, 3);
store.addPhone("Xiaomi", 300, 10);

const server = net.createServer((socket) => {
    console.log("Client connected");

    socket.on("data", (data) => {
        const message = data.toString().trim();

        console.log("Received:", message);

        const parts = message.split(/\s+/);
        const command = parts[0].toUpperCase();

        switch (command) {

            case "BUY": {
                if (parts.length !== 2) {
                    socket.write("Usage: BUY <id>\n");
                    break;
                }

                const id = Number(parts[1]);

                if (Number.isNaN(id)) {
                    socket.write("ID must be a number\n");
                    break;
                }

                const success = store.buyPhone(id);

                socket.write(
                    success
                        ? "BUY OK\n"
                        : "BUY FAILED\n"
                );

                break;
            }

            case "SELL": {
                if (parts.length !== 2) {
                    socket.write("Usage: SELL <id>\n");
                    break;
                }

                const id = Number(parts[1]);

                if (Number.isNaN(id)) {
                    socket.write("ID must be a number\n");
                    break;
                }

                const success = store.sellPhone(id);

                socket.write(
                    success
                        ? "SELL OK\n"
                        : "SELL FAILED\n"
                );

                break;
            }

            case "FETCH": {
                const phones = store.fetchPhones();

                socket.write(
                    JSON.stringify(phones) + "\n"
                );

                break;
            }

            default:
                socket.write(
                    "Unknown command. Use BUY, SELL or FETCH\n"
                );
        }
    });

    socket.on("end", () => {
        console.log("Client disconnected");
    });

    socket.on("error", (error) => {
        console.log("Socket error:", error.message);
    });
});

server.listen(3000, "127.0.0.1", () => {
    console.log("Server listening on 127.0.0.1:3000");
});
