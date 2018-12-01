#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  string input;
  cin>>input;
  
  int index = -1;
  for(int i=0;i<n-1;i++)if(input[i]>input[i+1]){ index = i;break; }
  if(index==-1)index= n-1;
  for(int i=0;i<n;i++)if(i!=index)cout<<input[i];cout<<'\n';
}
