#include <iostream>
#include <fstream>
#include "inventory.h"
#include "container.h"
#include "recordDict.h"

using namespace std;

	inventory::inventory(recordDict *d){dict = d;}
	inventory::~inventory(){
		delete dict;
	};

	void inventory::search(string s){
		container *ptr = dict->search(s);

		if (ptr == NULL){
			cout << "Barcode not found." << endl;
		}
		else{
			cout << ptr->data->tostring() << endl;
		}
	}

	void inventory::sell(string s, int a){
		container *ptr = dict->search(s);

		if (ptr == NULL){
			cout << "Barcode not found." << endl;
		}
		else if (ptr != NULL){
			float cost = ptr->data->sell(a);
			if (cost == 0){
				cout << "That quantity of item " << s << " is not available" << endl;
			}
			else{
				cout << endl << a << " of item " << s << " sold for " << cost;
			}
		}
	}

	void inventory::add(record* r){
		dict->insert(r);
	}

	void inventory::remove(string s){
		dict->remove(s);
	}

	void inventory::readfile(string s){
		ifstream myfile;
		myfile.open(s.c_str());

		string barcode, name;
		float price;
		int quantity;

		myfile >> barcode;
		while (!myfile.eof()){
			myfile >> name >> price >> quantity;
			record *r = new record(barcode, name, price, quantity);
			dict->insert(r); 
			myfile >> barcode;
		}
		myfile.close();
	}

	void inventory::toFile(string s){
		dict->toFile(s);
	}
