#include <limits.h>

int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    long long result = 0;

    // Skip leading whitespaces
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (s[i] == '+' || s[i] == '-') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    // Convert digits
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');

        // Handle overflow
        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;
        }
        if (sign == -1 && -result < INT_MIN) {
            return INT_MIN;
        }

        i++;
    }

    return (int)(sign * result);
}