#include "LoginSystem.h"
#include "QuizSystem.h"
#include <iostream>
#include <limits>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    LoginSystem loginSystem;
    QuizSystem quizSystem;
    int choice;

    while (true) {
        clearScreen();
        std::cout << "**************************************************************\n";
        std::cout << "*              WELCOME TO DIGITAL EXAM SYSTEM                *\n";
        std::cout << "**************************************************************\n\n";
        std::cout << "----------------Menu--------------------\n";
        std::cout << "1. Register\n";
        std::cout << "2. Login\n";
        std::cout << "3. Exit\n";
        std::cout << "----------------------------------------\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::string name, username, password, rePassword;
            clearScreen();
            std::cout << "Enter Full Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Password: ";
            std::getline(std::cin, password);
            std::cout << "Re-enter Password: ";
            std::getline(std::cin, rePassword);
            if (password != rePassword) {
                std::cout << "Passwords do not match!\n";
                std::cout << "Press Enter to continue...";
                std::cin.get();
                continue;
            }
            if (loginSystem.registerUser(name, username, password)) {
                std::cout << "Registration successful!\n";
            }
            std::cout << "Press Enter to continue...";
            std::cin.get();
        } else if (choice == 2) {
            std::string username, password;
            clearScreen();
            std::cout << "Enter Username: ";
            std::getline(std::cin, username);
            std::cout << "Enter Password: ";
            std::getline(std::cin, password);
            if (loginSystem.login(username, password)) {
                std::cout << "Login successful! Welcome, " << loginSystem.getCurrentUser() << "\n";
                int easyScore = quizSystem.runEasyQuiz();
                if (easyScore >= 30) {
                    std::cout << "Congratulations! Promoted to Medium level.\n";
                    int mediumScore = quizSystem.runMediumQuiz();
                    if (mediumScore >= 40) {
                        std::cout << "Congratulations! Promoted to Hard level.\n";
                        int hardScore = quizSystem.runHardQuiz();
                        std::cout << "\nFinal Scores:\n";
                        std::cout << "Easy: " << easyScore << "\n";
                        std::cout << "Medium: " << mediumScore << "\n";
                        std::cout << "Hard: " << hardScore << "\n";
                    } else {
                        std::cout << "\nFinal Scores:\n";
                        std::cout << "Easy: " << easyScore << "\n";
                        std::cout << "Medium: " << mediumScore << "\n";
                    }
                } else {
                    std::cout << "\nFinal Score:\n";
                    std::cout << "Easy: " << easyScore << "\n";
                }
                std::cout << "Press Enter to logout...";
                std::cin.get();
            }
        } else if (choice == 3) {
            std::cout << "Thank you for using Digital Exam System!\n";
            break;
        } else {
            std::cout << "Invalid choice! Press Enter to try again...";
            std::cin.get();
        }
    }
    return 0;
}