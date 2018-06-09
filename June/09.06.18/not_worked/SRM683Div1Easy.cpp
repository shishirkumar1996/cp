#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

class MoveStones{
  
  public:
    long get(vi a,vi b){
      
      int n = a.size();
      long sum_a = 0,sum_b = 0;
      for(int i = 0;i<a.size();i++) sum_a += a[i],sum_b += b[i];
      if(sum_a != sum_b) return -1;

      long long ans = 0;
      for(int i = 0;i<a.size();i++){
        
        int diff = 1;
        while(a[i]<b[i]){
          
          if(a[(i+diff)%n] > b[(i+diff)%n]){
            long long change = min(a[(i+diff)%n]-b[(i+diff)%n],b[i]-a[i]);
            ans += change*diff;a[i] += change;b[(i+diff)%n] -= change;
          }
          if(a[(i-diff+n)%n] > b[(i-diff+n)%n]) {
            long long change = min(a[(i-diff+n)%n]-b[(i-diff+n)%n],b[i] - a[i]);
            ans += change*diff; a[i]+= change;b[(i-diff+n)%n] -= change;
          }
          cout<<i<<" "<<ans<<" "<<diff<<endl;
          diff++;
        }
      }
      return ans;
    }

};

int main(){

  MoveStones m;
  int size = 15;
  vi a,b;
  int x[] = {7081371, 338721489, 786021164, 481381772, 109561094, 972164404, 47123795, 99605190, 716334155, 152659319, 135559580, 848333181, 973462908, 22801953, 313319489};
  int y[] = {716334155, 972164404, 22801953, 338721489, 481381772, 973462908, 786021164, 135559580, 7081371, 848333181, 109561094, 99605190, 152659319, 47123795, 313319489};
  for(int i =0;i<size;i++){a.push_back(x[i]);b.push_back(y[i]);}
  for(int i = 0;i<size;i++)cout<<a[i]<<" "<<b[i]<<endl;
  
  cout<<m.get(a,b)<<endl;
}
