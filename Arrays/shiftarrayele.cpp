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
void shiftArray(int arr[],int n){
    //last value store in some temporary storage
    int temp = arr[n-1];
    //chalao ji loop 
    for(int i = n-1; i>=1;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    outputArray(arr,n);
    cout<<endl;
    shiftArray(arr,n);
    outputArray(arr,n);
    return 0;
}