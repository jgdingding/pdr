//Justin Gou
//jyg2qhc
//1/28/2020
//List.cpp

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

// The default constructor.
// It should initialize all private data members
// and set up the basic list structure with the dummy head and tail nodes.
List :: List() {
	head = new ListNode();
	tail = new ListNode();
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	count = 0;
}

// The copy constructor.
// It should create a **new** list of ListNodes whose contents
// are the same values as the ListNodes in `source`.
List :: List(const List& source) {
	head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
	head->previous = NULL;
	tail->next = NULL;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// The destructor.
// It should empty the list and reclaim the memory allocated in the constructor for head and tail.
List :: ~List() {
	makeEmpty();
	delete head;
	delete tail;
}

// The copy assignment operator.
// It should copy the contents of every ListNode in `source`
// into an **existing** list (the reference to the calling List object itself).
List& List::operator=(const List& source) {
	if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Returns true if empty, else false
bool List :: isEmpty() const {
	return count==0;
}

// Removes (deletes) all items except the dummy head/tail.
// The list should be a working empty list after this.
void List :: makeEmpty(){
	ListItr temp = first();
	while(!temp.isPastEnd()){
		temp.moveForward();
		delete temp.current->previous;
	}
	head->next = tail;
	tail->previous = head;
}

// Returns an iterator that points to the first ListNode **after** the dummy head node (even on an empty list!)
ListItr List :: first(){
	return ListItr(head->next);
}

// Returns an iterator that points to the last ListNode **before** the dummy tail node (even on an empty list!)
ListItr List :: last(){
	return ListItr(tail->previous);
}

// inserts x after current iterator position
void List :: insertAfter(int x, ListItr position){
	if(isEmpty()){
		insertAtTail(x);
		return;
	}
	ListNode *temp = position.current->next;
	ListNode *newNode = new ListNode();
	newNode->value = x;
	position.current->next = newNode;
	newNode->previous = position.current;
	newNode->next = temp;
	temp->previous = newNode;
	count++;
}

// inserts x before current iterator position
void List :: insertBefore(int x, ListItr position){
	if(isEmpty()){
		insertAtTail(x);
		return;
	}
	ListNode *temp = position.current->previous;
	ListNode *newNode = new ListNode();
	newNode->value = x;
	position.current->previous = newNode;
	newNode->next = position.current;
	newNode->previous = temp;
	temp->next = newNode;
	count++;
}

// inserts x at tail of list
void List :: insertAtTail(int x){
	ListNode *newNode = new ListNode();
	newNode->value = x;
	tail->previous->next = newNode;
	newNode->next = tail;
	newNode->previous = tail->previous;
	tail->previous = newNode;
	count++;
}

// returns an iterator that points to the first occurrence of x.
// when the parameter is not in the list, return a ListItr object that points to the dummy tail node.
// this makes sense because you can test the return from find() to see if isPastEnd() is true.
ListItr List :: find(int x){
	ListItr temp = first();
	while(!temp.isPastEnd()){
		if(temp.retrieve()==x)
			break;
		temp.moveForward();
	}
	return temp;
}

// removes the first occurrence of x
void List :: remove(int x){
	ListItr found = find(x);
	if(!(found.current->next==NULL)){
		found.current->previous->next = found.current->next;
		found.current->next->previous = found.current->previous;
		delete found.current;
		count--;
	}
}

// returns the number of elements in the list
int	List :: size() const{
	return count;
}

void printList(List& source, bool forward){
	if(forward){
		ListItr temp = source.first();
		while(!temp.isPastEnd()){
			cout << temp.retrieve();
			temp.moveForward();
			if(!temp.isPastEnd())
				cout << ", ";
		}
		cout << endl;
	}else{
		ListItr temp = source.last();
		while(!temp.isPastBeginning()){
			cout << temp.retrieve();
			temp.moveBackward();
			if(!temp.isPastBeginning())
				cout << ", ";
		}
		cout << endl;
	}
}

