#include <bits/stdc++.h>
using namespace std;

struct RollbackDSU {
    int n;
    vector<int> parent, sz;
    vector<pair<int,int>> history; // pairs of (child, old_parent) or (-1,-1) sentinel when no union

    RollbackDSU(int n=0): n(n), parent(n), sz(n,1) {
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int a){
        while(parent[a]!=a) a = parent[a];
        return a;
    }
    // returns true if union performed (i.e. different components). stores history for rollback.
    bool unite(int a, int b){
        a = find(a); b = find(b);
        if(a==b){
            history.emplace_back(-1,-1); // sentinel: no union, means a cycle would occur (we won't call unite when cycle)
            return false;
        }
        if(sz[a] < sz[b]) swap(a,b);
        // attach b under a
        history.emplace_back(b, parent[b]); // save old parent
        parent[b] = a;
        history.emplace_back(~a, sz[a]); // store old size of a (encode index negated)
        sz[a] += sz[b];
        return true;
    }
    // rollback one "action block". We store pairs; to rollback we pop until we pop the matching set.
    void rollback(int steps){
        // steps is number of "history entries" pushed for that operation
        while(steps--){
            auto p = history.back();
            history.pop_back();
            if(p.first == -1 && p.second == -1){
                // sentinel for "no union performed" -> nothing to restore
                continue;
            }
            if(p.first < 0){
                // encoded size restore: first = ~a, second = old size
                int a = ~p.first;
                sz[a] = p.second;
            } else {
                // restore parent
                parent[p.first] = p.second;
            }
        }
    }
    int hist_size(){ return (int)history.size(); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<string> s(n+1);
    for(int i=0;i<=n;i++){
        cin >> s[i];
        if((int)s[i].size() != n+1){
            // malformed input
            cerr << "Bad input line length\n";
            return 0;
        }
    }

    // map intersection (i,j) -> node index
    auto node = [&](int i, int j){ return i*(n+1) + j; };
    int Nnodes = (n+1)*(n+1);

    vector<int> target(Nnodes, -1), deg(Nnodes, 0), rem_possible(Nnodes, 0);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            char c = s[i][j];
            if(c == '+') target[node(i,j)] = -1;
            else target[node(i,j)] = c - '0';
        }
    }

    // initially, every intersection can be incident to up to how many cells?
    // Count for each node how many adjacent cells (each cell can contribute at most 1 diagonal that touches the node).
    // For a node (i,j) it is adjacent to up to 4 cells:
    // cells: (i-1,j-1), (i-1,j), (i,j-1), (i,j) with appropriate bounds.
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int cnt = 0;
            // each of the four cells, if valid, will contain one diagonal that may touch this node
            if(i-1 >= 0 && j-1 >= 0) cnt++; // cell (i-1,j-1)
            if(i-1 >= 0 && j   <= n-1) cnt++; // cell (i-1,j)
            if(i   <= n-1 && j-1 >= 0) cnt++; // cell (i,j-1)
            if(i   <= n-1 && j   <= n-1) cnt++; // cell (i,j)
            rem_possible[node(i,j)] = cnt;
        }
    }

    // Prepare result grid filled with '?' initially
    vector<string> res(n, string(n, '?'));

    RollbackDSU dsu(Nnodes);

    // precompute cell endpoints for the two choices
    // For cell (i,j):
    // choice 0: '\' connects (i,j) <-> (i+1,j+1)
    // choice 1: '/' connects (i+1,j) <-> (i,j+1)
    struct EndPts { int u0,v0,u1,v1; };
    vector<EndPts> cells(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int id = i*n + j;
            cells[id].u0 = node(i,j); cells[id].v0 = node(i+1,j+1);
            cells[id].u1 = node(i+1,j); cells[id].v1 = node(i,j+1);
        }
    }

    // Helper: check prune possibility for a single node
    auto violates = [&](int idx)->bool{
        int t = target[idx];
        if(t == -1) return false;
        if(deg[idx] > t) return true;
        if(deg[idx] + rem_possible[idx] < t) return true;
        return false;
    };

    bool solved = false;
    function<void(int)> dfs = [&](int cellIndex){
        if(solved) return;
        if(cellIndex == n*n){
            // end: verify all constrained nodes reached target
            for(int v=0; v<Nnodes; ++v){
                if(target[v] != -1 && deg[v] != target[v]) return;
            }
            // success
            solved = true;
            return;
        }

        int i = cellIndex / n, j = cellIndex % n;
        // for each endpoint node touched by this cell, rem_possible will reduce by 1 because this cell becomes decided
        int u0 = cells[cellIndex].u0, v0 = cells[cellIndex].v0;
        int u1 = cells[cellIndex].u1, v1 = cells[cellIndex].v1;

        // decrease rem_possible for their four potentially affected nodes before choices (we'll revert after)
        rem_possible[u0]--; rem_possible[v0]--;
        rem_possible[u1]--; rem_possible[v1]--;

        // Try choice '\'
        bool okChoice = true;
        // prune by immediate degree overflow possibility
        if(deg[u0] + 1 > (target[u0]==-1?4:target[u0])) okChoice = false;
        if(deg[v0] + 1 > (target[v0]==-1?4:target[v0])) okChoice = false;
        if(okChoice){
            // check for cycle: if u0 and v0 already connected -> adding this edge creates a loop -> forbidden
            if(dsu.find(u0) == dsu.find(v0)) okChoice = false;
        }
        if(okChoice){
            // do action: update degrees and union
            deg[u0]++; deg[v0]++;
            int histBefore = dsu.hist_size();
            dsu.unite(u0, v0); // will always return true here because we tested find !=
            // quick prune: any node now impossible?
            if(!violates(u0) && !violates(v0)){
                // Also check all four nodes (some other nodes may be constrained)
                bool anyBad = false;
                // Only nodes whose rem_possible changed could violate: but we already have violates on u0,v0 and others with rem_possible changed will be checked below
                if(violates(u1) || violates(v1)) anyBad = true;
                if(!anyBad){
                    res[i][j] = '\\';
                    dfs(cellIndex + 1);
                }
            }
            // rollback
            res[i][j] = '?';
            deg[u0]--; deg[v0]--;
            int histAfter = dsu.hist_size();
            dsu.rollback(histAfter - histBefore);
        }

        if(solved){
            // restore rem_possible before returning
            rem_possible[u0]++; rem_possible[v0]++; rem_possible[u1]++; rem_possible[v1]++;
            return;
        }

        // Try choice '/'
        okChoice = true;
        if(deg[u1] + 1 > (target[u1]==-1?4:target[u1])) okChoice = false;
        if(deg[v1] + 1 > (target[v1]==-1?4:target[v1])) okChoice = false;
        if(okChoice){
            if(dsu.find(u1) == dsu.find(v1)) okChoice = false;
        }
        if(okChoice){
            deg[u1]++; deg[v1]++;
            int histBefore = dsu.hist_size();
            dsu.unite(u1, v1);
            if(!violates(u1) && !violates(v1)){
                bool anyBad = false;
                if(violates(u0) || violates(v0)) anyBad = true;
                if(!anyBad){
                    res[i][j] = '/';
                    dfs(cellIndex + 1);
                }
            }
            // rollback
            res[i][j] = '?';
            deg[u1]--; deg[v1]--;
            int histAfter = dsu.hist_size();
            dsu.rollback(histAfter - histBefore);
        }

        // restore rem_possible
        rem_possible[u0]++; rem_possible[v0]++; rem_possible[u1]++; rem_possible[v1]++;
    };

    dfs(0);

    if(!solved){
        // No solution found (shouldn't occur given problem statement)
        cerr << "No solution found\n";
        return 0;
    }

    // Print result
    for(int i=0;i<n;i++){
        cout << res[i] << '\n';
    }
    return 0;
}