int num[MXN], low[MXN], t;
vector<int> bcc[MXN];
void dfs(int x,int p){
    num[x] = low[x] = ++t;
    int lo = t;
    for(auto i : E[x]) if(i^p) {
        if(!num[i]) dfs(i,x);
        lo = min(lo,low[i]);
    }
    low[x] = lo;
}
int ck[MXN], bcnt;
void color(int x,int c){
    if(c) bcc[x].push_back(c);
    ck[x] = 1;
    for(int i : E[x]) if(!ck[i]){
        if (num[x]<=low[i]) {
            bcc[x].push_back(++bcnt);
            color(i,bcnt);
        }
        else color(i,c);
    }
}
