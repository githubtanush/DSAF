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
void insertattail(Node* &head,Node* &tail,int data){
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
void insertatposition(Node* &head,Node* &tail,int data,int position){
    // if(position < 1){
    //     cout<<"cannot insert Please enter a valid position "<<endl;
    //     return ;
    // }
    int length = len(head);
    // if(position > length){
    //     cout<<"cannot insert,please enter a valid position"<<endl;
    // }
    if(position==1){
        insertathead(head,tail,data);
    }
    else if(position > length){//greater than length krna yaad rkhna 
        insertattail(head,tail,data);
    }
    else{
        //insert at middle of the linked list;
        //create a node
        Node* newNode = new Node(data);
        //jaah par node insert krna chahta ho uss position par phuncho
        Node* prev = NULL;
        Node* curr = head;
        //travel curr/prev to position
        while(position != 1){
             position--;
            prev = curr;
            curr = curr->next;
        }
        //prev->next = temp
        prev->next = newNode;
        //temp -> next = curr
        newNode->next = curr;
    }

}
void deleteNode(Node* &head,Node* &tail,int position){
    //empty list
    if(head==NULL){
        cout<<"cannot delete ,coz LL is empty"<<endl;
        return ;
    }
    if(head==tail){
        //single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }
    int length = len(head);
    //delete from head
    if(position == 1){
        //first node ko delete kro 
        //step 1 - temp = head
        Node* temp = head;
        //step2 - head mein next assign kro 
        head = head->next;
        //step 3 - temp mein NULL daldo 
        temp->next = NULL;
        //temp delete krdo 
        delete temp;
    }
    else if(position == length ){
        //traverse till last second node
        Node* prev = head;
        while(prev->next != tail){
            prev = prev -> next;
        }
        //previous ka next mein null ko assign krdo 
        prev->next = NULL;
        //node delete kro 
        delete tail;
        //update tail
        tail = prev;
    }
    else{
        //middle me koi delete krdo 
        //step1 - set prev/curr pointers
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        //step 2 - prev ka next mein curr ka next assign krdo 
        prev->next = curr -> next;
        //step 3 -> node isolate krdo 
        curr->next = NULL;
        //step 4 - delete krdo node ko 
        delete curr;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertattail(head,tail,50);
    insertattail(head,tail,60);
    insertattail(head,tail,70);
    insertattail(head,tail,80);
    insertatposition(head,tail,1000,4);
    printLL(head);
    insertatposition(head,tail,100,10);
    printLL(head);
    deleteNode(head,tail,3);
    deleteNode(head,tail,5);
    deleteNode(head,tail,1);
    printLL(head);
    
    return 0;
}