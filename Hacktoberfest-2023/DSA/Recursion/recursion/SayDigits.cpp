#include<iostream>
using namespace std;

void sayDigits(int n,string arr[10]){

    if(n==0){
        return ;
    }

    int digit = n%10;
    n = n/10;
    sayDigits(n,arr);
    cout<<arr[digit]<<endl;
}

int main(){
    int n;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cin>>n;

    sayDigits(n,arr);

    return 0;
}