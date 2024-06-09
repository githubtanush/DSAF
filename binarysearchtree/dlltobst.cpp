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
    Node* convertdlltobst(Node*& head,int n){
        //base case
        if(head==NULL || n<=0){
            return NULL;
        }
        //LNR
        //L
        Node* leftsubtree = convertdlltobst(head,n/2);
        //N
        Node* root = head;
        root->left = leftsubtree;
        //headupdate
        head = head->right;
        //right
        Node* rightsubtree = convertdlltobst(head,n-n/2-1);
        root->right = rightsubtree;
        return root;
    }

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;
    //10<->20<->30
    Node* root = convertdlltobst(head,3);
    levelordertraversal(root);
    return 0;
}
//50 30 40 20 60 55 70 80 25 -1