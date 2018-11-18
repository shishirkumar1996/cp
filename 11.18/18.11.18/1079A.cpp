#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int process[101];
  for(int i=0;i<=100;i++)process[i] = 0;
  
  int n,k;
  cin>>n>>k;
  int maxm = 0,num=0;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(!process[a])num++;
    process[a]++;
    maxm = max(maxm,process[a]);    
  }
  int temp = (maxm+k-1)/k;
  temp = temp*k;
  cout<<temp*num-n<<'\n';
  
}
