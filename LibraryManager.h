#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include "Book.h"
#include <vector>

class LibraryManager {
private:
    vector<Book> books;

    int findBookIndex(int id) const;
    void loadBooks();
    void saveBooks() const;

public:
    LibraryManager();

    void addBook();
    void displayBooks() const;
    void searchBook() const;
    void issueBook();
    void returnBook();
    void displayAvailableBooks() const;
    void displayIssuedBooks() const;
    void deleteBook();
};

#endif