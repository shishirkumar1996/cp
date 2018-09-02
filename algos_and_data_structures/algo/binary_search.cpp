#include<bits/stdc++.h>

using namespace std;


int n;

int binarySearch(int arr[],int x){
  int l=0,r=n-1;
  while(l<=r){
    int mid = (l+r)/2;
    if(arr[mid]==x)return mid;
    if(arr[mid]<x) l =mid+1;
    else r =mid-1;
  }
  return -1;  
}

int main(){

  int arr[] = {2,3,4,10,40};
  n = 5;
  int x =10;
  int result = binarySearch(arr,x);
  if(result==-1)cout<<"element not present"<<endl;
  else cout<<"element is present at index "<<result<<endl;  

}
