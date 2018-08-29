#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >
#define MAXM (lld)(1e10)

using namespace std;

int main(){
  
  faster
  int k,n;
  cin>>n>>k;
  
  vp process;
  for(int i=0;i<n;i++){
    lld a,b;
    cin>>a>>b;
    process.push_back(make_pair(a,-1));
    process.push_back(make_pair(b,1));
    
  }
  sort(process.begin(),process.end());
  vp temp_output,output;
  
  lld start = MAXM;
  int temp = 0;
  for(int i=0;i<process.size();i++){
    if(process[i].second==-1)temp++;
    else temp--;
    if(temp==k && start==MAXM)start = process[i].first;
    if(temp==k-1 && start != MAXM){
      temp_output.push_back(make_pair(start,process[i].first));
      start = MAXM;
    }
  }
  
  int left = 0,right = 1;
  while(left<temp_output.size()){
    while(right<temp_output.size() && temp_output[right].first==temp_output[right-1].second)right++;
    output.push_back(make_pair(temp_output[left].first,temp_output[right-1].second));
    left = right;right++;
  }
  cout<<output.size()<<endl;
  for(int i=0;i<output.size();i++)
    cout<<output[i].first<<" "<<output[i].second<<"\n";    
}
