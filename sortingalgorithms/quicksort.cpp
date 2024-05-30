#include<iostream>
using namespace std;
void quicksort(int arr[],int s,int e){
    if(s>=e) return ;
    int pivot = e ;
    int i = s - 1;
    int j = s;

    while(j<pivot){
        if(arr[j]< arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    i++;
    //i is the right position for the pivot element
    swap(arr[i],arr[pivot]);
    quicksort(arr,s,i-1);
    quicksort(arr,i+1,e);

}
int main(){
    int arr[] = {7,2,1,8,6,3,5,4};
    int size = 8;
    int s = 0;
    int e = size - 1;
    cout<<"Before quick sort : "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quicksort(arr,s,e);
    cout<<"After quick sort : "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}