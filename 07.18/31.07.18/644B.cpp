#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  faster
  int n,x;
  cin>>n>>x;
  
  deque< lld > process;
  for(int i=0;i<n;i++){
    lld a,b;
    cin>>a>>b;
    while(process.size() && process.front() <= a)process.pop_front();
    if(process.size()==x+1) cout<<-1<<" ";
    else{
      if(process.size() == 0){
        cout<<a+b<<" ";
        process.push_back(a+b);
      }
      else{
        cout<<process.back()+b<<" ";
        process.push_back(process.back()+b);
      }
    }
  }
  cout<<endl;
}
