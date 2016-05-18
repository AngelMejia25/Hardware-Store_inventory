#ifndef RECORDDICT
#define RECORDDICT
#include "container.h"
#include "record.h"

class recordDict{
public:


	virtual void insert(record *r) = 0;
	virtual container* search(string a) = 0;
	virtual void remove (string a) = 0;
	virtual void toFile (string a) = 0;

	
};











#endif