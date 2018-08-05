#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

struct fenwick_tree{
  int n;
  vi data;
  fenwick_tree(vi _data): n(_data.size()), data(vi(n)){
    for(int i=0;i<n;i++)update(i,_data[i]);
  }
  
  void update(int at,int by){
    while(at<n){ data[at] += by; at |= at+1;}
  }
  
  int query(int at){
    int res = 0;
    while(at>=0){res += data[at];at = (at&(at+1))-1;}
    return res;
  }
  int rsq(int a,int b){ return query(b)-query(a-1);}
};

int main(){

  vi data;
  int n=5;
  int arr[] = {1,2,3,4,5};
  for(int i=0;i<n;i++) data.push_back(arr[i]);
  
  fenwick_tree x(data);
  cout<<x.query(4)<<endl;
  x.update(1,5);
  cout<<x.query(4)<<endl;
  
}
