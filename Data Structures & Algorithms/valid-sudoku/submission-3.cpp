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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vi> grid_bucket(9, vi(9, 0));
        vector<vi> hori_bucket(9, vi(9, 0));
        vector<vi> vert_bucket(9, vi(9, 0));

        bool ans = true;
        // read board
        char char_elem;
        int elem;
        rep(i, 0, 9) {
            auto row = board[i];

            // for every element of this row
            rep(j, 0, 9) {
                char_elem = board[i][j];
                if (char_elem == '.') continue;
                elem = (int)(char_elem - '1');

                hori_bucket[i][elem]++;
                if (hori_bucket[i][elem] > 1) {
                    ans = false;
                    return ans;
                };

                vert_bucket[j][elem]++;
                if (vert_bucket[j][elem] > 1) {
                    ans = false;
                    return ans;
                }

                // find out which grid it belongs to
                int x = (int)(i/3);
                int y = (int)(j/3);
                auto bucket_num = 3*x + y;
                grid_bucket[bucket_num][elem]++;
                if (grid_bucket[bucket_num][elem] > 1) {
                    ans = false;
                    return ans;
                }
            }
        }
        return ans;
    }
};
