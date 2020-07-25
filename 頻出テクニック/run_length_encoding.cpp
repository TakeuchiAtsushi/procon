vector<pair<char, int>> run_length_encoding(const string &s) {
    vector<pair<char, int>> ans;

    int num = 1;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            num++;
        }
        else {
            ans.emplace_back(make_pair(s[i], num));
            num = 1;
        }
    }
    ans.emplace_back(make_pair(s.back(), num));

    return ans;
}