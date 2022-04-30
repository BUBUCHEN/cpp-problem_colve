#include<iostream>
#include<algorithm>
using namespace std;
int n,k,map[60000];
int test(int dis){
	int kp=0,t,i;
	for(int t=0;t<n;){
		i=map[t];
		i+=dis;
		kp++;
		if(kp>k){
			return 0;
		}
		if(i>=map[n-1]){
			return 1;
		}
		for(;t<n-1;){
			if(i>=map[t]){
				t++;
			}
			else{
				break;	
			}
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>map[i];
	}
	sort(map,map+n);
	for(int s=1,e=(map[n-1]-map[0])/k+1;;){//why +1 : 怕有數字在做整數除法時被刪掉 
		int mid,ans;
		mid=(s+e)/2;
		if(s==e){
			cout<<s;
			return 0;
		}
		ans=test(mid);	
		if(ans==0){
			s=mid+1;// why +1 : because 'mid' 一定不合，所以拉高下限 
		}
		else{
			e=mid;// why not +1 : because 'mid' 一定會合理，但不知道是不是最小值，所以保留 
		}	
	}
}
//worst case (pos_max-pos_min)/k
//best case dis=1