#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        int n = queries[0].size(); // all words have same length

        for (const string& q : queries) {
            bool ok = false;
            for (const string& d : dictionary) {
                int diff = 0;
                for (int i = 0; i < n; ++i) {
                    if (q[i] != d[i]) {
                        ++diff;
                        if (diff > 2) break;
                    }
                }
                if (diff <= 2) {
                    ok = true;
                    break;
                }
            }
            if (ok) result.push_back(q);
        }

        return result;
    }
};