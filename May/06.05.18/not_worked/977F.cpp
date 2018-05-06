#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< int >

using namespace std;

int main(){
  faster
  int n;
  cin>>n;
  
  vi input(n+1);
  for(int i = 1;i<=n;i++)
    cin>>input[i];
  
  map<lld, lld  > seq,index;
  int last[n+1];
  for(int i = 1;i<=n;i++){
    last[i] = i;
    if(index[input[i]] == 0) index[input[i]]= i;
  }

  for(int i = 1;i<=n;i++){
    if((index[input[i]-1] == 0 || index[input[i]-1] > i) && seq[input[i]]==0)
      seq[input[i]] = 1;
    else
      seq[input[i]] = seq[input[i]-1]+1;
      
    if(seq[input[i]] > 1)
      last[i] = index[input[i]-1];
//    cout<<i<<" "<<last[i]<<" "<<seq[input[i]]<<endl;
  }
  
  lld max = 0,max_index = 0;
  for(int i = 1;i<=n;i++)
    if(max<seq[input[i]])
      max = seq[input[i]],max_index = i;

  vi output;
  lld ind = max_index;
  while(true){
//    cout<<ind<<endl;
    output.push_back(ind);
    if(ind==last[ind])
      break; 
    ind = last[ind];
    
  }
  
  cout<<output.size()<<endl;
  for(int i = output.size()-1;i>=0;i--)
    cout<<output[i]<<" ";
  cout<<endl;
}
