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
    int search(int inorder[],int size,int element){
        for(int i = 0; i < size;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }

Node* constructtreefrompreandinordertraversal(int preorder[],int inorder[],int &preindex, int inorderstart,int inorderend,int size){
        //base case
        if(preindex >= size || inorderstart>inorderend){
            return NULL;
        }
        //1 case mein solve krunga
        int element = preorder[preindex];
        preindex++;
        Node* root = new Node(element);
        //element search krna pdega inorder mein
        int position = search(inorder,size,element);
        //baaki recursion chacha
        root->left = constructtreefrompreandinordertraversal(preorder,inorder,preindex,inorderstart,position-1,size);
        root->right = constructtreefrompreandinordertraversal(preorder,inorder,preindex,position+1,inorderend,size);
        return root;
}
int main(){
    int inorder[]={10,8,6,2,4,12};
    int preorder[]={2,8,10,6,4,12};
    int size = 6;
    int preorderindex = 0;
    int inorderstart = 0;
    int inorderend = 5;
    Node* root = constructtreefrompreandinordertraversal(preorder,inorder,preorderindex,inorderstart,inorderend,size);
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