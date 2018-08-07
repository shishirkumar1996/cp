#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

struct sparse_table { 
  vii m;
  int n;
  sparse_table(vi arr){
    m.push_back(arr);
    n = arr.size();
    for(int k=1;(1<<k)<=n;k++){
      m.push_back(vi(n-(1<<k)+1));
      for(int i=0;i<n-(1<<k)+1;i++)
        m[k][i] = min(m[k-1][i],m[k-1][i+(1<<(k-1))]);
    }
  }
  int query(int l,int r){
    int k=0;
    while(1<<(k+1)<=r-l+1)k++;
    return min(m[k][l],m[k][r-(1<<k)+1]);
  }
};

int main(){
  
  int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
  vi arr;
  for(int i=0;i<9;i++)arr.push_back(a[i]);
  
  sparse_table s(arr);
  cout << s.query(0, 4) << endl;
  cout << s.query(4, 7) << endl;
  cout << s.query(7, 8) << endl;
  return 0;
}

