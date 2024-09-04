struct HASH_2{
    struct HASH{
        vector<ll> suf, b;
        int mod;
        void init(string s,int base,int mo){
            mod = mo;
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
    }H[2];
    HASH_2(string s,int b1,int b2,int mo){
        H[0].init(s,b1,mo);
        H[1].init(s,b2,mo);
    }
    pii substr(int l,int r){return {H[0].substr(l,r),H[1].substr(l,r)};}
};
