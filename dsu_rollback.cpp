struct rollback_UF{
    vector<int> par, sz;
    vector<pii> edges;
    void init(int x){
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
        sz[a] += sz[b];
        par[b] = a;
    }
    void rollback(){
        auto [a,b] = edges.back();
        for(int i = par[b];;i=par[i]){
            sz[i] -= sz[b];
            if(i==par[i]) break;
        }
        par[b] = b;
        edges.pop_back();
    }
};
