#include<bits/stdc++.h>
#define NUM 100007

using namespace std;

int totient[NUM];

void tot(int n){

  for(int i=1;i<=n;++i)totient[i] = i;
  for(int i=2;i<=n;i++)
    if(totient[i]==i)
      for(int j=i;j<=n;j+=i) totient[j] -= totient[j]/i;
}

int main(){
  int n = 100;
  tot(n);
  for(int i=1;i<=n;i++)cout<<totient[i]<<" ";
  cout<<endl;
}
