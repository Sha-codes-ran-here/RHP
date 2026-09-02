#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(){
	int N; cin>>N;
	vector<int>nos(N);
	for(int i=0;i<N;i++){
		int k;cin>>k;
		nos[i]=k;
	}
	sort(nos.begin(),nos.end());
	long long int res=0;
	for(int i:nos){
		auto lb=lower_bound(nos.begin(),nos.end(),i);
		auto ll=lb-nos.begin();
		auto up=upper_bound(nos.begin(),nos.end(),i);
		auto ul=nos.end()-up;
		res+=(ll*ul);
	}
	cout<<res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}