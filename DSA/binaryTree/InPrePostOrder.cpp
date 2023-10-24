//Inorder,Preorder,Postorder

#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    int data;
    cout<<"Enter the data "<<endl;
    cin>>data;

    //null values ke liye -1 dalre
    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);

     cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root; 
}

void inorder(node* root){

    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){

    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){

    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);

    return 0;
}