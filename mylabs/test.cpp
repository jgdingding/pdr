#include <iostream> 
using namespace std; 
  
/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
    char data; 
    struct Node* left, *right; 
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 
  
/* Given a binary tree, print its nodes according to the 
"bottom-up" postorder traversal. */
void printPostorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 
  
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    cout << node->data << " "; 
  
    /* now recur on right child */
    printInorder(node->right); 
} 
  
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  
  
/* Driver program to test above functions*/
int main() 
{ 
    struct Node *root = new Node('E');
	root->right = new Node('F');
	root->right->right = new Node('D');
	root->right->left = new Node('C');
	root->right->left->left = new Node('B');
	root->right->left->left->left = new Node('I');
	root->right->left->right = new Node('A');
	root->right->left->right->left = new Node('H');
	root->right->left->right->left->right = new Node('J');
	root->right->left->right->left->right->right = new Node('G');
  
    cout << "\nPreorder traversal of binary tree is \n"; 
    printPreorder(root); 
  
    cout << "\nInorder traversal of binary tree is \n"; 
    printInorder(root);  
  
    cout << "\nPostorder traversal of binary tree is \n"; 
    printPostorder(root); 
  
    return 0; 
} 
