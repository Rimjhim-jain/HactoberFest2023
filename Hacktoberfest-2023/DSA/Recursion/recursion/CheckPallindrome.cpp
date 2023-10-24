#include<iostream>
using namespace std;


bool checkPallindrome(string& str,int i,int j){
    if(i>j){
        return true;
    }

    if(str[i]!=str[j]){
        return false;
    }else{
        return checkPallindrome(str,i+1,j-1);
    }
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    int size =0;

    for(int i=0; str[i]!='\0'; i++){
        size++;
    }

    bool ans = checkPallindrome(str,0,size-1);

    if(ans){
        printf("It is a pallindrome");
    }else{
        printf("It is not a pallindrome");
    }
    return 0;
}