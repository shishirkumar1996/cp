#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';


using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  map< lld, int > process;
  vi temp;
  int group_num  = 1;
  vii output(n+1);
  for(int i=0;i<n;i++){
    lld a;
    cin>>a;
    int index = lower_bound(temp.begin(),temp.end(),-a)-temp.begin();
    if(index==temp.size()){
      temp.push_back(-a);
      process[a] = group_num++;
    } else {
      process[a] = process[-temp[index]];
      temp[index] = -a;
    }
    output[process[a]].push_back(a);
  }
  for(int i=1;i<group_num;i++){
    for(int j=0;j<output[i].size();j++)cout<<output[i][j]<<" ";cout<<'\n';
  }
}
