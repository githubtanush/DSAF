#include<iostream>
using namespace std;
//1st way use pair
//2nd way create class
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int val){

    }
};
class Info{
    public:
        int maxval;
        bool isheap;

    Info(int a,bool b){
        this->maxval = a;
        this->isheap = b;
    }
};
Info checkmaxheap(Node* root){
    //base case;
    if(root==NULL){
        Info temp;
        temp.maxval = INT_MIN;
        temp.isheap = true;
        return temp;
    }
    if(root->left == NULL && root->right==NULL){
        Info temp;
        temp.maxval = root->data;
        temp.isheap = true;
        return temp;
    }
    Info leftAns = checkmaxheap(root->left);
    Info rightAns = checkmaxheap(root->right);
    //1 case mujhe solve krna hai 
    if(root->data>leftAns.maxval && root->data>rightAns.maxval && leftAns.isheap && rightAns.isheap){
        Info ans;
        ans.maxval = root->data;
        ans.isheap = true;
        return ans;
    }
    else{
        Info ans;
        ans.maxval = max(root->data,max(leftAns.maxval,rightAns.maxval));
        ans.isheap = false;
        return ans;
    }
}

int main(){
    Node* root = NULL;
    Info hi = checkmaxheap(root);
    return 0;
}