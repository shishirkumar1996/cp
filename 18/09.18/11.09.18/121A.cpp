#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  vi process;
  for(int i = 1;i<=10;i++){
    for(int j=0;j<(1<<i);j++){
      lld val = 0;
      for(int k=0;k<i;k++) 
        if(((1<<k) & j) == 0)val = val*10+4;
        else val = val*10+7;
      process.push_back(val);     
    }
  }
  sort(process.begin(),process.end());
  lld l,r;
  cin>>l>>r;
 
  int index = lower_bound(process.begin(),process.end(),l)-process.begin();
  lld temp = l;
  lld ans = 0;
  while(temp<=r){
    ans += process[index]*(min(process[index],r)-temp+1);
    temp = min(process[index],r)+1;
    index++;    
  }
  cout<<ans<<endl;
}
