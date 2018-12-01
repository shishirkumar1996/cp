#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  vi output(n+1);
  int x = sqrt(n);
  int y = ceil(1.0*n/x);
  
  int index=n+1;
  int num = 1;
  for(int i=1;i<=y;i++){
    index = max(n+1-i*x,1);
    for(int j=1;j<=x && num<=n;j++){output[index] = num;index++;num++;}
  }
  
  for(int i=1;i<=n;i++)cout<<output[i]<<" ";
  cout<<endl;
}
