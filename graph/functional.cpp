int ck[MXN], nxt[MXN], cy[MXN];
vector<int> E[MXN], cycle;
void go(int s,int e){
    cy[s] = 1;
    cycle.push_back(s);
    if(s!=e) go(nxt[s],e);
}
void pre(int x,int p){
    ck[x] = 1;
    for(int i : E[x]) if(i!=p){
        nxt[x] = i;
        if(ck[i]==1) go(i,x);
        else if(!ck[i]) pre(i,x);
    }
    ck[x] = 2;
}
