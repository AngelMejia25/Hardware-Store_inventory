#ifndef RECORD
#define RECORD
#include <string>

using namespace std;

class record {
protected:
	string barcode;
	string name;
	float price;
	int quantity;
public:
	friend class record;

	record(string b, string n, float p, int q);
	string tostring();
	float sell(int s);
	string fileString();
	string getBarcode();
	bool operator==(record b);
	bool operator==(string a);
	bool operator<(record b);
	bool operator<(string a);
	bool operator>(record b);
	bool operator>(string a);
};

#endif