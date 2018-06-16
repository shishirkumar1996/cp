#include<bits/stdc++.h>
#include<map>

using namespace std;



string calc(string input){
  
  map<char,int> num;
  
  
  for(int i = 0;i<input.length()-1;i++){
    num[input[i]]++;
  
    if(input[i] >input[i+1])
      return "NO";
  }
  num[input[input.length()-1]]++;
  
  if(num['a']==0 || num['b']==0 || num['c']==0)
    return "NO";
  if(num['a']==num['c'] || num['b'] == num['c'])
    return "YES";
  
  return "NO";

}


int main(){

  string input;
  cin>>input;
  cout<<calc(input)<<endl;

}
