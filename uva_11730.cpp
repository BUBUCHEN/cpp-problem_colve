#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int s,t;
	bool pb[1500]={};
	vector<int> prime;
	for(int i=2;i<1100;i++){
		if(!pb[i]){
			prime.push_back(i);
		}
		for(vector<int>::iterator h=prime.begin();h!=prime.end();h++){
			if(*h*i>1100){
				break;
			}
			pb[*h*i]=1;
			if(i%*h==0){
				break;
			}
		}
	}	
	queue<int> q;
	int cs=1;
	while(cin>>s>>t){
		if(s==0&&t==0){
			return 0;
		}
		cout<<"Case "<<cs<<": ";
		cs++;
		q.push(s);
		bool vis[1100]={};
		vis[s]=1;
		int count[1100]={},time=0;
		while(!q.empty()){
			int ql=q.size();
			for(int i=0;i<ql;i++){
				int n=q.front();
				q.pop();
				count[n]=time;
				for(vector<int>::iterator h=prime.begin();h!=prime.end();h++){
					if(n%*h==0){
						int n2=n+*h;
						if(n2>t||n==*h){
							break;
						}
						if(!vis[n2]){
							q.push(n2);
							vis[n2]=1;
						}
					}
				}
			}
			time++;
		}
		if(vis[t]==0){
			cout<<"-1\n";
		}
		else{
			cout<<count[t]<<"\n";	
		}
	}
}