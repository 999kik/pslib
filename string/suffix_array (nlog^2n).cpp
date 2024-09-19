void build(string S,vector<int> &sa,vector<int> &lcp){
    int n= S.size();
    sa = lcp = vector<int>(n);
    iota(sa.begin(),sa.end(),0);
    vector<int> g(n);
    for(int i=0;i<n;i++) g[i] = S[i];
    for(int t=1;t<n;t*=2){
        auto cmp = [&](int i,int j){
            return g[i]<g[j]||(g[i]==g[j]&&g[i+t]<g[j+t]);
        };
        sort(sa.begin(),sa.end(),cmp);
        vector<int> ng(n);
        ng[sa[0]] = 1;
        for(int i=1;i<n;i++) ng[sa[i]] = ng[sa[i-1]]+cmp(sa[i-1],sa[i]);
        g = ng;
    }
    vector<int> isa(n);
    for(int i=0;i<n;i++) isa[sa[i]] = i;
    for(int i=0,k=0;i<n;i++) if(isa[i]) {
        while(S[sa[isa[i]-1]+k]==S[i+k]) k++;
        lcp[isa[i]] = k;
        k = max(0,k-1);
    }
}
