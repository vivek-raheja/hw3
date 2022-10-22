#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "stack.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


bool fn(int x) {
	if( x%2 == 0)
		return 1;
	
	return 0;
}
int main(int argc, char* argv[])
{
	if (argc < 2) {
		return -1;
	}

		
	Node* mylist = readList(argv[1]);	
	Node* smaller = NULL;
	Node* larger = NULL;
	llpivot(mylist, smaller, larger, 10);

	cout << "Smaller" << endl;
	while(smaller != NULL) {
		cout << smaller->val << endl;
		smaller = smaller->next;
	}

	cout << "Greater" << endl;
	while(larger != NULL) {
		cout << larger->val << endl;
		larger = larger->next;
	}
	
	srand(time(0));
	//Create the nodes
	int numNodes = 10;
	int count;
	int number = rand() / 1000000;
	
	Node* currentNode = new Node(number, NULL);
	Node* startNode;
	smaller = NULL;
	larger = NULL;
	
	int pivot = number;
	cout << "Pivot:" << pivot << endl;
    
	for(count=0;count<numNodes;count++) {
		cout << "Value " << count << " is " << currentNode->val << endl;
		number = rand() / 1000000;
		Node* nextNode = new Node(number, NULL);
		currentNode->next = nextNode;
		if(count == 0)
			startNode = currentNode;
			
		currentNode = nextNode;
	}
	
	llpivot(startNode, smaller, larger, pivot);
	
	
	Node* x = llfilter(startNode, fn);
	cout << "Function" << endl;
	while(x != NULL) {
		cout << x->val << endl;
		x = x->next;
	}
	
	cout << "Smaller" << endl;
	while(smaller != NULL) {
		cout << smaller->val << endl;
		smaller = smaller->next;
	}
	
	cout << "Greater" << endl;
	while(larger != NULL) {
		cout << larger->val << endl;
		larger = larger->next;
	}
	
	return 0;

}