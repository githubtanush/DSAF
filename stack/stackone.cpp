#include<iostream>
using namespace std;
class Stack{
    public:
        int *arr;
        int size;
        int top;
    
    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }
    void push(int data){
        if(top==size-1){
            cout<<"Stack overflow "<<endl;
            return ;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        else{
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int gettop(){
        if(top==-1){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    int getsize(){
        return top+1;
    }
    
    void print(){
        cout<<"Top : "<<top<<endl;
        cout<<"Top element : "<<gettop()<<endl;
        cout<<"Stack : ";
        for(int i = 0; i < getsize();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<endl;
    }
};
int main(){
    //creation
    //static stack
    Stack st(8);

    //insertion
    st.push(10);
    st.print();
    st.push(20);
    st.print();
    st.push(30);
    st.print();

    //size of stack 
    cout<<"size of the stack is : "<<st.getsize()<<endl;

    //remove
    st.pop();

    //check empty
    if(st.isEmpty()){
        cout<<"Stack is empty "<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    //top element
    cout<<"Top element for the stack is : "<<st.gettop()<<endl;
    return 0;
}