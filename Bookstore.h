//
// Created by Kareem Elnaghy on 08/07/2025.
//

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <iostream>
#include <vector>
using namespace std;

class Bookstore {
    vector<Book*> inventory;
public:
    void addBook(Book* book) {
        inventory.push_back(book);
        cout<< "Book added to inventory: " << book->getISBN() << endl;
    }
    void removeOutdatedBooks(int maxAge) {
        int currentYear = 2025;
        for (auto it = inventory.begin(); it != inventory.end(); it++) {
            if (currentYear - (*it)->getYear() > maxAge) {
                cout << "Outdated Book will be removed: " << (*it)->getISBN() << endl;
                it = inventory.erase(it);
                if (it == inventory.end()) break;
            }
        }
    }

    double buyBook(const string& isbn, int qty, const string& email, const string& address, bool ship) {
        cout<<"Quantum book store: Purchasing book with ISBN " << isbn << " and quantity " << qty << endl;
        for (auto& book : inventory) {
            if (book->getISBN() == isbn && book->isForSale()) {
                if (!book->isAvailable(qty)) {
                    throw runtime_error("Purchase Failed: Not enough stock available");
                }
                book->buy(qty); // deal with reducing stock
                if (ship) {
                    book->send(email, address); // deal with shipping if customer would like shipping (not implemented)
                }
                return book->getPrice() * qty;
            }
        }
        throw runtime_error("Purchase Failed: Book has not been found or is not for sale");
    }
};


#endif //BOOKSTORE_H
