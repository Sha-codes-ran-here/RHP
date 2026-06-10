#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max and std::reverse

// Function to find and return the longest common subsequence
std::string longestCommonSubsequence(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    // Create a 2D DP table initialized to 0
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    // Step 1: Build the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If characters match, add 1 to the diagonal value
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            // If they don't match, carry over the maximum value from either top or left
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Step 2: Reconstruct the string from the DP table
    std::string lcs = "";
    int i = m, j = n;
    
    // Start from the bottom-right corner and trace back
    while (i > 0 && j > 0) {
        // If characters match, it's part of the LCS
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        } 
        // Move in the direction of the larger value
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up
        } 
        else {
            j--; // Move left
        }
    }
    
    // The string was built backwards, so we must reverse it
    std::reverse(lcs.begin(), lcs.end());
    
    return lcs;
}

int main() {
    std::string text1, text2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, text1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, text2);

    std::string result = longestCommonSubsequence(text1, text2);

    std::cout << "\n--- Results ---\n";
    if (result.empty()) {
        std::cout << "No common subsequence found." << std::endl;
    } else {
        std::cout << "Longest Common Subsequence: \"" << result << "\"" << std::endl;
        std::cout << "Length: " << result.length() << std::endl;
    }

    return 0;
}