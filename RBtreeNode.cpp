#include <iostream>
#include "RBtreeNode.h"

using namespace std;

	RBtreeNode::RBtreeNode(record *d){
		data = d;
		parent = NULL;
		left = NULL;
		right = NULL;
		color = RED;
	}

	RBtreeNode::RBtreeNode(record *d, RBtreeNode *p){
		data = d;
		parent = p;
		left = NULL;
		right = NULL;
		color = RED;
	}
