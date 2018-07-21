#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int lcs(string a,string b){
  
  int m=a.length(),n = b.length();
  
  int ans[m+1][n+1];
  for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++) 
      if(i==0||j==0) ans[i][j] = 0;
      else if(a[i-1] == b[j-1]) ans[i][j]= ans[i-1][j-1]+1;
      else ans[i][j] = max(ans[i-1][j],ans[i][j-1]);

  return ans[m][n];
}

int main(){
  string a,b;
  cin>>a>>b;
  cout<<lcs(a,b)<<endl;
}
