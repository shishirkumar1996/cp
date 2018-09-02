#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int n;
vi input,tail;

int ceil_index(int l,int r,int key){
  while(r-l>1){
    int m = (l+r)/2;
    if(tail[m]>=key) r= m; else l=m;
  }
  return r;
}

int lis(){

  if(input.size()==0)return 0;
  int length = 1;
  tail[0] = input[0];
  for(int i=1;i<n;i++){
    if(input[i]<tail[0]) tail[0] =input[i];
    else if(input[i]> tail[length-1]) tail[length++] = input[i];
    else tail[ceil_index(-1,length-1,input[i])] = input[i];
  }
  return length;
}

int main(){

  cin>>n;
  input.resize(n);
  tail.resize(n);
  for(int i=0;i<n;i++){cin>>input[i];tail[i] = 0;}
  cout<<lis()<<endl;  
}
