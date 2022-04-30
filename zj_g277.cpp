#include<iostream>
#include<algorithm>
using namespace std;
struct con{
	long long val;
	int index;
};
bool comp(con a,con b){
	return a.val<b.val;
}
int main(){
	long long prefix[300500],n;
	con ary[300500];
	cin>>n;
	prefix[0]=0;
	for(int i=1;i<=n;i++){
		cin>>ary[i].val;
		ary[i].index=i;
		prefix[i]=ary[i].val+prefix[i-1];
	}
	sort(ary+1,ary+n+1,comp);
	int s=1,e=n;
	for(int i=1;i<=n;i++){
		if(s==e){
			cout<<prefix[s]-prefix[s-1];
			return 0;
		}
		if(ary[i].index<s||ary[i].index>e){
			continue;
		} 
		long long  l,r;
		l=prefix[e]-prefix[ary[i].index];
		r=prefix[ary[i].index-1]-prefix[s-1];
//		cout<<ary[i].index<<" ";
//		cout<<l<<" "<<r<<"\n";
		if(l>=r){
			s=ary[i].index+1;
		}
		else if(l<r){
			e=ary[i].index-1;
		}
	}
}