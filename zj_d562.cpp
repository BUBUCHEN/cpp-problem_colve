#include<iostream>
#include<algorithm>
using namespace std;
string i2s(int a){
	string opt="";
	while(a){
		opt+=(char)(a%10+'0');
		a/=10;
	}
	reverse(opt.begin(),opt.end());
	return opt;
}
int main(){
	int n,ary[200];
	string ans;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>n){
		ans.clear();
		for(int i=0;i<n;i++){
			cin>>ary[i];
		}
		int h=0,e=n-1,time=1;
		while(e-h!=-1){
			if(time%2){
			for(int i=h;i<=e;i++){
				ans+=i2s(ary[i])+' ';
			}
				ans+='\n';
				time++;
				h++;
			}
			else{
				for(int i=e;i>=h;i--){
					ans+=i2s(ary[i])+' ';
				}
				ans+='\n';
				time++;
				e--;
			}	
			
		}
		cout<<ans<<"\n";
	}
}