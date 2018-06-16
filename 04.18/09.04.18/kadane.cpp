#include<cstdio>
#include<iostream>



using namespace std;


void mcs(int a[],int n){
  
  int max_so_far = 0;
  int max_sum = 0;
  
  for(int i = 0;i<n;i++)
  {
    max_sum = (max_sum+a[i]>0) ? max_sum+a[i] : 0;
    
    if(max_sum > max_so_far)
      max_so_far = max_sum;
  }
  cout<<max_so_far<<endl;
  
}



int main(){
  
  cout<<"Enter the size of the array"<<endl;
  int n;
  cin>>n;
  int a[n];
  cout<<"Enter the numbers"<<endl;
  for(int i = 0;i<n;i++)
    cin>>a[i];
    
  mcs(a,n);

}
