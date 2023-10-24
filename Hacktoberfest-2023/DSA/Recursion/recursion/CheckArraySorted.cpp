#include<iostream>
using namespace std;

bool CheckArray(int arr[],int n){
    if(n == 0 || n == 1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }else{

        return CheckArray(arr+1,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans =CheckArray(arr,n);
    if(ans){
        printf("Array is sorted");
    }else{
        printf("Array is not sorted");
    }


    return 0;
}