#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vectro< int >

using namespace std;




int main(){

  faster
  lld fact[20];
  fact[0] = fact[1] = 1;
  for(lld i=2;i<20;i++)fact[i] = i*fact[i-1];
  int num[10];
  for(int i=0;i<10;i++)num[i] = 0;
  string input;
  cin>>input;
  lld ans = 0;
  set< string > temp;
  int k = input.length();
  for(int i = 0;i<k;i++) num[input[i]-'0']++;
  
  for(int i=1;i<= (1<<k);i++){
    string process;
    int ct[10];
    for(int j=0;j<10;j++)ct[j] = 0;
    int digit = 0;
    for(int j=0;j<k;j++)if( i & (1<<j)){
      process += input[j];
      ct[input[j]-'0']++;
      digit++;
    }
    int flag = 1;
    for(int j=0;j<10;j++)if(num[j] && !ct[j]){flag = 0;break;}
    if(!flag)continue;
    sort(process.begin(),process.end());
    if(temp.count(process))continue;
    temp.insert(process);
    
    lld x = fact[digit];
    for(int j=0;j<10;j++) x /= fact[ct[j]];
    if(ct[0]){
      ct[0]--;
      lld y = fact[digit-1];
      for(int j=0;j<10;j++) y /= fact[ct[j]];
      x = x-y;
    }
    ans += x;
  }
  cout<<ans<<endl; 
}
