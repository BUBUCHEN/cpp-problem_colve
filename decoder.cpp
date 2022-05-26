#include<iostream>
#include<windows.h>
using namespace std;
void press(int c){
	keybd_event(c,0,0,0);
	keybd_event(c,0,KEYEVENTF_KEYUP,0);
}
int main(){
	string s="vu0 gj bj4u/ jp61u0 a83 y94fu, cj04t/65j/ jp6gj bj4z83 b06c.4w8 ru.4cjo4mp4yji4bk3 ru42k604";
	for(int i=0;i<s.length();i++){
			if(s[i]==','){
				press(188);
				continue;
			}
			else if(s[i]=='.'){
				press(190);
				continue;
			}
			else if(s[i]=='/'){
				press(191);
				continue;
			} 
			if(s[i]<='z'&&s[i]>='a'){
				s[i]-='a'-'A';
			}
			press(s[i]);
			Sleep(40);
		}
		press(13);
		press(13);
		cout<<"enter\n";
	bool gay=1;
	press(16);
	while(getline(cin,s)){
	press(16);
		if(gay){
			gay=0;
			continue;
		}
		for(int i=0;i<s.length();i++){
			gay=1;
			if(s[i]==','){
				press(188);
				continue;
			}
			else if(s[i]=='.'){
				press(190);
				continue;
			}
			else if(s[i]=='/'){
				press(191);
				continue;
			} 
			if(s[i]<='z'&&s[i]>='a'){
				s[i]-='a'-'A';
			}
			press(s[i]);
			Sleep(40);
		}
		if(gay){
			press(13);
			press(13);	
		}
	press(16);	
	}
}
