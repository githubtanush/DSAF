//Fact(7) = 1*2*3*4*5*6*7;
#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number for which number u find factorial : ";
    cin>> n;
    int res=1;
    for(int i=1;i<=n;i++)
    {
      res*=i;  
    }
    cout<<"The value for this is : "<<res;

    return 0;
}
//res = 1;
//res*i;
//sum =  0;
//sum+i;


//swapping