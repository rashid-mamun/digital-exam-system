#include "LoginSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>

LoginSystem::LoginSystem() {
    loadUsers();
}

std::string LoginSystem::simpleHash(const std::string& input) {
   
    std::string result = input;
    for (char& c : result) {
        c = c + 1; // Basic transformation
    }
    return result;
}

bool LoginSystem::loadUsers() {
    std::ifstream file("Data/user_data.txt");
    if (!file.is_open()) {
        std::cerr << "Warning: Could not open user_data.txt\n";
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, username, password;
        std::getline(ss, name, ',');
        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        users.emplace_back(name, username, password);
    }
    file.close();
    return true;
}

bool LoginSystem::saveUser(const User& user) {
    std::ofstream file("Data/user_data.txt", std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error: Could not save user data\n";
        return false;
    }
    file << user.name << "," << user.username << "," << user.password << "\n";
    file.close();
    return true;
}

bool LoginSystem::registerUser(const std::string& name, const std::string& username, const std::string& password) {
    for (const auto& user : users) {
        if (user.username == username) {
            std::cout << "Username already exists!\n";
            return false;
        }
    }
    std::string hashedPassword = simpleHash(password);
    User newUser(name, username, hashedPassword);
    users.push_back(newUser);
    return saveUser(newUser);
}

bool LoginSystem::login(const std::string& username, const std::string& password) {
    std::string hashedPassword = simpleHash(password);
    for (const auto& user : users) {
        if (user.username == username && user.password == hashedPassword) {
            currentUser = user.name;
            return true;
        }
    }
    std::cout << "Invalid username or password!\n";
    return false;
}

std::string LoginSystem::getCurrentUser() const {
    return currentUser;
}