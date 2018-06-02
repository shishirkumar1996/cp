#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  lld sum[n+1];
  vi input(n+1);
  sum[0] = 0;
  for(int i = 1;i<=n;i++){
    cin>>input[i];
    sum[i] = sum[i-1]+input[i];
  }
  int s,f;
  cin>>s>>f;
  f--;
  
  lld maxm = 0,max_index = 0;
  for(int i = 1;i<=n;i++){
    
    int left = s-i+1;
    if(left<=0) left += n;
    int right = f-i+1;
    if(right<=0) right+= n;
    
    lld temp = 0;
    if(right<left) temp = sum[n]-sum[left-1]+sum[right];
    else temp = sum[right]-sum[left-1];
    if(temp>maxm) maxm = temp,max_index = i;   
    
  }
  cout<<max_index<<endl;
  
}
