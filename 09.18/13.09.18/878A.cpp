#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int n;
  cin>>n;
  char x[n];
  int y[n];
  
  for(int i=0;i<n;i++)cin>>x[i]>>y[i];
  int zero = 0,one = 1023;
  for(int i=0;i<n;i++){
    if(x[i]=='|') zero = (zero|y[i]),one = (one|y[i]);
    if(x[i]=='^') zero = (zero^y[i]),one = (one^y[i]);
    if(x[i]=='&') zero = (zero&y[i]),one  = (one&y[i]);
  }
  int xored = 0,anded = 1023,ored = 0;
  for(int i=0;i<10;i++){
    int first = (1<<i)&zero;
    int second = (1<<i)&one;
    if(!first && !second) anded -= (1<<i);
    if(first && second) ored += (1<<i);
    if(first && !second) xored += (1<<i);
  }
  cout<<3<<endl;
  cout<<"^ "<<xored<<endl;
  cout<<"| "<<ored<<endl;
  cout<<"& "<<anded<<endl;

}
