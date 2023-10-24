#include<iostream>
using namespace std;

bool BinarySearch(int arr[], int start, int end,int key);

int main(){
    int n,key,start=0,end;
    cout<<"Enter size of array: ";
    cin>>n;
    end=n-1;
    int *arr= new int[100];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Enter key to search: ";
    cin>>key;
    bool ans = BinarySearch(arr,start,end,key);
    if(ans){
        cout<<"Key is present ";
    }else{
        cout<<"Key is not present "; 
    }

    delete[] arr;
    return 0;
}

bool BinarySearch(int arr[],int start, int end,int key){
    int mid = (start+end)/2;
    
    if(start>end){
        return false;
    }
   if(arr[mid]==key){
        return true;
   }
    if(key>arr[mid]){
        return BinarySearch(arr,mid+1,end,key);
    }else{
        return BinarySearch(arr,start,mid-1,key);
    }
}