class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freqs1(26, 0);
        for (char c : word1) {
            ++freqs1[c - 'a'];
        }

        vector<int> freqs2(26, 0);
        for (char c : word2) {
            ++freqs2[c - 'a'];
        }

        vector<pair<int, int>> countToChar1;
        for (int i = 0; i < 26; ++i) {
            if (freqs1[i] > 0) {
                countToChar1.emplace_back(freqs1[i], i);
            }
        }
        sort(begin(countToChar1), end(countToChar1));

        vector<pair<int, int>> countToChar2;
        for (int i = 0; i < 26; ++i) {
            if (freqs2[i] > 0) {
                countToChar2.emplace_back(freqs2[i], i);
            }
        }
        sort(begin(countToChar2), end(countToChar2));

        if (countToChar1.size() != countToChar2.size()) {
            return false;
        }

        vector<int> degrees(26, 0);
        for (int i = 0; i < countToChar1.size(); ++i) {
            auto [count1, char1] = countToChar1[i];
            auto [count2, char2] = countToChar2[i];
            if (count1 != count2) {
                return false;
            }
            --degrees[char1];
            ++degrees[char2];
        }

        return all_of(begin(degrees), end(degrees), [](auto e) { return e == 0; });
    }
};