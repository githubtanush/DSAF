#include<iostream>
#include<limits.h>
using namespace std;
void find_mini(int arr[],int size,int index,int &maxi){//mini ko hmesha pass by refrence krna kyuki mini hmesha change hota hai 
//or hme original mini mein hi value store krni hai uski copy mein ni  pass by value krne se mini ki ek copy bni tab pass hua
//lekin hme mini mein hi change krna hai
    //Base case
    if(index>=size){
        return ;
    }
    //processing
    maxi = max(maxi,arr[index]);
    
    //recursive call
    find_mini(arr,size,index+1,maxi);
}

int main(){
    int arr[] = {80,20,30,40,50};
    int size = 5;
    int index = 0;
    int maxi = INT_MIN;
    find_mini(arr,size,index,maxi);
    cout<<"Minimum number in the array : "<<maxi<<endl;
    
    return 0;
}  