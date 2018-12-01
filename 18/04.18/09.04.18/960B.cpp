#include<bits/stdc++.h>


using namespace std;


int compare(pair< int,int > p1,pair <int,int> p2){
  return ( abs(p1.first - p1.second) > abs(p2.first - p2.second));


}

long long int calc(int a[],int b[],int k1,int k2,int size){
  
  vector< pair<int,int> > vec;
  for(int i =0;i<size;i++){
    pair<int ,int > p;
    p.first = a[i];
    p.second = b[i];
    vec.push_back(p);
  }
  
  sort(vec.begin(),vec.end(),compare);
  
  for(int i = 0;i<vec.size();i++)
    a[i] = vec[i].first,b[i]=vec[i].second;
 
  int i = 0;
  while(k1 || k2){
    if(a[i] > b[i]){
      if(k1)
        a[i]--,k1--;
      else
        b[i]++,k2--;
    }
    else{
      if(k1)
        a[i]++,k1--;
      else
        b[i]--,k2--;
    }
    int max = -1;
    int maxIndex = -1;
    for(int j = 0;j< size;j++)
      if(abs(a[j]-b[j])> max)
        max = abs(a[j]-b[j]),maxIndex = j;
    i = maxIndex;
  }
  
 long long int sum = 0;
 for(int i = 0;i<size;i++){
  sum += (long long int)(a[i]-b[i])*(long long int)(a[i]-b[i]);
 } 
 
 return sum;

}

int main(){
  int n,k1,k2;
  cin>>n>>k1>>k2;
  int a[n],b[n];
  for(int i = 0;i<n;i++)
    cin>>a[i];
  
  for(int i = 0;i<n;i++)
    cin>>b[i];

  cout<<calc(a,b,k1,k2,n)<<endl;  


}



