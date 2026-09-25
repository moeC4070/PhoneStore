const net = require("net");
const readline = require("readline");

const client = net.createConnection(
    {
        host: "127.0.0.1",
        port: 3000
    },
    () => {
        console.log("Connected to server");
        console.log("");
        console.log("Commands:");
        console.log("  BUY <id>");
        console.log("  SELL <id>");
        console.log("  FETCH");
        console.log("  EXIT");
        console.log("");

        rl.prompt();
    }
);

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: "> "
});

client.on("data", (data) => {
    console.log("Server:", data.toString().trim());
    rl.prompt();
});

rl.on("line", (line) => {
    const message = line.trim();

    if (message === "") {
        rl.prompt();
        return;
    }

    if (message.toUpperCase() === "EXIT") {
        client.end();
        rl.close();
        return;
    }

    client.write(message + "\n");
});

client.on("end", () => {
    console.log("Disconnected from server");
    rl.close();
});

client.on("error", (error) => {
    console.log("Connection error:", error.message);
    rl.close();
});
