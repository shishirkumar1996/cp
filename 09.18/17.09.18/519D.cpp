#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >

using namespace std;

int main(){


  int a[26];
  for(int i=0;i<26;i++)cin>>a[i];
  
  string input;
  cin>>input;
  
  lld sum[input.size()+1];
  sum[0] = 0;
  
  vii process(26);
  for(int i=1;i<=input.size();i++){ 
    sum[i] = sum[i-1]+(a[input[i-1]-'a']); 
    process[input[i-1]-'a'].push_back(i);
  }
//  for(int i=1;i<=input.size();i++)cout<<sum[i]<<endl;
  
  lld ans  = 0;
  for(int i=0;i<26;i++){
    map< lld,lld > first,last;
    for(int j=0;j<process[i].size();j++){
      int pt = process[i][j];
      ans += first[sum[pt-1]];
      first[sum[pt]]++;
      last[sum[pt-1]]++;      
    }  
  }
  cout<<ans<<endl;
}
