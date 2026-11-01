#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    string issuedTo;

public:
    Book();
    Book(int id, string bookTitle, string bookAuthor,
         string borrower = "");

    int getBookId() const;
    string getTitle() const;
    string getAuthor() const;
    string getIssuedTo() const;

    bool isAvailable() const;

    void issueBook(string borrower);
    void returnBook();

    void display() const;
};

#endif