#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  
  int n;
  cin>>n;
  vi input(2*n);
  int visited[n+1];
  vp process;
  
  for(int i = 0;i<=n;i++) visited[i] = 0;
  for(int i = 0;i<2*n;i++){ 
    cin>>input[i];
    if(!visited[input[i]]) process.push_back(make_pair(i,input[i]));
    visited[input[i]] = 1;
  }
  int ans = 0;
  for(int i= 0;i<n;i++){
    int temp = process[i].second;
    int index;
    for(int j= i*2+1;j<2*n;j++)
      if(input[j] == temp){index = j;break;}
//    cout<<i<<" "<<process[i].second<<" "<<" "<<i*2+1<<" "<<index<<endl;
    for(int j = index;j>i*2+1;j--) swap(input[j],input[j-1]), ans++;
  }
  cout<<ans<<endl;
  
}
