#include<bits/stdc++.h>

using namespace std;

int compare(pair<long long int , long long int > a, pair <long long int,long long int> b){
  return (a.first < b.first)||(a.first==b.first && a.second < b.second);

}



long long int calc(int n,vector< pair <long long int ,long long int > > day){

  
  sort(day.begin(),day.end(),compare);
  
  long long int days = 0;
  
  for(int i = 0;i<n;i++){
    if(days <= day[i].second)
      days = day[i].second;
    else
      days  = day[i].first;
  }
  
  return days;
}

int main(){

  int n;
  cin>>n;
  vector< pair<long long int, long long int> > input;
  for(int i = 0;i<n;i++){
    long long int a ,b;
    cin>>a>>b;
    pair < long long int,long long int> p;
    p.first = a;
    p.second = b;
    input.push_back(p); 
  }
  
  cout<<calc(n,input)<<endl;

}
