#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int row = 8;
    int col = 15;
    int tower = 3;
    vector<pair<int,int> >loc;
    //for modern cpp
    // loc.push_back({3,8});
    // loc.push_back({11,2});
    // loc.push_back({8,6});

    //compatible for g++ compiler
    loc.push_back(std::make_pair(3, 8)); // Using std::make_pair
    loc.push_back(std::make_pair(11, 2)); // Using std::make_pair
    loc.push_back(std::make_pair(8, 6)); // Using std::make_pair


    vector<int> xdim;
    xdim.push_back(0);
    xdim.push_back(col+1);
    for(int i = 0; i < loc.size(); i++){
        xdim.push_back(loc[i].first);
    }
    sort(xdim.begin(),xdim.end());

    vector<int> ydim;
    ydim.push_back(0);
    ydim.push_back(row+1);
    for(int i = 0; i < loc.size(); i++){
        ydim.push_back(loc[i].second);
    }
    sort(ydim.begin(),ydim.end());

    vector<int> xans;
    for(int i = 1; i < xdim.size();i++){
        int diff = xdim[i]-xdim[i-1] - 1;
        xans.push_back(diff);
    }

    vector<int> yans;
    for(int i = 1; i < ydim.size();i++){
        int diff = ydim[i]-ydim[i-1] - 1;
        yans.push_back(diff);
    }

    int maxi = -1;
    for(int i = 0; i < xans.size();i++){
        for(int j = 0; j < yans.size();j++){
            int prod = xans[i] * yans[j];
            maxi = max(maxi,prod);
        }
    }
    cout<<"Final Ans : "<<maxi<<endl;

    return 0;
}