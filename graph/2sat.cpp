struct sat_2{
    int n, hn;
    vector<vector<int>> E, R;
    void init(int x){
        hn = x;
        n = x*2;
        E.resize(n+1);
        R.resize(n+1);
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
    void build(){
        scc = ck = vector<int>(n+1,0);
        for(int i = 1;i<=n;i++) if(!ck[i]) f(i);
        reverse(st.begin(),st.end());
        int cnt = 0;
        for(int i : st) if(!scc[i]) g(i,++cnt);
    }
    void ins(int a,int b){
        if(a<0) a = hn-a;
        if(b<0) b = hn-b;
        E[a].push_back(b);
        R[b].push_back(a);
    }
    void OR(int a,int b){
        ins(-a,b); ins(-b,a);
    }
    void XOR(int a,int b){
        OR(a,b); OR(-a,-b);
    }
};
