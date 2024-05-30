#include<iostream>
using namespace std;
void inputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cin>>arr[i];
    }
}
void outputarray(int arr[1000],int n){
    for(int i = 0; i < n;i++){
        cout<<arr[i];
    }
}
int peakele(int arr[1000],int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid] < arr[mid + 1]){
            s = mid + 1;
        }
        else if (arr[mid]>arr[mid+1]){
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of tha array : ";
    cin>>n;
    inputarray(arr,n);
    int index = peakele(arr,n);
    cout<<"The element is found at index : "<<index<<endl;
    outputarray(arr,n);
    return 0;
}