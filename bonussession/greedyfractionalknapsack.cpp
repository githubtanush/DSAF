#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int fractionalknapsack(vector<int> val,vector<int> wt,int n,int capacity){
    vector<float> valwtratio;
    for(int i = 0; i < n;i++){
        float ratio = (val[i]*1.0)/wt[i];
        valwtratio.push_back(ratio);
    }
    priority_queue<pair<float,pair<int,int> > > maxi;
    for(int i = 0; i < n;i++){
        maxi.push({valwtratio[i],{val[i],wt[i]}});
    }
    //max heap is ready
    int totalval = 0;
    while(capacity != 0 && !maxi.empty()){
        auto front = maxi.top();
        float ratio = front.first;
        int value = front.second.first;
        int weight = front.second.second;
        maxi.pop();
        //full insert hoga
        if(capacity>=weight){
            totalval += value;
            capacity = capacity - weight;
        }
        else{
            //fractional insert hoga
            int valuetoInclude = ratio * capacity;
            totalval += valuetoInclude;
            capacity = 0;
            break;
        }
    }
    return totalval;
}
int main(){
    vector<int> val = {60,100,120};
    vector<int> wt = {10,20,30};
    int n = 3;
    int w = 50;
    int ans = fractionalknapsack(val,wt,n,w);
    cout<<"Final Answer is : "<<ans<<endl;
    return 0;
}