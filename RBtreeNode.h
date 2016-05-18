#ifndef RBTREENODE
#define RBTREENODE
#include "record.h"
#include "container.h"
#include "recordDict.h"

enum RBcolor{RED, BLACK};

//RBcolor x; x=Red; x = Black;

class RBtreeNode : public container { 
protected:
	RBtreeNode *parent;
	RBtreeNode *left;
	RBtreeNode *right;
	RBcolor color;
public:
	RBtreeNode(record *d);
	RBtreeNode(record *d, RBtreeNode *p);

	friend class RBRecordDict;

};




#endif