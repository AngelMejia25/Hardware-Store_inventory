#include <iostream>
#include <fstream>
#include "RBRecordDict.h"

using namespace std;

	RBRecordDict::RBRecordDict(){root = NULL;}
	RBRecordDict::~RBRecordDict(){destroy_tree(root);}

	void RBRecordDict::destroy_tree(RBtreeNode *n){
		if (n != NULL){
			destroy_tree(n->left);
			destroy_tree(n->right);
			delete n;}
		}

	RBtreeNode *RBRecordDict::grandparent(RBtreeNode *n){
		if (n == NULL || n->parent == NULL){
			return NULL;
		}
		else {
			return n->parent->parent;
		}	
	}	
	RBtreeNode *RBRecordDict::uncle(RBtreeNode *n){
		RBtreeNode *g = grandparent(n);
		if (g == NULL){
			return NULL;
		}
		else if (n->parent==g->left){
			return g->right;
		}
		else {
			return g->left;
		}
	}
	RBtreeNode *RBRecordDict::sibling(RBtreeNode *n){
		if (n->parent == NULL){
			return NULL;
		}
		else if (n==n->parent->left){
			return n->parent->left;
		}
		else {
			return n->parent->left;
		}
	}
	RBcolor RBRecordDict::Color(RBtreeNode *n){
		if (n==NULL){
			return BLACK;
		}
		else{
			return n->color;
		}
	}

	void RBRecordDict::insert(record *in){
		if (root==NULL){
			root = new RBtreeNode(in);
			insert_fixup(root);
		}
		else{
			insert_h(in, root);
		}
	}

	void RBRecordDict::insert_h(record *in, RBtreeNode *n){
		if (n->data->operator>(*in)){
			if(n->left == NULL){
				n->left = new RBtreeNode(in, n);
				insert_fixup(n->left);
			}
			else{
				insert_h(in, n->left);
			}
		}
		else{
			if(n->right == NULL){
				n->right = new RBtreeNode(in, n);
				insert_fixup(n->right);
			}
			else{
				insert_h(in, n->right);
			}
		}
	}

	void RBRecordDict::rotate_right(RBtreeNode *x){
		RBtreeNode *y = x->left;
		x->left = y->right;
		if (y->right != NULL){
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == NULL){
			root = y;
		}
		else if (x == x->parent->left){
			x->parent->left = y;
		}
		else{
			x->parent->right = y;
		}
		y->right = x;
		x->parent = y;
	}
	void RBRecordDict::rotate_left(RBtreeNode *y){
		RBtreeNode *x = y->right;
		y->right = x->left;
		if (x->left != NULL){
			x->left->parent = y;
		}
		x->parent = y->parent;
		if (y->parent == NULL){
			root = x;
		}
		else if (y == y->parent->right){
			y->parent->right = x;
		}
		else{
			y->parent->left = x;
		}
		x->left = y;
		y->parent = x;
	}
	void RBRecordDict::insert_fixup(RBtreeNode *n){
		if ( n == root){
			n->color = BLACK;
			return;
		}
		else if (n->parent->color == BLACK){
			return;
		}
		RBtreeNode *p = n->parent;
		RBtreeNode *g = grandparent(n);
		RBtreeNode *u = uncle(n);

		if (Color(u) == BLACK){
			if (p == g->left && n == p->right){
				rotate_left(p);
				swap(p,n);
			}
			else if (p == g->right && n == p->left){
				rotate_right(p);
				swap(p, n);
			}
			p->color = BLACK;
			g->color = RED;
			if (n == p->left){
				rotate_right(g);
			}
			else{
				rotate_left(g);
			}
		}
		else if(Color(u) == RED){
			p->color = BLACK;
			u->color = BLACK;
			g->color = RED;
			insert_fixup(g);
		}

	}

	RBtreeNode *RBRecordDict::search(string w){
		return search_h(w, root);

	}

	RBtreeNode *RBRecordDict::search_h(string w, RBtreeNode *r){
		if (r == NULL){
			return NULL;
		}
		else if (r->data->operator==(w)){
			return r;
		}
		else if (r->data->operator>(w)){
			return search_h(w, r->left);
		}
		else{
			return search_h(w, r->right);
		}
	}

	RBtreeNode *RBRecordDict::successor(RBtreeNode *c){
		RBtreeNode *Z = c->right;		
		while(Z->left != NULL){
			Z = Z->left;
		}
		return Z;
	}

	void RBRecordDict::remove(string w){
		RBtreeNode *datanode = search(w);
		RBtreeNode *indanger;
		if (datanode == NULL){
			return;
		}

		if (datanode->left == NULL || datanode->right == NULL){
			indanger = datanode;
		}
		else{
			indanger = successor(datanode);
			datanode->data = indanger->data;
		}

		if (indanger->left != NULL){
			indanger->data = indanger->left->data;
			delete indanger->left;
			indanger->left = NULL;
			return;
		}
		else if (indanger->right != NULL){
			indanger->data = indanger->right->data;
			delete indanger->right;
			indanger->right = NULL;
			return;
		}

		if (indanger->color == BLACK){
			remove_fixup(indanger);
		}

		if (indanger->parent == NULL){
			root = NULL;
		}
		else if (indanger == indanger->parent->left){
			indanger->parent->left = NULL;
		}
		else{
			indanger->parent->right = NULL;
		}

		delete indanger;
	}
	void RBRecordDict::remove_fixup(RBtreeNode *n){
	
		// CASE 1
		if (n == root){
			return;
		}

		RBtreeNode *s;
		s = sibling(n);

		//CASE 2
		if (s->color == RED){
			n->parent->color = RED;
			s->color = BLACK;
			if (n == n->parent->left){
				rotate_left(n->parent);
			}
			else {
				rotate_right(n->parent);
			}
			s = sibling(n);
		}


		//CASE 3
		if (n->parent->color == RED && s->color == BLACK &&
			Color(s->left) == BLACK && Color(s->right) == BLACK){
			n->parent->color = BLACK;
			s->color = RED;
			return;
		}

		//CASE 4 left
		if (s == n->parent->right && 
			Color(s->left) == RED &&
			Color(s->right) == BLACK){
			s->color = RED;
			s->left->color = BLACK;
			rotate_right(s);
			s = sibling(n);
		} // Right
		else if (s == n->parent->left &&
			Color(s->right) == RED &&
			Color(s->left) == BLACK){
			s->color = RED;
			s->right->color = BLACK;
			rotate_left(s);
			s = sibling(n);
		}	

		//CASE 5 left
		if (n == n->parent->left && Color(s->right) == RED){
			s->color = n->parent->color;
			n->parent->color = BLACK;
			s->right->color = BLACK;
			rotate_left(n->parent);
			return;
		} //right
		else if (n == n->parent->right && Color(s->left) == RED){
			s->color = n->parent->color;
			n->parent->color = BLACK;
			s->left->color = BLACK;
			rotate_right(n->parent);
			return;
		}

		//CASE 6
		s->color = RED;
		remove_fixup(n->parent);
	}

	void RBRecordDict::inOrder_h(RBtreeNode *n){
		if (n != NULL){
			inOrder_h(n->left);
			myfile << n->data->fileString() << endl;
			inOrder_h(n->right);
		}
	}
	void RBRecordDict::preOrder_h(RBtreeNode *n){
	if (n != NULL){
			myfile << n->data->fileString() << endl;
			preOrder_h(n->left);
			preOrder_h(n->right);
		}
	}
	void RBRecordDict::postOrder_h(RBtreeNode *n){
	if (n != NULL){
			postOrder_h(n->left);
			postOrder_h(n->right);
			myfile << n->data->fileString() << endl;
		}
	}

	void RBRecordDict::toFile(string filename){
		cout << endl << "1 - Preorder Traversal. 2 - Inorder Traversal. 3 - Post order Traversal: ";

		int choice;
		cin >> choice;

		myfile.open(filename.c_str());

		if (choice == 1){
			preOrder_h(root);
		}
		else if (choice == 2){
			inOrder_h(root);
		}
		else if(choice == 3){
			postOrder_h(root);
		}
		else{
			cout << "Not a valid choice..." << endl;
		}

		myfile.close();

	}