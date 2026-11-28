class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int n = items.size();
        vector<int> freq(n + 1, 0);
        int mn = INT_MAX;
        for (auto& it : items) { ++freq[it[0]]; if (it[1] < mn) mn = it[1]; }

        // cnt[f] = number of OTHER items whose factor is a multiple of f (harmonic sieve)
        vector<int> cnt(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (!freq[f]) continue;
            int s = 0;
            for (int m = f; m <= n; m += f) s += freq[m];
            cnt[f] = s - 1;
        }

        // Keep only useful candidates, packed as (price << 17 | gain) for a fast 64-bit sort
        const long long lim = 2LL * mn;
        vector<unsigned long long> c; c.reserve(n);
        for (auto& it : items) {
            int g = cnt[it[0]];
            if (g > 0 && it[1] < lim) c.push_back(((unsigned long long)it[1] << 17) | g);
        }
        sort(c.begin(), c.end());

        long long rem = budget, ans = 0;
        for (unsigned long long k : c) {
            long long p = k >> 17, g = k & 131071;
            long long b = min(g, rem / p);
            ans += 2 * b;
            rem -= b * p;
            if (b < g) break;          // ran out of money; every later item costs at least as much
        }
        return ans + rem / mn;         // spend what's left on the cheapest item
    }
};