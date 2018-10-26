#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
    
  
  lld t;
  cin>>t;
  for(int j=0;j<t;j++){
    lld start = -1;
    string input;
    cin>>input;
    lld n = input.length();
    int flag = 1;
    for(lld i=0;i<n;i++){
      if(input[i]=='.')continue;
      lld temp = max(0ll,i-(input[i]-'0'));
      if(temp<=start){ cout<<"unsafe\n";flag = 0;break;}
      start = min(n-1,i+(input[i]-'0'));      
    }
    if(flag){cout<<"safe\n";}
  }
}
