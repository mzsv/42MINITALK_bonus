# Minitalk - A Small Data Exchange Program

## Table of Contents

1. [Overview](#overview)
3. [Features](#features)
4. [Objectives](#objectives)
5. [How to use](#how-to-use)
6. [Author](#author)
7. [Acknowledgements](#acknowledgements)

## Overview

This project involves creating a simple client-server communication system using UNIX signals. The client sends a string to the server, which then prints the received string. The system is designed to handle multiple clients and ensure robust error handling, efficient performance, and memory management.

## Features

- **Command-Line Interaction:** The server prints its PID upon launch, and the client sends a string to the server.
- **Efficient Communication:** Communication between the client and server is performed using UNIX signals (`SIGUSR1` and `SIGUSR2`).
- **Error Handling:** Comprehensive error handling to avoid crashes such as segmentation faults, bus errors, and double frees.
- **Memory Management:** Ensures no memory leaks occur in the program.
- **Dynamic Client Handling:** The server can receive strings from multiple clients without needing a restart.
- **Acknowledgment:** The server sends an acknowledgment signal back to the client upon receiving a message. Bonus feature.
- **Unicode Support:** Extended support for Unicode characters in message transmission. Bonus feature.

## Objectives

- **Server:** 
  - Start the server and print its PID.
  - Handle multiple client connections and print received strings promptly (e.g., within a second for 100 characters).
- **Client:**
  - Requires two parameters: 
    1. Server’s PID.
    2. String to send.
  - Sends the string to the server for processing.
- **Communication:**
  - Utilize UNIX signals (`SIGUSR1` and `SIGUSR2`) for client-server communication.
  - Ensure real-time handling of signals as Linux does not queue signals of the same type.

## How to Use

1. **Clone the repository:**
   ```sh
   git clone <repository-url>

2. **Compile the code:**
   ```sh
   make

3. **Run the server:**
   ```sh
   ./server

4. **Run the client:**
   ```sh
   ./client <server_pid> <message>
  Replace <server_pid> with the PID of the running server and <message> with the string you wish to send.

## Author

- [Andre Silva](https://github.com/mzsv/)

## Acknowledgements

- The 42 School for providing the project specifications and work environment.
