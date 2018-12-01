#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define NUM 1000007

using namespace std;

bool taken[NUM];

int main(){
  
  faster
  int n;
  cin>>n;
  for(int i=0;i<NUM;i++)taken[i] = false;
  
  for(int i=0;i<n;i++){
    lld a;
    cin>>a;
    taken[a] = true;
  }
  
  vi ans;
  int num = 0;
  for(int i=1;i<=1000000;i++){
    if(taken[i] && taken[1000000-i+1]) num++;
    else if(taken[i])ans.push_back(1000000-i+1);
  }
  num = num/2;
  int index = 1,temp = 0;
  while(temp<num){
    if(!taken[index] && !taken[1000000-index+1]){ 
      temp++;
      ans.push_back(index);
      ans.push_back(1000000-index+1);
    }
    index++;
  }
  cout<<ans.size()<<'\n';
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";cout<<'\n';
}
