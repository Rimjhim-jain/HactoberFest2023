#include<iostream>
using namespace std;

int partition(int arr[],int s,int e){


    int pivot = arr[s];
    int count =0;

    for(int i=s+1; i<e; i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    int index = count+s;
    //swap pivot 
    swap(arr[index],arr[s]);

    int i=s;
    int j=e;
    while(i<index && j>index){
        while(arr[i]<= pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        while(i<index && j>index){
           swap(arr[i],arr[j]); 
           i++;
           j--;
        }

    }

    return index;

  

}

void  quicksort(int arr[],int s,int e){

//base condition
   if(s>=e){
    return ;
   }
  
  int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);


}



int main(){
     int n;
    cout<<"Enter array size: ";
    cin>>n;

    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr,0,n-1); 

    cout<<"Sorted array is: ";
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}