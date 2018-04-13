#include<bits/stdc++.h>
#define lld long long int

using namespace std;


int binary_search(int search, int ones[],int i){
  
   int low = 0,high = i;
   int mid;
    while(low<=high){
      mid = (low+high)/2;
      if(ones[mid]<search)
        low = mid+1;
      else if(ones[mid] > search)
        high = mid-1;
      else if(ones[mid]==search){
        if(mid > 0 && ones[mid] == ones[mid-1])
          high = mid-1;
        else
          break;
      }
    }
    return mid;    
}


lld calc(int n,string input){


  int ones[input.size()];
  memset(ones,0,input.size());
  for(int i = 0;i<input.size();i++)
    if(input[i]=='1')
      ones[i] = (i==0)?1:ones[i-1]+1;
    else
      ones[i] = (i==0)?0:ones[i-1];  
      
  lld result = 0;
  
  for(int i = 0;i<input.size();i++){
    lld present = ones[i];
    lld last,one_before_last;  // the diff between these two will be added
    if(ones[i]<n)
      continue;
    if(ones[i]==n){
      one_before_last = -1;
    }
    else{
      int search = ones[i]-n;
      one_before_last = binary_search(search,ones,i);
    }
    int search = ones[i]-n+1;
    last = binary_search(search,ones,i);
    
    result += (last-one_before_last);
    
  }

  return result;
}


int main(){
  
  ios::sync_with_stdio(false);
  int n;
  string input;
  cin>>n>>input;
  cout<<calc(n,input)<<endl;

}
