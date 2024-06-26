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
void printLL(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<endl;
}
//print the length of the linked list 
int len(Node* head){
    //best practice make temp pointer don't use head pointer
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    cout<<endl;
    return length;
}
void insertathead(Node* &head,int data){
    if(head==NULL){
        //empty LL
        //step 1 : create new node
        Node* newNode = new Node(data);
        //step2 : update head
        head = newNode;
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
void insertattail(Node* head,Node* tail,int data){
 if(head==NULL){
    //emptyll
    //step 1 : create toh kro Node
    Node* newNode = new Node(data);
    //step 2 : single node hai entire list mein
    //that's why head and tail ko esi par point krwa do 
    head = newNode;
    tail = newNode;

 }
 else{
//step 1 : create new node
Node* newNode = new Node(data);
//step 2 : tail->next = temp
tail->next = newNode;
//step 3 : tail = temp (update tail)
tail = newNode;
}

}
void createtail(Node* &head,Node* &tail){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    //jab yeh loop khatam ho gya hoga
    //tab aapka temp wala pointer
    //khada hoga last node pr
    //tab tail = temp krke le aao tail ko last node par
    tail = temp;
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
    Node* tail = fifth;
    cout<<"printing the linked list : "<<endl;
    printLL(head);
    cout<<"printing the length of the linked list : "<<len(head);
    
    insertathead(head,18);
    insertathead(head,tail,500);
    insertattail(head,tail,600);
    cout<<endl;
    printLL(head);
    return 0;
}