#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    bool isAvailable;

public:
    Book(int id, const std::string& title, const std::string& author);

    int getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getAvailability() const;

    void setAvailability(bool status);

    void display() const;
};

#endif
