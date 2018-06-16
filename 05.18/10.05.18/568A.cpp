#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define NUM (lld)(1e7+7)

using namespace std;


bool prime[NUM];
int palin(lld a){

  lld b = a,c = 0;
  while(a)
    c = c*10+(a%10),a = a/10;
  return b==c;
}

int main(){

  faster
  int p,q;
  cin>>p>>q;
  memset(prime,true,sizeof(prime));
  
  prime[1] = false;
  lld ans = 0;
  for(lld i = 2;i<NUM;i++){
    if(!prime[i])
      continue;
      for(lld j = 2*i;j<NUM;j+=i)
        prime[j] = false;
  }
  lld num_prime = 0,num_palin = 0;  
  for(lld i = 1;i<NUM;i++){
    if(prime[i]) num_prime++;
    if(palin(i)) num_palin++;
    
    
    if(num_prime*q <= num_palin*p) ans = i;
      
  }
  if(ans)
    cout<<ans<<endl;
  else
    cout<<"Palindromic tree is better than splay tree"<<endl;
}
