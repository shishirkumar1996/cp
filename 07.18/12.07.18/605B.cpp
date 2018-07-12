#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define pr pair< lld, lld >
#define ppr pair< pr, int >
#define vp vector< pr >
#define vpp vector< ppr >

using namespace std;

int main(){


  int n,m;
  cin>>n>>m;
  
  vpp input(m);
  for(int i = 0;i<m;i++){ 
    cin>>input[i].first.first>>input[i].first.second;
    input[i].second  = i;
    input[i].first.second ^= 1;
  }
  
  sort(input.begin(),input.end());
  
  vp output(m);
  
  int first = 3,second = 1;
  int num = 1;
  for(int i=0;i<m;i++){
    int index = input[i].second;
    if(input[i].first.second == 0){
      output[index] = make_pair(num,num+1);
      num++;
    } else {
      if(second>=first-1) first++,second = 1;
//      cout<<i<<" "<<first<<" "<<second<<endl;
      if(first > num){
//      cout<<num<<" "<<first<<" "<<second<<" "<<i<<endl;
      cout<<-1<<endl;return 0;}
      output[index] = make_pair(first,second);
      second++;
    }
  
  }
  for(int i=0;i<output.size();i++) 
    cout<<output[i].first<<" "<<output[i].second<<endl;

}
