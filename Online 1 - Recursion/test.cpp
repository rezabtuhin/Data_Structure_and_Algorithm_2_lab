#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int is_pal(int n,int temp){
    if (n == 0){
        return temp;
    }
    temp = (temp * 10) + (n % 10);
    return is_pal(n / 10, temp);
}



int main(){
    int n1,n2;
    cin>>n1;
    cin>>n2;
    for(int i = n1;i<=n2;i++){
        int temp = is_pal(i, 0);
        if(temp == i){
            cout<<temp<<" ";
        }
    }
}
