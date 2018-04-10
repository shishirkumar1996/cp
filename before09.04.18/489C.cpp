#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;

string val(int m,int s){

  string output = "";
  if(m*9 < s)
    return "-1";
  
  if(m!=1 && s==0)
    return "-1";
  
  int tot = s;
  int num_digit = m;
  for(int i = 9;i>=1;i--)
  {
    int digit = tot/i;
    for(int j = 0;j<digit;j++)
      output += char(i+'0'),tot-= i,num_digit--;

  }
  
  for(int i = 0;i<num_digit;i++)
    output += char(0+'0');  
  return output;
}


int main(){

  int m,s;
  cin>>m>>s;
  string output = val(m,s);
  
  if(output=="-1")
    cout<<output<<" "<<output<<endl;
  else
  {
    string out = output;
    if(output[m-1]=='0'){
      for(int i = m-1;i>=0;i--){
        if(output[i]!='0'){
          output[m-1]  = '1';
          output[i] -= 1;
          break;
        }
      }
    }
    string reverse = "";
    for(int i = output.length()-1;i>=0;i--)
      reverse += output[i];
    cout<<reverse<<" "<<out<<endl;
  }
}
