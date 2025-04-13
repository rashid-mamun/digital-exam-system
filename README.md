# Digital Exam System

A console-based C++ application for conducting multi-level quizzes with user authentication.

## Features
- **User Authentication**: Register and log in with a username and password.
- **Multi-Level Quizzes**: Three difficulty levels (Easy, Medium, Hard) with promotion based on scores.
- **Persistent Storage**: User data and quiz questions stored in text files.
- **Scoring System**: Tracks and displays scores across levels.
- **Cross-Platform**: Built with standard C++ for portability.

## Prerequisites
- **Without Docker**:
  - C++17 compatible compiler (e.g., g++, MSVC, clang)
  - CMake 3.10 or higher
  - Standard C++ libraries (ensure `<limits>`, `<iostream>`, etc., are available)
  - Optional: `make` for Unix-like systems
- **With Docker**:
  - Docker 20.10 or higher
  - Optional: Docker Compose (not required for this project)

## Installation

### Option 1: Build and Run without Docker
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/digital-exam-system.git
   cd digital-exam-system
   ```
2. Create the `Data/` directory and add question files:
   ```bash
   mkdir Data
   ```
   Copy `question_easy.txt`, `question_medium.txt`, and `question_hard.txt` into `Data/`.
   Create an empty `user_data.txt`:
   ```bash
   touch Data/user_data.txt
   ```
3. Create a build directory:
   ```bash
   mkdir build && cd build
   ```
4. Generate build files with CMake:
   ```bash
   cmake ..
   ```
5. Build the project:
   ```bash
   cmake --build .
   ```
6. Run the executable:
   ```bash
   ./DigitalExamSystem
   ```

### Option 2: Build and Run with Docker
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/digital-exam-system.git
   cd digital-exam-system
   ```
2. Ensure the `Data/` directory contains `question_easy.txt`, `question_medium.txt`, and `question_hard.txt`. The `user_data.txt` file will be created automatically.
3. Build the Docker image:
   ```bash
   docker build -t digital-exam-system .
   ```
4. Run the container:
   ```bash
   docker run -it digital-exam-system
   ```
   The `-it` flag enables interactive mode for console input/output.

**Note**: User data (`Data/user_data.txt`) is stored inside the container and will be lost when the container stops. To persist data, use a volume (see Advanced Docker Usage).

## Usage
1. **Register**: Create a new account with a full name, username, and password.
2. **Login**: Access the quiz system with your credentials.
3. **Take Quizzes**:
   - Start with the Easy quiz (5 questions, 10 points each).
   - Score ≥30 to unlock the Medium quiz.
   - Score ≥40 in Medium to unlock the Hard quiz.
4. **View Scores**: Final scores are displayed at the end of each quiz session.

## Question File Format
Each question file (`question_easy.txt`, etc.) follows this format:
```
Q-X	Question text
1. Option 1
2. Option 2
3. Option 3
4. Option 4
CorrectAnswer
```
Example:
```
Q-1	Who invented C++ program?
1. Bjarne Stroustrup
2. Dennis Ritchie
3. Brian Kernighan
4. Herb Sutter
1
```