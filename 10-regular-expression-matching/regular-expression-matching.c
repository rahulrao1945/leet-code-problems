#include <stdbool.h>
#include <string.h>

int dp[21][21];

bool solve(char *s, char *p, int i, int j) {
    if (dp[i][j] != -1)
        return dp[i][j];

    if (p[j] == '\0')
        return dp[i][j] = (s[i] == '\0');

    bool firstMatch = (s[i] != '\0') &&
                      (s[i] == p[j] || p[j] == '.');

    if (p[j + 1] == '*') {
        dp[i][j] = solve(s, p, i, j + 2) ||
                   (firstMatch && solve(s, p, i + 1, j));
    } else {
        dp[i][j] = firstMatch && solve(s, p, i + 1, j + 1);
    }

    return dp[i][j];
}

bool isMatch(char* s, char* p) {
    memset(dp, -1, sizeof(dp));
    return solve(s, p, 0, 0);
}