#include <bits/stdc++.h>
using namespace std;

struct DINIC{
    struct EDGE {
        int v, c, r;
        EDGE(int v, int c, int r) : v(v), c(c), r(r) {}
    };
    static const int MAXN = 52;
    const int inf = 1e9;
    vector<EDGE> ed[MAXN];
    int w[MAXN], lvl[MAXN];
    int S, E;
    void addedge(int a, int b, int c) {
        ed[a].push_back({b, c, ed[b].size()});
        ed[b].push_back({a, 0, ed[a].size() - 1});
    }
    bool bfs() {
        memset(lvl, 0, sizeof(lvl));
        lvl[S] = 1;
        queue<int> q;
        q.push(S);
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            for(auto &a : ed[t]) if(a.c && !lvl[a.v]) {
                lvl[a.v] = lvl[t] + 1;
                q.push(a.v);
            }
        }
        return lvl[E];
    }

    int dfs(int x, int c) {
        if(x == E) return c;
        for(; w[x] < ed[x].size(); w[x]++) {
            EDGE &e = ed[x][w[x]];
            if(!e.c || lvl[e.v] != lvl[x] + 1) continue;
            int f = dfs(e.v, min(c, e.c));
            if(f) {
                e.c -= f;
                ed[e.v][e.r].c += f;
                return f;
            }
        }
        return 0;
    }

    int run() {
        int ans = 0;
        while(bfs()) {
            memset(w, 0, sizeof(w));
            while(1) {
                int c = dfs(S, inf);
                if(!c) break;
                ans += c;
            }
        }
        return ans;
    }
};
