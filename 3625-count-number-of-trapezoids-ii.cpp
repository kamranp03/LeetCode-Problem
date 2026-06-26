class Solution {
public:
    using ll = long long;

    // return reduced (a, b)
    pair<ll,ll> norm(ll a, ll b) {
        if (b < 0) a = -a, b = -b;
        if (a == 0) return {0, 1};
        ll g = std::gcd(abs(a), abs(b));
        return {a / g, b / g};
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        // slope -> vector of intercept
        unordered_map<ll, vector<pair<ll,ll>>> m1;  
        // midpoint -> vector of slopes
        unordered_map<ll, vector<pair<ll,ll>>> m2;  

        m1.reserve(500000);
        m2.reserve(500000);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                ll x1 = points[i][0], y1 = points[i][1];
                ll x2 = points[j][0], y2 = points[j][1];

                ll dx = x2 - x1;
                ll dy = y2 - y1;

                pair<ll,ll> slope;
                pair<ll,ll> intercept;

                if (dx == 0) {  
                    // vertical line → slope = (1,0)
                    slope = {1, 0};
                    // intercept defined by x = constant → intercept = (x,1)
                    intercept = {x1, 1};
                } else {
                    slope = norm(dy, dx);

                    // intercept = c/d  where  ax + by + c = 0
                    // c = y1 * dx - x1 * dy
                    ll c = y1 * dx - x1 * dy;
                    intercept = norm(c, dx);
                }

                // midpoint key packed into a single 64-bit integer
                ll mx = x1 + x2;
                ll my = y1 + y2;
                ll midKey = (mx << 32) ^ (my & 0xffffffff);

                m1[((slope.first << 32) ^ (slope.second & 0xffffffff))].push_back(intercept);
                m2[midKey].push_back(slope);
            }
        }

        long long result = 0;

        // count pairs with same slope & same intercept
        for (auto &it : m1) {
            auto &vec = it.second;
            if (vec.size() <= 1) continue;

            map<pair<ll,ll>, int> cnt;
            for (auto &p : vec) cnt[p]++;

            long long prev = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                result += c * prev;
                prev += c;
            }
        }

        // subtract pairs with same midpoint & same slope
        for (auto &it : m2) {
            auto &vec = it.second;
            if (vec.size() <= 1) continue;

            map<pair<ll,ll>, int> cnt;
            for (auto &p : vec) cnt[p]++;

            long long prev = 0;
            for (auto &kv : cnt) {
                long long c = kv.second;
                result -= c * prev;
                prev += c;
            }
        }

        return (int)result;
    }
};
