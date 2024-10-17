<h1 align="center">
    <picture>
        <source media="(prefers-color-scheme: dark)" srcset="./assets/logo.png">
        <img src="./assets/logo.png">
    </picture>
</h1>

# Syncio

## Project Description

Syncio is an open source C++ library designed for providing many different functions. It offers a lightweight cross-platform solution.

## Features

- **Performance**: This is a lightweight library designed to efficiently perform operations on strings.

## Prerequisites

Before you begin, ensure you have the following installed:

| Dependency | Version |
| :--- | :--- |
| **GCC** | *latest* |

## Installation

To install Syncio, follow these steps:

1. **Clone the repository:**
```.sh
 git clone https://github.com/DevByEagle/Syncio.git
```

2. **Navigate to the project directory:**
```.sh
cd Syncio
```
### Building on Linux

For Linux, use the following commands to build the library:

1. Run the build command:
```.sh
make
```
2. Install headers and lib file:
```.sh
sudo make install
```

### Building on Windows

For Windows, you can use a batch script with MinGW. Here’s how:

1. Ensure that MinGW is installed and added to your system's PATH.
2. Open a Command Prompt and navigate to the project directory:
```.bat
rem Go to the place were you put Syncio
cd path\to\Syncio
```
3. Run the build script:
```.bat
build.bat
```
## Usage

To use Syncio in your project, include the header file and link the library. Here's a simple example:

```.cpp
#include <syncio.h>

int main() {
    Syncio::println("Hello World\n"); // Prints `Hello World`
    return 0;
}
```
