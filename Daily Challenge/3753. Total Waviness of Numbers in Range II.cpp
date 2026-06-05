class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;

    Node dp[16][2][2][11][11];
    bool vis[16][2][2][11][11];

    Node dfs(int pos,
             int tight,
             int started,
             int prev2,
             int prev1) {

        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][started][prev2 + 1][prev1 + 1]) {
            return dp[pos][tight][started][prev2 + 1][prev1 + 1];
        }

        vis[pos][tight][started][prev2 + 1][prev1 + 1] = true;

        Node ans = {0, 0};

        int limit = tight ? (s[pos] - '0') : 9;

        for (int d = 0; d <= limit; d++) {

            int ntight = tight && (d == limit);

            if (!started) {

                if (d == 0) {

                    Node child =
                        dfs(pos + 1,
                            ntight,
                            0,
                            -1,
                            -1);

                    ans.cnt += child.cnt;
                    ans.sum += child.sum;
                }
                else {

                    Node child =
                        dfs(pos + 1,
                            ntight,
                            1,
                            -1,
                            d);

                    ans.cnt += child.cnt;
                    ans.sum += child.sum;
                }
            }
            else {

                int extra = 0;

                if (prev2 != -1) {

                    bool peak =
                        (prev1 > prev2 && prev1 > d);

                    bool valley =
                        (prev1 < prev2 && prev1 < d);

                    if (peak || valley)
                        extra = 1;
                }

                Node child =
                    dfs(pos + 1,
                        ntight,
                        1,
                        prev1,
                        d);

                ans.cnt += child.cnt;

                ans.sum += child.sum;

                ans.sum += child.cnt * extra;
            }
        }

        return dp[pos][tight][started][prev2 + 1][prev1 + 1] = ans;
    }

    long long calc(long long x) {

        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, -1, -1).sum;
    }

    long long totalWaviness(long long num1, long long num2) {

        return calc(num2) - calc(num1 - 1);
    }
};
