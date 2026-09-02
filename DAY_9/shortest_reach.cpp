
vector<int> bfs(int N, int m, vector<vector<int>> edges, int s) {
    map<int,vector<int>> g;
    for(vector<int> v :edges){
        int a=v[0],b=v[1];
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<pair<int,int>> q;
    vector<int> dist(N+1,INF);
    q.push(make_pair(s,0));
    dist[s]=0;
    while(!q.empty()){
        auto[node,e]=q.front();
        q.pop();
        for(int oth:g[node]){
            if(dist[oth]>e+1){
                dist[oth] = e+1;
                q.push(make_pair(oth,e+1));
            }
        }
    }
    vector<int> ans;
    for(int node=1;node<=N;node++){
        if(node==s) continue;
        ans.push_back(dist[node]==INF?-1:dist[node]*6);
    }
    return ans;
}