#include<iostream>
using namespace std;
int main(){
	int n,a,b;
	double ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		b-=a;
		ans=((double)b/(double)a)*100.0;
		if(ans<0){
			ans-=0.00001;
		}
		else if(ans>0){
			ans+=0.00001;
		}
		printf("%.2f",ans);
		if(ans>=10.0||ans<=-7.0){
			cout<<"% dispose\n";
		}
		else{
			cout<<"% keep\n";
		}
	}
}