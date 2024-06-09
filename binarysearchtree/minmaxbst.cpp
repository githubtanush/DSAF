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
void preorderTraversal(Node* root){
        //base case
        if(root==NULL){
            return ;
        }
        //NLR
        //N
        cout<<root->data<<" ";
        //L
        preorderTraversal(root->left);
        //R
        preorderTraversal(root->right);
    }
    void inorderTraversal(Node* root){
        //base case
        if(root==NULL){
            return ;
        }
        //LNR
        //L
        inorderTraversal(root->left);
        //N
        cout<<root->data<<" ";
        //R
        inorderTraversal(root->right);
    }
    void postorderTraversal(Node* root){
        //base case
        if(root==NULL){
            return ;
        }
        //LRN
        //L
        postorderTraversal(root->left);
        //R
        postorderTraversal(root->right);
        //N
        cout<<root->data<<" ";
    }
    Node* minValue(Node* root){
        if(root==NULL){
            return NULL;
        }
        else{
            Node* temp = root;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }
    }
    Node* maxValue(Node* root){
        if(root==NULL){
            return NULL;
        }
        else{
            Node* temp = root;
            while(temp->right != NULL){
                temp = temp->right;
            }
            return temp;
        }
    }

int main(){
    Node* root = NULL;
    createBST(root);
    levelordertraversal(root);
    cout<<"Preorder Traversal : "<<endl;
    preorderTraversal(root);
    cout<<endl;
    cout<<"Inorder Traversal : "<<endl;
    inorderTraversal(root);
    cout<<endl;
    cout<<"Postorder Traversal : "<<endl;
    postorderTraversal(root);
    cout<<endl;
    Node* minNode = minValue(root);
    if(minNode == NULL){
        cout<<"There is no need in a tree, so no min value"<<endl;
    }
    else{
        cout<<"MinValue : "<<minNode->data<<endl;
    }
    cout<<endl;
   Node* maxNode = maxValue(root);
    if(maxNode == NULL){
        cout<<"There is no need in a tree, so no min value"<<endl;
    }
    else{
        cout<<"MinValue : "<<maxNode->data<<endl;
    }
    cout<<endl;
    return 0;
}
//50 30 40 20 60 55 70 80 25 -1