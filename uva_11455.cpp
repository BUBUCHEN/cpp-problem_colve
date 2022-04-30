#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,ary[4];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ary[0]>>ary[1]>>ary[2]>>ary[3];
		sort(ary,ary+4);
		if(ary[0]==ary[1]&&ary[0]==ary[2]&&ary[0]==ary[3]){
			cout<<"square\n";
		}
		else{
			if(ary[0]==ary[1]&&ary[2]==ary[3]){
				cout<<"rectangle\n";
			}
			else{
				int tot=ary[0]+ary[1]+ary[2]+ary[3];
				if(ary[0]+ary[1]>ary[3]-ary[2]){
					cout<<"quadrangle\n";
				}
				else{
					cout<<"banana\n";
				}
			}
		}
	}
}