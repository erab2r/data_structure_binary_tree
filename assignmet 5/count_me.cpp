#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;

        map<string, int> freq;
        vector<string> order;

        string Freq_Word;
        int max_Count = 0;

        while (ss >> word) {
            if (freq[word] == 0) {
                order.push_back(word);
            }
            freq[word]++;
            if (freq[word] > max_Count) {
                max_Count = freq[word];
                Freq_Word = word;
            }
        }

        cout << Freq_Word << " " << max_Count << endl;
    }

    return 0;
}