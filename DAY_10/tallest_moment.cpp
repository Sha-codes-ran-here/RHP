#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
void solve(){
	int N;cin>>N;
	vector<pair<int,int>> LH(N);
	for(int i=0;i<N;i++){
		int L,H;cin>>H>>L;
		LH[i]=make_pair(H,L);
	}
	sort(LH.begin(),LH.end(),greater<>());
	int prevt=0;
	vector<int>ltarr,htarr;
	for(auto[ht,lt]:LH){
		if(prevt<lt){
			prevt=lt;
			ltarr.push_back(lt);
			htarr.push_back(ht);
		}
	}
	int Q;cin>>Q;
	while(Q--){
		int time;cin>>time;
		auto ub=upper_bound(ltarr.begin(),ltarr.end(),time);
		auto idx=ub-ltarr.begin();
		cout<<htarr[idx]<<endl;
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}