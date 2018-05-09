#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  vi first(n);
  for(int i = 0;i<n;i++)  cin>>first[i];
  cin>>n;
  vi second(n);
  for(int i =0;i<n;i++)  cin>>second[i];
  sort(first.begin(),first.end());
  sort(second.begin(),second.end());
  
  int maxm = INT_MIN;
  int a,b;
  
  a = 2*first.size(),b = 2*second.size();
  maxm = a - b;
  for(int i = 0;i<first.size();i++){
    if(i>0 && first[i] == first[i-1])
      continue;
    lld search = first[i]-1;
    int index = upper_bound(second.begin(),second.end(),search)-second.begin();
    
    int inter_a,inter_b;
    inter_a = i*2+(first.size()-i)*3;
    inter_b = index*2+(second.size()-index)*3;
    if(inter_a-inter_b > maxm || (inter_a-inter_b == maxm && inter_a > a))
      a=inter_a,b=inter_b,maxm = inter_a- inter_b;
  
  }
  cout<<a<<":"<<b<<endl;


}
