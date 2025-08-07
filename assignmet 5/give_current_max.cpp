#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp {
public:
    bool operator()(Student l, Student r) {
        if (l.marks != r.marks)
            return l.marks < r.marks; 
        return l.roll > r.roll;      
    }
};

int main() {
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        pq.push(Student(name, roll, marks));
    }

    int q;
    cin >> q;
    cin.ignore(); 

    while (q--) {
        string s;
        getline(cin, s);

        if (s[0] == '0') {
            stringstream ss(s.substr(2));
            string name;
            int roll, marks;
            ss >> name >> roll >> marks;
            pq.push(Student(name, roll, marks));

            if (!pq.empty()) {
                Student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (s == "1") {
            if (!pq.empty()) {
                Student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (s == "2") {
            if (!pq.empty()) {
                pq.pop(); 
            }

            if (!pq.empty()) {
                Student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        }
    }

    return 0;
}