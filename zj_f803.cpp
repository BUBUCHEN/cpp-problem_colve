#include<iostream>
#include<vector>
using namespace std;
bool bp[10000000]={};
int main(){
	vector<int> prime;
	int s,t,tp=0;
	int n,p;
	cin>>n>>p;
	for(int i=2;i<=n;i++){
		if(!bp[i]){
			prime.push_back(i);
		}
		for(vector<int>::iterator h=prime.begin();h!=prime.end();h++){
			if(*h*i>n){
				break;
			}
			bp[*h*i]=1;
			if(i%*h==0){
				break;
			}
		}
	}
	int q,count=prime.size();
	for(int i=0;i<p;i++){
		cin>>q;
		for(int s=0,e=count-1;;){
			int mid=(s+e)/2;
			if(prime[mid]==q){
				cout<<mid+1<<"\n";
				break;
			}
			if(prime[mid]>q){
				e=mid-1;
			}
			else{
				s=mid+1;
			}
		}
	}
}