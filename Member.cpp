#include "Member.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

Member::Member(int id, const std::string& name, const std::string& contact)
    : memberID(id), name(name), contact(contact) {}

int Member::getMemberID() const { return memberID; }
std::string Member::getName() const { return name; }
std::string Member::getContact() const { return contact; }
std::vector<int> Member::getBorrowedBooks() const { return borrowedBookIDs; }

void Member::borrowBook(int bookID) {
    borrowedBookIDs.push_back(bookID);
}

void Member::returnBook(int bookID) {
    auto it = std::find(borrowedBookIDs.begin(), borrowedBookIDs.end(), bookID);
    if (it != borrowedBookIDs.end()) {
        borrowedBookIDs.erase(it);
    }
}

bool Member::hasBorrowed(int bookID) const {
    return std::find(borrowedBookIDs.begin(), borrowedBookIDs.end(), bookID) != borrowedBookIDs.end();
}

void Member::display() const {
    std::cout << std::left
              << std::setw(8)  << memberID
              << std::setw(25) << name
              << std::setw(20) << contact
              << "Books Borrowed: " << borrowedBookIDs.size()
              << std::endl;
}
