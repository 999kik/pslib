using pii = pair<int,int>;
struct dijkstra{
    const int inf = 1e9;
    vector<int> d;
    void run(int s,int sz,vector<pii> *E){
        d.assign(sz+1,inf);
        priority_queue<pii> pq;
        d[s] = 0; pq.push({0,s});
        for(;pq.size();){
            auto [dist,x] = pq.top(); dist *= -1;
            pq.pop();
            if(d[x]<dist) continue;
            for(auto &[i,w] : E[x]) if(d[i]>dist+w){
                d[i] = dist+w;
                pq.push({-d[i],i});
            }
        }
    }
};
