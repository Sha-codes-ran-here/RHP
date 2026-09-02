#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int find(vector<int>& arr, int idx) {
    if (idx == arr[idx]) {
        return idx;
    }
    return find(arr, arr[idx]);
}
void union_set(vector<int>& arr, int node1, int node2) {
    node1 = find(arr,node1);
    node2 = find(arr,node2);
    if (node1 != node2) {
        arr[node1] = node2;
    }
}
int main(){
	int N,M;
	cin>>N>>M;
	vector<int> dis(N+1);
	int rew=0;
	vector<pair<int,pair<int,int>>> edges;
	for(int i=0;i<M;i++){
		int A,B,C;
		cin>>A>>B>>C;
		edges.push_back(C,make_pair(A,B));
	}
	sort(edges.begin(),edges.end());
	for(auto[cost,pair]:edges){
		auto[n1,n2]=p;
		if(find(dis,n1)!=find(dis,n2)){
			union_set(dis,n1,n2);
		}
		else{
			rew+=cost;
		}
	}
}
	