#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-><-";
        temp = temp->next;
    }
}
int findlength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(Node* &head,Node* &tail,int data){
    //DLL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertattail(Node* &head,Node* &tail,int data){
    //DLL is empty
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        //DLL is not empty
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void insertatposition(Node* &head,Node*&tail,int data,int pos){
    if(head==NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = findlength(head);
        if(pos==1){
            insertathead(head,tail,data);
        }
        else if(pos==len+1){
            insertattail(head,tail,data);
        }
        else{
            //insert in middle
            //step 1 = create node
            Node* newNode = new Node(data);
            //step 2  = set prev and curr pointers
            Node* prev = NULL;
            Node* curr = head;
            while(pos != 1){
                pos--;
                prev = curr;
                curr = curr->next;
            }
            //step 3 : pointers update krne the
            prev -> next = newNode;
            newNode-> prev = prev;
            newNode->next = curr;
            curr->prev = newNode;

        }
    }
}
void deleteNode(Node* &head,Node* &tail,int position){
    if(head==NULL){
        //LL is empty
        cout<<"cannot delete , coz ll is empty"<<endl;
        return ;
    }
    if(head==tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }
    int len = findlength(head);
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == len){
            //delete from tail
            Node* prev =  tail->prev;
            prev->next = NULL;
            tail->prev = NULL;
            delete tail;
            tail = prev;
    }
    else{
        //delete from middle
        //step 1 - set prev/curr/next
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        Node* nextNode = curr->next;
        prev->next = nextNode;
        curr->prev = NULL;
        curr->next = NULL;
        nextNode->prev = prev;
        delete curr;

    }

}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,10);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertathead(head,tail,50);
    insertattail(head,tail,70);
    insertattail(head,tail,80);
    insertattail(head,tail,90);
    insertattail(head,tail,100);
    insertatposition(head,tail,73,2);
    insertatposition(head,tail,28,3);
    deleteNode(head,tail,1);
    deleteNode(head,tail,10);
    deleteNode(head,tail,3);
    printLL(head);
    return 0;
}