#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< int,int >
#define vi vector< int >
#define vii vector< vi >
#define vp vector< pr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  faster
  int n,k;
  cin>>n>>k;
   vp input;
   for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    input.push_back(make_pair(a,i));
  }
  sort(input.begin(),input.end());
  
  if((input[0].first>0)||(input[1].first==0)||(k==1 && n>2)){cout<<-1<<endl;return 0;}
  
  int index = 1;
  int num = 0,temp = 0;
  vp output;
  while(index<n){
    while(temp<index && input[index].first-input[temp].first != 1){num=1;temp++;}
    if((temp==index)){cout<<-1<<endl;return 0;}        
    output.push_back(make_pair(input[temp].second,input[index].second));
    num++;
    if(num==k){ temp++;num = 1;}
    index++;
  }
  cout<<output.size()<<'\n';
  for(int i=0;i<output.size();i++)cout<<output[i].first<<" "<<output[i].second<<'\n';
}
