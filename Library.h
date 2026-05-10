#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "Book.h"
#include "Member.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<Member> members;
    int nextBookID;
    int nextMemberID;

    Book* findBookByID(int bookID);
    Member* findMemberByID(int memberID);

public:
    Library();

    // Book management
    void addBook(const std::string& title, const std::string& author);
    void displayAllBooks() const;

    // Member management
    void addMember(const std::string& name, const std::string& contact);
    void displayAllMembers() const;

    // Borrowing & returning
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);

    // Search
    void searchByTitle(const std::string& keyword) const;
    void searchByAuthor(const std::string& keyword) const;
};

#endif
