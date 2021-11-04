#include<bits/stdc++.h>
using namespace std;


struct item{
    char ID;
    int hour;
    int payment;
};

bool comp(item a,item b){
    return a.payment > b.payment;
}
int test(struct item arr[],int n, int maximum){
    int newArr[n+1][maximum+1];
    for(int w = 0;w<=maximum;w++){
		newArr[0][w] = 0;
	}
	for(int i = 0;i<=n;i++){
        newArr[i][0] = 0;
		if(i == 0){
			continue;
		}
		int hour = arr[i-1].hour;
		int payment = arr[i-1].payment;
		for(int w = 1;w<=maximum;w++){
            if(hour<=w){
                if(payment+newArr[i-1][w-hour]>newArr[i-1][w]){
                    newArr[i][w] = payment + newArr[i-1][w-hour];

                }
                else{
					newArr[i][w] = newArr[i-1][w];
				}
            }
            else{
				newArr[i][w] = newArr[i-1][w];
			}
		}
	}

	cout<<newArr[n][maximum];
	int x = newArr[n][maximum];
	sort(arr,arr+n,comp);
	int maxim = maximum;
	cout<<"\n";
	for(int i = 0;i<n;i++){
        if(x!=0){
            if(maxim!=0){
                if(maxim-arr[i].hour < 0){
                    continue;
                }
                else{
                    cout<<arr[i].ID<<endl;
                    x = x-arr[i].payment;
                    maxim = maxim - arr[i].hour;
                }
            }
        }
	}
}
int main(){
    item arr[] = {{'A', 2,6000},{'B', 2,1000},{'C',1,1200},{'D',2,2000},{'E',1,3000}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maximum = 5;
    test(arr,n,maximum);
}
