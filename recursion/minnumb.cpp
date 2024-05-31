#include<iostream>
#include<limits.h>
using namespace std;
void find_mini(int arr[],int size,int index,int &mini){//mini ko hmesha pass by refrence krna kyuki mini hmesha change hota hai 
//or hme original mini mein hi value store krni hai uski copy mein ni  pass by value krne se mini ki ek copy bni tab pass hua
//lekin hme mini mein hi change krna hai
    //Base case
    if(index>=size){
        return ;
    }
    //processing
    mini = min(mini,arr[index]);
    
    //recursive call
    find_mini(arr,size,index+1,mini);
}

int main(){
    int arr[] = {80,20,30,40,50};
    int size = 5;
    int index = 0;
    int mini = INT_MAX;
    find_mini(arr,size,index,mini);
    cout<<"Minimum number in the array : "<<mini<<endl;
    
    return 0;
}  