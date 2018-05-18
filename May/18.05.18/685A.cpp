#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
using namespace std;

int main(){

  faster
  lld n,m;
  cin>>n>>m;
  int count = 0;
  
  lld temp = n-1;
  while(temp) {count++; temp = temp/7;}
  
  count = max(1,count);
  temp = m-1;
  while(temp) { count++;temp = temp/7;}
  
  count = max(2,count);
  if(count > 7){ cout<<0<<endl;return 0;}
  
  lld ans = 0;
  for(int i = 0;i<n;i++){
    
    for(int j = 0;j<m;j++){

      map< lld, int > occur;
      occur[0] = count;
      lld temp = i;
      while(temp){int rem = temp%7;occur[rem]++;occur[0]--;temp = temp/7; }
      
      
      temp = j;
      while(temp){int rem= temp%7;occur[rem]++;occur[0]--;temp = temp/7;}
      
      int flag = 1;
      for(int k = 0;k<7;k++)
        if(occur[k]>1) flag = 0;
      if(flag)   ans++;
      
      occur.clear();
    }
  
  }
  cout<<ans<<endl;

}
