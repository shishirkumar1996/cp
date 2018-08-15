#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vector< string > input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  int ans[26][26];
  for(int i=0;i<26;i++)for(int j=0;j<26;j++)ans[i][j] = 0;
  
  for(int i=0;i<n;i++){
    int first = input[i][0]-'a';
    int last = input[i][input[i].length()-1]-'a';
    for(int j=0;j<26;j++)
      if(ans[j][first])
        ans[j][last] = max(ans[j][last],ans[j][first]+(int)input[i].length());
    
    ans[first][last] = max(ans[first][last],(int)input[i].length());
  }
  int sol = 0;
  for(int i=0;i<26;i++) sol = max(sol,ans[i][i]);
  cout<<sol<<endl;
}
