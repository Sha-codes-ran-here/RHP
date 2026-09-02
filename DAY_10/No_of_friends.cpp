#include<iostream>
#include<vector>
#include<set>
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
	vector<int> friends(N+1);
	for(int i=0;i<N+1;i++){
		friends[i] = i;
	}
	for(int i=0;i<M;i++){
		int A,B;
		cin>>A>>B;
		union_set(friends,A,B);
	}
	vector<int> edges(N+1);
	vector<int> ldr(N+1);
	for(int i=1;i<N+1;i++){
		for(int j=1;j<N+1;j++){
			if(i==find(friends,j)){
				ldr[i]+=1;
			}
		}
		cout<<ldr[i];
	}
	
}