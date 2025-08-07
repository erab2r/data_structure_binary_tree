#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        
        int x;
        cin >> x;
        pq.push(x);
    }

    int q;
    cin >> q;
    cin.ignore(); 

    while (q--) {
        string s;
        getline(cin, s);

        if (s[0] == '0') {
             int num = stoi(s.substr(2));
             pq.push(num);
            if (!pq.empty()) 
               cout << pq.top() <<endl;
            else
                cout << "Empty" << endl;
        } else if (s == "1") {
            if (!pq.empty()) {
                cout << pq.top() <<endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (s == "2") {
            if (!pq.empty()) {
                pq.pop(); 
            }

            if (!pq.empty()) {
                 cout << pq.top() <<endl;
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}