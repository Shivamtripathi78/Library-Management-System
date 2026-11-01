# Library Management System

A console-based Library Management System developed using C++. It helps manage library records by allowing users to add, search, issue, return, and delete books efficiently.

## Features

* Add and display books.
* Search books by ID, title, or author.
* Issue books to borrowers.
* Return issued books.
* View available and issued books.
* Delete book records.
* Prevent issuing already-issued books.
* Store book records using file handling.

## Technologies Used

* **Language:** C++
* **Concepts:** OOP, Classes, Encapsulation, Vectors, File Handling, Searching, CRUD Operations.
* **Compiler:** GCC (G++)

## Project Structure

```text
Library-Management-System/
│
├── main.cpp
├── Book.h
├── Book.cpp
├── LibraryManager.h
├── LibraryManager.cpp
├── books.txt
└── README.md
```

## How to Run

**1. Clone the repository**

```bash
git clone https://github.com/Shivamtripathi78/Library-Management-System.git
```

**2. Navigate to the project directory**

```bash
cd Library-Management-System
```

**3. Compile the project**

```bash
g++ -std=c++17 main.cpp Book.cpp LibraryManager.cpp -o LibrarySystem.exe
```

**4. Run the application**

```powershell
.\LibrarySystem.exe
```

## Learning Outcomes

* Understanding OOP principles in C++.
* Implementing CRUD operations.
* Managing records using vectors.
* Performing search operations.
* Using file handling for persistent data storage.
* Building menu-driven console applications.

## Author

**Shivam Tripathi**

GitHub: [Shivamtripathi78](https://github.com/Shivamtripathi78)
