#include<bits/stdc++.h>
#define pr pair< int,int >
#define vp vector< pr >
#define vi vector< int >
#define NUM 100007

using namespace std;

int block;   //to represent block size;
vp query;
vi arr;
int n;//array size
int m;//query size

bool compare(pr x,pr y){
  if(x.first != y.first) return x.first<y.first;
  return x.second<y.second;
}

void query_result(){
 block = (int)sqrt(n);
 sort(query.begin(),query.end(),compare);
 int currL=0,currR=0,currSum = 0;
 
 for(int i=0;i<m;i++){
  int l=query[i].first,r = query[i].second;
  while(currL<l) currSum -= arr[currL],currL++;
  while(currL>l) currSum += arr[currL-1],currL--;
  while(currR<=r) currSum += arr[currR],currR++;
  while(currR>r+1) currSum -= arr[currR-1],currR--;
 
  cout<<" Sum of ["<<l<<", "<<r<<"] is "<<currSum<<endl;
 }
}

int main(){
  n = 9,m = 3;
  int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  int q[][2] = {{0, 4}, {1, 3}, {2, 4}};
  for(int i=0;i<n;i++) arr.push_back(a[i]);
  for(int i=0;i<m;i++)query.push_back(make_pair(q[i][0],q[i][1]));
  
  query_result();
  return 0;
}
