vector<pii> E[MXN]; // idx
int num[MXN], low[MXN], t;
vector<int> bcc[MXN];
void dfs(int x,int p){
    num[x] = low[x] = ++t;
    int lo = t;
    for(auto [i,w] : E[x]) if(i^p) {
        if(!num[i]) dfs(i,x);
        lo = min(lo,low[i]);
    }
    low[x] = lo;
}
int ck[MXN], bcnt;
int col[MXN]; // edge's color
void color(int x,int c){
    if(c) bcc[x].push_back(c);
    ck[x] = 1;
    for(auto [i,w] : E[x]) {
        if(!ck[i]){
            if (num[x]<=low[i]) {
                bcc[x].push_back(++bcnt);
                col[w] = bcnt;
                color(i,bcnt);
            }
            else col[w] = c, color(i,c);
        }else {
            if(!col[w])
                col[w] = c;
        }
    }
}
