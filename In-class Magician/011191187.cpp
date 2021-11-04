#include <bits/stdc++.h>
using namespace std;

struct Item {
	char potion;
	int hour;
	int coin;
};

struct order{
	char classname;
	char potion;
	int last_time;
};

bool comp(Item a, Item b){
	return a.coin/a.hour > b.coin/b.hour;
}


void maxCoin(struct Item arr[],struct order arr2[],int n,int n2){
	sort(arr, arr+n, comp);
	int cointCount= 0;
	int time = 0;
	for(int i = 0;i<n;i++){
		for (int j = 0;j<n2;j++){
			if(arr[i].potion == arr2[j].potion){
				if(time<=arr2[j].last_time - arr[i].hour){
					time = time+arr[i].hour;
					cout<<arr2[j].classname<<", ";
					cointCount = cointCount+arr[i].coin;
				}
			}
		}
	}
	cout<<"\n"<<cointCount<<endl;
}


int main(){
	Item arr[] = {{'r', 2, 2000},{'s',1,1000},{'t',1,4000},{'u',2,3000},{'v',1,3000}};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	order arr2[] = {{'a','r',4},{'b','s',1},{'c','t',1},{'d','u',4},{'e','v',3}};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	maxCoin(arr,arr2,n,n2);
}