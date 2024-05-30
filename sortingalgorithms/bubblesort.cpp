#include<iostream>
#include<vector>
using namespace std;
void inputarray(vector<int> &v,int n){
    for(int i = 0; i < n;i++){
        int data;
        cin>>data;
        v.push_back(data);
    }
}
void outputarray(vector<int> &v){
    int n = v.size();
    for(int i = 0; i < n;i++){
        cout<<v[i]<<" ";
    }
}
void bubblesort(vector<int> &v){
    int n = v.size();
    for(int i = 0;i < n;i++){
        for(int j = 0; j < n-i-1;j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    vector<int> v;
    inputarray(v,n);
    bubblesort(v);
    outputarray(v);
    return 0;
}