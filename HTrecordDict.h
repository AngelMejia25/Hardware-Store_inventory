#ifndef HTRECORDDICT
#define HTRECORDDICT
#include "recordDict.h"
#include "cell.h"

class HTrecordDict : public recordDict{
protected:
	int size, a, b; 
	cell **H;

	int hash(string s);

	void linkedlist_insert(record *in, int h);
	cell *linkedlist_search(string w, int h);
	void linkedlist_remove(string w, int h);
public:
	HTrecordDict(int i);
	~HTrecordDict();

	void insert(record *in);
	cell *search(string w);
	void remove(string w);
	void toFile(string filename);


};



#endif