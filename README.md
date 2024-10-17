<h1 align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://user-images.githubusercontent.com/80087248/229268959-a3cb2881-3022-4acf-afc5-b6007e94ff3d.png">
    <img src="./assets/logo.png">
  </picture>

  <!--[![GitHub release](https://img.shields.io/github/v/release/RyanLua/Shime?logo=roblox&color=2db74c)](https://github.com/RyanLua/Shime/releases)
  [![GitHub top language](https://img.shields.io/github/languages/top/RyanLua/Shime?logo=lua&color=2db74c)](https://github.com/search?q=repo%3ARyanLua%2FShime++language%3ALua&type=code) -->
  [![GitHub license](https://img.shields.io/github/license/DevByEagle/Syncio?logo=apache&color=2db74c)](LICENSE)
  [![Lint](https://github.com/DevByEagle/Syncio/actions/workflows/build.yml/badge.svg)](https://github.com/DevByEagle/Syncio/actions/workflows/build.yml)

  <!-- [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/RyanLua/Shime?quickstart=1) -->

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
2. Install headers and the lib file:
```.sh
sudo make install
```
3. Compiling code:
```.sh
g++ main.cpp -o <output_name> -lsync -lstdc++ # You Need to use -lstdc++ or else it will not work
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
