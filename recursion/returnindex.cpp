#include<iostream>
#include<vector>
using namespace std;
vector<int> printoccurances(int arr[],int size,int index,int target){
    vector<int> ans;
    if(index>=size)
        return ans;
    
    if(arr[index]==target){
        ans.push_back(index);
    }

    printoccurances(arr,size,index+1,target);
    return ans;
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