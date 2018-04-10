#include<bits/stdc++.h>
#include<map>
#define lld long long int
#define vlld vector < lld >
#define pr pair < lld,int>

using namespace std;


bool compare(pair <int,int> a,pair<int,int> b){

  return a.second < b.second;

}


void calc(int n,vlld input){

  int minm = INT_MAX;
  priority_queue< pair <lld,int> ,vector<pair <lld,int> >,std::greater<pair <lld,int> > > pq;
  for(int i = 0;i<n;i++){
    pq.push(make_pair(input[i],i));
  }

  vector< pair<lld,int> > result;
  pr top,second_top;
  while(pq.size() >= 2){
    top = pq.top();
    cout<<top.first<<endl;
    pq.pop();
    second_top = pq.top();
    pq.pop();
    if(top.first != second_top.first)
      break;
    
    pq.push(make_pair(2*second_top.first,second_top.second));
  
  }

  result.push_back(top);
  result.push_back(second_top);
  for(int i=0;i<pq.size();i++)
  {
    pr top = pq.top();
    pq.pop();
    result.push_back(top);
  }
  
  sort(result.begin(),result.end(),compare);
  vector<lld> pr_result;
  for(int i =0;i<result.size();i++)
    pr_result.push_back(result[i].first);
  
  cout<<pr_result.size()<<endl;
  for(int i = 0;i<pr_result.size();i++)
    cout<<pr_result[i]<<" ";
  cout<<endl;  

}


int main(){
  int n;
  cin>>n;
  vlld input;
  for(int i =0;i<n;i++)
  {
    lld num;
    cin>>num;
    input.push_back(num);
  }
  calc(n,input);
  
}
