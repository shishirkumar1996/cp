#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int sum = 0;
  int n,a,b;
  cin>>n>>a>>b;

  vi output;
  output.push_back(1);
  sum = 1;
  
  if(a>0 && a==n-1&&!b){cout<<-1<<endl;return 0;}
  if(!b && n>1){output.push_back(1);n--;}

  for(int i=1;i<n;i++){
    if(b>0){ 
      if(sum+1>50000){cout<<-1<<endl;return 0;}
      output.push_back(sum+1); sum = 2*sum+1; b--;
    }
    else if(a>0){
      int last = output[output.size()-1];
      if(last+1>50000){cout<<-1<<endl;return 0;}
      output.push_back(last+1);
      sum = sum+last+1;
      a--;
    } else output.push_back(1);
  }
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
}
