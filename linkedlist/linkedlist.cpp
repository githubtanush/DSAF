#include<iostream>
using namespace std;
class Node{
    public:
     int data;
     Node* next;

    Node(){//default ctor
    this->next = NULL;
    }
    //if we call ctor then it will initialize all parameters itself
    Node(int data){//parametrized ctor
        this->data = data;
        this->next = NULL;
    }
};
void printLL(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
}
//print the length of the linked list 
int len(Node* head){
    //best practice make temp pointer don't use previous pointer
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    cout<<endl;
    return length;
}
//head pass by refrence not passby value
void insertathead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        //empty LL
        //step 1 : create new node
        Node* newNode = new Node(data);
        //step2 : update head
        head = newNode;
        tail = newNode;
    }
    else{
    //create new node
    Node* newNode = new Node(data);
    //pointer ko head se connect  kr do 
    newNode->next = head;
    //head ko temp par assign kr do 
   head = newNode;
    }
}
int main(){
    
    //creation of node
    //static or dynamically ctor always called
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;
    cout<<"printing the linked list : "<<endl;
    printLL(head);
    cout<<"printing the length of the linked list : "<<len(head);
    
    insertathead(head,tail,18);
    cout<<endl;
    printLL(head);
    return 0;
}