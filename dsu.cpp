struct dsu{
    vector<int> par;
    dsu(int n){par.resize(n+1); iota(par.begin(),par.end(),0);}
    int find(int x){return par[x]-x?par[x]=find(par[x]):x;}
    void u(int a,int b){par[find(a)] = find(b);}
};
