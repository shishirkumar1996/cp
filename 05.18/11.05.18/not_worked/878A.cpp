#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  
  int zeroes[10],ones[10];
  memset(zeroes,0,sizeof(zeroes));
  
  
  for(int j = 0;j<10;j++) ones[j] = 1;
  
  for(int i = 0;i<n;i++){
  
    char ct;
    int num;
    cin>>ct>>num;
    
    int val[10];
    memset(val,10,sizeof(val));
    for(int j=0;j<10;j++)
      val[j] = num%2, num = num/2;
    
    for(int j = 0;j<10;j++)
      if(ct=='|') zeroes[j] = zeroes[j] | val[j], ones[j] = ones[j] | val[j];
      else if(ct=='^') zeroes[j] = zeroes[j] ^ val[j],ones[j] = ones[j]^val[j];
      else if(ct=='&') zeroes[j] = zeroes[j] & val[j],ones[j] = ones[j]&val[j];

    cout<<endl;
    for(int j = 0;j<10;j++) cout<<zeroes[j];
    cout<<" ";
    for(int j = 0;j<10;j++) cout<<ones[j];
    cout<<endl;
  }
    int pr_or=0,pr_and=0,pr_xor=0;
    for(int j = 0;j<10;j++)
      if(zeroes[j]==1 && ones[j] == 1) pr_or = pr_or | (1<<j);
      else if(zeroes[j] ==  0 && ones[j] == 0)  pr_and = pr_and | (1<<j);
      else if(zeroes[j]==1 && ones[j] == 1) pr_xor = pr_xor | (1<<j);
    
    pr_and = 1023-pr_and;
    
    cout<<3<<endl;
    cout<<"| "<<pr_or<<endl;
    cout<<"^ "<<pr_xor<<endl;
    cout<<"& "<<pr_and<<endl;

}
