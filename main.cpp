#include <iostream>
#include "record.h"
#include "cell.h"
#include "listRecordDict.h"
#include "inventory.h"
#include "container.h"
#include "recordDict.h"
#include "RBRecordDict.h"
#include "RBtreeNode.h"
#include "HTrecordDict.h"

using namespace std;

int main(){
	cout << "Hello. How would you like the inventory?" << endl << "1 - Linked List." << endl
		<< "2 - Red-Black Tree." << endl << "3 - Hash Table" << endl << "Enter a corresponding number: ";

	int select;
	inventory *myinv;
	cin >> select; 
	int size;

	switch(select){

	case 1:
		myinv = new inventory(new listRecordDict);

		break;
	case 2:
		myinv = new inventory(new RBRecordDict);

		break;
	case 3:
		cout << "How big would you like the Hash table to be?: ";
		cin >> size;
		myinv = new inventory(new HTrecordDict(size));

		break;
	}

	int option = 1;

	string barcode; string name; float price; int quantity;	string filename;
	record *newAdd;


	while(option != 0){
		cout << endl << endl << "which option would you like: " << endl << "1: Read a file." << endl
		<< "2: Manually add an entry" << endl << "3: Search for Barcode in the inventory" 
		<< endl << "4: Sell an item" << endl << "5: Remove a barcode from the inventory" << endl
		<< "6: Write the inventory to file" << endl << "0: End the program" << endl
		<< endl << "Enter a corresponding number: ";

		cin >> option;

		switch(option){

		case 1:
			cout << endl << "Enter the name of the file: ";
			cin >> filename;
			myinv->readfile(filename);
			break;
		case 2:
			cout << endl << "Add a new record" << endl;
			cout << "Barcode: "; cin >> barcode; cout << endl;
			cout << "Name: "; cin >> name; cout << endl;
			cout << "Price: "; cin >> price; cout << endl;
			cout << "Quantity: "; cin >> quantity; cout << endl;
			newAdd = new record(barcode, name, price, quantity);
			myinv->add(newAdd);
			break;
		case 3:
			cout << "Barcode you would like to search for: ";
			cin >> barcode;
			cout << endl;
			myinv->search(barcode);
			break;
		case 4:
			cout << "Barcode: "; cin >> barcode; cout << endl;
			cout << "Quantity: "; cin >> quantity; cout << endl;
			myinv->sell(barcode, quantity);
			break;
		case 5:
			cout << "Barcode to remove: ";
			cin >> barcode;
			myinv->remove(barcode);
			cout << endl << "Barcode: " << barcode << " Removed." << endl;
			break;
		case 6:
			cout << "Filename to write the file into: ";
			cin >> filename;
			myinv->toFile(filename);
			break;
		case 0:
			delete myinv;
			break;


		}
	}
}