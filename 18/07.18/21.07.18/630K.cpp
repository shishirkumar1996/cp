#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  lld div2,div3,div5,div7,div23,div25,
  div27,div35,div37,div57,div235,div237,div357,div257,
  div2357;
  
  div2 = n/2,div3 = n/3,div5=n/5,div7=n/7,
  div27 = n/(2*7),div23 = n/(2*3),div25 = n/(2*5),
  div35 = n/(3*5),div37 = n/(3*7),div57 = n/(5*7),
  div235 = n/(2*3*5),div237 = n/(2*3*7),div357 = n/(3*5*7),div257 = n/(2*5*7);
  div2357 = n/(2*3*5*7);
  
  lld ans = n - (div2+div3+div5+div7)+(div23+div25+div27+div35+div37+div57)-
  (div235+div237+div357+div257)+div2357;
//  cout<<div2+div3+div5+div7<<" "<<div23+div25+div27+div35+div37+div57<<" "<<div235+div237+div357+div257<<endl;
  cout<<ans<<endl;
}
