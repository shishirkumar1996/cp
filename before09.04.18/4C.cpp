#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;


map<string,int> username;

string result(string input){

  username[input]++;
  if(username[input]==1)
    return "OK";
  else
  {
    int x= username[input]-1;
    string buffer = "";
    while(x){
      int  y = x%10;
      buffer =  (char)((y)+'0')+buffer;
      x = x/10;
    }
    return input+buffer;
  }
}

int main(){
  int n;
  cin>>n;  
  for(int i = 0;i<n;i++){
    string input;
    cin>>input;
    cout<<result(input)<<endl;
  }
}
 
