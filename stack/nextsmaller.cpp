#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> nextsmallerElement(int* arr,int size , vector<int>& ans){
    stack<int> st;
    st.push(-1);
    for(int i = size-1;i>=0;i--){
        int curr = arr[i];
        //answer find kro current ke liye
        while(st.top()>=curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}
vector<int> prevsmallerElement(int* arr,int size , vector<int>& next){
    stack<int> st;
    st.push(-1);
    for(int i = 0;i < size;i++){
        int curr = arr[i];
        //answer find kro current ke liye
        while(st.top()>=curr){
            st.pop();
        }
        next[i] = st.top();
        st.push(curr);
    }
    return next;
}
int main(){
    int arr[] = {8,4,6,2,3};
    int size = 5;
    vector<int> ans(size);
    ans = nextsmallerElement(arr,size,ans);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    vector<int> next(size);
    next = prevsmallerElement(arr,size,ans);
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}