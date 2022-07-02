#define ll long long
const int MOD = 1e9 + 7;
ll Mod(ll x) {
	return (x % MOD + MOD) % MOD;
}
ll Mul(ll a, ll b) {
	return Mod(Mod(a) * Mod(b));
}

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        hc.push_back(h);        
        vc.push_back(w);
        
        int mh = hc[0], mv = vc[0];
        
        for(int i = 1; i < hc.size(); ++i) mh = max(mh, hc[i] - hc[i - 1]);
        for(int i = 1; i < vc.size(); ++i) mv = max(mv, vc[i] - vc[i - 1]);
        
        return  Mul((ll)mh, (ll)mv);
    }
};