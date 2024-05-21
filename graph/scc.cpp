struct SCC{
    int n;
    vector<vector<int>> E, R;
    void init(int x,vector<int> *e){
        n = x;
        E = R = vector<vector<int>>(x+1);
        for(int i = 1;i<=n;i++) {
            E[i] = e[i];
            for(int j : e[i]) R[j].push_back(i);
        }
    }
    vector<int> ck, st, scc;
    void f(int x){
        ck[x] = 1;
        for(int i : E[x]) if(!ck[i]) f(i);
        st.push_back(x);
    }
    void g(int x,int id){
        scc[x] = id;
        for(int i : R[x]) if(!scc[i]) g(i,id);
    }
    int siz = 0;
    void build(){
        scc = ck = vector<int>(n+1,0);
        for(int i = 1;i<=n;i++) if(!ck[i]) f(i);
        reverse(st.begin(),st.end());
        for(int i : st) if(!scc[i]) g(i,++siz);
    }
};
