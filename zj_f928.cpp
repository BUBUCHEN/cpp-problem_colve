#include<iostream>
using namespace std;
int n,ary[2000],pop;
void f(int now){
	if(ary[now]==0){
		return ;
	}
	int nxt=0,going=ary[now];
	ary[now]=0;
	if(going==2){
		if(now-1>=0){
			f(now-1);
		}
		if(now+1<n){
			f(now+1);
		}
	}
	else if(going>=3){
		if(now-going>=0){
			f(now-going);
			if(now-2*going>=0){
				f(now-2*going);
			}
		}
		if(now+going<n){
			f(now+going);
			if(now+2*going<n){
				f(now+2*going);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ary[i];
	}
	cin>>pop;
	f(pop);
	for(int i=0;i<n;i++)cout<<ary[i]<<" ";
}