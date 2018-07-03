#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  int left = 0,right = 0;
  int maxm_left,maxm_right;
  int maxm = 0,num = 0;
  map< int,int > process;
  
  for(int i =0;i<n;i++){
    right = i;
    process[input[right]]++;
    if(process[input[right]]==1){
      num++;
      while(num>k){
        process[input[left]]--;
        if(process[input[left]]==0) num--;
        left++;
      }
    }
//    cout<<left<<" "<<right<<" "<<process[input[right]]<<endl;
    if(maxm<right-left+1)
      maxm = right-left+1,maxm_left =left,maxm_right = right;
  }
  cout<<maxm_left+1<<" "<<maxm_right+1<<endl;
}
