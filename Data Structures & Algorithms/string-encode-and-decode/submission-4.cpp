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

    string encode(vector<string>& strs) {
        int n = sz(strs);

        vi str_sizes;
        str_sizes.reserve((st)n);
        for (auto &x: strs) str_sizes.push_back((int)x.size());
        string positions = "";
        for (auto x : str_sizes) {
            positions += (to_string(x) + " ");
        }

        string comb_strs = "";
        for (auto &x : strs) {
            comb_strs += x;
        }

        return to_string(n) + " " + positions + comb_strs;
    }

    vector<string> decode(string s) {
        stringstream payload(s);

        int n;
        payload >> n;

        vi str_sizes(n);
        for (auto &x : str_sizes) {
            payload >> x;
        }

        string comb_strs;
        payload.ignore();
        getline(payload, comb_strs);

        // split comb_strs according to str_sizes
        vector<string> strs(n);
        int curr_pos = 0;
        int i = 0;
        for (auto &x : strs) {
            x = comb_strs.substr(curr_pos, str_sizes[i]);
            curr_pos += str_sizes[i];
            i++;
        }

        return strs;
    }
};
