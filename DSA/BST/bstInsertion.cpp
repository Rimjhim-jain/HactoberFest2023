#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:

        int data;
        Node* left;
        Node* right;
        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }

};

Node* insertNodeBST(Node* root, int d){

    if(root == NULL){
        root = new Node(d); 
        return root;
    }

    
    if(d > root->data){
        //right mai dalo
        root->right = insertNodeBST(root->right,d);
    }else{
        //left mai dalo
         root->left = insertNodeBST(root->left,d);
    }


    return root;
}

void levelOrderTraversal(Node* root){
    //BFS
  queue<Node*>q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * temp = q.front();
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

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node* root, int nodeToDlt){
    if(root == NULL){
        return root;
    }

    if(root->data == nodeToDlt){
        //0-child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        //1-child
        //left child
        if(root->left == NULL && root->right != NULL ){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        if(root->left != NULL && root->right == NULL ){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //2-child
        if(root->left != NULL && root->right != NULL){
            //option-1: left part ka max val lelo
            int maxi = maxVal(root->left)->data;
            root->data = maxi;
            root->left = deleteNode(root->left,maxi);
            return root;
        }

    }else if(root->data > nodeToDlt){
        root->left = deleteNode(root->left, nodeToDlt);
        return root;
    }else{
        root->right = deleteNode(root->right, nodeToDlt);
        return root;
    }

    return root;
}


int main(){
    
    Node* root = NULL;

    int data;
    cin>> data;

    while(data != -1){
       root = insertNodeBST(root,data);
        cin>>data;
    }

    levelOrderTraversal(root);

    cout<<endl<<"enter node to delete";
    int nodeToDlt;
    cin>>nodeToDlt;

   root = deleteNode(root, nodeToDlt);

      levelOrderTraversal(root);

    return 0;
}