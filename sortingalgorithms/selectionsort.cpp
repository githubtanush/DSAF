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
void selectionsort(vector<int> &v){
    int n = v.size();
    for(int i = 0;i < n-1;i++){
        //ith element hi smallest element hai 
        int minIndex = i;
        for(int j = i+1 ; j < n;j++){
            if(v[j]<v[minIndex]){
            minIndex = j;
            }
        }
        swap(v[i],v[minIndex]);
    }
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    vector<int> v;
    inputarray(v,n);
  selectionsort(v);
    outputarray(v);
    return 0;
}