#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define pr pair< int, int >
#define vp vector< pr >
using namespace std;


int main(){
  
  lld n,x1,x2;
  cin>>n>>x1>>x2;
  vi input(n);
  for(int i =0;i<n;i++)
    cin>>input[i];
  vp process;
  for(int i = 0;i<n;i++)
    process.push_back(make_pair(input[i],i+1));
  
  sort(process.begin(),process.end());
  
  int flag = 0;
  if(x1>x2)
    flag = 1;
//  cout<<x1<<endl;

  lld num1 = 0,sum1 = 0,sum2= 0,num2 = 0;
  lld min1 = process[n-1].first;
//  cout<<process[0].first<<" "<<process[0].second<<endl;
  lld index = n-1;
  while(sum1 < x2 && index>=0){
    num1++;
    sum1 = num1*process[index].first;
    index--;
//    cout<<sum1<<endl;
  }
  if(num1==-1){
    cout<<"No"<<endl;
    return 0;
  }
  num2 = 0;
  lld min2 = process[index].first;
  while(index>=0 && sum2 < x1){
    num2++;
    sum2 = num2 * process[index].first;
    index--;
  }
  cout<<sum1<<" "<<sum2<<endl;
  if(sum2<x1){
    cout<<"No"<<endl;
    return 0;
  }
  else{
    cout<<"Yes"<<endl;

    if(flag){
      
      cout<<num2<<" "<<num1<<endl;
    
      for(int i =n-num1-1;i>=n-num1-num2;i--)
        cout<<process[i].second<<" ";
      cout<<endl;
      
      for(int i =n-1 ;i>=n-num1;i--)
        cout<<process[i].second<<" ";
      cout<<endl;
    }
    else{
      cout<<num1<<" "<<num2<<endl;
      
      for(int i =n-1;i>=n-num1;i--)
        cout<<process[i].second<<" ";
      cout<<endl;
      
      for(int i =n-num1-1 ;i>=n-num1-num2;i--)
        cout<<process[i].second<<" ";
      cout<<endl;
    }
  
  }
  return 0;

}
