#include<iostream>
#include<algorithm>
using namespace std;
int ary[100000];
int main(){
	int r,n,ans,pos;
	while(cin>>r>>n){
		ans=0;
		if(r==-1&&n==-1){
			return 0;
		}
		for(int i=0;i<n;i++){
			cin>>ary[i];
		}
		sort(ary,ary+n);
		pos=ary[0];
		for(int i=0;i<n;i++){
			ans++;
			pos+=2*r;
			while(pos>=ary[i]){
				i++;
				if(i==n){
					break;
				}
			}
			pos=ary[i];
			i--;
		}	
		cout<<ans<<"\n";
	}
	 
}