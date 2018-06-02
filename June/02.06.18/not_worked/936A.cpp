#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  lld k,d,t;
  cin>>k>>d>>t;
  
  lld first_time,second_time;
  
  if(k<=d){
    first_time = k,second_time = d-k;
  } else{
    first_time = k,second_time = (d-(k%d))%d;
  }
  
  double first_cook = first_time*1.0/t;
  double second_cook = second_time*1.0/(2*t);
  
  double time = 0;
  double total_cook = first_cook+second_cook;
  double over = 1.0;
  
  time = (first_time+second_time)*floor(1.0/(total_cook));
  over = over-total_cook*floor((1/total_cook));
  cout<<first_cook<<" "<<second_cook<<" "<<" "<<total_cook<<" "<<over<<endl;  
 
  if(over<=first_cook){
    time += over*t;
    over = 0;
  } else {
    time += first_time;
    over -= first_time/t;
  }
  if(over<=second_cook){
    time += over*t*2;
    over = 0;
  }
  cout<<setprecision(15)<< time<<endl;

}
