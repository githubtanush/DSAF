#include<iostream>
using namespace std;

class TrieNode{
    public:
        char value;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char val){
            this->value = val;
            for(int i = 0; i<26;i++){
                children[i] = NULL;
            }
            this->isTerminal = false;
        }
};
//insertion  
void insertword(TrieNode* root,string word){
    cout<<"Recieved word : "<<word<<" for insertion "<<endl;
//base case
if(word.length()==0){
    root->isTerminal = true;
    return ;
}
char ch = word[0];
int index = ch - 'a';
TrieNode* child;
if(root->children[index]!= NULL){
    //present
    child = root->children[index];
}
else{
    //absent
    child = new TrieNode(ch);
    root->children[index] = child;
}
//recursion
insertword(child,word.substr(1));
}
bool searchword(TrieNode* root,string word){
    //base case
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        //present or found
        child = root->children[index];
    }
    else{
        //not found
        return index;
    }
    //baaki recursion
    bool recursionkaans = searchword(child,word.substr(1));
    return recursionkaans;
}
void deleteword(TrieNode* root,string word){
    if(word.length()==0){
        root->isTerminal=false;
        return ;
    }
    //1 case mera
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    if(root->children[index] != NULL){
        //present
        child = root->children[index];
    }
    else{
        //not present
        return ;
    }
    //baaki recursion chacha
    deleteword(child,word.substr(1));
}
int main(){
    TrieNode* root = new TrieNode('-');
    insertword(root,"cater");
    insertword(root,"care");
    insertword(root,"com");
    insertword(root,"lover");
    insertword(root,"load");
    insertword(root,"lov");
    insertword(root,"loved");
    insertword(root,"bat");
    insertword(root,"car");
    insertword(root,"cat");
    cout<<"Insertion done"<<endl;
    if(searchword(root,"lov")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    deleteword(root,"lov");
     if(searchword(root,"lov")){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}