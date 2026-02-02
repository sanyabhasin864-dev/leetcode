class Solution {
public:
    typedef long long ll;

    struct Fenwick {
        int n;
        vector<ll> cnt, sum;

        Fenwick(int n) : n(n), cnt(n+1), sum(n+1) {}

        void update(int i, ll c, ll s) {
            for (; i <= n; i += i & -i) {
                cnt[i] += c;
                sum[i] += s;
            }
        }

        ll getCnt(int i) {
            ll r = 0;
            for (; i > 0; i -= i & -i) r += cnt[i];
            return r;
        }

        ll getSum(int i) {
            ll r = 0;
            for (; i > 0; i -= i & -i) r += sum[i];
            return r;
        }

        // sum of smallest k elements
        ll getKSum(ll k) {
            ll pos = 0, curr = 0;
            for (int p = 1 << 17; p; p >>= 1) {
                if (pos + p <= n && curr + cnt[pos + p] < k) {
                    curr += cnt[pos + p];
                    pos += p;
                }
            }
            ll res = getSum(pos);
            if (pos + 1 <= n)
                res += (k - curr) * values[pos];
            return res;
        }

        vector<ll> values;
    };

    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        // coordinate compression
        vector<ll> vals(nums.begin(), nums.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();
        Fenwick fw(m);
        fw.values = vals;

        auto idx = [&](ll x) {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        };

        ll ans = LLONG_MAX;
        int l = 1;

        for (int r = 1; r < n; r++) {
            fw.update(idx(nums[r]), 1, nums[r]);

            while (r - l > dist) {
                fw.update(idx(nums[l]), -1, -nums[l]);
                l++;
            }

            if (fw.getCnt(m) >= k - 1) {
                ll curr = fw.getKSum(k - 1);
                ans = min(ans, curr);
            }
        }

        return nums[0] + ans;
    }
};
