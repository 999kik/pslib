struct Lichao{
    struct line{ll a,b; ll operator()(ll x){return a*x+b;}};
    struct node{int l,r;line up;};
    vector<node> t;
    int make(){t.push_back({-1,-1,0,-inf}); return t.size()-1;}
    void insert(int x,ll s,ll e,line v){
        line lo = t[x].up, hi = v;
        if(lo(s)>hi(s)) swap(lo,hi);
        if(lo(e)<=hi(e)) {t[x].up=hi; return;}
        ll mid = s+e>>1;
        if(lo(mid)<hi(mid)){
            t[x].up = hi;
            if(t[x].r<0) t[x].r = make();
            insert(t[x].r,mid+1,e,lo);
        }
        else {
            t[x].up = lo;
            if(t[x].l<0) t[x].l = make();
            insert(t[x].l,s,mid,hi);
        }
    }
    ll get(int x,ll s,ll e,ll v){
        if(x<0) return -inf;
        ll mid = s+e>>1;
        if(v<=mid) return max(t[x].up(v),get(t[x].l,s,mid,v));
        return max(t[x].up(v),get(t[x].r,mid+1,e,v));
    }
};
