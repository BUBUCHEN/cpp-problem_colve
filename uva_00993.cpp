#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,d;
	cin>>n;
	for(int in=0;in<n;in++){
		string ans;
		cin>>d;
		if(d==1){
			ans="1";
		}
		for(int i=9;i>=2;){
			if(d%i==0){
				d/=i;
				ans+=i+'0';
			}
			else{
				i--;
			}
		}
		if(d!=1){
			cout<<"-1\n";
		}
		else{
			reverse(ans.begin(),ans.end());
			cout<<ans<<"\n";
		}
	}
}