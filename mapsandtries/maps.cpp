#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    //creation 
    unordered_map<string,int> mapping;
    //insert
    pair<string,int> p = make_pair("Tanush Arora",25);
    pair<string,int> q("Sagar Arora",34);
    pair<string,int> r;
    r.first = "Jatin Arora";
    r.second = 43;
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    //insert
    mapping["Arora"] = 76;
    cout<<"Size of map : "<<mapping.size()<<endl;
    cout<<mapping.at("Tanush Arora")<<endl;
    cout<<mapping["Tanush Arora"]<<endl;
    cout<<mapping.count("Tanush Arora")<<endl;
    if(mapping.find("Tanush Arora") != mapping.end()){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
       cout<<"Size of map : "<<mapping.size()<<endl;
    cout<<mapping["kumar"]<<endl;//entry create ho jaygi if u use this bracket 
       cout<<"Size of map : "<<mapping.size()<<endl;
    return 0;
}
