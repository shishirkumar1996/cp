#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  lld h,n;
  cin>>h>>n;
  
  lld num = (pow(2,h)-1)+n;
  vi process;
  while(num>1){
    int x= num%2;
    process.push_back(x);
    num = num/2;
  }
  reverse(process.begin(),process.end());
  lld ans = 0;
  int height = h;
  if(process[0] == 1) ans += 1+(pow(2,height)-1); else ans += 1;
  height--;
  for(int i = 1;i<process.size();i++){
    if(process[i] == process[i-1]) ans += 1+(pow(2,height)-1); else ans += 1;
    height--;
  }
  cout<<ans<<endl;
}
