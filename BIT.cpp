struct BIT{
    vector<int> t; int n;
    BIT(int x){n=x+1;t.assign(n,0);}
    void upd(int x,int v){for(x++;x<=n;x+=x&-x)t[x]+=v;}
    int sum(int x){int r=0;for(x++;x;x-=x&-x)r+=t[x];return r;}
    int query(int l,int r){return sum(r)-sum(l-1);}
};
