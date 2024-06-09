//heapify - very very very very important function
#include<iostream>
using namespace std;
class heap{
    public: 
        int *arr;
        int capacity;
        int size;
    
    heap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        //size = current number of elements in heap
        this->size = 0;
    }
    void insert(int val){
        if(size==capacity){
            cout<<"Heap Overflow"<<endl;
        }
        //size inc. krr jayega
        size++;
        int index = size;
        arr[index] = val;
        //take the val to its current position
        while(index>1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }
    void printheap(){
         for(int i = 0; i <= size;i++){
        cout<<arr[i]<<" ";
    }
    }

};
//creation - O(N)
    void heapify(int *arr, int n, int index) {
  int leftIndex = 2*index;
  int rightIndex = 2*index+1;
  int largestKaIndex = index;

  //teno me se max lao 
  if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]) {
    largestKaIndex = leftIndex;
  }
  if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]) {
    largestKaIndex = rightIndex;
  }
  //after these 2 conditions largestKaIndex will be pointing towards largest elemnt among 3 
  if(index != largestKaIndex) {
    swap(arr[index], arr[largestKaIndex]);
    //ab recursion sambhal lega
    index = largestKaIndex;
    heapify(arr, n, index);
  }
}

void buildHeap(int *arr, int n) {
  for(int index = n/2; index>0; index--) {
    heapify(arr, n, index);
  }
}

void heapSort(int *arr, int n) {
  while(n != 1 ) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr,n,1);
  }
}

int main(){
    // heap h(20);
    // //insertion
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout<<"Printing the content of heap : "<<endl;
    // h.printheap();
    int arr[] = {-1,5,10,15,20,25,12};
    buildHeap(arr,6);
    cout<<"printing heap : "<<endl;
    for(int i = 1 ;i <= 6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    heapSort(arr,6);
    cout<<"printing heap : "<<endl;
    for(int i = 1 ;i <= 6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    return 0;
}