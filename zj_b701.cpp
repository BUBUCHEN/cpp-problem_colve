#include<iostream>
#include<queue>
using namespace std;
struct st{
	int x;
	int y;
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	bool vis[600][600]={},map[600][600];
	cin>>n>>m;
	for(int im=0;im<m;im++){
		for(int in=0;in<n;in++){
			cin>>map[in][im];
		}
	}
	int area=0,cx[]={0,0,-1,1},ans=0,cy[]={-1,1,0,0};
	for(int im=0;im<m;im++){
		for(int in=0;in<n;in++){
			if(map[in][im]==1&&vis[in][im]==0){
				int ni=im,s=im,e=in,w=in;
				queue<st> q;
				st now,tmp;		
				tmp.x=in;
				tmp.y=im;
				q.push(tmp);
				vis[in][im]=1;
				while(!q.empty()){
					now=q.front();
					q.pop();
					if(map[now.x][now.y]==0){
						continue;
					}
					ans++;
					if(now.y<ni){
						ni=now.y;
					}
					if(now.y>s){
						s=now.y;
					}
					if(now.x>e){
						e=now.x;
					}
					if(now.x<w){
						w=now.x;
					}
					for(int i=0;i<4;i++){
						int nx=now.x+cx[i],ny=now.y+cy[i];
						if(vis[nx][ny]){
							continue;
						}
						vis[nx][ny]=1;
						tmp.x=nx;
						tmp.y=ny;
						q.push(tmp);
					}
					area++;
				}
				cout<<w<<" "<<ni<<" "<<e<<" "<<s<<" "<<area<<"\n";
				area=0;
			}
			
		}
	}
}