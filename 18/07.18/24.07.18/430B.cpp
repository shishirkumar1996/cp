#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  int n,k,x;
  cin>>n>>k>>x;
  
  vp process;
  int counter  = 0;
  int last = -1;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(i && a!= last){ 
      process.push_back(make_pair(last,counter));
      counter = 0;
    }
    counter++;last=a;
  }
  process.push_back(make_pair(last,counter));
  
  
  int ans = 0;
  for(int i=0;i<process.size();i++){
    if(process[i].first != x) continue;
    int counter = process[i].second;
    if(counter<2) continue;
    int left = i-1,right = i+1;
    while(left>=0 && right<process.size()){
      if(process[left].first != process[right].first||(process[left].second+process[right].second<3)) break;
      counter += process[left].second+process[right].second;
      left--;right++;
    }
    ans = max(ans,counter);
  }
  cout<<ans<<endl;
}
