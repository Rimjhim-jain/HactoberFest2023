#include<iostream>
using namespace std;

string reverseString(string& str,int i,int j){
   if(i>j){
    return str;
   }

   swap(str[i],str[j]);
    
    return reverseString(str,i+1,j-1);

}

int main(){
    string str;
    cin>>str;
    int size =0;

    for(int i=0; str[i]!='\0'; i++){
        size++;
    }

    cout<<"Reversed String is: "<<reverseString(str,0,size-1);
    return 0;
}