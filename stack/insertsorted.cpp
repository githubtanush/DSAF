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
void insertsorted(stack<int> &st,int element){
    //base case - 100 % glti 
    if(st.empty()|| element > st.top()){
        st.push(element);
        return ;
    }
    //1 case to mujhe sambhalna hi pdega
    int temp = st.top();
    st.pop();
    //recursion sambhal lega
    insertsorted(st,element);
    //backtrack
    st.push(temp);
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
        insertsorted(st,25);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
