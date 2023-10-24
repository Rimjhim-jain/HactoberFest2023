#include <bits/stdc++.h>
using namespace std;

// Structure of a node of BST
struct Node {

	int data;
	Node *left, *right;
};

struct Node* getNode(int data)
{
	struct Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void inorderTraversal(Node* root,queue<int>&q){
    if(root == NULL){
        return;
    }
    
    inorderTraversal(root->left,q);
    q.push(root->data);
    inorderTraversal(root->right,q);
}

void BSTtoMinHeap(Node* root,queue<int>&q){
    
     if(root == NULL){
        return;
    }
    
        root->data = q.front();
        q.pop();
        BSTtoMinHeap(root->left,q);
        BSTtoMinHeap(root->right,q);
}

void convertToMinHeapUtil(Node* root){
    std::queue<int>q;
    inorderTraversal(root,q);
    
    BSTtoMinHeap(root,q);
}

void preorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
	// BST formation
	struct Node* root = getNode(4);
	root->left = getNode(2);
	root->right = getNode(6);
	root->left->left = getNode(1);
	root->left->right = getNode(3);
	root->right->left = getNode(5);
	root->right->right = getNode(7);

	// Function call
	convertToMinHeapUtil(root);
	cout << "Preorder Traversal:" << endl;
	preorderTraversal(root);

	return 0;
}