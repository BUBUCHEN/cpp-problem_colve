#include<iostream>
using namespace std;
bool ed[60000]={};
int now,n,ary[60000],ans=0;
void find(int x){
	if(x==now){
		ans++;
		return ;
	}
	find(ary[x]);
	ed[ary[x]]=1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ary[i];
	}
	for(int i=0;i<n;i++){
		now=i;
		if(!ed[i]){
			find(ary[i]);
			ed[ary[i]]=1;
		}
	}
	cout<<ans<<"\n";
}