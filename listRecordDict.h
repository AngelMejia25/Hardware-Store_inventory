#ifndef LISTRECORDDICT
#define LISTRECORDDICT
#include "cell.h"
#include "recordDict.h"
#include <string>

class listRecordDict : public recordDict {
protected:
	cell *first;
	cell *last;

public:

	listRecordDict();
	~listRecordDict();

	void insert(record *in);
	cell *search(string w);
	void remove(string w);
	void toFile(string filename);

};


#endif