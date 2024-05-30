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
int firstocc(int arr[1000],int n,int target){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==target){
            ans = mid;
            e = mid - 1;
        }
        else if(target<arr[mid]){
            e = mid - 1;
        }
        else if(target>arr[mid]){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastocc(int arr[1000],int n,int target){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid]==target){
            ans = mid;
            s = mid + 1;
        }
        else if(target<arr[mid]){
            e = mid - 1;
        }
        else if(target>arr[mid]){
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int totalocc(int arr[1000],int n,int target){
    int firstoccurance = firstocc(arr,n,target);
    int lastoccurance  = lastocc(arr,n,target);
    int totaloccurance = lastoccurance - firstoccurance + 1;
    return totaloccurance;
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
    int index =  firstocc(arr,n,target);
    cout<<"The element is found at firstocc index : "<<index<<endl;
    int in =  lastocc(arr,n,target);
    cout<<"The element is found at lastocc index : "<<in<<endl;
    int ind =  totalocc(arr,n,target);
    cout<<"The Total occurance of the element is : "<<ind<<endl;
    outputarray(arr,n);
    return 0;
}