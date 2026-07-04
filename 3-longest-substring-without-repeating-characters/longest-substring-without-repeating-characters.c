#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int lastIndex[128];

    for (int i = 0; i < 128; i++)
        lastIndex[i] = -1;

    int left = 0, maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        if (lastIndex[(int)s[right]] >= left)
            left = lastIndex[(int)s[right]] + 1;

        lastIndex[(int)s[right]] = right;

        if (right - left + 1 > maxLen)
            maxLen = right - left + 1;
    }

    return maxLen;
}