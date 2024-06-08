#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
    //it returns the root node of tree
    Node* createTree(){
        cout<<"Enter the value "<<endl;
        int data;
        cin>>data;
        if(data==-1){
            return NULL;
        }
        //Step 1-> create Node;
        Node* root = new Node(data);
        //Step 2-> create left subtree
        cout<<"left of Node : "<<root->data<<endl;
        root->left = createTree();
        //Step 3-> create right subtree
        cout<<"right of Node : "<<root->data<<endl;
        root->right = createTree();
        return root;
    }
    void printLeftView(Node* root , int level , vector<int>& leftview){
        if(root==NULL){
            return ;
        }
        if(level==leftview.size()){
            //iska matlab left view k node mil gyi hai usse store krlo
            leftview.push_back(root->data);
        }
        printLeftView(root->left,level+1,leftview);
        printLeftView(root->right,level+1,leftview);
    }
     void printRightView(Node* root , int level , vector<int>& rightview){
        if(root==NULL){
            return ;
        }
        if(level==rightview.size()){
            //iska matlab left view k node mil gyi hai usse store krlo
            rightview.push_back(root->data);
        }
        printRightView(root->right,level+1,rightview);
        printRightView(root->left,level+1,rightview);
    }
    int main(){
        Node* root = createTree();
        vector<int> leftview;
        vector<int> rightview;
        printLeftView(root,0,leftview);
        for(int i = 0; i < leftview.size();i++){
            cout<<leftview[i]<<" ";
        }
        cout<<endl<<endl;
        printRightView(root,0,rightview);
        for(int i = 0; i < rightview.size();i++){
            cout<<rightview[i]<<" ";
        }
        return 0;
    }

// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1