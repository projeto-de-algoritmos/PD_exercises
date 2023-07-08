#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int start = 0;
    int max_length = 1;
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            max_length = 2;
        }
    }
    
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                max_length = length;
            }
        }
    }
    
    // Cria uma nova string para armazenar a substring palindrômica mais longa
    char* result = (char*) malloc((max_length + 1) * sizeof(char));
    strncpy(result, s + start, max_length);
    result[max_length] = '\0';
    
    return result;
}

int main() {
    char s[1000];
    scanf("%s",s);
    char* result = longestPalindrome(s);
    printf("%s\n", result);
    
    free(result);
    return 0;
}
