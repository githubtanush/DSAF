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
    void printbottomview(Node* root){
        map<int,int> hdtoNodemap;
        queue<pair<Node*, int> >q ;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<Node*,int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
  
                //overwrite answers so that deeper nodes can be stored
                hdtoNodemap[hd]=frontNode->data;
            //child ko dekhna hai 
            if(frontNode->left != NULL){
                q.push(make_pair(frontNode-> left, hd-1));
            }
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        cout<<"Printing bottom view : "<<endl;
        for(auto i: hdtoNodemap){
            cout<<i.second<<" ";
        }
    }
    int main(){
        Node* root = createTree();
        levelorderTraversal(root);
        cout<<endl<<endl;
        printbottomview(root);
        return 0;
    }
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1