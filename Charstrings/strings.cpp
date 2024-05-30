//strings arrays modified dynamically 
#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;//not need to specify the size
    // cin>>name; //again delimeter is also space 
    //To avoid space delimeter use getline cin
    getline(cin,name);
    cout<<name <<endl;
    cout<<"Printing the first character"<<name[0]<<endl;
    int index = 0;
    while(name[index]!='\0'){
        cout<<"index : "<<index<<"character : "<<name[index]<<endl;
        index++;
    }
    return 0;
}