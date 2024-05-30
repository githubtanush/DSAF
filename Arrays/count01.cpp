#include<iostream>
using namespace std;
void inputArray(int arr[],int n){
    for(int i = 0 ;  i < n;i++){
        cin>>arr[i];
    }
}
void countZeroOne(int arr[],int n){
    int ZeroCount = 0;
    int oneCount = 0;
    for(int i = 0; i < n;i++){
        if(arr[i]==0){
            ZeroCount++;
        }
        else if(arr[i]==1){
            oneCount++;
        }
    }
    cout<<"Zero in this array is : "<<ZeroCount<<endl<<"One in this array is : "<<oneCount<<endl;
}
int main(){
    int arr[1000];
    int n;
    cout<< "Enter the length of the array that how many big array you want to print : "<<endl;
    cin>>n;
    inputArray(arr,n);
    countZeroOne(arr,n);
    return 0;
}