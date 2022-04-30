#include<iostream>
using namespace std;
int main(){
	int n,now=0,c;
	cin>>n;
	while(cin>>c){
		if(c==0){
			return 0;
		}
		if(c%n==0){
			cout<<c/n<<"\n";
		}
		else{
			cout<<n-c%n<<"\n";
		}
	}
}