#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n,int i){


    //base condition
    if(i==n-1){
        return;
    }

  for(int j=i+1; j<n; j++){
   if(arr[i]>arr[j]){
    swap(arr[i],arr[j]);
   }
  }    

   SelectionSort(arr,n,i+1);

}

int main(){
    int n;
    int i=0;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    SelectionSort(arr,n,i);

    cout<<"Sorted array is: ";
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}