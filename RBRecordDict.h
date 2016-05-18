#ifndef RBRECORDDICT
#define RBRECORDDICT
#include <fstream>
#include <string>
#include "RBtreeNode.h"
#include "record.h"
#include "recordDict.h"

class RBRecordDict : public recordDict{
protected:
	RBtreeNode *root;
	ofstream myfile;
	void destroy_tree(RBtreeNode *n);
	RBtreeNode *grandparent(RBtreeNode *n);
	RBtreeNode *uncle(RBtreeNode *n);
	RBtreeNode *sibling(RBtreeNode *n);
	RBcolor Color(RBtreeNode *n);

	void insert_h(record *in, RBtreeNode *n);
	void rotate_right(RBtreeNode *x);
	void rotate_left(RBtreeNode *y);
	void insert_fixup(RBtreeNode *n);
	RBtreeNode *successor(RBtreeNode *n);
	void remove_fixup(RBtreeNode *n);

	void inOrder_h(RBtreeNode *n);
	void preOrder_h(RBtreeNode *n);
	void postOrder_h(RBtreeNode *n);


public:

	RBRecordDict();
	~RBRecordDict();

	void insert(record *in);
	RBtreeNode *search(string w);
	RBtreeNode *search_h(string w, RBtreeNode *r);
	void remove(string w);
	void toFile(string filename);



};





#endif