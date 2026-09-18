#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = static_cast<int>(s.size());

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find the first and last occurrence of every character.
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }

        vector<pair<int, int>> intervals; // {right, left}

        // Build the smallest valid interval for every character.
        for (int c = 0; c < 26; ++c) {
            if (last[c] == -1) {
                continue; // Character does not occur in s.
            }

            int left = first[c];
            int right = last[c];
            bool valid = true;

            for (int i = left; i <= right; ++i) {
                int current = s[i] - 'a';

                // An occurrence of this character exists before 'left'.
                if (first[current] < left) {
                    valid = false;
                    break;
                }

                right = max(right, last[current]);
            }

            if (valid) {
                intervals.push_back({right, left});
            }
        }

        // Earliest finishing intervals are optimal for maximizing count.
        sort(intervals.begin(), intervals.end());

        vector<string> answer;
        int previousRight = -1;

        for (auto [right, left] : intervals) {
            if (left > previousRight) {
                answer.push_back(s.substr(left, right - left + 1));
                previousRight = right;
            }
        }

        return answer;
    }
};