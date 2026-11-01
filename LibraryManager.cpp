#include "LibraryManager.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

LibraryManager::LibraryManager() {
    loadBooks();
}

int LibraryManager::findBookIndex(int id) const {
    for (int i = 0; i < static_cast<int>(books.size()); i++) {
        if (books[i].getBookId() == id) {
            return i;
        }
    }

    return -1;
}

void LibraryManager::loadBooks() {
    ifstream file("books.txt");
    string line;

    while (getline(file, line)) {
        try {
            stringstream ss(line);

            string id, title, author, borrower;

            getline(ss, id, '|');
            getline(ss, title, '|');
            getline(ss, author, '|');
            getline(ss, borrower);

            int bookId = stoi(id);

            if (bookId > 0 && !title.empty() &&
                findBookIndex(bookId) == -1) {
                books.emplace_back(bookId, title, author, borrower);
            }
        }
        catch (...) {
            continue;
        }
    }

    file.close();
}

void LibraryManager::saveBooks() const {
    ofstream file("books.txt");

    if (!file) {
        cout << "Error saving book records!\n";
        return;
    }

    for (const Book& book : books) {
        file << book.getBookId() << "|"
             << book.getTitle() << "|"
             << book.getAuthor() << "|"
             << book.getIssuedTo() << "\n";
    }

    file.close();
}

void LibraryManager::addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";

    if (!(cin >> id) || id <= 0) {
        cout << "Invalid Book ID!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (findBookIndex(id) != -1) {
        cout << "Book ID already exists!\n";
        return;
    }

    cout << "Enter Book Title: ";
    getline(cin >> ws, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    if (title.find('|') != string::npos ||
        author.find('|') != string::npos) {
        cout << "The character | is not allowed.\n";
        return;
    }

    books.emplace_back(id, title, author);

    saveBooks();

    cout << "\nBook added successfully!\n";
}

void LibraryManager::displayBooks() const {
    if (books.empty()) {
        cout << "\nNo books available in the library.\n";
        return;
    }

    cout << "\n"
         << left
         << setw(10) << "Book ID"
         << setw(25) << "Title"
         << setw(22) << "Author"
         << setw(20) << "Status"
         << "\n";

    cout << string(77, '-') << "\n";

    for (const Book& book : books) {
        book.display();
    }
}

void LibraryManager::searchBook() const {
    int choice;

    cout << "\nSearch By:\n";
    cout << "1. Book ID\n";
    cout << "2. Book Title\n";
    cout << "3. Author Name\n";
    cout << "Enter Choice: ";

    if (!(cin >> choice)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    bool found = false;

    if (choice == 1) {
        int id;

        cout << "Enter Book ID: ";

        if (!(cin >> id)) {
            cout << "Invalid input!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        int index = findBookIndex(id);

        if (index != -1) {
            books[index].display();
            return;
        }
    }
    else if (choice == 2 || choice == 3) {
        string keyword;

        cout << (choice == 2 ? "Enter Book Title: " :
                               "Enter Author Name: ");

        getline(cin >> ws, keyword);

        for (const Book& book : books) {
            string value = (choice == 2)
                ? book.getTitle()
                : book.getAuthor();

            if (value.find(keyword) != string::npos) {
                book.display();
                found = true;
            }
        }

        if (found) return;
    }
    else {
        cout << "Invalid choice!\n";
        return;
    }

    cout << "\nNo matching book found!\n";
}

void LibraryManager::issueBook() {
    int id;
    string borrower;

    cout << "\nEnter Book ID to Issue: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findBookIndex(id);

    if (index == -1) {
        cout << "Book not found!\n";
        return;
    }

    if (!books[index].isAvailable()) {
        cout << "Book is already issued!\n";
        return;
    }

    cout << "Enter Borrower's Name: ";
    getline(cin >> ws, borrower);

    if (borrower.find('|') != string::npos) {
        cout << "Invalid borrower name!\n";
        return;
    }

    books[index].issueBook(borrower);

    saveBooks();

    cout << "\nBook issued successfully to "
         << borrower << "!\n";
}

void LibraryManager::returnBook() {
    int id;

    cout << "\nEnter Book ID to Return: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findBookIndex(id);

    if (index == -1) {
        cout << "Book not found!\n";
        return;
    }

    if (books[index].isAvailable()) {
        cout << "This book is not currently issued!\n";
        return;
    }

    books[index].returnBook();

    saveBooks();

    cout << "\nBook returned successfully!\n";
}

void LibraryManager::displayAvailableBooks() const {
    bool found = false;

    cout << "\nAvailable Books:\n";

    for (const Book& book : books) {
        if (book.isAvailable()) {
            book.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No available books found.\n";
    }
}

void LibraryManager::displayIssuedBooks() const {
    bool found = false;

    cout << "\nIssued Books:\n";

    for (const Book& book : books) {
        if (!book.isAvailable()) {
            book.display();
            found = true;
        }
    }

    if (!found) {
        cout << "No issued books found.\n";
    }
}

void LibraryManager::deleteBook() {
    int id;

    cout << "\nEnter Book ID to Delete: ";

    if (!(cin >> id)) {
        cout << "Invalid input!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    int index = findBookIndex(id);

    if (index == -1) {
        cout << "Book not found!\n";
        return;
    }

    if (!books[index].isAvailable()) {
        cout << "Cannot delete an issued book. Return it first.\n";
        return;
    }

    books.erase(books.begin() + index);

    saveBooks();

    cout << "\nBook deleted successfully!\n";
}