#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int compare(string a,string b){
  return a+b<b+a;  
}

int main(){
  
  int n;
  cin>>n;
  vs input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  sort(input.begin(),input.end(),compare);
  string output = "";
  for(int i=0;i<n;i++) output += input[i];
  cout<<output<<endl;
}

