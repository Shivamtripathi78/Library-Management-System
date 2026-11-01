#include "Book.h"
#include <iostream>
#include <iomanip>

Book::Book() {
    bookId = 0;
    title = "";
    author = "";
    issuedTo = "";
}

Book::Book(int id, string bookTitle, string bookAuthor,
           string borrower) {
    bookId = id;
    title = bookTitle;
    author = bookAuthor;
    issuedTo = borrower;
}

int Book::getBookId() const {
    return bookId;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

string Book::getIssuedTo() const {
    return issuedTo;
}

bool Book::isAvailable() const {
    return issuedTo.empty();
}

void Book::issueBook(string borrower) {
    issuedTo = borrower;
}

void Book::returnBook() {
    issuedTo = "";
}

void Book::display() const {
    cout << left
         << setw(10) << bookId
         << setw(25) << title
         << setw(22) << author
         << setw(20)
         << (isAvailable() ? "Available" : issuedTo)
         << endl;
}