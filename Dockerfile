# Use an official GCC image with build essentials
FROM gcc:latest

# Install CMake
RUN apt-get update && \
    apt-get install -y cmake && \
    rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /app

# Copy the current directory (where .cpp and CMakeLists.txt are) into the container
COPY . /app

# Create a build directory and compile the program using CMake
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make

# Run the built executable when the container starts
CMD ["./build/cpp_lims"]
