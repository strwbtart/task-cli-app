# C++ Task CLI App

A simple command-line task manager built in C++ that allows users to create, manage, edit, and persist tasks using file I/O.

---

## Features

* Add new tasks
* View all tasks
* Mark tasks as completed
* Edit existing tasks
* Delete tasks
* Automatically save tasks to a file (`tasks.txt`)
* Automatically load tasks on startup

---

## Concepts Used

* Structs
* Vectors
* Functions
* Pass-by-reference
* File I/O (`ifstream`, `ofstream`)
* Multi-file project structure
* Input validation
* Modular programming

---

## Technologies

* C++
* VS Code
* g++

---

## How to Build

Compile using g++:

```bash
g++ main.cpp task.cpp -o app
```

---

## How to Run

### Windows (PowerShell)

```bash
app.exe
```

### Mac/Linux

```bash
./app
```

---

## Project Structure

```text
main.cpp   -> Program flow and menu system
task.cpp   -> Function implementations
task.h     -> Struct definitions and function declarations
tasks.txt  -> Saved task data
```

---

## Example

```text
1. Add Task
2. View Tasks
3. Complete Task
4. Delete Task
5. Edit Task
6. Exit
```

---

## What I Learned

This project helped reinforce core C++ programming concepts including:

* Working with structs and vectors
* Separating code into header and implementation files
* Reading/writing files
* Building interactive CLI applications
* Organizing and refactoring code

---

## Author

Built while practicing C++ fundamentals and software development skills.
