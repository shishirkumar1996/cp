#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< lld ,lld >
#define vp vector< pr >


using namespace std;

int main(){
  
  faster
  lld n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  vp answer;
  for(int i = 0;i<n;i++){
    if(input[i].first != 1)
      continue;
    
    stack< lld > process;
    process.push(i);
    while(process.size()){
    
    
      lld front = process.top();
      input[front].first--;
      process.pop();
      lld next = input[front].second;
      answer.push_back(make_pair(front,next));
      input[next].second = input[next].second^front;
      input[next].first--;
      if(input[next].first==1)
        process.push(next);
    }
  }
  cout<<answer.size()<<endl;
  for(int i= 0;i<answer.size();i++)cout<<answer[i].first<<" "<<answer[i].second<<endl;
}
