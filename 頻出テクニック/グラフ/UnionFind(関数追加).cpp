struct uf {
 
     vector<int> par;
     vector<int> sizes;
 
     uf(int n)
             : par(n), sizes(n, 1) {
         for (int i = 0; i < n; i++) {
             par[i] = i;
         }
     }
 
     int find(int x) {
         return x == par[x] ? x : par[x] = find(par[x]);
     }
 
     void unite(int x, int y) {
         x = find(x);
         y = find(y);
         if (x == y) return;
         if (sizes[x] < sizes[y]) swap(x, y);
         par[y] = x;
         sizes[x] += sizes[y];
     }
 
     bool same(int x, int y) {
         return find(x) == find(y);
     }
 
     int get_size(int x) {
         return sizes[find(x)];
     }
 
     bool all_same() {
         bool good = true;
         for (int i = 0, n = par.size(); i < n; i++) if (find(0) != find(i)) good = false;
         return good;
     }
 
     int get_connectivity() {
         set<int> s;
         for (int i = 0, n = par.size(); i < n; i++) s.insert(find(i));
         return s.size();
     }
 
 };