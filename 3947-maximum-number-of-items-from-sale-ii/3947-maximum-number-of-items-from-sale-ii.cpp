
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mx = 0, minPrice = INT_MAX;

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            int f = item[0], p = item[1];
            freq[f]++;
            mx = max(mx, f);
            minPrice = min(minPrice, p);
        }

        // Count all divisible item types.
        vector<int> gain(mx + 1, 0);

        for (int f = 1; f <= mx; f++) {
            for (int j = f; j <= mx; j += f) {
                gain[f] += freq[j];
            }
            gain[f]--;
        }

        // Cheapest items first.
        sort(items.begin(), items.end(),
             [](const auto& a, const auto& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long remaining = budget;

        // Buy valuable copies (each gives 2 items).
        for (auto& item : items) {
            long long f = item[0];
            long long p = item[1];

            if (p >= 2LL * minPrice) break;

            long long cnt = min(
                (long long)gain[f],
                remaining / p
            );

            ans += 2 * cnt;
            remaining -= cnt * p;
        }

        // Spend the remaining budget on the cheapest item.
        ans += remaining / minPrice;

        return (int)ans;
    }
};
