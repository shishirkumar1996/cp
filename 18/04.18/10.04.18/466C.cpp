#include<bits/stdc++.h>
#include<vector>


using namespace std;


long long int calc(vector<long long int>input,int n){
  
  if(n<3)
    return 0;
  
  vector<long long int>cumsum;
  long long int sum = 0;
  vector<int> firstpt;
  vector<int> secondpt;
  
  
  for(int i = 0;i<n;i++)
    sum+= input[i],cumsum.push_back(sum);
  
  for(int i = 0;i<n;i++)
  {
    if(cumsum[i]==sum/3 && i<n-2)
      firstpt.push_back(i);
    if(cumsum[i]==2*sum/3 && i<n-1 && i>0)
      secondpt.push_back(i);
   } 
   if(sum%3 != 0)
    return 0;
  long long int count = 0;
  for(int i =0;i<firstpt.size();i++){
    int low = 0,high= secondpt.size()-1;
    int mid;
    while(low<=high){
      mid = (low+high)/2;
      if(secondpt[mid] < firstpt[i])
        low = mid+1;
      else if(secondpt[mid] >firstpt[i])
        high = mid-1;
      else if(secondpt[mid]==firstpt[i])
        break;
    }
    
    if(firstpt[i]<secondpt[mid])
      count+= secondpt.size()-1-(mid-1);
    else if(firstpt[i]>=secondpt[mid])
      count += (secondpt.size()-1-mid);
  
  }
  
  return count;

}


int main(){
  int n;
  cin>>n;
  vector<long long int>input;
  for(int i = 0;i<n;i++){
    int x;
    cin>>x;
    input.push_back(x);
  }

  cout<<calc(input,n)<<endl;
}
