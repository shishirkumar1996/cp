#include<bits/stdc++.h>
#define vi vector< int >

using namespace std;

int main(){

  int n;
  cin>>n;
  char input[n];
  for(int i = 0;i<n;i++)cin>>input[i];
  for(int i = 1;i<=n;i++) if(n%i==0) reverse(input,input+i);

  for(int i=0;i<n;i++)cout<<input[i];
  cout<<endl;
}
