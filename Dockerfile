FROM ubuntu:22.04

# Install build essentials, CMake, and other dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /app

COPY . .

# Create the Data directory and ensure it's writable
RUN mkdir -p Data && touch Data/user_data.txt && chmod -R 777 Data

# Build the application using CMake
RUN mkdir build && cd build && cmake .. && cmake --build .


ENTRYPOINT ["./build/DigitalExamSystem"]