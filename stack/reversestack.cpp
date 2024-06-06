#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int>& st,int& element){
    //base case
    if(st.empty()){
        st.push(element);
        return;
    }
    //1 case mein solve krunga
    int temp = st.top();
    st.pop();

    //recursion chacha ji
    insertatbottom(st,element);
    //backtracking
    st.push(temp);
}
void reverseStack(stack<int>& st){
    //base case
    if(st.empty()){
        return;
    }
    //1 case mein solve krunga
    int temp = st.top();
    st.pop();
    //recursion
    reverseStack(st);
    //backtrack
    insertatbottom(st,temp);
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    // cout<<"without reverse : "<<endl;
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl<<endl;
    cout<<"with reverse : "<<endl;
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
