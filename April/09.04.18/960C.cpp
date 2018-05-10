#include<bits/stdc++.h>


using namespace std;



void calc(long long int x,long long int d){
  
  vector<long long int> vec;
  
  if(d==0)
  {
    cout<<-1<<endl;
    return;
  }
  
  long long int size = 1;
  long long int tot = x;
  long long int a = 1;
  while(tot){
    while(pow(2,size)-1 <= tot){
      vec.push_back(a);
      size++;
    }
    size-=1;  
    tot-=pow(2,size)-1;
    size = 1;
    a  += d+1;
  }
  
  cout<<vec.size()<<endl;
  for(int i =0;i<vec.size();i++)
    cout<<vec[i]<<" ";
  cout<<endl;

}


int main(){
  long long int x,d;
  
  cin>>x>>d;
  calc(x,d);


}


