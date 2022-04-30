#include<iostream>
using namespace std;
int s,t,n,m,prefix[110][110],r,a[110][110],b[110][110],area;
bool comp(int c,int d){
	area=0;
	int tot=0;
	for(int is=0,in=c;is<s;is++,in++){
		for(int it=0,im=d;it<t;it++,im++){
			area+=b[in][im];
			if(a[is][it]!=b[in][im]){
				tot++;
				if(tot>r){
					return 0;
				}
			}
		}
	}
	return 1;
}
int abs(int a){
	if(a<0){
		return -1*a;
	}
	return a;
}
int main(){
	int ans=0,q2=0;
	cin>>s>>t>>n>>m>>r;
	for(int is=0;is<s;is++){
		for(int it=0;it<t;it++){
			cin>>a[is][it];
			q2+=a[is][it];
		}
	}
	for(int is=0;is<n;is++){
		for(int it=0;it<m;it++){
			cin>>b[is][it];
		}
	}
	int cn[]={-1,0,-1},cm[]={0,-1,-1};
	for(int in=0;in<n;in++){
		for(int im=0;im<m;im++){
			prefix[in][im]=b[in][im];
			for(int ic=0;ic<3;ic++){
				int nn=in+cn[ic],nm=im+cm[ic];
				if(nn<0||nm<0||nn>=n||nm>=m){
					continue;
				}
				prefix[in][im]+=prefix[nn][nm];
			}
		}
	}
	int clst=999999;
	for(int in=0;in<=n-s;in++){
		for(int im=0;im<=m-t;im++){
			if(comp(in,im)){
				ans++;
				if(abs(area-q2)<clst){
					clst=abs(area-q2);
				}
			}
		}
	}
	cout<<ans<<"\n";//pro 1 
	if(clst==999999){
		cout<<"-1\n";
	}
	else{
		cout<<clst<<"\n";
	}
}