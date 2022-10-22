#include "llrec.h"
#include <iostream>
#include <time.h>
#include "stack.h"
#include <string>
using namespace std;

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	Node* newNode = new Node(head->val, NULL);
	
	if(head->val <= pivot) {
		if(smaller == NULL) {
			smaller = newNode;
		} else {
			Node* current = smaller;
			while(current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}
	} else {
		if(larger == NULL) {
			larger = newNode;
		} else {
			Node* current = larger;
			while(current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
		}
	}
	head = head->next;
	if(head != NULL) {
		llpivot(head, smaller, larger, pivot);
	}
}