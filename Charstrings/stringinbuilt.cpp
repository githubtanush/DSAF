#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    cin>>name;
    string temp = "Arora";
    string hnji = "This is a car";
    cout<<"Length of the string : "<<name.length()<<endl;
    cout<<"string is empty or not : "<<temp.empty()<<endl;
    cout<<"character at position 0 : "<<name.at(0)<<endl;
    cout<<"Front character of string is : "<<name.front()<<endl;
    cout<<"Last character of string is : "<<name.back()<<endl;
    name.append(temp);
    cout<<"After appending the name string will be "<<name<<endl;
    cout<<"After erasing the string hnji will be : "<<hnji.erase(4,3)<<endl;
    string firstname = "Tanush Arora";
    string lastname = "kumar ";
    firstname.insert(7,lastname);
    cout<<"Printing name : "<<firstname<<endl;
    name.push_back('A');
    cout<<name<<endl;
    name.pop_back();
    cout<<name<<endl;
    string str1 = "yaar tera superstar desi kalakar";
    string str2 = "superstar";
    if(str1.find(str2)==string::npos){
        //not found
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }
    string str3 = "Tanush";
    string str4 = "Tanush";
    //compare function is case sensitive use it wisely
    //don't compare the string like ch[] like this if(ch[1]==ch[2])
    if(str3.compare(str4)==0){
        cout<<"Matching"<<endl;
    }
    else{
        cout<<"Not matching"<<endl;
    }

    string str5 = "This is a car, big daddy of all suvs";
    cout<<str5.substr(19,5)<<endl;
    return 0;
}

//character arrays = space allocate 
//string = dynamically allocate the size automatically size will increase