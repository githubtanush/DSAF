#include<iostream>
using namespace std;
class cqueue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

    cqueue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void push(int val){
        //overflow
        if((front==0 &&rear == size-1) || (rear==front-1)){
            cout<<"Queue Overflow"<<endl;
            return ;
        }
        //single element
        else if(front==-1 && rear==-1){
            //empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        //circular nature
        else if(rear==size-1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }
    void pop(){
        //underflow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
            return ;
        }
        //single element
        else if(front==rear){
            //empty case - single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        //circular nature 
        else if(front==size-1){
            arr[front] = -1;
            front = 0;
        }
        //normal case
        else{
            arr[front] = -1;
            front++;
        }
    }
    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        if(front==-1 && rear==-1){
            return  0;
        }
        else{
            return rear-front+1;
        }
    }
    int getFront(){
        if(front==-1){
            cout<<"No element in the queue,cannot give front element"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    void print(){
        cout<<"Printing Queue : ";
        for(int i = 0; i < size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    cqueue q(5);
    q.push(10);
    q.print();
    q.push(20);
    q.print();
    q.push(30);
    q.print();
    q.push(40);
    q.print();
    q.push(50);
    q.print();
    q.pop();
    q.push(60);
    q.print();
    return 0;
}