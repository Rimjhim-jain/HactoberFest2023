#include<iostream>
using namespace std;

void merge(int arr[],int s,int e){
    int  mid = (s+e)/2;
    int len1  = mid-s+1;
    int len2 = e-mid;
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values in first array from start till mid
    int mainIndex = s;
    for(int i=0;i<len1; i++){
        first[i] = arr[mainIndex++];
    }
    //copy values in second array from mid+1 to end
    mainIndex = mid+1;
    for(int i=0;i<len2; i++){
        second[i] = arr[mainIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainIndex = s;
    while(index1 < len1 && index2 < len2){
        if(first[index1]< second[index2]){
            arr[mainIndex++] = first[index1++];
        }else{
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[mainIndex++] = first[index1++];
    }

     while(index2 < len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void MergeSort(int arr[], int s, int e){

    if(s>=e){
        return ;
    }
    int mid= (s+e)/2;
    MergeSort(arr,s,mid);
    MergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main(){
    int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    MergeSort(arr,0,n-1); 

    cout<<"Sorted array is: ";
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}