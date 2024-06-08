#include<iostream>
#include<map>
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
     void levelorderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        //asli traversal
        while(!q.empty()){
        // while(q.size()>1){//sbse bdi glti jab dobara insert hoga  uska size check krlo jab ek se jada hoga tbhi insert krega voh
            Node* front = q.front();
            q.pop();
            if(front==NULL){
                cout<<endl;
                if(!q.empty())//do these extra condition if u not want to change the while condition
                    q.push(NULL);
            }
            else{
            cout<<front->data<<" ";
            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
            }
        }
    }
void printleftboundary(Node* root){
    if(root==NULL){
        return ;
    }
    if(root->left == NULL && root->right==NULL){
        return ;
    }
    cout<<root->data<<" ";
    if(root->left != NULL){
        printleftboundary(root->left);
    }
    else{
        printleftboundary(root->right);
    }
}
void printleafboundary(Node* root){
    if(root==NULL){
        return ;
    }
    if(root->left == NULL && root->right==NULL){
       cout<<root->data<<" ";
    }
    printleafboundary(root->left);
    printleafboundary(root->right);
}
void printrightboundary(Node* root){
    if(root==NULL){
        return ;
    }
    if(root->left == NULL && root->right==NULL){
        return ;
    }
    if(root -> right != NULL){
        printrightboundary(root->right);
    }
    else{
        printrightboundary(root->left);
    }
    cout<<root->data<<" ";
}
void boundarytraversal(Node* root){
    if(root==NULL){
        return ;
    }
    printleftboundary(root);
    printleafboundary(root);
    if(root->right != NULL){
        printrightboundary(root->right);
    }
    else{
        printrightboundary(root->left);
    }
}
int main(){
    Node* root = createTree();
    levelorderTraversal(root);
    boundarytraversal(root);
    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1