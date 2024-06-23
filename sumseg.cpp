struct SEG{
    vector<int> t; int n;
    SEG(int x){n=x;t.assign(2*n+1,0);}
    void upd(int p,int v){
        for(p+=n;p;p>>=1) t[p]+=v;
    }
    int query(int l,int r){
        int ret = 0;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1) ret += t[l++];
            if(r&1) ret += t[--r];
        }
        return ret;
    }
};
