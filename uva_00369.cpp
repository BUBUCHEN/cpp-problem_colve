#include<iostream>
using namespace std;
unsigned long long int dp[101][101]={};
bool vis[101][101]={};
unsigned long long int func(int n,int x){//c(n,x)
	if(vis[n][x]){
		return dp[n][x];
	}
	if(n<=0||x>n){
		return 0;
	}
	if(x==1){
		return n;
	}
	dp[n][x]=func(n-1,x)+func(n-1,x-1);
	vis[n][x]=1;
	return dp[n][x];
}
int main(){
	int n,m;
	string ans="";
	while(cin>>n>>m){
		if(n==0&&m==0){
			return 0;
		}
		cout<<n<<" things taken "<<m<<" at a time is "<<func(n,m)<<" exactly.\n";
	}
	
}
