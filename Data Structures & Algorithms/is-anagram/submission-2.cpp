#include <bits/stdc++.h>
using namespace std;

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
    bool isAnagram(string s, string t) {
        vi vs(all(s));
        vi vt(all(t));

        sort(all(vs));
        sort(all(vt));

        return (vs == vt);
    }
};
