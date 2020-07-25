template<typename T>
 class CulSum {
 private:
     long long N;
     vector<T> a;
     vector<T> aa;
     vector<T> b;
     vector<T> bb;
 
 public:
 
     /// @param a original array
     CulSum(vector<T> _a) {
         N = _a.size();
         a = _a;
         b = _a;
         reverse(b.begin(), b.end());
         this->aa = vector<T>(N + 1, T{});
         this->bb = vector<T>(N + 1, T{});
         for (int i = 0; i < N; i++) aa[i + 1] = a[i] + aa[i];
         for (int i = 0; i < N; i++) bb[i + 1] = b[i] + bb[i];
     }
 
     /// @brief 0-index original
     /// @param l original close
     /// @param r original open
     T get_sum(int l, int r) {
         return aa[r] - aa[l];
     }
 
     /// @brief 0-index original
     /// @param l original close
     /// @param r original open
     T get_sum_reverse(int l, int r) {
         l = N - l;
         r = N - r;
         return bb[l] - bb[r];
     }
 
     /// @brief 0-index original
     /// @param k length
     T get_sum_lead_k_len(int k) {
         return get_sum(0, k);
     }
 
     /// @brief 0-index original
     /// @param k length
     T get_sum_tail_k_len(int k) {
         return get_sum_reverse(N - k, N);
     }
 
     void show() {
         for (int i = 0; i < N + 1; i++) cout << aa[i] << " ";
         cout << endl;
     }
 
     void show_reverse() {
         for (int i = N; i >= 0; i--) cout << bb[i] << " ";
         cout << endl;
     }
 
 };