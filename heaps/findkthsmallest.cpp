#include<iostream>
#include<queue>
using namespace std;
int getkthsmallestelement(int arr[],int n,int k ){
    priority_queue<int> pq;
    for(int i = 0; i < k;i++){
        int element = arr[i];
        pq.push(element);
    }
    //remaining element ko tbhi insert krenge age voh root se chotte honge
    for(int i = k; i < n;i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}
int main(){
    int arr[] = {3,5,4,6,9,8,7};
    int n = 7;
    int k = 5;
    cout<<k<<"th smallest element is : "<<getkthsmallestelement(arr,n,k)<<endl;
    return 0;
}