#include <iostream>
#include <vector>
using namespace std;

int main(){
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> a(rows, vector<int>(cols));
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> a[i][j];
        }
    }
    
    vector<vector<int>> dp(rows, vector<int>(cols));
    
    for(int j = 0; j < cols; j++){
        dp[0][j] = a[0][j];
    }
    for(int i = 1; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int Max = 0;
            for(int k = 0; k < cols; k++){
                if(k != j){
                    Max = max(Max, dp[i-1][k]);
                }
            }
            dp[i][j] = a[i][j] + Max;
        }
    }
    int Max = 0;
    for(int j = 0; j < cols; j++){
        Max = max(Max, dp[rows-1][j]);
    }
    cout << Max << endl;
}