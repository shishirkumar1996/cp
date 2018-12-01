#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  vi input(n+1);
  for(int i = 1;i<=n;i++) cin>>input[i];
  
  vp output;
  set< lld > freq;
  pr segment;
  segment.first = 1;
  
  for(int i = 1;i<=n;i++){
    if(freq.count(input[i])){
      segment.second = i;
      output.push_back(segment);
      segment.first = i+1;
      freq.clear();
    } else
      freq.insert(input[i]);
  }

  if(output.size()>0 && output[output.size()-1].second != n)
    output[output.size()-1].second = n;
    
  if(output.size()){  
    cout<<output.size()<<endl;
    for(int i = 0;i<output.size();i++)cout<<output[i].first<<" "<<output[i].second<<endl;
  }
  else
    cout<<-1<<endl;

}
