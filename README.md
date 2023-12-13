# Simple Shell Project

## Overview

This is the Simple Shell project, a UNIX command line interpreter developed as part of the ALX Software Engineering program. The objective of this project is to create a basic shell that can handle various command line operations.

## Project Description

The Simple Shell project involves creating a command line interpreter that can execute commands entered by the user. It covers different aspects of system calls, environment variables, and basic shell functionalities.

## Table of Contents

1. [Project Overview](#overview)
2. [Project Description](#project-description)
3. [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
4. [Usage](#usage)
5. [Features](#features)
6. [Contributing](#contributing)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

## Getting Started

### Prerequisites

- You need a system running Ubuntu 20.04 LTS.
- GCC compiler for compiling the code.

### Installation

Clone the repository:

### bash
git clone https://github.com/OlaiyaO/simple_shell.git
cd simple_shell

### Compile the code:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell.

### Usage

Run the shell:
./simple_shell

The shell will display a prompt where you can enter commands.

### Features
Display a prompt and wait for user commands.
Execute simple commands with or without arguments.
Handle command lines with arguments.
Implement the exit built-in to exit the shell.
Implement the env built-in to display the current environment.
...

### Contributing
Contributions to the Simple Shell project are welcome! If you find any issues or have suggestions for improvements, please open an issue or create a pull request.
