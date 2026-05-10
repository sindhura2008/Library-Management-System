# Library Management System

A console-based Library Management System built in C++ using Object-Oriented Programming principles. It manages books, members, and borrowing records efficiently.

## Features

- **Book Management** – Add books and display the full catalog
- **Member Management** – Register members and view member details
- **Issue & Return** – Issue books to members and process returns
- **Search** – Search books by title or author (case-insensitive)

## Project Structure

```
library_management/
├── main.cpp        # Entry point — menu-driven UI
├── Book.h          # Book class declaration
├── Book.cpp        # Book class implementation
├── Member.h        # Member class declaration
├── Member.cpp      # Member class implementation
├── Library.h       # Library class declaration
├── Library.cpp     # Library class implementation
├── Makefile        # Build configuration
└── README.md       # Project documentation
```

## Classes

| Class | Responsibility |
|-------|---------------|
| `Book` | Stores book ID, title, author, and availability status |
| `Member` | Stores member ID, name, contact, and list of borrowed book IDs |
| `Library` | Manages collections of books and members; handles all operations |

## How to Compile & Run

### Using Makefile (Linux / macOS)
```bash
make
./library_management
```

### Using g++ directly
```bash
g++ -std=c++17 -Wall main.cpp Book.cpp Member.cpp Library.cpp -o library_management
./library_management
```

### On Windows (MinGW)
```cmd
g++ -std=c++17 main.cpp Book.cpp Member.cpp Library.cpp -o library_management.exe
library_management.exe
```

## Menu Options

```
1. Add Book
2. Display All Books
3. Search Book by Title
4. Search Book by Author
5. Register Member
6. Display All Members
7. Issue Book
8. Return Book
0. Exit
```

## Sample Output

```
╔══════════════════════════════════════╗
║     LIBRARY MANAGEMENT SYSTEM        ║
╠══════════════════════════════════════╣
...

[✓] Book "1984" issued to Alice Johnson successfully.
[✓] Book "1984" returned by Alice Johnson successfully.
```

## Requirements

- C++17 or later
- g++ compiler (GCC / MinGW / Clang)
