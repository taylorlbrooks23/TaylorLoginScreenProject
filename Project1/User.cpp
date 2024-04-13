#include "User.h"

User::User(std::string name, std::string pass) : username(name), password(pass) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}
