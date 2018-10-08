#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" "; cerr<<'\n';}
#define TM

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  set< string > process;
  for(int i=0;i<n;i++){
    string input;
    cin>>input;
    for(int j=0;j<input.length();j++){
      for(int k=0;k<3;k++){
        if(input[j]==k+'a')continue;
        char temp = input[j];
        input[j] = k+'a';
        process.insert(input);
        input[j] = temp;
      }
    }  
  }
  
  while(m--){
    string temp;
    cin>>temp;
    if(process.find(temp) != process.end())cout<<"YES"<<'\n';
    else cout<<"NO\n";
  }  

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s\n";
  #endif
}
