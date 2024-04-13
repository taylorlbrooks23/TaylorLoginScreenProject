# Simple Login System in C++ with MySQL Database Backend

This project is a simple command-line-based login system implemented in C++ with a MySQL database backend. It allows users to register, login, view the user list, search for users, and delete users.

## Features

- User Registration: Users can register by providing a username and password. The information is stored securely in a MySQL database.
- User Login: Registered users can log in by providing their username and password. The system verifies the credentials against the database.
- User List: Administrators can view a list of all registered users.
- User Search: Administrators can search for a specific user by username.
- User Deletion: Administrators can delete a user from the system.

## Prerequisites

- C++ Compiler
- MySQL Server
- MySQL Connector/C++ Library

## Setup

1. Install MySQL Server and MySQL Connector/C++ Library if not already installed.
2. Create a MySQL database named `taylorusers` (or any other name) and a table named `Users` with columns `username` and `password`.
3. Update the connection details in `UserManager.cpp` file:
    ```cpp
    con = driver->connect("tcp://127.0.0.1:3306", "root", "life2020");
    con->setSchema("taylorusers");
    ```
    Replace `"root"` with your MySQL username and `"life2020"` with your MySQL password.
4. Compile the source code using a C++ compiler.

## Usage

1. Run the compiled executable.
2. Follow the on-screen instructions to perform various operations:
   - Register User: Enter username and password to register a new user.
   - Login: Enter username and password to log in.
   - Show User List: View the list of all registered users.
   - Search User: Search for a specific user by username.
   - Delete User: Delete a user from the system.


