#include<iostream>
#include<queue>
using namespace std;
void solveformedian(double& median,priority_queue<int>& maxi,priority_queue<int,vector<int>,greater<int> >& mini,int element){
    if(maxi.size() == mini.size()){
        if(element>median){
            mini.push(element);
            median = mini.top();
        }
        else{
            maxi.push(element);
            median = maxi.top();
        }
    }
    else if(maxi.size() == mini.size()+1){
        if(element>median){
            mini.push(element);
        }
        else{
            int maxtop = maxi.top();
            maxi.pop();
            mini.push(maxtop);
            maxi.push(element);
        }
        median = (mini.top()+maxi.top())/2.0;
    }
    else if(mini.size()==maxi.size()+1){
        if(element>median){
            int mintop = mini.top();
            mini.pop();
            maxi.push(mintop);
            mini.push(element);
        }
        else{
            maxi.push(element);
        }
        median = (mini.top()+maxi.top())/2.0;
    }
}
int main(){
    int arr[] = {12,10,8,4,2,3,15};
    int n = 7;
    double median = 0;
    priority_queue<int> maxi;
    priority_queue<int,vector<int>,greater<int> > mini;
    for(int i = 0; i < n;i++){
        int element = arr[i];
        solveformedian(median,maxi,mini,element);
        cout<<"Median found : "<<median<<endl;
    }
}