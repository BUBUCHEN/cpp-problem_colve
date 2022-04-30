#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,d,r,a1[200],a2[200];
	while(cin>>n>>d>>r){
		if(n==0){
			return 0;
		}
		for(int i=0;i<n;i++){
			cin>>a1[i];
		}
		for(int i=0;i<n;i++){
			cin>>a2[i];
		}
		sort(a1,a1+n);
		sort(a2,a2+n);
		int ans=0;
		for(int i=0;i<n;i++){
			int t=a1[i]+a2[n-i-1];
			ans+=(t-d>0)*(t-d);
		}
		cout<<ans*r<<"\n";
	}
}
