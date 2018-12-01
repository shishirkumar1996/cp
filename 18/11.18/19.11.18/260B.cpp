#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31};
  string input;
  cin>>input;
  int n = input.length();
  map< string,int > process;
  for(int i=0;i<=n-10;i++){
    string temp = input.substr(i,10);
    int flag = 1;
    for(int j=0;j<10;j++){
      if(j==2||j==5)continue;
      if(temp[j]=='-'){ flag = 0;continue; }
    }
    if(temp[2]!='-' || temp[5]!='-') flag = 0;
    if(!flag)continue;
    int day = (temp[0]-'0')*10+(temp[1]-'0');
    int month = (temp[3]-'0')*10+(temp[4]-'0');
    int year = (temp[6]-'0')*1000+(temp[7]-'0')*100+(temp[8]-'0')*10+(temp[9]-'0');
    if(month==0||month>12)continue;
    if(day == 0 || day > days[month-1])continue;
    if(year<2013||year>2015)continue;
    process[temp]++;
  }
  map< string,int >::iterator it;
  string ans;
  int maxm = 0;
  for(it = process.begin();it != process.end();it++)
    if((it->second)>maxm){ maxm = it->second;ans = it->first; }
  cout<<ans<<endl;
}
