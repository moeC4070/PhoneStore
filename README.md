# 📱 PhoneStore

A simple phone inventory management system built with C++ and Node.js, demonstrating native bindings, TCP client-server communication, and inventory management.

## 📌 Overview

PhoneStore is a project that simulates a phone store inventory system. It combines C++ for inventory management logic and JavaScript (Node.js) for client-server communication.

The project uses Node.js Native API (N-API) to connect the C++ backend with JavaScript, allowing the application to execute inventory operations through a TCP connection.

## ✨ Features

- 📱 Phone inventory management
- 🛒 Buy phones from the inventory
- 💰 Sell phones and update stock quantities
- 📋 Fetch and display available phones
- 🌐 TCP client-server communication
- 🔗 C++ and JavaScript integration using native bindings

## 🏗️ Architecture

The project is divided into three main components:

- **Client (`client.js`):** Sends commands to the server.
- **Server (`server.js`):** Handles client connections and processes requests.
- **C++ Backend:** Implements the phone inventory management logic through a Node.js native addon.

## 🛠️ Technologies Used

- C++17
- JavaScript
- Node.js
- Node-API (N-API)
- node-gyp
- TCP Sockets

## ⚙️ Compilation & Execution

### Requirements

- Node.js and npm
- Python 3
- C++ compiler
- Build tools required by node-gyp

### Linux

Install the required build tools (Ubuntu/Debian):

```bash
sudo apt install build-essential python3
```

**Clone the repository:**

```bash
git clone https://github.com/moeC4070/PhoneStore.git
cd PhoneStore
```

**Install dependencies and compile:**

```bash
npm install
npm run build
```

**Run the application:**

Open two terminals.

Terminal 1 – Start the server:

```bash
npm run server
```

Terminal 2 – Start the client:

```bash
npm run client
```

### Windows

**Prerequisites:**
- Node.js
- Python 3
- Visual Studio Build Tools with the Desktop development with C++ workload

**Clone the repository:**

```cmd
git clone https://github.com/moeC4070/PhoneStore.git
cd PhoneStore
```

**Install dependencies and compile:**

```cmd
npm install
npm run build
```

**Run the application:**

Terminal 1:

```cmd
npm run server
```

Terminal 2:

```cmd
npm run client
```

## 🎮 Available Commands

| Command | Description |
|---|---|
| `BUY <id>` | Buy a phone and decrease its stock |
| `SELL <id>` | Sell a phone and increase its stock |
| `FETCH` | Display the phone inventory |
| `EXIT` | Disconnect from the server |

## 📚 Learning Objectives

- Understand TCP client-server architecture.
- Practice communication between C++ and JavaScript.
- Explore Node.js Native API (N-API).
- Learn how to build native Node.js addons using node-gyp.
- Apply object-oriented programming in C++.
- Understand how to manage and update inventory data.

## 👨‍💻 Author

**moeC4070**

- GitHub: [@moeC4070](https://github.com/moeC4070)
- Repository: [PhoneStore](https://github.com/moeC4070/PhoneStore)
