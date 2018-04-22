#include<bits/stdc++.h>
#define vc vector< char >
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


char calc(int n,vc input){

  queue<int> r_times;
  queue<int> d_times;
  
  for(int i = 1;i<=n;i++)
    if(input[i]=='D')
      d_times.push(i);
    else
      r_times.push(i);
  
  while(r_times.size() && d_times.size()){
    int first_d = d_times.front();
    int first_r = r_times.front();
    d_times.pop();
    r_times.pop();
    if(first_d < first_r)
      d_times.push(first_d+n);
    else
      r_times.push(first_r+n);  
  }
  
  if(r_times.size())
    return 'R';
  else
    return 'D';

}


int main(){
  faster
  int n;
  cin>>n;
  vc input(n+1);
  for(int i = 1;i<=n;i++)
    cin>>input[i];

  cout<<calc(n,input)<<endl;
}
