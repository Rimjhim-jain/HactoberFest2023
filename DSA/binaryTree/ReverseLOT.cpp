#include<iostream>
#include<queue>
#include<stack>
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

void ReverselevelOrderTraversal(node* root){
    //DFS
    queue<node*>q;
    stack<node *>st;

    q.push(root);
//1 2 4 -1 -1 5 -1 -1 3 -1 -1
    while(!q.empty()){
        node * temp = q.front();
        st.push(temp);
        q.pop();

             if(temp->right != NULL){
                q.push(temp->right);

            } 

            if(temp->left != NULL){
                q.push(temp->left);
            } 
    }

    while(!st.empty()){
        node* val = st.top();
        cout<<val->data<<" ";
        st.pop();
    }

}

int main(){

    node* root = NULL;
    root = buildTree(root);
    ReverselevelOrderTraversal(root);

    return 0;
}