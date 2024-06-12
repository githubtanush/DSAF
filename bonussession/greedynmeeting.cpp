#include<iostream>
#include<vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second<b.second;
}
int minMeetings(int st[],int end[],int n){
    vector<pair<int,int> > time;
    for(int i = 0; i < n;i++){
        time.push_back({st[i],end[i]});
    }
    sort(time.begin(),time.end(),cmp);
    int count = 1;
    int prevstart = time[0].first;
    int prevend = time[0].second;
    for(int i = 1; i < n;i++){
        int currstart = time[i].first;
        int currend = time[i].second;
    if(currstart>prevend){
        //include current meeting
        count++;
        prevstart = currstart;
        prevend = currend;
    }
    }
    return count;
}
int main(){
    int st[] = {10,12,20};
    int end[] = {20,25,30};
    int n = 3;
    int ans = minMeetings(st,end,n);
    cout<<"Final Ans : "<<ans<<endl;
    return 0;
}