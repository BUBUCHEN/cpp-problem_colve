#include "vector"
#include "iostream"
#include "cmath"
#include "ctime"
#include <stdlib.h>
using namespace std;
#define int long long
int f(int x){
	x = x%30000;
	return floor(((x * x) + 87 - (int)floor(x / 3) - (x % 7)) % 48763);
}
int g(int x){
	x = x%30000;
    return floor(((x - 1) * (x + 2) + (int)floor(x / 4) - (x % 3)) % 48763);
}
int q(int x){
	x = x%30000;
    x = x + x * x + (449*x)%48763;
    return floor((((x % 3) + (x % 5) + (x % 7) + (x % 2) + (x % 11) + (x % 101)) % 48763));
}
int seed;
double test(string s){
	vector<int> answer_array = {4, 8, 7, 6, 3, 4, 8, 7, 6, 3, 4, 8, 7, 6, 3, 4, 8, 7, 6, 3, 4, 8, 7, 6, 3};
	int tot=0;
	for(int i=0;i<s.size();i++){
		tot+=(int)s[i];
		answer_array.push_back((int)s[i]);
	}
	int temp=tot;
	tot=(f(temp) + g(temp) + q(temp)) % 48763;
	for(int i=0;i<answer_array.size();i++){
		int swap_seed = (seed+f(tot)+g(tot)+q(tot));
		if(i%3==0){
			swap_seed=(swap_seed + f(answer_array[i]+ seed) ) % 48763;
		}
		else if (i % 3 == 1) {
			swap_seed = (swap_seed + g(answer_array[i])) % 48763;
		}
		else {
			swap_seed = (swap_seed + q(answer_array[i])) % 48763;
		}
		int px=i;
		int py=(f(swap_seed) + g(swap_seed + seed) + q(swap_seed + seed)) % answer_array.size();
		int tp=answer_array[py];
		answer_array[py] = answer_array[px];
		answer_array[px] = tp;
	}
	int score=0;
	for(int i=0;i<answer_array.size();i++){
		if(i%3==0){
			score = (score+f(answer_array[i]))%48763;
		}
		else if(i%3==1){
			score = (score+g(answer_array[i]+seed))%48763;
		}
		else{
			score = (score+q(answer_array[i]+seed))%48763;
		}
	}

	double t_ans=(double)score*1.0;
	return t_ans/487.63;
}
signed main(){
	time_t now=time(0);
	tm *ltm = localtime(&now);
	// cout<<ltm->tm_year+1900<<" "<<ltm->tm_mon+1<<" "<<ltm->tm_mday<<"\n";
	seed=(f(ltm->tm_year+1900)+g(ltm->tm_mon+1)+q(ltm->tm_mday))%48763;
	
	int mode=0;
	cout<<"mode 1:test the string on today  2:calculate the answer for today :";
	cin>>mode;
	cout<<"\n";
	mode=2;
	if(mode==1){
		cout<<"請輸入string\n";
		string s;
		cin>>s;
		cout<<test(s);
	}
	else if(mode==2){
		// range 32~126
		// -> 0~94 (+32)
		bool no_ans=1;
		string test_s;
		double rslt;
		while(no_ans){
			srand( time(NULL) );
			int leng=rand()%25;
			test_s="";
			for(int i=0;i<leng;i++){
				int rd=rand()%95;
				rd+=32;
				test_s+=(char)rd;
			}
			rslt=test(test_s);
			if(rslt>=95.0)no_ans=0;
		}
		cout<<rslt<<" "<<test_s<<"\n";
	}
	else{
		cout<<"errrrrr...";
		return 87;
	}
}
