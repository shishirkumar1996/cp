#include<bits/stdc++.h>
#define NUM 100007
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

vp items;
int n;

bool cmp( pr a, pr b){
  
  double r1= (double)a.first/a.second;
  double r2 = (double)b.first/b.second;
  return r1>r2;
}

double fractionalKnapsack(int W){
  
  sort(items.begin(),items.end());
  int cur_weight = 0;
  double ans = 0.0;
  for(int i=0;i<n;i++){
    if(cur_weight+items[i].second<=W){ cur_weight+= items[i].second;ans+=items[i].first;}
    else {
      int remain = W-cur_weight;
      ans += items[i].first*((double)remain/items[i].second);
      break;
    }
  }
  return ans;
}

int main(){
  
  int W=50;
  n = 3;
  items.resize(n);
  int arr[][2] =  {{60,10},{100,20},{120,30}};
  for(int i=0;i<n;i++)items[i].first = arr[i][0],items[i].second = arr[i][1];
  
  cout<<"maximum value we can obtain = "<<fractionalKnapsack(W)<<endl;
  
}
