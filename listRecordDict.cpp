#include <iostream>
#include <string>
#include <fstream>
#include "listRecordDict.h"
#include "record.h"
#include "cell.h"
#include "recordDict.h"

using namespace std;

	listRecordDict::listRecordDict(){first = NULL; last = NULL;}
	listRecordDict::~listRecordDict(){
		cell *currentCell = first;
		while (currentCell != NULL) {
			cell* tmp;
			tmp = currentCell;
			currentCell = currentCell->next;
			delete tmp;
		}
	}


	void listRecordDict::insert(record *in){
		if (first == NULL && last == NULL){
			first = new cell(in);
			last = first;
		}
		else{
			cell *newcell;
			newcell = new cell(in);
			newcell->previous = last;
			last->next = newcell;
			last = newcell;
		}
	}

	cell *listRecordDict::search(string w){
		cell *currentCell = first;
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

	void listRecordDict::remove(string w){
		cell* todelete = search(w);
		if (todelete == NULL){
			return;
		}
		else if (todelete == first && todelete == last){
			first = NULL;
			last = NULL;
			delete todelete;
		}
		else if(todelete == first){
			first = first->next;
			first->previous = NULL;
			delete todelete;
		}
		else if(todelete == last){
			last = last->previous;
			last->next = NULL;
			delete todelete;
		}
		else{
			todelete->previous->next = todelete->next;
			todelete->next->previous = todelete->previous;
			delete todelete;
		}
	}

	void listRecordDict::toFile(string filename){
		ofstream myfile;
		cell *currentCell = first;

		myfile.open(filename.c_str());

		while (currentCell != NULL){
			myfile << currentCell->data->fileString() << endl;
			currentCell = currentCell->next;
		}

		myfile.close();
	}