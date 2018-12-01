#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

struct student{ int sum;int index;};

int compare(student a,student b){
  
  return a.sum>b.sum || (a.sum==b.sum && a.index<b.index);
}

int main(){

  int n;
  cin>>n;
  
  vector< student > input(n);
  for(int i=0;i<n;i++){
    int a,b,c,d,sum = 0;
    cin>>a>>b>>c>>d;
    sum  = a+b+c+d;
    input[i].sum = sum;
    input[i].index = i;
  }
  sort(input.begin(),input.end(),compare);
  
  
  for(int i=0;i<n;i++)
    if(input[i].index==0){cout<<i+1<<endl;return 0;}
  
}
