#include <iostream>
#include <limits>
#include "LibraryManager.h"

using namespace std;

int main() {
    LibraryManager library;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "       LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";

        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Display Available Books\n";
        cout << "7. Display Issued Books\n";
        cout << "8. Delete Book\n";
        cout << "0. Exit\n";

        cout << "====================================\n";
        cout << "Enter Your Choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                library.displayAvailableBooks();
                break;

            case 7:
                library.displayIssuedBooks();
                break;

            case 8:
                library.deleteBook();
                break;

            case 0:
                cout << "\nThank you for using the Library Management System!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}