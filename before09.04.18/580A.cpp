#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


int solution(vector<int> vec)
{
  int maxm = 1;
  int  current = 1;
  for(int i = 1;i<vec.size();i++){
    if(vec[i]<vec[i-1]){
      maxm = max(maxm,current);
      current = 1;
    }
    else 
      current++;
  }
  maxm = max(current,maxm);
  return maxm;
}

int main(){
  int n;
  cin>>n;
  
  vector<int> x;
  for(int i = 0;i<n;i++)
  {
    int a;
    cin>>a;
    x.push_back(a);
  }
  
  cout<<solution(x)<<endl;


}
