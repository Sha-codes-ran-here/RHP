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
    
    for(int i = 0; i < rows; i++){
        dp[i][0] = a[i][0];
    }
    for(int j = 1; j < cols; j++){
        for(int i = 0; i < rows; i++){
            int Max = 0;
            for(int k = 0; k < rows; k++){
                if(k != i){
                    Max = max(Max, dp[i][j-1]);
                }
            }
            dp[i][j] = a[i][j] + Max;
        }
    }
    int Max = 0;
    for(int i = 0; i < rows; i++){
        Max = max(Max, dp[i][cols-1]);
    }
    cout << Max << endl;
}