#include<iostream>
using namespace std;
void inputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
}
void outputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
int linearsearch(int arr[1000],int target,int n){
     for(int i = 0; i < n;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    inputarray(arr,n);
    int target;
    cout<<"Enter the targeted value : ";
    cin>>target;
    int index =  linearsearch(arr,target,n);
    if(index != -1)
    cout<<"The element is found at index : "<<index<<endl;
    else
    cout<<"The element is not present in this array "<<endl;
    outputarray(arr,n);
    return 0;
}