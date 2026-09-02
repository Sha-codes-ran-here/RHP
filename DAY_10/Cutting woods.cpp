#include<iostream>
#include<set>
using namespace std;
void solve(){
	int L,Q;cin>>L>>Q;
	set<int> st;
	st.insert(0);st.insert(L);
	while(Q--){
		int c,x;cin>>c>>x;
		if(c==1) st.insert(x);
		else{
			auto it=st.upper_bound(x);
			cout<<*it-*(prev(it))<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}