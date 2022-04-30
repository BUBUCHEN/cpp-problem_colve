#include<iostream>
using namespace std;
int cond(string inp){
	bool fin=0;
	string a1="Get_Assist",a2="Get_Kill";
	for(int i=0;i<a1.length();i++){
		if(a1[i]!=inp[i]){
			fin=1;
			break;
		}
	}
	if(!fin){
		return 1;
	}
	fin=0;
	for(int i=0;i<a2.length();i++){
		if(a2[i]!=inp[i]){
			fin=1;
			break;
		}
	}
	if(!fin){
		return 2;
	}
	return 3;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int con,n,k=0,d=0,a=0;
	string inp;
	cin>>n;
	con=0;
	getline(cin,inp);
	for(int i=0;i<n;i++){
		getline(cin,inp);
		int re=cond(inp);
		if(re==1){
			a++;
		}
		else if(re==2){
			k++;
			con++;
			if(con<3){
				cout<<"You have slain an enemie.\n";
			}
			else if(con==3){
				cout<<"KILLING SPREE!\n";
			}
			else if(con==4){
				cout<<"RAMPAGE~\n";
			}
			else if(con==5){
				cout<<"UNSTOPPABLE!\n";
			}
			else if(con==6){
				cout<<"DOMINATING!\n";
			}
			else if(con==7){
				cout<<"GUALIKE!\n";
			}
			else{
				cout<<"LEGENDARY!\n";
			}
		}
		else{
			if(con<3){
				cout<<"You have been slained.\n";
			}
			else{
				cout<<"SHUTDOWN.\n";
			}
			con=0;
			d++;
		}
	}
	cout<<k<<"/"<<d<<"/"<<a<<"\n";
}