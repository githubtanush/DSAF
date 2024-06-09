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
    void convertbsttodll(Node*  root, Node* &head){
        if(root==NULL){
            return ;
        }
        //RNL
        //R
        convertbsttodll(root->right,head);
        //N
        root->right = head;
        if(head!=NULL){
            head->left = root;
        }
        head = root;
        //L
        convertbsttodll(root->left,head);

    }
    Node* deletefrombst(Node* root,int target){
        //target ko dhundlo
        //target ko delete krdo 
        //Base case
        if(root==NULL)
        return NULL;
        if(target==root->data){
             //1st case if left and right both are null
             if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
             }
        //2nd case if left is null but right is not
        if(root->left == NULL && root->right!=NULL){
            Node* childsubtree = root->right;
            delete root;
            return childsubtree;
        }
        //3rd case if left is not null but right is null
        else if(root->left!= NULL && root->right==NULL){
            Node* childsubtree = root->left;
            delete root;
            return childsubtree;
        }
        //4th case - left is not equal to null as well as right is not equal to null
        else{
            //a = left subtree ka max
            Node* maxi = maxValue(root->left);
            //replacement
            root->data = maxi->data;
            //delete actual maxi vali mode
            root->left = deletefrombst(root->left,maxi->data);
            return root;
        }
    }
    else if(root->data>target){
        //left mein chlo 
        root->left = deletefrombst(root->left,target);
    }
    else{
        root->right = deletefrombst(root->right,target);
    }
    return root;
    }
    void printll(Node* head){
        Node* temp = head;
        while(temp!= NULL){
            cout<<temp->data<<"<->";
            temp = temp->right;
        }
        cout<<endl; 
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
    // int t;
    // cout<<"Enter target : "<<endl;
    // cin>>t;
    // while(t!=-1){
    //     root = deletefrombst(root,t);
    //     cout<<"Printing level order traversal : "<<endl;
    //     levelordertraversal(root);
    //     cout<<"Enter the value of target"<<endl; 
    //     cin>>t;
    // }
    Node* head = NULL;
    convertbsttodll(root,head);
    printll(head);
    return 0;
}
//50 30 40 20 60 55 70 80 25 -1