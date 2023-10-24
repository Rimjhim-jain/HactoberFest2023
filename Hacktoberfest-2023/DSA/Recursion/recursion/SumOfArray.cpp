#include<iostream>
using namespace std;

int mySum(int arr[],int n);

int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    int arr[100];
    cout<<"Enter elements of array";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = mySum(arr,n);
    cout<<"Sum is: "<<ans;
    return 0;
}

int mySum(int arr[],int n){
    if(n==0){
        return 0;
    }
    if(n ==1){
        return arr[0];
    }
    if(n>0){
        return arr[0]+mySum(arr+1,n-1);
    }
}