//Justin Gou
//jyg2qhc
//2/23/2020
//AVLTree.cpp

#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
	root = insert(root,x);
}

AVLNode* AVLTree::insert(AVLNode*& n, const string& x){
	if(!n){
		AVLNode* temp = new AVLNode();
		temp->value = x;
		temp->height = 0;
		return temp;
	}else if(x < n->value){
		n->left = insert(n->left,x);
	}else if(x > n->value){
		n->right = insert(n->right,x);
	}
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);
	
	return n;
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
	string result = "";
	AVLNode* temp = root;
	while(temp != NULL){
		if(temp->value == x){
			return result + temp->value;
		}else if(x < temp->value){
			result += temp->value + " ";
			temp = temp->left;
		}else if(x > temp->value){
			result += temp->value + " ";
			temp = temp->right;
		}
	}
	return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
	string path = pathTo(x);
	if(path.length()){
		return true;
	}
	return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    return numNodes(root);
}

int AVLTree::numNodes(AVLNode* n) const{
	if(n==NULL){
		return 0;
	}
	return 1 + numNodes(n->left) + numNodes(n->right);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
	int rootBF = getBalanceFactor(n);
	if(rootBF == 2){
		if(getBalanceFactor(n->right) < 0){
			n->right = rotateRight(n->right);
		}
		n = rotateLeft(n);
	}else if(rootBF == -2){
		if(getBalanceFactor(n->left) > 0){
			n-> left = rotateLeft(n->left);
		}
		n = rotateRight(n);
	}
}

int AVLTree::getBalanceFactor(AVLNode *n){
	return height(n->right) - height(n->left);
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
	AVLNode* newRoot = n->right;
	AVLNode* moveChild = newRoot->left;
	newRoot->left = n;
	n->right = moveChild;

	n->height = max(height(n->left), height(n->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;  

	return newRoot;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
	AVLNode* newRoot = n->left;
	AVLNode* moveChild = newRoot->right;
	newRoot->right = n;
	n->left = moveChild;

	n->height = max(height(n->left), height(n->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;  

	return newRoot;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
