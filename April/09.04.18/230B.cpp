#include<cstdio>
#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

#define MAX 10000001


using namespace std;

bool prime[MAX];

void Sieve(){

  memset(prime,true,sizeof(prime));
  prime[0] = prime[1] = false;
  for(long long int i = 2;i<=MAX;i++){
    if(prime[i] == true){
      for(long long int j = 2*i;j<=MAX;j+=i)
        prime[j] = false;
      
      }
  }
  

}

string calc(long long int n){

  double root = sqrt(n);
  if((long long int)root!=root)
    return "NO";
  
  if(prime[(int)root]== true)
    return "YES";
  else
    return "NO";
}

int main(){
  Sieve();
  int n;
  cin>>n;
  for(int i = 0;i<n;i++)
  {
    long long int t;
    cin>>t;
    cout<<calc(t)<<endl;
  }
  

}



