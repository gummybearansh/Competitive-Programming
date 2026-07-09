class Solution {
public:
  vector<int> sumAndMultiply(string s, vector<vector<int>> &queries) {
    int n = s.size();
    long long mod = 1e9 + 7;
    // precompute powers of 01 modulo 10^9 + 7 for O(1) extraction later
    vector<long long> p10(n + 1, 1);
    for (int i = 1; i <= n; i++) {
      p10[i] = (p10[i - 1] * 10) % mod;
    }

    // if at L we have 123 and r we have 12345 and we need 45
    // we'll do 12345 - 12300
    // X = (P[r] - P[l - 1] * 10 ^k) (mod 10^9 + 7)

    // prefix arrays
    vector<long long> pf_s(n, 0); // prefix sum of all digits
    vector<long long> pf_x(n, 0); // prefix modulo val of non-zero digits
    vector<int> pf_count(n, 0);   // prefix count of non-zero digits

    pf_s[0] = s[0] - '0';
    if (s[0] != '0') {
      pf_count[0] = 1;
      pf_x[0] = s[0] - '0';
    }

    // buiild pfrefixes
    for (int i = 1; i < n; i++) {
      pf_s[i] = pf_s[i - 1] + (s[i] - '0');
      if (s[i] != '0') {
        pf_count[i] = pf_count[i - 1] + 1;
        pf_x[i] = (pf_x[i - 1] * 10 + (s[i] - '0')) % mod;
      } else {
        pf_count[i] = pf_count[i - 1];
        pf_x[i] = pf_x[i - 1];
      }
    }

    vector<int> ans(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      int l = queries[i][0], r = queries[i][1];

      // standard pf sum exteaction
      long long sum = pf_s[r] - (l > 0 ? pf_s[l - 1] : 0);

      long long x = pf_x[r];
      if (l > 0) {
        // how many non zero digits in our taret substring
        int k = pf_count[r] - pf_count[l - 1];

        // value of prefix we need to chop shifted by k zeroes
        long long sub = (pf_x[l - 1] * p10[k]) % mod;

        // wrap around modullus
        x = ((x - sub) % mod + mod) % mod;
      }

      ans[i] = (sum * x) % mod;
    }
    return ans;
  }
};
