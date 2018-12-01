#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int compare(string a,string b){
  return (b.size() != a.size() && b.find(a)<=b.size());
}


int main(){
  
  faster
  int n;
  cin>>n;
  vs input(n);
  
  for(int i = 0;i<n;i++) cin>>input[i];
  sort(input.begin(),input.end(),compare);
  
  for(int i = 1;i<n;i++){
    if(input[i].find(input[i-1])> input[i].size()){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  for(int i = 0;i<n;i++)cout<<input[i]<<endl;
}
