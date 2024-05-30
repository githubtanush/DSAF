#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid = ( s + e)/2;
    int lenleft = mid - s + 1;
    int lenright  = e - mid;
    //create left and right array 
    int *left = new int[lenleft];
    int *right = new int[lenright];

    //copy values from the original array to the left array 
    int k = s;
    //k->starting index of left array values in original array 
    for(int i = 0; i < lenleft;i++){
        left[i] = arr[k];
        k++;
    }
    //copy values from the original array to the right array 
    k = mid + 1;
    for(int i = 0; i < lenright;i++){
        right[i] = arr[k];
        k++;
    }

    //actual merge logic here
    //left array is already sorted
    //right array is already sorted
     int leftIndex = 0;
     int rightIndex = 0;
     //yhi par glti kroga
     int mainArrayIndex = s;
    
    while(leftIndex < lenleft && rightIndex < lenright){
        if(left[leftIndex]<right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }
    //2 more cases - 1st case - left array khatam but right array bcha hai 
    while(rightIndex < lenright){
        arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
    }
    //2nd case - and 2nd is that ki right array khatam but left array bcha hai 
    while(leftIndex < lenleft){
        arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
    }
    //1 more step pending
    delete[] left;
    delete[] right;

}
void mergesort(int arr[],int s,int e){
    //base case
    if(s>e){
        //invalid array ;
        return ;
    }
    if(s==e){
        //single element;
        return ;
    }
    //break;
    int mid = (s+e)/2;
    //s->mid->left;
    //mid+1->e->right;
    //recursion bhaiya ko bulao 
    //left and right array ko sort krwao
    //recursive call for left array 
    mergesort(arr,s,mid);
    //recursive call for right array 
    mergesort(arr,mid+1,e); 
    //merge two sorted arrays 
    merge(arr,s,e);
}
int main(){
    int arr[] = {2,1,6,9,4,5};
    int size = 6;
    int s = 0;
    int e = size - 1;
    cout<<"Before merge sort : "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergesort(arr,s,e);
    cout<<"After merge sort : "<<endl;
    for(int i = 0;i < size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
//T.C - O(nlogn)