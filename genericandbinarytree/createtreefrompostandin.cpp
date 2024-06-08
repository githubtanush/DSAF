#include<iostream>
#include<queue>
#include<map>
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
void createmapping(int inorder[],int size,map<int,int>& valuetoindexmap){
    for(int i = 0; i < size;i++){
        int element = inorder[i];
        int index = i;
        valuetoindexmap[element] = index;
    }
}
Node* constructtreefrompostandinordertraversal(map<int,int>& valuetoindexmap,int postorder[],int inorder[],int &postindex, int inorderstart,int inorderend,int size){
        //base case
        if(postindex < 0  || inorderstart>inorderend){
            return NULL;
        }
        //1 case mein solve krunga
        int element = postorder[postindex];
        postindex--;
        Node* root = new Node(element);
        //element search krna pdega inorder mein
        // int position = search(inorder,size,element);
        int position = valuetoindexmap[element];
        //baaki recursion chacha
        root->right = constructtreefrompostandinordertraversal(valuetoindexmap,postorder,inorder,postindex,position+1,inorderend,size);
        root->left = constructtreefrompostandinordertraversal(valuetoindexmap,postorder,inorder,postindex,inorderstart,position-1,size);
        return root;
}
int main(){
    int inorder[]={8,14,6,2,10,4};
    int postorder[]={8,6,14,4,10,2};
    int size = 6;
    int postorderindex = size-1;
    int inorderstart = 0;
    int inorderend = size-1;
    map<int,int> valuetoindexmap;
    createmapping(inorder,size,valuetoindexmap);
    Node* root = constructtreefrompostandinordertraversal(valuetoindexmap,postorder,inorder,postorderindex,inorderstart,inorderend,size);
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