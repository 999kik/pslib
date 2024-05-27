struct SEG{
    vector<int> t;
    int n;
    SEG(int x){n=x;t.assign(2*n+1,0);}
    void upd(int p,int v){
        for(t[p+=n-1]=v;p>0;p>>=1) t[p>>1] = max(t[p],t[p^1]);
    }
    int query(int l,int r){
        int ret = 0;
        for(l+=n-1,r+=n;l<r;l>>=1,r>>=1){
            if(l&1) ret = max(ret,t[l++]);
            if(r&1) ret = max(ret,t[--r]);
        }
        return ret;
    }
};
