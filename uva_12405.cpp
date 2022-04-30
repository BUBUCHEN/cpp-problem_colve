#include<iostream>
using namespace std;
int main(){
	int n,l;
	string h;
	cin>>n;
	for(int in=0;in<n;in++){
		cout<<"Case "<<in+1<<": ";
		cin>>l;
		cin>>h;
		int ans=0,pos=-1;
		for(int i=0;i<l;i++){
			if(h[i]=='.'&&i>pos){
				pos=i+2;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}