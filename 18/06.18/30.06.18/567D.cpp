#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n,k,a,m;
  cin>>n>>k>>a>>m;
  
  int max_num_ship  = 0;
  
  vi input(m);
  set< int > process;
  for(int i= 0;i<m;i++){
    cin>>input[i];
    process.insert(input[i]);
  }
  process.insert(0);process.insert(n+1);
  set< int >::iterator it;
  for(it = next(process.begin(),1);it != process.end();it++){
    int num = *it - *prev(it,1);
    max_num_ship += num/(a+1);
  }
  if(max_num_ship >= k){cout<<-1<<endl;return 0;}
  for(int i = m-1;i>=0;i--){
    it = process.find(input[i]);
    int num = *it,n = *next(it,1),p = *prev(it,1);
    max_num_ship += -(n-num)/(a+1) -(num-p)/(a+1)+(n-p)/(a+1);
    if(max_num_ship >= k){cout<<(i+1)<<endl;return 0;}
    process.erase(input[i]);
  }
}
