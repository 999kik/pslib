class Hopcroft_Karp {
private:
    int n;
    vector<int> X, Y, dist;
    vector<vector<int>> graph;
    bool bfs(){
        queue<int> q;
        dist[0] = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!X[i]){
                dist[i] = 0;
                q.push(i);
            }
            else dist[i] = INT_MAX;
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : graph[x]) {
                if (dist[Y[y]] == INT_MAX) {
                    dist[Y[y]] = dist[x] + 1;
                    q.push(Y[y]);
                }
            }
        }
        return dist[0] != INT_MAX;
    }
    bool dfs(int x){
        for (auto y : graph[x]) {
            if (dist[Y[y]] == dist[x] + 1 && (!Y[y] || dfs(Y[y]))){
                X[x] = y; Y[y] = x;
                return true;
            }
        }
        dist[x] = INT_MAX;
        return false;
    }
public:
    Hopcroft_Karp(int x_count, int y_count)
        : n(x_count), X(x_count + 1), Y(y_count + 1), dist(x_count + 1), graph(x_count + 1) {}
    void addEdge(int x_node, int y_node) {
        graph[x_node].push_back(y_node);
    }
    int solve(){
        int match = 0;
        while (bfs()) {
            for (int i = 1; i <= n; i++) {
                if (!X[i] && dfs(i)) {
                    match++;
                }
            }
        }
        return match;
    }
    const vector<int>& getX() const {
        return X;
    }
    const vector<int>& getY() const {
        return Y;
    }
};
