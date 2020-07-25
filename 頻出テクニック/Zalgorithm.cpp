// 最長共通接頭辞の長さ(先頭何文字が一致してるのか)
vector<int> z_algorithm(const string &s) {
    int n = s.size();
    vector<int> res(n);
    res[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i+j]) j++;
        res[i] = j;
        if (j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while (i + k < n && k + res[k] < j) res[i+k] = res[k], k++;
        i += k, j -= k;
    }
    return res;
}