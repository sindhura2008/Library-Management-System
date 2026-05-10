#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    int memberID;
    std::string name;
    std::string contact;
    std::vector<int> borrowedBookIDs;

public:
    Member(int id, const std::string& name, const std::string& contact);

    int getMemberID() const;
    std::string getName() const;
    std::string getContact() const;
    std::vector<int> getBorrowedBooks() const;

    void borrowBook(int bookID);
    void returnBook(int bookID);
    bool hasBorrowed(int bookID) const;

    void display() const;
};

#endif
