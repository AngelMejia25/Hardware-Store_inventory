#ifndef CELL
#define CELL
#include "record.h"
#include "container.h"

class cell : public container {
protected:
	cell *previous;
	cell *next;

public:

	cell(record *d);
	cell(record *d, cell *p);
	cell(record *d, cell *p, cell *r);

	friend class listRecordDict;
	friend class HTrecordDict;

};


#endif 