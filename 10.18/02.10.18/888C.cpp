#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define fr(i,a,b) for(int i=a;i<b;i++)
#define br(i,a,b) for(int i=b-1;i>=a;i--)
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define ber(i,a,b) for(int i=b;i>=a;i--)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define TM

using namespace std;

int main(){

  string input;
  cin>>input;
  vii process(26);
  int n = input.size();
  for(int i=0;i<26;i++)process[i].push_back(-1),process[i].push_back(n);
  for(int i=0;i<n;i++)process[input[i]-'a'].push_back(i);
  
  for(int i=0;i<26;i++)sort(process[i].begin(),process[i].end());
  
  lld ans = (n+2)/2;
  for(int i=0;i<26;i++){
    if(process[i].size()<2)continue;
    lld temp = 0;
    for(int j=1;j<process[i].size();j++)
      temp = max(temp,process[i][j]-process[i][j-1]);
    ans = min(ans,temp);
  }
  cout<<ans<<endl;
  

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
