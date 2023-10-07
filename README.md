<!-- https://github.com/sidhant-khamankar/Railway-Reservation-System -->
# Railway Reservation System Documentation

## Overview

The Railway Reservation System is a software solution designed to streamline the process of booking, canceling, and managing train tickets for passengers. Its primary purpose is to provide an efficient and user-friendly platform for travelers to reserve seats on trains, inquire about available routes, and manage their bookings. This system plays a crucial role in modernizing and optimizing the railway industry by automating ticketing procedures and ensuring a smooth travel experience for passengers.

### Purpose

The purpose of the Railway Reservation System is to:

- **Simplify Ticket Booking:** Enable users to easily book train tickets from the comfort of their homes or any location with internet access.
- **Provide Real-time Information:** Offer up-to-date information on train schedules, seat availability, and ticket prices.
- **Facilitate Secure Transactions:** Ensure secure payment gateways for transactions, enhancing user trust and confidence in the system.
- **Optimize Seat Utilization:** Effectively manage seat allocations to maximize train occupancy and revenue.
- **Improve User Experience:** Enhance the overall experience of travelers by providing a seamless and hassle-free ticketing process.

### Implementation Choices

The Railway Reservation System has been implemented using a combination of Object-Oriented Programming (OOP), Multithreading, and Sockets for several reasons:

- **Modularity and Reusability:** OOP allows the system to be organized into modular, reusable components (objects and classes), making it easier to maintain and extend the system's functionality.
- **Concurrency and Responsiveness:** Multithreading enables the system to handle multiple client requests simultaneously, ensuring quick response times and efficient utilization of resources.
- **Client-Server Communication:** Sockets facilitate communication between the client and server components of the system, allowing seamless exchange of data and requests over a network.

By leveraging these technologies, the Railway Reservation System achieves a balance between robust architecture, concurrent processing, and effective communication, resulting in a powerful and responsive ticketing solution for both users and railway administrators.

## Files

### `server.cpp`
#### Server Class
- **User**
  - `Create(Mobile, Password)`: Creates a new user account.
  - `Authenticate(Mobile, Password)`: Authenticates user based on mobile number and password.
  - `Delete(Mobile, Password)`: Deletes user account.

- **Train**
  - `Add(Train-no, Source, Destination)`: Adds a new train to the system.
  - `Remove(Train-no, Source, Destination)`: Removes a train from the system.
  - `Display()`: Displays train information including train number, source, destination, start time, end time, and dynamic pricing per booked seats.

- **Reservation**
  - `Book-Ticket(user, train)`: Books a ticket for the user on a specific train.
  - `Cancel-Ticket(user, train)`: Cancels a booked ticket and updates empty seats and refunds the amount.
  - `Show-Coach(train)`: Displays the available seats in a train.

### `client.cpp`
#### Client Class
- **Account**
  - `Register(Mobile, Password)`: Registers a new user account.
  - `Login(Mobile, Password)`: Logs in an existing user.
  - `Delete-Account(Mobile, Password)`: Deletes the user account.

- **Ticket**
  - `Reserve(Mobile, Password, trn-no, src, dest)`: Reserves a ticket for the user on a specific train.
  - `Cancel(Mobile, Password, ticket-id)`: Cancels a booked ticket using the ticket ID.
  - `Status(Mobile, Password, ticket-id)`: Checks the status of a booked ticket.
  - `Enquire-Trains(trn-no)`: Provides information about available trains based on the train number.

#### Socket
- `Create socket`: Sets up a socket for communication between the server and clients.
- `Bind and listen server`: Binds the socket to a specific address and port and listens for incoming connections.
- `Accept requests (divide across threads)`: Accepts incoming client requests and divides them across threads for processing.
- `Close client`: Closes the connection with the client after processing the request.
- `Local IP address and routers`: Explains how to find the local IP address and configure routers for the server-client communication.

## How to Use

To use the Railway Reservation System, follow these steps to compile and run the server and client programs. Please ensure you have the necessary dependencies installed and configured on your system before proceeding.

### Prerequisites

1. **C++ Compiler:** Ensure you have a C++ compiler installed on your system. If you're using Linux, you can use `g++`. On Windows, you can use MinGW or Visual Studio.

### Compilation

#### Server Program (`server.cpp`)

Compile the server program using the following command:

```bash
g++ -o server server.cpp -lpthread
```

This command compiles `server.cpp` and creates an executable named `server`.

#### Client Program (`client.cpp`)

Compile the client program using the following command:

```bash
g++ -o client client.cpp
```

This command compiles `client.cpp` and creates an executable named `client`.

### Running the Server

Run the server program with the following command:

```bash
./server
```

The server will start listening for incoming connections on port `8080`.

### Running the Client

Run the client program with the following command:

```bash
./client
```

The client will attempt to connect to the server at `127.0.0.1:8080`. Ensure the server is running before starting the client.

### Note:

- **Port Number:** The server is configured to listen on port `8080`. If you need to change the port number, modify the `server.cpp` file and recompile the server program.
- **IP Address:** Both server and client are set to communicate on the localhost (`127.0.0.1`). If the server is hosted on a different machine, modify the IP address in the `client.cpp` file to match the server's IP address.

Make sure to handle any firewall or network configurations to allow communication between the server and client if they are running on different machines.