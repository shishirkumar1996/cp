#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >


using namespace std;


int main(){

  int n;
  cin>>n;
  
  vi input(n);
  vp process(n);
  int dis[n];
  for(int i =0;i<n;i++){
    cin>>input[i];
    process[i] = make_pair(input[i],i);
    dis[i]  = -1;
  }
  
  sort(process.begin(),process.end());
  
  int index = n;
  for(int i = n-1;i>=0;i--){
    pr y = make_pair(input[i],i);
    int x = upper_bound(process.begin(),process.end(),y)-process.begin();
    int temp = x;
    if(x>index){continue;}
    for(;x<index;x++) dis[process[x].second] = (i-process[x].second-1);
    index = temp-1;
//    cout<<i<<" "<<input[i]<<" "<<index<<endl;
  }
  for(int i= 0;i<n;i++) cout<<dis[i]<<" ";
  cout<<endl;
}
