/**
 * Author: Theerada Siri
 * Description:
 * Time: O()
 */

#define N 100010
#define L 20

ll rmq[N][L];

ll f(ll a, ll b) { return min(a, b); } //must be idempotent

ll query(ll l, ll r) { //half open interval [l, r)
    ll k = 63 - __builtin_clzll(r - l);
    return f(rmq[l][k], rmq[r - (1 << k)][k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n) F(i, 0, n) cin >> rmq[i][0];
    F(j, 1, L) F(i, 0, n) {
        ll i2 = i + (1 << (j - 1));
        if(i2 < n) rmq[i][j] = f(rmq[i][j - 1], rmq[i2][j - 1]);
        else rmq[i][j] = rmq[i][j - 1];
    }
}
