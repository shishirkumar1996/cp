#include<bits/stdc++.h>

#define lli long long int
#define vi vector< int >
#define vii vector< vi >

using namespace std;


double fact(int n){
  
  if(n==0||n==1)
    return 1;
  return n*fact(n-1);
}


float calc(string original,string sent){

  int unknown = 0;
  int sum1 = 0,sum2 = 0;
  for(int i = 0;i<original.size();i++)
  {
    if(original[i]=='+')
      sum1++;
    else if(original[i]=='-')
      sum1--;
      
    if(sent[i]=='+')
      sum2++;
    else if(sent[i]=='-')
      sum2--;
    else
      unknown++;
  }
  
  int diff = abs(sum1 - sum2);
  if(diff > unknown || (unknown-diff)%2 != 0)
    return 0;
  
  int first = 0,second = 0;   //representing the signs
  second = (unknown-diff)/2;
  first = unknown - second;
  
  return (fact(unknown)/(fact(first)*fact(second))/(pow(2,unknown)));  

}

int main(){

  string original,sent;
  cin>>original>>sent;
  
  cout<<setprecision(15)<<calc(original,sent)<<endl;
  
}



