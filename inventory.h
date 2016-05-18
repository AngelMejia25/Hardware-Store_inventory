#ifndef INVENTORY
#define INVENTORY
#include "record.h"
#include "recordDict.h"
#include "listRecordDict.h"
#include <string>

using namespace std;

class inventory {
protected:
	recordDict *dict;
public:

	inventory(recordDict *d);
	~inventory();

	void search(string s);
	void sell(string s, int a);
	void add(record* r);
	void remove(string s);
	void readfile(string s);
	void toFile(string s);

};


#endif