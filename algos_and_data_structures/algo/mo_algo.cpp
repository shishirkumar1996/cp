#include<bits/stdc++.h>
#define pr pair< int,int >
#define vp vector< pr >
#define vi vector< int >
#define NUM 100007

using namespace std;

int block;   //to represent block size;

struct Query{int L,R;};

vector< Query >query;
vi arr;
int n;//array size
int m;//query size

bool compare(Query x,Query y){
  
  if(x.L/block != y.L/block)return x.L/block<y.L/block;
  return x.R<y.R;
}

void query_result(){
 block = (int)sqrt(n);
 sort(query.begin(),query.end(),compare);
 int currL=0,currR=0,currSum = 0;
 
 for(int i=0;i<m;i++){
  int l=query[i].L,r = query[i].R;
  while(currL<l) currSum -= arr[currL],currL++;
  while(currL>l) currSum += arr[currL-1],currL--;
  while(currR<=r) currSum += arr[currR],currR++;
  while(currR>r+1) currSum -= arr[currR-1],currR--;
 
  cout<<" Sum of ["<<l<<", "<<r<<"] is "<<currSum<<endl;
 }
}

int main(){
  n = 9,m = 3;
  query.resize(m);
  int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
  int q[][2] = {{0, 4}, {1, 3}, {2, 4}};
  for(int i=0;i<n;i++) arr.push_back(a[i]);
  for(int i=0;i<m;i++){query[i].L= q[i][0];query[i].R=q[i][1];}
  
  query_result();
  return 0;
}
