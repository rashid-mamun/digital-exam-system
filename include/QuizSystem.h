#ifndef QUIZ_SYSTEM_H
#define QUIZ_SYSTEM_H

#include <string>
#include <vector>

class QuizSystem {
private:
    struct Question {
        std::string text;
        std::vector<std::string> options;
        int correctAnswer;
    };
    int runQuiz(const std::string& fileName, const std::string& difficulty);

public:
    int runEasyQuiz();
    int runMediumQuiz();
    int runHardQuiz();
};

#endif