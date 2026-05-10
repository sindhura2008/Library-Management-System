#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book(int id, const std::string& title, const std::string& author)
    : bookID(id), title(title), author(author), isAvailable(true) {}

int Book::getBookID() const { return bookID; }
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
bool Book::getAvailability() const { return isAvailable; }

void Book::setAvailability(bool status) {
    isAvailable = status;
}

void Book::display() const {
    std::cout << std::left
              << std::setw(6)  << bookID
              << std::setw(30) << title
              << std::setw(25) << author
              << (isAvailable ? "Available" : "Issued")
              << std::endl;
}
