#include<iostream>
#include<queue>
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

//build tree using recursion
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

void levelOrderTraversal(node* root){
    //BFS
  queue<node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }  
    }

}

int main(){

    node* root = NULL;
    root = buildTree(root);
    levelOrderTraversal(root);

    return 0;
}