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
    string my_hash(string &s) {
        array<int, 26> count{};
        for (auto c : s) count[c-'a']++;

        string key;
        key.reserve(26*4);
        rep(i, 0, 26) {
            key += '#';
            key += to_string(count[i]);
        }
        return key;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strs) {
            groups[my_hash(s)].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(groups.size());
        for (auto &[_, group] : groups) {
            ans.push_back(std::move(group));
        }

        return ans;
    }
};