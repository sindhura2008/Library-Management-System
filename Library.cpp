#include "Library.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cctype>

// Helper: case-insensitive substring search
static bool containsIgnoreCase(const std::string& haystack, const std::string& needle) {
    std::string h = haystack, n = needle;
    std::transform(h.begin(), h.end(), h.begin(), ::tolower);
    std::transform(n.begin(), n.end(), n.begin(), ::tolower);
    return h.find(n) != std::string::npos;
}

Library::Library() : nextBookID(1001), nextMemberID(2001) {}

// ─── Private helpers ──────────────────────────────────────────────────────────

Book* Library::findBookByID(int bookID) {
    for (auto& b : books)
        if (b.getBookID() == bookID) return &b;
    return nullptr;
}

Member* Library::findMemberByID(int memberID) {
    for (auto& m : members)
        if (m.getMemberID() == memberID) return &m;
    return nullptr;
}

// ─── Book management ──────────────────────────────────────────────────────────

void Library::addBook(const std::string& title, const std::string& author) {
    books.emplace_back(nextBookID++, title, author);
    std::cout << "[+] Book added successfully. Book ID: " << (nextBookID - 1) << "\n";
}

void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    std::cout << "\n" << std::string(72, '=') << "\n";
    std::cout << std::left
              << std::setw(6)  << "ID"
              << std::setw(30) << "Title"
              << std::setw(25) << "Author"
              << "Status\n";
    std::cout << std::string(72, '-') << "\n";
    for (const auto& b : books)
        b.display();
    std::cout << std::string(72, '=') << "\n";
}

// ─── Member management ────────────────────────────────────────────────────────

void Library::addMember(const std::string& name, const std::string& contact) {
    members.emplace_back(nextMemberID++, name, contact);
    std::cout << "[+] Member registered successfully. Member ID: " << (nextMemberID - 1) << "\n";
}

void Library::displayAllMembers() const {
    if (members.empty()) {
        std::cout << "No members registered.\n";
        return;
    }
    std::cout << "\n" << std::string(65, '=') << "\n";
    std::cout << std::left
              << std::setw(8)  << "ID"
              << std::setw(25) << "Name"
              << std::setw(20) << "Contact"
              << "Borrowed\n";
    std::cout << std::string(65, '-') << "\n";
    for (const auto& m : members)
        m.display();
    std::cout << std::string(65, '=') << "\n";
}

// ─── Issue & Return ───────────────────────────────────────────────────────────

void Library::issueBook(int memberID, int bookID) {
    Member* member = findMemberByID(memberID);
    if (!member) {
        std::cout << "[!] Member ID " << memberID << " not found.\n";
        return;
    }
    Book* book = findBookByID(bookID);
    if (!book) {
        std::cout << "[!] Book ID " << bookID << " not found.\n";
        return;
    }
    if (!book->getAvailability()) {
        std::cout << "[!] Book \"" << book->getTitle() << "\" is currently not available.\n";
        return;
    }
    book->setAvailability(false);
    member->borrowBook(bookID);
    std::cout << "[✓] Book \"" << book->getTitle()
              << "\" issued to " << member->getName() << " successfully.\n";
}

void Library::returnBook(int memberID, int bookID) {
    Member* member = findMemberByID(memberID);
    if (!member) {
        std::cout << "[!] Member ID " << memberID << " not found.\n";
        return;
    }
    if (!member->hasBorrowed(bookID)) {
        std::cout << "[!] Member " << member->getName()
                  << " has not borrowed book ID " << bookID << ".\n";
        return;
    }
    Book* book = findBookByID(bookID);
    if (!book) {
        std::cout << "[!] Book ID " << bookID << " not found.\n";
        return;
    }
    book->setAvailability(true);
    member->returnBook(bookID);
    std::cout << "[✓] Book \"" << book->getTitle()
              << "\" returned by " << member->getName() << " successfully.\n";
}

// ─── Search ───────────────────────────────────────────────────────────────────

void Library::searchByTitle(const std::string& keyword) const {
    std::cout << "\nSearch results for title: \"" << keyword << "\"\n";
    std::cout << std::string(72, '-') << "\n";
    bool found = false;
    for (const auto& b : books) {
        if (containsIgnoreCase(b.getTitle(), keyword)) {
            b.display();
            found = true;
        }
    }
    if (!found) std::cout << "No matching books found.\n";
}

void Library::searchByAuthor(const std::string& keyword) const {
    std::cout << "\nSearch results for author: \"" << keyword << "\"\n";
    std::cout << std::string(72, '-') << "\n";
    bool found = false;
    for (const auto& b : books) {
        if (containsIgnoreCase(b.getAuthor(), keyword)) {
            b.display();
            found = true;
        }
    }
    if (!found) std::cout << "No matching books found.\n";
}
