class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int top = 0, cheapest = INT_MAX;
        for (auto& it : items) { top = max(top, it[0]); cheapest = min(cheapest, it[1]); }

        // have[f] = items with factor f, gain[f] = items whose factor is a multiple of f
        vector<int> have(top + 1, 0), gain(top + 1, 0);
        for (auto& it : items) have[it[0]]++;
        for (int f = 1; f <= top; ++f)
            if (have[f])
                for (int m = f; m <= top; m += f) gain[f] += have[m];

        // Base case: spend everything on the cheapest item
        vector<int> best(budget + 1);
        for (int money = 0; money <= budget; ++money) best[money] = money / cheapest;

        for (auto& it : items) {
            int g = gain[it[0]], price = it[1];
            if (price > budget || g <= price / cheapest) continue;  // cheap copies are at least as good
            for (int money = budget; money >= price; --money)       // backwards = one first copy per item
                best[money] = max(best[money], best[money - price] + g);
        }
        return best[budget];
    }
};