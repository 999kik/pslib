int par[MXN], sz[MXN], dep[MXN];
void dfs(int x,int p){
    dep[x] = dep[p]+1;
    par[x] = p;
    for(int &i : E[x]) if(i^p){
        dfs(i,x);
        sz[x] += sz[i];
        if(E[x][0]==p || sz[E[x][0]]<sz[i])
            swap(E[x][0],i);
    }
    sz[x]++;
}
int ind[MXN], pos[MXN], h[MXN], ti;
vector<vector<int>> chain;
int head(int x){return chain[ind[x]][0];}
void hld(int x){
    pos[x] = ++ti;
    if(ind[x]>=chain.size()) chain.push_back({});
    chain[ind[x]].push_back(x);
    for(int i : E[x]) if(i^par[x]){
        ind[i] = (i==E[x][0]?ind[x]:chain.size());
        if(ind[i]^ind[x]) h[ind[i]] = h[ind[x]]+1;
        hld(i);
    }
}
int lca(int a,int b){
    while(ind[a]^ind[b]){
        if(h[ind[a]]<h[ind[b]]) swap(a,b);
        a = par[head(a)];
    }
    return a;
}
void lca_query(int a,int b){
    while(ind[a]^ind[b]){
        if(h[ind[a]]<h[ind[b]]) swap(a,b);
        query(pos[head(a)],pos[a]);
        a = par[head(a)];
    }
    if(pos[a]>pos[b]) swap(a,b);
    query(pos[a],pos[b]);
}
