//
// Created by Kareem Elnaghy on 08/07/2025.
//

#ifndef TEST_H
#define TEST_H

#include "Book.h"
#include "Bookstore.h"

class QuantumBookstoreTest {
public:
    static void runTest() {
        Bookstore store;
        cout<<"=========Welcome to Quantum Bookstore========="<<endl;
        store.addBook(new PaperBook("ISBN1", "Invincible Vol. 1", "Robert Kirkman", 2008, 50.0, 5));
        store.addBook(new EBook("ISBN2", "Cant Hurt Me", "David Goggins", 2018, 30.0, "PDF"));
        store.addBook(new ShowcaseBook("ISBN3", "Intro to Computer Engineering", "Kareem Elnaghy", 2025));
        store.addBook(new PaperBook("ISBN4", "Rose in Chains", "Julie Soto", 2025, 20.0, 10));

        store.showInventory();

        cout<<endl;

        store.removeOutdatedBooks(10);

        // Test: Buying Paper Book
        try {
            double amountPaid = store.buyBook("ISBN1", 2, "kareemelnaghy@aucegypt.edu", "Maadi, Cairo, Egypt", 1);
            cout << "Quantum book store: Paid amount is " << amountPaid << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }

        try {
            double amountPaid = store.buyBook("ISBN4", 2, "kareemelnaghy@aucegypt.edu", "Maadi, Cairo, Egypt", 1);
            cout << "Quantum book store: Paid amount is " << amountPaid << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }

        // Test: Buying EBook
        try {
            double amountPaid = store.buyBook("ISBN2", 1, "johndoe@gmail.com", "", 1);
            cout << "Quantum book store: Paid amount = " << amountPaid << endl;
        } catch (exception& e) {
            cout << e.what() << endl;
        }

        try {
            double amountPaid = store.buyBook("ISBN3", 1, "charleslec@hotmail.com", "", 1);
            cout << "Quantum book store: Paid = " << amountPaid << endl;
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }
};


#endif //TEST_H
