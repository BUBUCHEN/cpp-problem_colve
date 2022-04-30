#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string a,b;
	while(cin>>a){
		bool count[100]={};
		for(int i=0;i<a.length();i++){
			if(a[i]<='Z'&&a[i]>='A'){
				count[(a[i]+('a'-'A'))-'a']=!count[(a[i]+('a'-'A'))-'a'];
			}
			else if(a[i]<='z'&&a[i]>='a'){
				count[a[i]-'a']=!count[a[i]-'a'];
			}
		}
		bool diedjg=0,br=0;
		for(int i=0;i<=26;i++){
			if(count[i]&&diedjg){
				cout<<"no...\n";
				br=1;
				break;
			}
			if(count[i]){
				diedjg=1;
			}
		}
		if(!br){
			cout<<"yes !\n";
		}
	}
}