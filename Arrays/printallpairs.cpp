#include<iostream>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
void outputArray(int arr[],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i]<<" ";
    }
}
void printpairs(int arr[],int n){
    for(int i = 0; i < n;i++){
        for(int j = i; j < n;j++){
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<" ";
        }
    }
}
void printtriplets(int arr[],int n){
    for(int i = 0 ; i < n;i++){
        for(int j = i; j < n;j++){
            for(int k = i; k < n;k++){
                cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<" ";
            }
        }
    }
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    outputArray(arr,n);
    cout<<endl;
    printpairs(arr,n);
    printtriplets(arr,n);
    return 0;
}