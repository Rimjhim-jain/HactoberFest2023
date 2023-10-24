#include<iostream>
using namespace std;

int power(int a,int b){
    if(b==0){
        return 1;
    }

    if(b==1){
        return a;
    }

    int result = power(a,b/2);

    if(b%2 == 0){
        return result*result;
    }else{
        return a*result*result;
    }
}

int main(){
    int a,b;
    cout<<"Enter number a: ";
    cin>>a;
    cout<<"Enter power b: ";
    cin>>b;
    int ans= power(a,b);
    cout<<"Answer: "<<ans;
    return 0;
}