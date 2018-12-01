#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){

  int n,a,b;
  cin>>n>>a>>b;
  
  if(a>b) swap(a,b);
  vi output(n);
  int num_a  = n/a,num_b = 0;
  while(num_a >=0) if((n-num_a*a)%b==0) break; else num_a--;
  
  num_b = (n-num_a*a)/b;
    
  if(num_a == -1){cout<<-1<<endl;return 0;}
  
  int index = 1;
  for(int i = 0;i<num_a;i++)
    for(int j = 0;j<a;j++)
      output[i*a+j] = (i*a+1)+(j+1)%a;


  index = num_a*a;
  for(int i=  0;i<num_b;i++)
    for(int j = 0;j<b;j++)
      output[index+i*b+j] = (index+i*b+1)+(j+1)%b;    
    
  
  for(int i =0;i<n;i++)cout<<output[i]<<" ";
  cout<<endl;
  
}
