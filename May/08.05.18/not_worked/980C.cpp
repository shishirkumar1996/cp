#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


int main(){

  int n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  vi seg;
  for(int i = 0;i<n;i++){
  
    int flag = 0;
    int min_dist = INT_MAX;
    for(int j = 0;j<seg.size();j++){
      if(input[i]<seg[j])
        continue;
      min_dist = min(k,min(min_dist,input[i]-seg[j]+1-k));
      if(input[i]-seg[j]+1 <= k){
        flag = 1;
        cout<<input[i]<<" "<<seg[j]<<endl;
        input[i] = seg[j];
        break;
      }
    
    }
    if(!flag){
      input[i] = max(0,input[i]-min_dist+1);
      seg.push_back(input[i]);
//      cout<<i<<" "<<input[i]<<endl;
    }
  }
  for(int i =0 ;i<input.size();i++)
    cout<<input[i]<<" ";
  cout<<endl;

}

