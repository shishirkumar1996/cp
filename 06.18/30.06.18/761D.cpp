#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int main(){
  
  int n;
  lld l,r;
  cin>>n>>l>>r;
  vi input(n);
  vp process(n);
  for(int i=0;i<n;i++)cin>>input[i];
  for(int i = 0;i<n;i++){
    lld a,b;
    cin>>a;
    process[i] = make_pair(a,i);
  }

  sort(process.begin(),process.end());
  
  lld diff = -abs(r-l);
  
  vi output(n);
  for(int i = 0;i<n;i++){
    int index = process[i].second;
    diff = max(diff,l-input[index]);

    if(input[index]+diff>r){cout<<-1<<endl;return 0;}
    output[index] = input[index]+diff;
    diff++;
  }
  
  for(int i=  0;i<n;i++)cout<<output[i]<<" ";
  cout<<endl;
}
