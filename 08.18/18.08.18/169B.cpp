#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input,process;
  cin>>input>>process;
  int n=input.length(),m=process.length();
  sort(process.begin(),process.end());
  reverse(process.begin(),process.end());
  
  for(int i=0,j=0;i<n&&j<m;i++)
    if(input[i]<process[j]){input[i] = process[j];j++;}
  
  cout<<input<<endl;

}
