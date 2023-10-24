#include<iostream>
using namespace std;

void  InsertionSort(int arr[],int n,int i){


    //base condition
    if(i>n-1){
        return;
    }


    int temp= arr[i];
    int j=i-1;
  while(j>=0){
        if(temp<arr[j]){
            arr[j+1]= arr[j];
        }else{
            break;
        }
            j--;
  }
    arr[j+1] = temp;  

   InsertionSort(arr,n,i+1);

}

int main(){
    int n;
    int i=1;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    InsertionSort(arr,n,i); 

    cout<<"Sorted array is: ";
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}