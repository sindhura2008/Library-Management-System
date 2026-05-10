#include <iostream>
#include <string>
#include <limits>
#include "Library.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printMenu() {
    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║     LIBRARY MANAGEMENT SYSTEM        ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  BOOK OPERATIONS                     ║\n";
    std::cout << "║  1. Add Book                         ║\n";
    std::cout << "║  2. Display All Books                ║\n";
    std::cout << "║  3. Search Book by Title             ║\n";
    std::cout << "║  4. Search Book by Author            ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  MEMBER OPERATIONS                   ║\n";
    std::cout << "║  5. Register Member                  ║\n";
    std::cout << "║  6. Display All Members              ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  BORROWING OPERATIONS                ║\n";
    std::cout << "║  7. Issue Book                       ║\n";
    std::cout << "║  8. Return Book                      ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  0. Exit                             ║\n";
    std::cout << "╚══════════════════════════════════════╝\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;

    // Pre-load sample data
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("To Kill a Mockingbird", "Harper Lee");
    library.addBook("1984", "George Orwell");
    library.addBook("Pride and Prejudice", "Jane Austen");
    library.addBook("The Catcher in the Rye", "J.D. Salinger");

    library.addMember("Alice Johnson", "9876543210");
    library.addMember("Bob Smith", "9123456789");

    std::cout << "\nWelcome to the Library Management System!\n";
    std::cout << "(Sample books and members have been loaded.)\n";

    int choice;
    while (true) {
        printMenu();

        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "[!] Invalid input. Please enter a number.\n";
            continue;
        }
        clearInput();

        if (choice == 0) {
            std::cout << "\nThank you for using the Library Management System. Goodbye!\n";
            break;
        }

        std::string title, author, name, contact, keyword;
        int memberID, bookID;

        switch (choice) {
            case 1:
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author name: ";
                std::getline(std::cin, author);
                library.addBook(title, author);
                break;

            case 2:
                library.displayAllBooks();
                break;

            case 3:
                std::cout << "Enter title keyword: ";
                std::getline(std::cin, keyword);
                library.searchByTitle(keyword);
                break;

            case 4:
                std::cout << "Enter author keyword: ";
                std::getline(std::cin, keyword);
                library.searchByAuthor(keyword);
                break;

            case 5:
                std::cout << "Enter member name: ";
                std::getline(std::cin, name);
                std::cout << "Enter contact number: ";
                std::getline(std::cin, contact);
                library.addMember(name, contact);
                break;

            case 6:
                library.displayAllMembers();
                break;

            case 7:
                std::cout << "Enter Member ID: ";
                std::cin >> memberID;
                std::cout << "Enter Book ID to issue: ";
                std::cin >> bookID;
                clearInput();
                library.issueBook(memberID, bookID);
                break;

            case 8:
                std::cout << "Enter Member ID: ";
                std::cin >> memberID;
                std::cout << "Enter Book ID to return: ";
                std::cin >> bookID;
                clearInput();
                library.returnBook(memberID, bookID);
                break;

            default:
                std::cout << "[!] Invalid choice. Please select from the menu.\n";
        }
    }

    return 0;
}
