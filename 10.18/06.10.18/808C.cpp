#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  int n,w;
  cin>>n>>w;
  vp input(n);
  for(int i=0;i<n;i++){
    cin>>input[i].first;
    input[i].second = i;
  }
  sort(input.begin(),input.end());

  vi output(n,0);
  for(int i=0;i<n;i++){
    if(w<(input[i].first+1)/2){cout<<-1<<endl;return 0;}
    output[input[i].second] = (input[i].first+1)/2;
    w -= output[input[i].second];
  }
  int index = n-1;
  while(w && index>=0){
    int x = min(w,input[index].first-output[input[index].second]);
    output[input[index].second] += x;
    w -= x;
    index--;
  }
  if(w){ cout<<-1<<endl;return 0;}
  
  for(int i=0;i<n;i++)cout<<output[i]<<" "; cout<<endl;
}
