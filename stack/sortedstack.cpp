#include<iostream>
#include<stack>
using namespace std;

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
void sortStack(stack<int>& st){
    //base case
    if(st.empty()){
        return ;
    }
    //1 case
    int temp = st.top();
    st.pop();
    //recursion
    sortStack(st);
    //backtrack
    insertsorted(st,temp);
}
int main(){
    stack<int> st;
    st.push(9);
    st.push(8);
    st.push(12);
    st.push(5);
    st.push(10);
    cout<<"without reverse : "<<endl;
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<endl;

    return 0;
}
