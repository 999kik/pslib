using ll = long long;
struct HASH{
    vector<ll> suf, b;
    int mod;
    HASH(string s,int base,int mo){
        mod = mo;
        int sz = s.size();
        suf = b = vector<ll>(sz+1,0);
        b[0] = 1;
        for(int i=sz-1;i>=0;i--)
            suf[i]=(s[i]+1LL*suf[i+1]*base)%mod;
        for(int i=1;i<=sz;i++)
            b[i]=1LL*b[i-1]*base%mod;
    }
    int substr(int l,int r){
       ll v = suf[l] - suf[r+1]*b[r-l+1];
       return (v%mod+mod)%mod;
    }
};
