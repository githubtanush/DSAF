#include<iostream>
#include<queue>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertintobst(Node* root,int data){
    //base case
    if(root==NULL){
        root = new Node(data);
        return root;
    }
    //its not the first root recursion chacha
    if(data > root->data){
        root->right = insertintobst(root->right,data);
    }
    else{
        root->left = insertintobst(root->left,data);
    }
    return root;
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
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
void createBST(Node*& root){
cout<<"Enter data : "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        root = insertintobst(root,data);
        cin>>data;
    }
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelordertraversal(root);
    return 0;
}
//50 30 40 20 60 55 70 80 25 -1