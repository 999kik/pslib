struct multi_hash{
    struct HASH{
        int base, mod;
        vector<ll> suf, b;
        void hashing(string &s){
            int sz = s.size();
            suf.assign(sz+1,0);
            b.assign(sz+1,0);
            b[0] = 1;
            for (int i = sz-1;i>=0;i--)
                suf[i] = (s[i] + (ll)suf[i+1]*base)%mod;
            for (int i = 1;i<=sz;i++)
                b[i] = (ll)b[i - 1] * base % mod;
        }
        ll substr(int l,int r){
            ll v = suf[l] - suf[r+1]*b[r-l+1];
            return (v%mod+mod)%mod;
        }
    };
    vector<HASH> v;
    multi_hash(vector<int> bases,vector<int> mods,string &x){
        for(int i : bases) for(int j : mods) {
            v.push_back({});
            v.back().base = i, v.back().mod = j;
            v.back().hashing(x);
        }
    };
    vector<int> substr(int l,int r){
        vector<int> c;
        for(auto &i : v) c.push_back(i.substr(l,r));
        return c;
    }
};
