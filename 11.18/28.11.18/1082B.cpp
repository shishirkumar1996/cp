#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  int n;
  cin>>n;
  string input;
  cin>>input;
  vp process;
  map< char,int > t;
  t['G'] = 0;t['S']= 1;
  int temp=1,type = -1;
  type = t[input[0]];
  for(int i=1;i<n;i++){
    if(type==t[input[i]]) temp++;
    else{
      process.push_back(make_pair(temp,type));
      temp = 1;
      type = type^1;
    }
  }
  process.push_back(make_pair(temp,type));
  int m = process.size();
  int ans = 0;
  int num = 0;
  for(int i=0;i<m-2;i++){
    if(process[i].second==1)continue;
    num++;
    if(process[i+1].first != 1)continue;
    ans = max(ans,process[i].first+process[i+2].first);
  }
  for(int i=max(0,m-2);i<m;i++){
    if(process[i].second==1)continue;
    num++;
    ans = max(ans,process[i].first);  
  }
  if(num>2) ans++;
  cout<<ans<<'\n';
}
