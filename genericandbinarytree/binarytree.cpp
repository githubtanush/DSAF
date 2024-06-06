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
int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    cout<<endl<<endl;
    cout<<"Preorder Traversal :"<<endl;
    preorderTraversal(root);
    cout<<endl<<endl;
    cout<<"Postrder Traversal :"<<endl;
    postorderTraversal(root);
    cout<<endl<<endl;
    cout<<"Inorder Traversal :"<<endl;
    inorderTraversal(root);
    cout<<endl<<endl;
    cout<<"LevelOrder Traversal : "<<endl;
    levelorderTraversal(root);
    return 0;
}
//Test case
// 10 20 40 80 -1 -1 90 -1 -1 50 -1 -1 30 60 -1 -1 70 110 -1 -1 120 -1 -1