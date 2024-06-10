#include<iostream>
#include<queue>
#include<vector>
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
void storeinordertraversal(Node* root,vector<int>& in){
    if(root==NULL){
        return ;
    }
    //LNR
    storeinordertraversal(root->left,in);
    in.push_back(root->data);
    storeinordertraversal(root->right,in);
}
void replaceusingppostorder(Node* root,vector<int> in,int& index){
    if(root==NULL){
        return;
    }
    //LRN
    replaceusingppostorder(root->left,in,index);
    replaceusingppostorder(root->right,in,index);
    root->data = in[index];
    index++;
}
Node* convertbstintomaxheap(Node* root){
    //step1 - store inorder
    vector<int> inorder;
    storeinordertraversal(root,inorder);
    //replace the node values with stored inorder values
    //by using the postorder traversal
    int index = 0;
    replaceusingppostorder(root,inorder,index);
    return root;
}
int main(){
    Node* root = NULL;
    createBST(root);
    cout<<"printing the BST: "<<endl;
    levelordertraversal(root);
    cout<<endl;
    cout<<"Converting into heap : "<<endl;
    root = convertbstintomaxheap(root);
    cout<<"Printing the heap : "<<endl;
    levelordertraversal(root);
    return 0;
}
//100 50 150 40 60 110 200 20 -1