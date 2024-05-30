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
int findUnique(int arr[],int n){
    int ans = 0;
    for(int i = 0; i < n;i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    outputArray(arr,n);
    cout<<endl;
    int uniqueElement = findUnique(arr,n);
    cout<<"The Unique Element in this Array is : "<<uniqueElement<<endl;

    return 0;
}