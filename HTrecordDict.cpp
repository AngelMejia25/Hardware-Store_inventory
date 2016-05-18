#include <iostream>
#include <fstream>
#include "HTrecordDict.h"
#include <cstdlib>
#include <string>

using namespace std;

	HTrecordDict::HTrecordDict(int i){
		size = i;
		H = new cell *[size];

		for(int i = 0; i < size; i++){
			H[i] = NULL;
		}

		a = rand()%size+1;
		b = rand()%size+1;
	}

	HTrecordDict::~HTrecordDict(){
		cell* temp;
		cell* temp_next;

		for (int i = 0; i < size; i++){
			temp = H[i];
			while (temp != NULL){
				temp_next = temp->next;
				delete temp;
				temp = temp_next;
			}
		}
		delete H;
	}

	int HTrecordDict::hash(string s){
		int h = b;
		for (int i = 0; i < s.length(); i++){
			h = (h * a + (int)s[i]) % size;
		}
		return h;
	}

	void HTrecordDict::insert(record *in){
		int h = hash(in->getBarcode());
		linkedlist_insert(in, h);
	}

	void HTrecordDict::linkedlist_insert(record *in, int h){

		if (H[h] == NULL){
			H[h] = new cell(in);
		}
		else{
			cell *newcell;
			newcell = new cell(in);
			newcell->next = H[h];
			H[h]->previous = newcell;
			H[h] = newcell;
		}
	}

	cell* HTrecordDict::search(string w){
		int h = hash(w);
		return linkedlist_search(w, h);
	}

	cell *HTrecordDict::linkedlist_search(string w, int h){
		cell *currentCell = H[h];
		while (currentCell != NULL){
			if (currentCell->data->operator==(w)){
				return currentCell;
			}
			else{
				currentCell = currentCell->next;
			}
		}
		return NULL;	
	}


	void HTrecordDict::remove(string w){
		int h = hash(w);
		linkedlist_remove(w, h);	
	}

	void HTrecordDict::linkedlist_remove(string w, int h){
		cell* todelete = search(w);
		if (todelete == NULL){
			return;
		}
		else if (todelete == H[h] && todelete->next == NULL){
			H[h] = NULL;
			delete todelete;
		}
		else if(todelete == H[h]){
			H[h] = H[h]->next;
			H[h]->previous = NULL;
			delete todelete;
		}
		else if(todelete->next == NULL){
			todelete->previous->next = NULL;
			delete todelete;
		}
		else{
			todelete->previous->next = todelete->next;
			todelete->next->previous = todelete->previous;
			delete todelete;
		}
	}

	void HTrecordDict::toFile(string filename){
		ofstream myfile;

		myfile.open(filename.c_str());

		for (int i = 0; i < size; i++){
			cell* currentCell = H[i]; 

			while (currentCell != NULL){
				myfile << currentCell->data->fileString() << endl;
				currentCell = currentCell->next;
			}

		}
		myfile.close();

	}