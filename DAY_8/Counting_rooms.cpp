#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>&dp,int row,int col){
	dp[row][col]=0;
	if(dp[row-1][col]==1)
		dfs(dp,row-1,col);
	if(dp[row][col-1]==1)
		dfs(dp,row,col-1);
	if(dp[row+1][col]==1)
		dfs(dp,row+1,col);
	if(dp[row][col+1]==1)
		dfs(dp,row,col+1);
}
int main(){
	int R,C;
	cin>>R>>C;
	vector<vector<int>>dp(R+2,vector<int>(C+2,0));
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			char c; cin>>c;
			if(c=='.'){
				dp[i][j]=1;
			}
		}
	}
	int rooms=0;
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			if(dp[i][j]==1){
				rooms++;
				dfs(dp,i,j);
			}
		}
	}
	cout<<rooms;
}