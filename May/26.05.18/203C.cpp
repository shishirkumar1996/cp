#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){
  faster
  lld n,d,a,b;
  cin>>n>>d>>a>>b;
  
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  vp process;
  for(int i =0;i<n;i++)
    process.push_back(make_pair(a*input[i].first+b*input[i].second,i+1));

  sort(process.begin(),process.end());
  
  lld sum = 0;
  int index = 0;
  while(true) 
    if(index == n || sum+process[index].first>d) break;
    else
      sum = sum+process[index].first,index++;
      
  cout<<index<<endl;    
  for(int i = 0;i<index;i++) cout<<process[i].second<<" ";
  cout<<endl;
}
