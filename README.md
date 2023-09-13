# Minitalk

This project was completed as part of the curriculum at School 42. The goal of the project is to implement a client-server model using signals to communicate between two processes.

## Installation

To install and run the program, follow these steps: 

1. Clone the repository to your local machine.
2. Open a terminal window and navigate to the root directory of the project.
3. Run the command `make` to compile the program.
4. Run the server using the command `./server`.
5. Run the client using the command `./client [server_pid] [message]`.

## Usage

The server is a daemon that waits for incoming signals from the client. When a signal is received, the server decodes the message and displays it on the screen.

The client sends a message to the server by sending a series of signals, one for each bit in the message. Each bit is sent as a separate signal using the `kill()` function. The client must specify the process ID of the server and the message to be sent as command-line arguments.

## Example

Here's an example of how to use the program to send a message from the client to the server:

```bash
$ ./server
Server PID: 1234

$ ./client 1234 "Hello, world!"
```

In this example, the server is started and displays its process ID on the screen. The client then sends a message to the server by sending a series of signals, one for each bit in the message.

## Credits

This project was completed by Edgar Boutillot as part of the curriculum at School 42.
