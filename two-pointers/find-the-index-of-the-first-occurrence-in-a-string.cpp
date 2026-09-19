class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0;      // by convention; constraints say m >= 1
        if (m > n) return -1;

        for (int i = 0; i <= n - m; ++i) {
            // Check if substring starting at i matches needle
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) return i;
        }
        return -1;
    }
};