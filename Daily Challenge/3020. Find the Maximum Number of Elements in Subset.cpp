class Solution {
public:
    int maximumLength(vector<int>& nums) {
        /*unordered_map<int, int> freq;
        for (auto& n : nums)
            freq[n]++;

        int res = (freq[1] - 1) | 1;
        freq.erase(1);

        for (auto& f : freq) {
            int n = 0, x = f.first;

            int sq = sqrt(x);
            if (sq * sq == x && freq.count(sq) && freq[sq] > 1)
                continue;

            while (x < 31623 && freq.count(x) && freq[x] > 1) {
                n += 2;
                x *= x;
            }

            res = fmax(res, n + ((freq.count(x) << 1) - 1));
        }

        return res;
        */

        unordered_map<long long, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 1;

        // Handle 1 separately
        if (mp.count(1)) {
            int cnt = mp[1];
            ans = max(ans, cnt % 2 ? cnt : cnt - 1);
        }

        for (auto &[num, f] : mp) {
            if (num == 1) continue;

            long long x = num;
            int len = 0;

            while (mp.count(x) && mp[x] >= 2) {
                len += 2;

                if (x > 1e9) break; // avoid overflow
                x = x * x;
            }

            if (mp.count(x))
                len++;

            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
