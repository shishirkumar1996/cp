#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e20)

using namespace std;

lld val(string s,int a,int b){
  lld ans = 0;
  for(int i=b;i>=a;i--)ans = ans*10+(s[i]-'0');
  return ans;

}

int main(){
  
  faster
  lld num[67][67];
  lld n;string input;
  cin>>n>>input;
  reverse(input.begin(),input.end());
  int s = input.size();
  input = " "+input;
  for(int i=0;i<=s;i++)for(int j=0;j<=s;j++) num[i][j] = MAXM;
  
  num[0][0] = 0;

  for(int j=1;j<=s;j++){ // number of powers
    for(int i=j;i<=s;i++){
      for(int k=j;k<=i;k++){
       if(num[k-1][j-1]==MAXM) continue;
        lld temp = val(input,k,i);
        if(i-k>=20||pow(n,j-1)>MAXM)continue;
        num[i][j] = min(num[i][j],num[k-1][j-1]+temp*(lld)pow(n,j-1));
        cout<<i<<" "<<j<<" "<<" "<<k<<" "<<num[i][j]<<" "<<temp<<endl;
      }
    }
  }

  lld minm = MAXM;
  for(int i=1;i<=s;i++)
  minm= min(minm,num[s][i]);

  cout<<minm<<endl;
}
