#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    //insertion
    q.push(5);
    //size
    cout<<"size of the queue is : "<<q.size()<<endl;
    //empty
    if(q.empty()==true){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is not Empty"<<endl;
    }
    q.pop();
    //push kr
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"Front Element : "<<q.front()<<endl;
    cout<<"Back Element : "<<q.back()<<endl;
    return 0;
}