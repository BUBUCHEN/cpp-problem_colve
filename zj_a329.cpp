#include<iostream>
#include<vector>
using namespace std;
struct node{
	vector<int> from;
	unsigned long long value;
};
int n,xn,tmp;
node city[100010];
int re(int want){
	if(want==1){
		return 1;
	}
	for(int i=0;i<city[want].from.size();i++){
		if(city[city[want].from[i]].value==0){
			city[want].value+=re(city[want].from[i]);
		}
		else{
			city[want].value+=city[city[want].from[i]].value;
		}
        city[want].value %= 1234567 ;
	}
	return city[want].value ;
}	
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xn;
		city[i].value=0;
		for(int in=0;in<xn;in++){
			cin>>tmp;
			city[tmp].from.push_back(i);
		}
	}
	cout<<re(n);
}