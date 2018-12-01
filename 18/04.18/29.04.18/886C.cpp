#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


int calc(int n,vi input){

  map<int,int> process;
  for(int i = 0;i<n;i++)
    process[input[i]]++;
    
  
  int sum = 1;
  for(int i = 0;i<n;i++)
    sum = sum+max(0,process[i]-1);

  return sum;
}
int main(){
  int n;
  cin>>n;
  vi input(n);
  for(int i= 0;i<n;i++)
    cin>>input[i];
  cout<<calc(n,input)<<endl;
}

