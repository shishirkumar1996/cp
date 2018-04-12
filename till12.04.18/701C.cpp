#include<bits/stdc++.h>

#define lld long long int
#define vi vector < lld >
#define vii vector < vi >
using namespace std;


int compare(vi a,vi b){

  for(int i = 0;i<a.size();i++){
    if(a[i]<b[i])
      return -1;
  }
  return 1;

}


int calc(int n,string input){
  vii process;
  vi counter;
  map< char, int > present;
  int index = 1;
  for(int i =0;i<n;i++)
    if(!present[input[i]])
    {  
      present[input[i]] = index,index++;
      counter.push_back(0);
    } 
    
  for(int i =0;i<n;i++){

      counter[present[input[i]]-1]++;
    process.push_back(counter);
  }

  int minm = INT_MAX;
  for(int i =0;i<n;i++){
    vi search;
    
    for(int j = 0;j<counter.size();j++)
    {
     
      if(i>0)
        search.push_back(process[i-1][j]+1); 
      else
        search.push_back(1);
    }  
    
      
    int low = i,high = n-1;
    int mid;
    while(low<=high){
      
      mid = (low+high)/2;
      int comp = compare(process[mid],search);
      if(comp < 0)
        low = mid+1;
      else if(comp > 0)
      {
        minm = min(minm,mid-i+1);
        high = mid -1;
      }
    }
  }  
  return minm;  
}

int main(){

  ios::sync_with_stdio(false);
  int n;
  string input;
  cin>>n>>input;
  cout<<calc(n,input)<<endl;
}


