#include<iostream>
using namespace std;

bool LinearSearch(int arr[], int n, int key);

int main(){
    int n,key;
    cout<<"Enter size of array: ";
    cin>>n;
    int *arr= new int[100];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter key to search: ";
    cin>>key;
    bool ans = LinearSearch(arr,n,key);
    if(ans){
        cout<<"Key is present ";
    }else{
        cout<<"Key is not present "; 
    }

    delete[] arr;
    return 0;
}

bool LinearSearch(int arr[],int n,int key){
    if(n==0){
        return false;
    }
   if(arr[0]==key){
        return true;
   }
    if(n>0){
        return LinearSearch(arr+1,n-1,key);
    }
}