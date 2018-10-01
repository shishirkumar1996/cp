#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

double dist(lld f_x,lld f_y,lld s_x,lld s_y){
  return sqrt((f_x-s_x)*(f_x-s_x)+(f_y-s_y)*(f_y-s_y));
}

int main(){

  lld first_x,first_y,second_x,second_y,t_x,t_y;
  int n;
  cin>>first_x>>first_y>>second_x>>second_y>>t_x>>t_y;
  vector< pair<double,int> > first,second;
  cin>>n;
  double ans = 0;
  vector< double > trash_dist(n);
  vp input(n);
  for(int i=0;i<n;i++){
    cin>>input[i].first>>input[i].second;
    trash_dist[i] = dist(input[i].first,input[i].second,t_x,t_y);
    ans += 2*trash_dist[i];
    double first_dist = dist(input[i].first,input[i].second,first_x,first_y);
    double second_dist=dist(input[i].first,input[i].second,second_x,second_y);
    first.push_back(make_pair(first_dist-trash_dist[i],i));
    second.push_back(make_pair(second_dist-trash_dist[i],i));
  }
  sort(first.begin(),first.end());
  sort(second.begin(),second.end());
  
  if(first[0].second != second[0].second){
    pair< double,int > a = first[0],b = second[0];
    ans += a.first+b.first;
  }
  else{
    pair<double,int> a_one = first[0],a_two = first[1],b_one = second[0],b_two = second[1];
    double first_temp = a_one.first+b_two.first;
    double second_temp = a_two.first+b_one.first;
    double minm = min(first_temp,second_temp);
    ans += minm;
  }
  cout<<setprecision(15)<<ans<<endl;
}
