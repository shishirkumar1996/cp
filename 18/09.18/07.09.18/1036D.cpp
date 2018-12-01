#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n;
  vi first(n);
  for(int i=0;i<n;i++)cin>>first[i];
  cin>>m;
  vi second(m);
  for(int i=0;i<m;i++)cin>>second[i];

  if(n==1 && m==1 && first[0]==second[0]){cout<<1<<endl;return 0;}
  int index1 = 0,index2 = 0;
  lld sum1 =first[index1],sum2=second[index2];
  int ans = 0;
  
  while(index1<n && index2<m){
    if(sum1==sum2){
      ans++;
      index1++;
      index2++;
      if(index1==n) sum1 = 0;else sum1= first[index1];
      if(index2==m) sum2 = 0;else sum2= second[index2];
    }else if(sum1<sum2){
      index1++;
      if(index1<n) sum1 += first[index1];
    } else if(sum1>sum2){
      index2++;
      if(index2<m) sum2 += second[index2];
    }
  }
  if(sum1==0 && sum2==0)cout<<ans<<endl;
  else cout<<-1<<endl;
}
