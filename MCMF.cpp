using pii = pair<int,int>;
struct MCMF{
    static const int SZ = 7505;
    static const int inf = 3e9;
    int s, t; //source, sink
    struct Edge{ int v, c, d, dual; };
    vector<Edge> g[SZ];
    void add(int s, int e, int c, int d){ // cost, flow
        g[s].push_back({e, c, d, (int)g[e].size()});
        g[e].push_back({s, 0, -d, (int)g[s].size()-1});
    }
    int dst[SZ], inq[SZ];
    bool spfa(){
        for(int i=0;i<SZ;i++) dst[i]=inf, inq[i]=0;
        queue<int> q; q.push(s); inq[s] = 1; dst[s] = 0;
        while(q.size()){
            int now = q.front(); q.pop(); inq[now] = 0;
            for(auto i : g[now]){
                if(i.c && dst[i.v] > dst[now] + i.d){
                    dst[i.v] = dst[now] + i.d;
                    if(!inq[i.v]) inq[i.v] = 1, q.push(i.v);
                }
            }
        }
        return dst[t] < inf;
    }

    int chk[SZ], work[SZ];
    bool update(){ //update shortest path DAG in O(V+E)
        int mn = inf;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) continue;
            for(auto j : g[i]){
                if(j.c && !chk[j.v]) mn = min(mn, dst[i] + j.d - dst[j.v]);
            }
        }
        if(mn >= inf) return 0;
        for(int i=0; i<SZ; i++){
            if(!chk[i]) dst[i] += mn;
        }
        return 1;
    }

    int dfs(int now, int fl){
        chk[now] = 1;
        if(now == t) return fl;
        for(; work[now] < g[now].size(); work[now]++){
            auto &i = g[now][work[now]];
            if(!chk[i.v] && dst[i.v] == dst[now] + i.d && i.c){
                int ret = dfs(i.v, min(fl, i.c));
                if(ret){
                    i.c -= ret; g[i.v][i.dual].c += ret;
                    return ret;
                }
            }
        }
        return 0;
    }
    pii run(int _s, int _t){
        s = _s, t = _t;
        int cst = 0, fl = 0;
        spfa();
        do{
            memset(chk, 0, sizeof chk);
            memset(work, 0, sizeof work);
            int now = 0;
            while(now = dfs(s, inf)){
                cst += dst[t] * now;
                fl += now;
                memset(chk, 0, sizeof chk);
            }
        }while(update());
        return pii(cst, fl);
    }
}F;
