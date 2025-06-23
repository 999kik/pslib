struct ufrb{
    vector<int> par, sz;
    vector<pii> edges;
    ufrb(int x){
        par.resize(x+1);
        sz.assign(x+1,1);
        iota(par.begin(),par.end(),0);
    }
    int find(int x){
        while(x!=par[x]) x = par[x];
        return x;
    }
    void u(int a,int b){
        a = find(a), b = find(b);
        if(sz[a]<sz[b]) swap(a,b);
        edges.push_back({a,b});
        if(a==b) return;
        sz[a] += sz[b];
        par[b] = a;
    }
    void rollback(){
        auto [a,b] = edges.back();
        edges.pop_back();
        if(a==b) return;
        for(int i = par[b];;i=par[i]){
            sz[i] -= sz[b];
            if(i==par[i]) break;
        }
        par[b] = b;
    }
};
