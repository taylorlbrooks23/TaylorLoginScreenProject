#include "UserManager.h"
#include <iostream>

UserManager::UserManager() {
    std::cout << "Connecting to MySQL database..." << std::endl;
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "life2020"); // Replace with your MySQL username and password
    con->setSchema("taylorusers"); // Replace with your database name
    std::cout << "Connection successful." << std::endl;
}

void UserManager::RegisterUser() {
    std::string username, password;
    std::cout << "Enter User Name: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;

    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("INSERT INTO Users (username, password) VALUES (?, ?)");
    pstmt->setString(1, username);
    pstmt->setString(2, password);
    pstmt->execute();
    delete pstmt;

    std::cout << "User Registered Successfully." << std::endl;
}

bool UserManager::LoginUser(const std::string& username, const std::string& password) {
    std::cout << "Logging in user..." << std::endl;

    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    pstmt = con->prepareStatement("SELECT * FROM Users WHERE username = ? AND password = ?");
    pstmt->setString(1, username);
    pstmt->setString(2, password);
    res = pstmt->executeQuery();
    bool success = res->next();
    delete res;
    delete pstmt;
    if (success) {
        std::cout << "Login Successful." << std::endl;
    }
    else {
        std::cout << "Invalid Username or Password." << std::endl;
    }
    return success;
}

void UserManager::ShowUserList() {
    std::cout << "Fetching user list..." << std::endl;

    sql::Statement* stmt;
    sql::ResultSet* res;
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT username FROM Users");
    std::cout << "--- User List ---" << std::endl;
    while (res->next()) {
        std::cout << res->getString("username") << std::endl;
    }
    delete res;
    delete stmt;
}

void UserManager::SearchUser(const std::string& username) {
    std::cout << "Searching for user..." << std::endl;

    sql::PreparedStatement* pstmt;
    sql::ResultSet* res;
    pstmt = con->prepareStatement("SELECT * FROM Users WHERE username = ?");
    pstmt->setString(1, username);
    res = pstmt->executeQuery();
    if (res->next()) {
        std::cout << "User Found." << std::endl;
    }
    else {
        std::cout << "User Not Found." << std::endl;
    }
    delete res;
    delete pstmt;
}

void UserManager::DeleteUser(const std::string& username) {
    std::cout << "Deleting user..." << std::endl;

    sql::PreparedStatement* pstmt;
    pstmt = con->prepareStatement("DELETE FROM Users WHERE username = ?");
    pstmt->setString(1, username);
    pstmt->execute();
    delete pstmt;

    std::cout << "User Deleted Successfully." << std::endl;
}
