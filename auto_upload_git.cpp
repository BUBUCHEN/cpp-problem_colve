#include<iostream>
#include<windows.h>
#include<ctime>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;
// struct tm {
//   int tm_sec;   // s 0~60 exp:61
//   int tm_min;   // min 0~60 exp:61
//   int tm_hour;  // h 0~23
//   int tm_mday;  // 幾月幾號 1~31
//   int tm_mon;   // month 0~11
//   int tm_year;  // 西元年 since 1900
//   int tm_wday;  // monday~sunday 0~6
//   int tm_yday;  // 1~365
//   int tm_isdst; // 夏令時間
// };
string reverse(string s){
    string ans="";
    for(int d=s.size()-1;d>=0;d--){
        ans+=s[d];
    }
    return ans;
}
string int2str(int a){
    string ans="";
    while(a){
        ans+=a%10+'0';
        a/=10;
    }
    ans=reverse(ans);
    return ans;
}

int main(){
    time_t now=time(0);
    tm *ltm = localtime(&now);
    system("git status");
    system("git add .");
    
    string cmd="git commit -m \"";
    cmd+=int2str(1900+ltm->tm_year);
    cmd+=int2str(1+ltm->tm_mon);
    cmd+=int2str(1+ltm->tm_mday);
    cmd+='"';
    cout<<cmd<<"\n";
    const char* c_s = cmd.c_str();
    system(c_s);

}