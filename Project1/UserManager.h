#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <jdbc\mysql_driver.h>
#include <jdbc\cppconn\driver.h>
#include <jdbc\cppconn\prepared_statement.h>

class UserManager {
public:
    UserManager();
    void RegisterUser();
    bool LoginUser(const std::string& username, const std::string& password);
    void ShowUserList();
    void SearchUser(const std::string& username);
    void DeleteUser(const std::string& username);

private:
    sql::Driver* driver;
    sql::Connection* con;
};

#endif // USERMANAGER_H

