#include <bits/stdc++.h>
using namespace std;

string solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n), B(n), cntA(n + 1), cntB(n + 1);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];

  int l, r;
  for (l = 0, r = 0; r < n; r++) {
    cntA[A[r]]++;
    if (r + k < n) {
      if (B[r] == -1) B[r] = A[r];
    }
    if (B[r] != -1) cntB[B[r]]++;

    while (r - l >= k) {
      cntA[A[l]]--;
      if (B[l] != -1) cntB[B[l]]--;
      if (A[l] != B[l]) return "NO\n";
      l++;
    }
  }

  r--;
  int gap = 0, wildcard = 0;
  for (int i = l; i <= r; i++) {
    if (cntA[A[i]] < cntB[A[i]]) return "NO\n";
    gap += cntA[A[i]] - cntB[A[i]];
    if (B[i] == -1) wildcard++;
  }
  if (gap > wildcard) return "NO\n";
  return "YES\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) cout << solve();
}