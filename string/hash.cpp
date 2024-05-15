struct HASH{
	vector<ll> suf, b;
	void hashing(vector<int> &s){
		int sz = s.size();
		suf.assign(sz+1,0);
		b.assign(sz+1,0);
	    b[0] = 1;
	    for (int i = sz-1;i>=0;i--)
	        suf[i] = (s[i] + (ll)suf[i+1]*base)%mod;
	    for (int i = 1;i<=sz;i++)
	        b[i] = (ll)b[i - 1] * base % mod;
	}
	int substr(int l,int r){
		ll v = suf[l] - suf[r+1]*b[r-l+1];
	    return (v%mod+mod)%mod;
	}
}
