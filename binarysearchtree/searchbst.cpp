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
    bool searchinbst(Node* root,int target){
        //base case
        if(root==NULL)
        return false;

        //1 case mujhe solve krna hai 
        if(root->data==target){
            return true;
        }
        //baaki recursion sambhal lega
        //left ya right
        bool leftAns = false;
        bool rightAns = false;
        if(target>root->data){
            rightAns = searchinbst(root->right,target);
        }
        else{
            leftAns = searchinbst(root->left,target);
        }
        return leftAns||rightAns;
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
    int t;
    cout<<"Enter target : "<<endl;
    cin>>t;
    while(t!=-1){
        bool ans = searchinbst(root,t);
        if(ans==true){
            cout<<"Found"<<endl;
        }
        else{
            cout<<"Not found"<<endl;
        }
        cin>>t;
    }
    
    return 0;
}
//50 30 40 20 60 55 70 80 25 -1