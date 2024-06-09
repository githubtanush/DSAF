#include<iostream>
#include<queue>
using namespace std;
int main(){
//     //create maxheap by default
//     priority_queue<int> pq;
        //create minheap by passing 3 parameters;
        priority_queue<int,vector<int>,greater<int> > pq;
    //insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    cout<<"Top element of Heap : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Top element of Heap : "<<pq.top()<<endl;
    cout<<"Size of heap : "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Non - Empty"<<endl;
    }
    return 0;
}