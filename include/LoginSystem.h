#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include <string>
#include <vector>

class LoginSystem {
private:
    struct User {
        std::string name;
        std::string username;
        std::string password; 
        User(const std::string& n, const std::string& u, const std::string& p)
            : name(n), username(u), password(p) {}
    };
    std::vector<User> users;
    std::string currentUser;
    bool loadUsers();
    bool saveUser(const User& user);
    std::string simpleHash(const std::string& input); // Basic hash for demo

public:
    LoginSystem();
    bool registerUser(const std::string& name, const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    std::string getCurrentUser() const;
};

#endif