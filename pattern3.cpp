#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cout<<"Enter no. of rows: ";
    cin>>a;
    for(int i=1;i<a+1;i++){
        for(int j=0;j<i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}