#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  if(n%2==0){cout<<"NO"<<endl;return 0;}
  
  vp output;
  output.push_back(make_pair(1,2));
  
  int num = n+1;
  int counter = 3;
  for(int i=1;i<=(n-1)/2;i++){
    
    output.push_back(make_pair(1,counter));
    output.push_back(make_pair(1,counter+1));
    
    for(int j=counter+2;j<counter+num;j++)output.push_back(make_pair(counter,j));
    
    for(int j=counter+1;j<counter+num-1;j++)
      for(int k=j+1;k<counter+num;k++)output.push_back(make_pair(j,k));
    counter += num;
  }
  
  for(int i=1;i<=(n-1)/2;i++){
    output.push_back(make_pair(2,counter));
    output.push_back(make_pair(2,counter+1));
    for(int j=counter+2;j<counter+num;j++)output.push_back(make_pair(counter,j));
    
    for(int j=counter+1;j<counter+num-1;j++)
      for(int k=j+1;k<counter+num;k++)output.push_back(make_pair(j,k));
    counter += num;
  }
  cout<<"YES"<<endl;
  cout<<counter-1<<" "<<output.size()<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i].first<<" "<<output[i].second<<endl;
}
