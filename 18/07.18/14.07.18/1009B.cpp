#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){

  string input;
  cin>>input;
  int zero_after = 0,zero=0,one = 0,two = 0,first = INT_MAX,zero_before = 0;
  for(int i=0;i<input.length();i++){
    if(input[i] == '1') one++;
    else if(input[i] == '2') {two++; first = min(first,i);}
    else if(input[i] == '0') {zero++;if(first == INT_MAX) zero_before++;}
  }
  string output = "";
  for(int i=0;i<zero_before;i++)output += "0";
  for(int i=0;i<one;i++) output += "1";
  for(int i = first;i<input.length();i++){
    if(input[i] == '0') output += "0";
    else if(input[i] == '2') output += "2";
  }  
  cout<<output<<endl;
}
