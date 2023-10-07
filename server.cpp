#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <mutex>
#include <thread>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// **************************************************************
// FORMAT FOR CLASSES
// **************************************************************
class user
{
private:
    // **************************************************************
    // MEMBER DATA
    // **************************************************************
public:
    user(/* args */);
    ~user();
    // **************************************************************
    // MEMBER FUNCTIONS
    // **************************************************************
    bool create(string & mobile, string & password);
}; 

bool user::create(string & mobile, string & password){
    return true;
}
user::user(/* args */)
{
}

user::~user()
{
}


// **************************************************************
// ACTUAL CODE
// **************************************************************
std::mutex mtx;

class User {
public:
    std::string mobile;
    std::string password;

    User(std::string mobile, std::string password) : mobile(mobile), password(password) {}
};

class Train {
public:
    int trainNumber;
    std::string source;
    std::string destination;
    int availableSeats;

    Train(int number, std::string src, std::string dest, int seats)
        : trainNumber(number), source(src), destination(dest), availableSeats(seats) {}
};

class ReservationSystem {
private:
    std::map<std::string, User> users;
    std::map<int, Train> trains;

public:
    void createUser(std::string mobile, std::string password) {
        std::lock_guard<std::mutex> lock(mtx);
        users[mobile] = User(mobile, password);
    }

    bool authenticateUser(std::string mobile, std::string password) {
        std::lock_guard<std::mutex> lock(mtx);
        if (users.find(mobile) != users.end() && users[mobile].password == password) {
            return true;
        }
        return false;
    }

    void addTrain(int trainNumber, std::string source, std::string destination, int seats) {
        std::lock_guard<std::mutex> lock(mtx);
        trains[trainNumber] = Train(trainNumber, source, destination, seats);
    }
    // **************************************************************
    // Add other methods for booking, canceling tickets, etc.
    // **************************************************************
};

void handleClient(int clientSocket, ReservationSystem& reservationSystem) {
    char buffer[1024] = {0};
    char response[1024] = {0};

    // Receive data from client
    read(clientSocket, buffer, sizeof(buffer));
    
    // Process client request and send response back to client

    // Close the socket
    close(clientSocket);
}

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind the socket to localhost:8080
    if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    ReservationSystem reservationSystem;

    while (true) {
        // Accept incoming connection
        if ((newSocket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new thread to handle client
        std::thread(handleClient, newSocket, std::ref(reservationSystem)).detach();
    }

    return 0;
}