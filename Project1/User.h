#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string name, std::string pass);

    std::string getUsername() const;
    std::string getPassword() const;
};

#endif // USER_H
