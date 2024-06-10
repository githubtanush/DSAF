#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Info{
    public:
        int data;
        int rowIndex;
        int colIndex;

    Info(int a,int b,int c){
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};
class compare{
    public:
        bool operator()(Info* a,Info* b){
            return a->data>b->data;
        }
};
void mergesortedarrays(int arr[][4],int n,int k,vector<int>& ans){ 
        for(int i = 0; i < k;i++){
            int element = arr[i][0];
            Info* temp = new Info(element,i,0);
            pq.push(temp);
        }
        while(!pq.empty()){
            Info* temp = pq.top();
            pq.pop();
            int topData = temp->data;
            int toprow = temp->rowIndex;
            int topcol = temp->colIndex;
            

            //store in answer vector
            ans.push_back(topData);

            //next element for the same row,jisme se pop kia hai just abhi usse insert bhi toh krna hai 
            if(topcol+1<n){
                //iska matlab row mein element abhi present hai 
                Info* newInfo = new Info(arr[toprow][topcol+1],toprow,topcol+1);
                pq.push(newInfo);
            }
        }
}
int main(){
    int arr[3][4]={
    {1,4,8,11},
    {2,3,6,10},
    {5,7,12,14}
    };
    int n = 4;
    int k = 3;
    vector<int> ans;
    mergesortedarrays(arr,n,k,ans);
    cout<<"printing the heap : "<<endl;
    for(int i = 0; i < ans.size();i++){
        cout<<ans[i]<<" "; 
    }
    return 0;
}