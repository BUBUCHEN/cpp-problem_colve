#include<iostream>
#include<queue> 
using namespace std;
struct Node{
	int x,y;
};
int main(){
	string ans="";
	int h,w,si,sj,z;
	int map[510][510]={};
	cin>>h>>w>>si>>sj>>z;
	queue<Node> q;
	Node tmp;
	tmp.y=si;
	tmp.x=sj;
	q.push(tmp);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>map[j][i];
		}
	}
	bool vis[510][510]={};
	vis[sj][si]=1;
	int tar=map[sj][si],cx[]={0,0,-1,1},cy[]={-1,1,0,0};
	map[sj][si]=z;
	while(!q.empty()){
		Node np=q.front();
		q.pop();
//		cout<<np.x<<" "<<np.y<<" !\n";
		int nx,ny;
		for(int i=0;i<4;i++){
			nx=np.x+cx[i],ny=np.y+cy[i];
			if(nx<=0||ny<=0||ny>h||nx>w){
				continue;
			}
			if(map[nx][ny]==tar&&(!vis[nx][ny])){
				map[nx][ny]=z;
				Node to;
				to.x=nx;
				to.y=ny;
				q.push(to);
				vis[nx][ny]=1;
			}
		}
	}
	for(int x=1;x<=h;x++){
		for(int y=1;y<=w;y++){
			cout<<map[y][x]<<" ";
		}
		cout<<"\n";
	}
}
