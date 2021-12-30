class Solution {
public:
    bool queryString(string S, int N) {
    while (N > 0) {
    auto s = bitset<32>(N--).to_string();
    if (S.find(s.substr(s.find("1"))) == string::npos) return false;
  }
  return true;
}
};