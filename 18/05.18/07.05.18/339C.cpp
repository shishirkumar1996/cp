#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr  pair< int ,int >
#define ppr pair< int, pr >

using namespace std;

int last[1001],n;
vector<char > input;

int dfs(int step,int diff){
  if(step>n){
    cout<<"YES"<<endl;
    for(int i = 1;i<=n;i++)
      cout<<last[i]<<" ";
    cout<<endl;
    return 1;
  }
  
  for(int i = diff+1;i<=10;i++)
    if( i != last[step-1] && (input[i]-'0') > 0){
      last[step] = i;
      if(dfs(step+1,i-diff))
        return 1;
    }
  return 0;
}


int main(){
  
  input.resize(11);
  for(int i = 1;i<=10;i++)
    cin>>input[i];
  cin>>n;
  last[0] = 0;

  if(!dfs(1,0))
    cout<<"NO"<<endl;
}
