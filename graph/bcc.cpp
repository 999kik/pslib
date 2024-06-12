int num[MXN], low[MXN], t;
vector<vector<int>> bcc;
void dfs(int x,int p){
    num[x] = low[x] = ++t;
    int lo = t;
    for(int i : E[x]) if(i^p) {
        if(!num[x]) dfs(i,x);
        lo = min(lo,low[i]);
    }
    low[x] = lo;
}
int ck[MXN];
void color(int x,int c){
    if(c!=-1) bcc[x].push_back(c);
    ck[x] = 1;
    for(int i : E[x]) if(!ck[i]){
        if (num[x]<=low[i]) {
			bcc[x].push_back(bcc.size());
            bcc.push_back({});
			color(i,bcc.size());
		}
		else color(i,c);
    }
}
