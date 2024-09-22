# Use a base image with C++ build tools
FROM gcc:latest

WORKDIR /app

# Copy the source and header files into the container
COPY src/ ./src/
COPY include/ ./include/

# Compile the C++ code, including the header files from the include directory
RUN g++ -o syncio src/main.cpp -I include/

# Set the command to run the program
CMD ["./syncio"]

