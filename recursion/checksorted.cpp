#include<iostream>
using namespace std;
bool checksorted(int arr[],int size, int index){
    //base case
    if(index>=size)
        return true;

    //processing
    if(arr[index]<arr[index-1]){
        //yani ki sorted hai 
        //yani ki recursion lgega
        // bool aagakaAns = checksorted(arr,size,index+1)
        return false;
    }
    else{
    bool aagakaAns =  checksorted(arr,size,index+1);
    return aagakaAns;
    } 
}

int main(){
    int arr[6] = {10};
    int n = 1;
    int index = 1;

    bool isSorted = checksorted(arr,n,index);
    if(isSorted){
        cout<<"Array is Sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}