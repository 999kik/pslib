struct dijkstra{
    const ll inf = 1LL<<62;
    vector<ll> d;
    void run(int s,int sz,vector<pii> &E){
        d.assign(sz+1,inf);
        priority_queue<pair<ll,int>> pq;
        d[s] = 0; pq.push({0,s});
        for(;pq.size();){
            int x = pq.top().second; ll dist = -pq.top().first;
            pq.pop();
            if(d[x]<dist) continue;
            for(auto &[i,w] : E[x]) if(d[i]>dist+w){
                d[i] = dist+w;
                pq.push({-d[i],i});
            }
        }
    }
};
