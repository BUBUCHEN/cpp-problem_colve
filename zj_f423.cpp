#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if(n%2==0){
		n--;
	}
	cout<<(1+n)*(n+1)/4;
}