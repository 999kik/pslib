int lca(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int j = 20;j>=0;j--) if(dep[b]-dep[a]>>j&1) b = table[j][b];
    if(a==b) return a;
    for(int j = 20;j>=0;j--) if(table[j][a]^table[j][b]) a = table[j][a], b = table[j][b];
    return table[0][a];
}
