using ll  = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi  = vector<int>;
using vll = vector<ll>;
using st = size_t;

#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define sz(x)       (int)(x).size()
#define rep(i,a,b)  for (int i = (a); i < (b); ++i)
#define irep(i,a,b) for (int i = (a); i > (b); --i)

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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = sz(nums);

        vi prefix_product;
        prefix_product.reserve(n);

        vi suffix_product;
        suffix_product.reserve(n);

        int prev_prod = 1;
        rep(i, 0, n-1) {
            prefix_product.push_back(prev_prod);
            prev_prod *= nums[i];
        }
        prefix_product.push_back(prev_prod);

        prev_prod = 1;
        irep(i, n-1, 0) {
            suffix_product.push_back(prev_prod);
            prev_prod *= nums[i];
        }
        suffix_product.push_back(prev_prod);

        vi ans(n);
        rep(i, 0, n) {
            ans[i] = prefix_product[i] * suffix_product[n-i-1];
        }

        return ans;
    }
};