<h1 align="center">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="./assets/SyncioDark.png">
    <source media="(prefers-color-scheme: light)" srcset="./assets/SyncioLight.png">
    <img src="./assets/Syncio.png">
  </picture>
  
  [![GitHub license](https://img.shields.io/github/license/DevByEagle/Syncio?logo=apache&color=2db74c)](LICENSE)
  [![Lint](https://github.com/DevByEagle/Syncio/actions/workflows/build.yml/badge.svg)](https://github.com/DevByEagle/Syncio/actions/workflows/build.yml)

  <!-- [![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/RyanLua/Shime?quickstart=1) -->

</h1>

# Syncio

## Project Description

Syncio is an open source C/C++ library designed for providing many different functions. It offers a lightweight cross-platform solution.

## Features

- **Performance**: This is a lightweight library designed to efficiently perform.

## Prerequisites

Before you begin, ensure you have the following installed:

| Dependency | Version |
| :--- | :--- |
| **CMake** | *latest* |

## Installation

To install Syncio, follow these steps:

1. **Clone the repository:**
```.sh
 git clone https://github.com/DevByEagle/Syncio.git
```

2. **Navigate to the project directory:**
```.sh
cd Syncio
mkdir build
```

### Building on Linux

For Linux, use the following commands to build the library:

1. **Initialize CMake:**
```.sh
cmake -S . -B build
```
2. **Run the build command:**
```.sh
cmake --build build/
```
2. **Install headers and the lib file:**
```.sh
sudo cmake --install .
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
#include <Syncio/syncio.h>

int main() {
    println("Hello World\n"); // Prints `Hello World`
    return 0;
}
```
