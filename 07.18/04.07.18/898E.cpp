#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define vi vector< lld >

using namespace std;

int main(){

  
  int n;
  cin>>n;
  
  vi input(n),process;
  int num_zero = 0;
  for(int i= 0;i<n;i++){
    cin>>input[i];
    if(!input[i]) num_zero++;
    int num = pow(input[i],0.5);
    lld dist = min(abs(input[i]-pow(num,2)),abs(input[i]-pow(num+1,2)));
    process.push_back(dist);
  }
  
  lld ans = 0;
  sort(process.begin(),process.end());
  for(int i = 0;i<n/2;i++) ans += process[i];
  
  if(ans==0){
    if(num_zero>n/2)
    ans += (num_zero-n/2);
    int index = n/2;
    while(process[index] == 0&& index<n) ans++,index++;
  }
  cout<<ans<<endl;
    
}
