#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';}
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  string input;
  cin>>input;
  int n = input.size();
  vp process(n+1);
  process[0].first = 0;process[0].second = 0;
  for(int i=0;i<n;i++){
    process[i+1].first = process[i].first+(input[i]=='B'?1:-1);
    process[i+1].second = i+1;  
  }
  
  sort(process.begin(),process.end());
//  for(int i=0;i<process.size();i++)cout<<process[i].first<<" "<<process[i].second<<'\n';  

  int x = process[process.size()-1].first;
  int index = lower_bound(process.begin(),process.end(),make_pair(x,-1))-process.begin();
  int a = process[index].second;
  int b = process[0].second;
  if(a>b)swap(a,b);
  a++;
  cout<<a<<" "<<b<<endl;
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif
}


