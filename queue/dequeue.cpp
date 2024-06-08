#include<iostream>
using namespace std;
class dequeue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

    dequeue(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    void pushback(int val){
        //check full
        if(rear == size-1){
            cout<<"Queue Overflow"<<endl;
            return ;
        }
        else if(front==-1 && rear==-1){
            //empty case
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            //normal case
            rear++;
            arr[rear] = val;
        }
    }
    void pushfront(int val){
        //overflow
        if(front==0){
            cout<<"Overflow"<<endl;
            return ;
        }
        else if(front==-1 && rear == -1){
            front++;
            rear--;
            arr[front] =  val;
        }
        else{
            front--;
            arr[front] = val;
        }
    }
    void popfront(){
        //underflow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
            return ;
        }
        else if(front==rear){
            //empty case - single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    void popback(){
        //underflow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
            return ;
        }
        else if(front==rear){
            //empty case - single element
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[rear] = -1;
            rear--;
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
    //Creation
   dequeue dq(5);
   dq.pushback(5);
   dq.print();
   dq.pushfront(7);
   dq.print();

    return 0;
}