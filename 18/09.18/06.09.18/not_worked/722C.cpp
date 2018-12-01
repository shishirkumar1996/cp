#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vi input(n+1),process(n),sum(n+1);
  sum[0] = 0;
  for(int i=1;i<=n;i++){
    cin>>input[i];
    sum[i] = sum[i-1]+input[i];
  }
  
  multiset< int > temp,num;
  temp.insert(0);temp.insert(n+1);
  num.insert(-(sum[n]-sum[0]));
  for(int i=0;i<n;i++){
    cin>>process[i];
    multiset< int >::iterator it  = lower_bound(temp.begin(),temp.end(),process[i]);
    lld last = *it;
    lld first = *(prev(it,1));
//    cout<<last<<" "<<first<<endl;
    num.erase(num.find(-(sum[last-1]-sum[first])));
    temp.insert(process[i]);
    num.insert(-(sum[last-1]-sum[process[i]]));
    num.insert(-(sum[process[i]-1]-sum[first]));
    cout<<-(*num.begin())<<"\n";
  }
}
