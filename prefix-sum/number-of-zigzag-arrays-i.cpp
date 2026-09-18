#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 0);
        vector<long long> down(m, 0);

        /*
            Initialize arrays of length 2.

            up[j]:
                Number of pairs (i, j) such that i < j.
                There are j such values of i.

            down[j]:
                Number of pairs (i, j) such that i > j.
                There are m - 1 - j such values of i.
        */
        for (int j = 0; j < m; ++j) {
            up[j] = j;
            down[j] = m - 1 - j;
        }

        /*
            Add one element at a time.

            To end at j with an upward move, the previous move
            must have been downward and the previous value i must
            satisfy i < j.

            To end at j with a downward move, the previous move
            must have been upward and i > j.
        */
        for (int length = 3; length <= n; ++length) {
            vector<long long> nextUp(m, 0);
            vector<long long> nextDown(m, 0);

            long long prefix = 0;

            // nextUp[j] = sum(down[i]) for i < j
            for (int j = 0; j < m; ++j) {
                nextUp[j] = prefix;
                prefix = (prefix + down[j]) % MOD;
            }

            long long suffix = 0;

            // nextDown[j] = sum(up[i]) for i > j
            for (int j = m - 1; j >= 0; --j) {
                nextDown[j] = suffix;
                suffix = (suffix + up[j]) % MOD;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long answer = 0;

        for (int value = 0; value < m; ++value) {
            answer = (answer + up[value] + down[value]) % MOD;
        }

        return static_cast<int>(answer);
    }
};