<!-- https://github.com/sidhant-khamankar/Railway-Reservation-System -->
# Railway Reservation System Documentation

## Overview
Explain briefly what the railway reservation system does, its purpose, and why it was implemented using object-oriented programming, multithreading, and sockets.

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
Provide instructions on how to compile and run the server and client programs. Include any dependencies or configurations needed for successful execution.
