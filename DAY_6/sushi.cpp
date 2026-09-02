#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll unsigned long long int
void solve(){
  int M,N;
  cin>>M>>N;
  vector<int> a(M),b(N);
  for(int i=0;i<M;i++) cin>>a[i];
  for(int i=0;i<N;i++) cin>>b[i];
  int count=0;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int ai=M-1,bi=N-1;a1>=0 && bi>=0;){
    if(b[bi]<=a[ai]*2){
      count++;bi--; ai--;
    }else{
      bi--;
    }
  }
  cout<<count;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T=1;
  while(T--) solve();
}