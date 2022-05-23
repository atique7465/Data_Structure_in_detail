/**
 * ################### Fenwick Tree #################
 * Tutorial: 
 *     * https://cp-algorithms.com/data_structures/fenwick.html#1-point-update-and-range-query
 *     * https://www.youtube.com/watch?v=uSFzHCZ4E-8&list=PLqDolECUfoYxtkcoJEO-7_Irdpd2lnAPx&index=3&ab_channel=StableSort
 */

#include<bits/stdc++.h>

#define ll long long int
using namespace std;

struct FenwickTree {
    vector<ll> bit;
    ll n;

    FenwickTree(ll n) {
        this->n = n + 1; // one based indexing
        bit.assign(n + 1, 0);
    }

//    FenwickTree(vector<ll> v) : FenwickTree(v.size()) { //less efficient [n log n]
//        for (ll i = 0; i < v.size(); i++)
//            add(i + 1, v[i]);
//    }

    FenwickTree(vector<ll> v) : FenwickTree(v.size()) { //efficient [n]
        for (ll i = 0; i < n; i++)
            bit[i + 1] = v[i];

        for (ll i = 1; i < n; i++) {
            ll idx = i + (i & -i); // get parent
            if (idx < n) {
                bit[idx] += bit[i];
            }
        }
    }

    ll sum(ll idx) {
        ll ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    ll rangeSum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        if (idx <= 0) return;
        for (; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
};

int main() {
    ll n, x;
    cin >> n;

    FenwickTree F(n);
    
    return 0;
}

