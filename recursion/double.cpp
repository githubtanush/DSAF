#include<iostream>
#include<vector>
using namespace std;
void solve(int arr[],int size,int index){
    //solve function store even numbers in array into vectors
    //base case
    if(index>=size){
        return ;
    }
    //processing
        arr[index] = 2 * arr[index];
    //recursive call
    solve(arr,size,index+1);


}
int main(){
    int arr[5] = {11,20,31,40,51};
    int size = 5;
    int index = 0;
    solve(arr,size,index);
    for(int i = 0; i < size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}