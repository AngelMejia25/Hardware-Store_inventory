#include "cell.h"

using namespace std; 

	cell::cell(record *d){data = d; previous = NULL; next = NULL;}
	cell::cell(record *d, cell *p){data = d; previous = p; next = NULL;}
	cell::cell(record *d, cell *p, cell *r){data = d; previous = p; next = r;}