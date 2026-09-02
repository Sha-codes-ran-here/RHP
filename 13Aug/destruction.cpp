#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int find(vector<int> &ldr, int node){
	if(node != ldr[node]){
		ldr[node] = find(ldr, ldr[node]);
	}
	return ldr[node];
}

void join(vector<int> &ldr, int lt, int rt){
	ldr[find(ldr, lt)] = find(ldr, rt);
}

void solve(){
	int N, E;
	cin>>N>>E;
	vector<int> ldr(N+1);
	for(int node = 1;node < N+1;node++)
		ldr[node] = node;
		
	vector<pair<int, pair<int, int>>> edges;
	while(E--){
		int a, b, cost;
		cin>>a>>b>>cost;
		if(cost <= 0){
			join(ldr, a, b);
		}
		else{
			edges.push_back(make_pair(cost, make_pair(a, b)));
		}
	}
	long long reward = 0;
	
	sort(edges.begin(), edges.end());
	
	for(auto[cost, pair] : edges){
		int a = pair.first, b = pair.second;
		if(find(ldr, a) != find(ldr, b)){
			join(ldr, a, b);
		}
		else{
			reward += cost;
		}
	}
	cout<<reward<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}