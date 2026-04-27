using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using st = size_t;

#define all(x)     (x).begin(), (x).end()
#define rall(x)    (x).rbegin(), (x).rend()
#define sz(x)      (int)(x).size()
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

#ifdef LOCAL
  template<typename... Ts>
  void _dbg_(int line, const char* names, Ts&&... vals) {
      cerr << "[" << line << "] " << names << " = ";
      ((cerr << vals << ' '), ...);
      cerr << '\n';
  }
  #define dbg(...) _dbg_(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
  #define dbg(...) ((void)0)
#endif

class Solution {
public:
    // create a hashmap table with frequency as the key?
    // if freq is key all elements that have that freq can be it's values
    // that way we can order by key and return first k values for that key
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_table;
        for (auto x : nums) freq_table[x]++;

        vector<vi> buckets(nums.size()+1);
        for (auto &[key, value] : freq_table) {
            buckets[value].push_back(key);
        }

        // return first k elements
        vi ans;
        ans.reserve(k);
        for (auto i = buckets.size() - 1; i > 0 && (int)ans.size() < k; i--) {
            for (int x : buckets[i]) {
                ans.push_back(x);
                if ((int)ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
