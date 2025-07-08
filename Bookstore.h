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

    double buyBook(const string& isbn, int qty, const string& email, const string& address) {
        for (auto& book : inventory) {
            if (book->getISBN() == isbn && book->isForSale()) {
                if (!book->isAvailable(qty)) {
                    throw runtime_error("Quantum book store: Not enough stock available");
                }
                book->buy(qty); // deal with reducing stock
                book->send(email, address); // deal with shipping (not implemented)
                return book->getPrice() * qty;
            }
        }
        throw runtime_error("Quantum book store: Book has not been found or is not for sale");
    }
};


#endif //BOOKSTORE_H
