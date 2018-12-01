#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  string a;
  vi process;
  cin>>a;
  process.push_back(1);
  cin>>a;
  while(a != "="){
    string b;
    cin>>b;
    if(a=="+") process.push_back(1);
    else process.push_back(-1);
    cin>>a;
  }
  lld n;
  cin>>n;
  
  lld sum=0;
  lld temp[process.size()];
  for(int i=0;i<process.size();i++){
    if(process[i]==1){temp[i] = n; sum += n; }
    else { temp[i] =  -1; sum -= 1; }
  }
  if(sum<n){ cout<<"Impossible\n"; return 0; }
  
  int index = 0;
  while(index< process.size() && sum>n){
    while(index< process.size() && temp[index]==-1)index++;
    if(index==process.size())break;
    lld diff = min(sum-n,temp[index]-1);
    sum -= diff;
    temp[index] -= diff;
    index++;
  }
  index = 0;
  while(index< process.size() && sum>n){
    while(index<process.size() && temp[index]>0)index++;
    if(index==process.size())break;
    lld diff = min(sum-n,n-(-temp[index]));
    sum -= diff;
    temp[index] -= diff;
    index++;
  }
  if(sum>n){ cout<<"Impossible\n"; return 0; }
  
  cout<<"Possible\n";
  cout<<temp[0]<<" ";
  for(int i=1;i<process.size();i++){
    if(temp[i] < 0)cout<<"- "<<(-temp[i])<<" ";
    else cout<<"+ "<<temp[i]<<" ";
  }
  cout<<"= "<<n;
  cout<<'\n';
}
