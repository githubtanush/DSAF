#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reversequeue(queue<int> &q){
    stack<int> s;
    //one by one queue se element lo and stack mein insert kro 
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();
        s.push(frontElement);
    }
    while(!s.empty()){
        int Element = s.top();
        s.pop();
        q.push(Element);
    }
}
void reverseK(queue<int>& q, int k){
    stack<int> st;
    //push first element into stack
    for(int i = 0; i < k;i++){
        int temp = q.front();
        q.pop();
        st.push(temp);
    }
    int n = q.size();
    if(k>n || k==0){
        return ;
    }
    //push all k element into queue
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }
    //pop and push first(n-k) elements 
    for(int i = 0; i < (n-k);i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
int  main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    reverseK(q,4);
    cout<<"Printing queue : "<<endl;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
    return 0;
}