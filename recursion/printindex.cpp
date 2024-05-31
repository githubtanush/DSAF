#include<iostream>
using namespace std;
void printoccurances(int arr[],int size,int index,int target){
    if(index>=size)
        return ;
    
    if(arr[index]==target){
        cout<<index<<" ";
    }

    printoccurances(arr,size,index+1,target);
}
int main(){
    int arr[] = {10,20,30,10,40,50,60,10};
    int size = 8;
    int index = 0;
    int target = 10;
    cout<<"Index is : ";
    printoccurances(arr,size,index,target);
    return 0;
}