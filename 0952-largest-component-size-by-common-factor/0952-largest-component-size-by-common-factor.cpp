
class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int largestComponentSize(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());

        parent.resize(mx + 1);
        sz.assign(mx + 1, 1);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int, int> mp;

        for (int x : nums) {
            int num = x;

            for (int d = 2; d * d <= num; d++) {
                if (num % d == 0) {
                    if (mp.count(d))
                        unite(x, mp[d]);
                    else
                        mp[d] = x;

                    while (num % d == 0)
                        num /= d;
                }
            }

            if (num > 1) {
                if (mp.count(num))
                    unite(x, mp[num]);
                else
                    mp[num] = x;
            }
        }

        unordered_map<int, int> count;
        int ans = 0;

        for (int x : nums) {
            ans = max(ans, ++count[find(x)]);
        }

        return ans;
    }
};
