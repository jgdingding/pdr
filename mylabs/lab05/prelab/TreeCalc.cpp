//Justin Gou
//jyg2qhc
//2/21/2020
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
	for(int i=0;i<expressionStack.size();i++){
		cleanTree(expressionStack.top());
		expressionStack.pop();
	}
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
	if(tree->left==NULL && tree->right==NULL){
		delete tree;
		return;
	}
	cleanTree(tree->left);
	cleanTree(tree->right);
	delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
	TreeNode* toAdd = new TreeNode(val);
	if(val=="/" || val=="+" || val=="-" || val=="*"){
		TreeNode* rightNode = expressionStack.top();
		expressionStack.pop();
		TreeNode* leftNode = expressionStack.top();
		expressionStack.pop();
		toAdd->left = leftNode;
		toAdd->right = rightNode;
	}
	expressionStack.push(toAdd);
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
	if(tree->left==NULL && tree->right==NULL){
		cout << tree->value << " ";
		return;
	}
	cout << tree->value << " ";
	printPrefix(tree->left);
	printPrefix(tree->right);
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
	if(tree->left==NULL && tree->right==NULL){
		cout << tree->value;
		return;
	}
	cout << "(";
	printInfix(tree->left);
	cout << " " << tree->value << " ";
	printInfix(tree->right);
	cout << ")";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
	if(tree->left==NULL && tree->right==NULL){
		cout << tree->value << " ";
		return;
	}
	printPostfix(tree->left);
	printPostfix(tree->right);
	cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
   	if(tree->left==NULL && tree->right==NULL){
		return stoi(tree->value);
	} 
	
	int leftValue = calculate(tree->left);
	int rightValue = calculate(tree->right);

	if(tree->value=="+"){
		return leftValue+rightValue;
	}else if(tree->value=="-"){
		return leftValue-rightValue;
	}else if(tree->value=="/"){
		return leftValue/rightValue;
	}else if(tree->value=="*"){
		return leftValue*rightValue;
	}     
	return 1;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
	TreeNode* temp = expressionStack.top();
	int result = calculate(temp);
	expressionStack.pop();
	cleanTree(temp);
    return result;
}
