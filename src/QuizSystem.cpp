#include "QuizSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <limits>

int QuizSystem::runQuiz(const std::string& fileName, const std::string& difficulty) {
    std::vector<Question> questions;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << fileName << "\n";
        return 0;
    }

    std::string line;
    while (std::getline(file, line)) {
        Question q;
        q.text = line.substr(line.find('\t') + 1);
        for (int i = 0; i < 4; ++i) {
            std::getline(file, line);
            q.options.push_back(line.substr(line.find('\t') + 1));
        }
        std::getline(file, line);
        q.correctAnswer = std::stoi(line);
        questions.push_back(q);
    }
    file.close();

    int score = 0;
    std::cout << "\nStarting " << difficulty << " Quiz...\n";
    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << "\nQuestion " << (i + 1) << ": " << questions[i].text << "\n";
        for (size_t j = 0; j < questions[i].options.size(); ++j) {
            std::cout << (j + 1) << ". " << questions[i].options[j] << "\n";
        }
        int answer;
        do {
            std::cout << "Enter your answer (1-4): ";
            std::cin >> answer;
            if (answer < 1 || answer > 4) {
                std::cout << "Invalid option! Try again.\n";
            }
        } while (answer < 1 || answer > 4);

        if (answer == questions[i].correctAnswer) {
            std::cout << "Correct!\n";
            score += 10;
        } else {
            std::cout << "Wrong! Correct answer was " << questions[i].correctAnswer << "\n";
        }
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
    std::cout << "Your score in " << difficulty << " level: " << score << "\n";
    return score;
}

int QuizSystem::runEasyQuiz() {
    return runQuiz("Data/question_easy.txt", "Easy");
}

int QuizSystem::runMediumQuiz() {
    return runQuiz("Data/question_medium.txt", "Medium");
}

int QuizSystem::runHardQuiz() {
    return runQuiz("Data/question_hard.txt", "Hard");
}