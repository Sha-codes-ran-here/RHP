#include <iostream>
#include <string>
#include <vector>

// Function to find the longest common substring
std::string longestCommonSubstring(const std::string& s1, const std::string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    // Create a 2D DP table initialized to 0
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    int maxLength = 0; // To store the length of the longest substring
    int endIndex = 0;  // To store the ending index of the longest substring in s1
    
    // Build the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If the characters match, extend the substring length from the previous diagonal
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                
                // Update maxLength and ending index if we found a longer substring
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i; 
                }
            } 
            // If characters do not match, the contiguous streak is broken
            else {
                dp[i][j] = 0;
            }
        }
    }
    
    // Extract the substring using the endIndex and maxLength
    if (maxLength == 0) {
        return ""; // No common substring found
    }
    
    return s1.substr(endIndex - maxLength, maxLength);
}

int main() {
    std::string text1, text2;

    std::cout << "Enter the first string: ";
    std::getline(std::cin, text1);

    std::cout << "Enter the second string: ";
    std::getline(std::cin, text2);

    std::string result = longestCommonSubstring(text1, text2);

    std::cout << "\n--- Results ---\n";
    if (result.empty()) {
        std::cout << "No common substring found." << std::endl;
    } else {
        std::cout << "Longest Common Substring: \"" << result << "\"" << std::endl;
        std::cout << "Length: " << result.length() << std::endl;
    }

    return 0;
}