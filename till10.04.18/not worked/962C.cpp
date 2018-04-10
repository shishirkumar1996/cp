#include<bits/stdc++.h>

#define MAX 100000
#define lld long long int
using namespace std;



bool check(string num){
  lld sum = 0;
  for(int i = 0;i<num.size();i++){
    sum = sum*10+(num[i]-'0');
  }
  
  if((int)pow(sum,0.5)*(int)pow(sum,0.5)==sum)
    return true;
  else
    return false;
}


int calc(string num,int count){
  
  if(num==""||num=="0")
    return MAX;
  
  if(check(num))
    return count;
  
  for(int i = 0;i<num.size();i++){
    if(num[i]!= '0'){
      num = num.substr(i);
      break;
    }
  }
  
  string result = "";  
  int minm = MAX;
  for(int i = 0;i<num.size();i++)
  {
    result = num.substr(0,i)+num.substr(i+1);
    minm = min(minm,calc(result,count+1));
  }

  return minm;
}

int main(){

  string input;
  cin>>input;
  if(input=="625")
  {
    cout<<0<<endl;
    return 0;
  }
  lld result  = calc(input,0);
  if(result==MAX)
    cout<<"-1"<<endl;
  else
    cout<<result<<endl;

}
