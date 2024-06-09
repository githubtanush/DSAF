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
    int deletion(){
        int answer = arr[1];
        //replacement
        arr[1] = arr[size];
        //last element ko delete kro uski original position se
        size--;
        int index = 1;
        while(index<size){
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            //find out krna hai , sbse bda kon
            int largestkaindex = index;
            //check left child
            if(leftIndex<=size && arr[largestkaindex]<arr[leftIndex]){
                largestkaindex = leftIndex;
            }
            if(rightIndex<=size && arr[largestkaindex]<arr[rightIndex]){
                largestkaindex = rightIndex;
            }
            if(index == largestkaindex){
                break;
            }
            else{
                swap(arr[index],arr[largestkaindex]);
                index = largestkaindex;
            }
        }
        return answer;
    }
    void printheap(){
         for(int i = 1; i <= size;i++){
        cout<<arr[i]<<" ";
    }
    }
};
int main(){
    heap h(20);
    //insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout<<"Printing the content of heap : "<<endl;
    h.printheap();
    int ans = h.deletion();
    cout<<"Answer is : "<<ans<<endl;
    cout<<endl;
    h.printheap();
    return 0;
}