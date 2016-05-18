#include <iostream>
#include "record.h"
#include <sstream>

using namespace std;

record::record(string b, string n, float p, int q){barcode = b, name = n, price = p, quantity = q;}

string record::tostring(){
	string rElements;
	ostringstream convert;
	convert << "Name: " << name << endl << "Price: " << price << "    Quantity left: " << quantity << endl << "Barcode: " << barcode;
	rElements = convert.str();
	return rElements;
}

float record::sell(int s){
	float product;

	if (quantity >= s) {
		product = price * s;
		quantity = quantity - s;
		return product;
	}
	else if(quantity <= 0) {
		cout << "Out of Stock." << endl;
		return 0;
	}
}

string record::fileString(){
	string rElements;
	ostringstream convert;
	convert << barcode << " " << name << " " << price << " " << quantity;
	rElements = convert.str();
	return rElements;
}

string record::getBarcode(){
	string rElements;
	ostringstream convert;
	convert << barcode;
	rElements = convert.str();
	return rElements;}

bool record::operator==(record b){
	if (barcode == b.barcode){
		return true;
	}
	else{
		return false;
	}
}

bool record::operator==(string a){
	if (barcode == a){
		return true;
	}
	else {
		return false;
	}
}

bool record::operator<(record b){
	if (barcode < b.barcode){
		return true;
	}
	else {
		return false;
	}
}

bool record::operator<(string a){
	if (barcode < a){
		return true;
	}
	else {
		return false;
	}
}

bool record::operator>(record b){
	if (barcode > b.barcode){
		return true;
	}
	else {
		return false;
	}
}

bool record::operator>(string a){
	if (barcode > a) {
		return true;
	}
	else {
		return false;
	}
}
