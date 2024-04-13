#include <iostream>
#include "UserManager.h"

int main() {
    UserManager usermanage;

    int op;
    char choice;
    do {
        std::system("cls");
        std::cout << "\n\n\t\t1. Register User " << std::endl;
        std::cout << "\t\t2. Login " << std::endl;
        std::cout << "\t\t3. Show User List " << std::endl;
        std::cout << "\t\t4. Search User " << std::endl;
        std::cout << "\t\t5. Delete User" << std::endl;
        std::cout << "\t\t6. Exit" << std::endl;
        std::cout << "\t\tEnter Your Choice : ";
        std::cin >> op;
        switch (op) {
        case 1: {
            usermanage.RegisterUser();
            break;
        }
        case 2: {
            std::string username, password;
            std::cout << "Enter User :";
            std::cin >> username;
            std::cout << "Enter Password :";
            std::cin >> password;
            usermanage.LoginUser(username, password);
            break;
        }
        case 3: {
            usermanage.ShowUserList();
            break;
        }
        case 4: {
            std::string username;
            std::cout << "Enter User Name :";
            std::cin >> username;
            usermanage.SearchUser(username);
            break;
        }
        case 5: {
            std::string username;
            std::cout << "Enter User Name :";
            std::cin >> username;
            usermanage.DeleteUser(username);
            break;
        }
        case 6:
            std::cout << "Exiting program..." << std::endl;
            exit(0);
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        std::cout << "Do You Want to Continue [Yes/ No] ? :";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

