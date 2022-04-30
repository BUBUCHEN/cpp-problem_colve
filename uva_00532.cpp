#include<queue>
#include<iostream>
using namespace std;
struct node{
	int x;
	int y;
	int z;	
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int l,r,c;
	string str;
	int map[40][40][40],el,er,ec;
	while(cin>>l>>r>>c){
		if(l==0&&r==0&&c==0){
			return 0;
		}
		queue<node> q;
		node tmp,now;
		bool vis[40][40][40]={};
		for(int il=0;il<l;il++){
			for(int ir=0;ir<r;ir++){
				cin>>str;
				for(int ic=0;ic<c;ic++){
					if(str[ic]=='#'){
						map[ic][ir][il]=-1;
						vis[ic][ir][il]=1;
					}
					else if(str[ic]=='.'){
						map[ic][ir][il]=0;
					}
					else if(str[ic]=='S'){
						map[ic][ir][il]=0;
						tmp.x=ic;
						tmp.y=ir;
						tmp.z=il;	
						vis[ic][ir][il]=1;
						q.push(tmp);
					}
					else{
						map[ic][ir][il]=0;
						el=il,er=ir,ec=ic;
					}
				}
			}
		}
		//input end
		int time=0,cx[]={0,0,-1,1},cy[]={-1,1,0,0};
		while(!q.empty()){
			int nl=q.size();
			for(int inl=0;inl<nl;inl++){
				node nxt;
				now=q.front();
				q.pop();
				nxt=now;
				if(map[now.x][now.y][now.z]==-1){
					continue;
				}
				map[now.x][now.y][now.z]=time;
				if(nxt.z-1>=0){
					nxt.z--;
					if(!vis[nxt.x][nxt.y][nxt.z]){
						vis[nxt.x][nxt.y][nxt.z]=1;
						q.push(nxt);	
					}
					nxt.z++;
				}
				if(nxt.z+1<l){
					nxt.z++;
					if(!vis[nxt.x][nxt.y][nxt.z]){
						vis[nxt.x][nxt.y][nxt.z]=1;
						q.push(nxt);	
					}
					nxt.z--;
				}
				for(int i=0;i<4;i++){
					nxt.x=now.x+cx[i],nxt.y=now.y+cy[i],nxt.z=now.z;
					if(nxt.x<0||nxt.y<0||nxt.x>=c||nxt.y>=r){
						continue;
					}
					if(!vis[nxt.x][nxt.y][nxt.z]){
						vis[nxt.x][nxt.y][nxt.z]=1;
						q.push(nxt);
					}
				}	
			}
			time++;
		}
//		for(int il=0;il<l;il++){
//			for(int ir=0;ir<r;ir++){
//				for(int ic=0;ic<c;ic++){
//					cout<<map[ic][ir][il]<<" ";
//				}
//				cout<<"\n";
//			}
//			cout<<"\n";
//		}
		if(map[ec][er][el]!=0){
			cout<<"Escaped in "<<map[ec][er][el]<<" minute(s).\n";
		}
		else{
			cout<<"Trapped!\n";
		}
	}
}