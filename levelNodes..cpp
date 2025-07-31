#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree()
{
   int val;
   cin >> val;
   Node* root;
   if(val == -1) root = NULL;
   else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);
    while (!q.empty())
    {
        Node* p = q.front();
        q.pop();
        int l,r;
        cin >> l >> r;
        Node* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        p->left = myLeft;
        p->right = myRight;
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);

    }
    return root;
    
}

void print_level(Node* root, int x) {
    if (!root) {
        cout << "Invalid\n";
        return;
    }
    queue<Node*> q;
    queue<int> levels;
    q.push(root);
    levels.push(0);
    bool found = false;

    while (!q.empty()) {
        Node* node = q.front(); 
        q.pop();
        int level = levels.front(); 
        levels.pop();
        if (level == x) {
            cout << node->val << " ";
            found = true;
        }
        if (level > x) 
            break;

        if (node->left) {
            q.push(node->left);
            levels.push(level + 1);
        }
        if (node->right) {
            q.push(node->right);
            levels.push(level + 1);
        }
    }

    if (!found) 
        cout << "Invalid";
    cout << "\n";
}

int main() {
    Node* root = input_tree();
    int x;
    cin >> x;
    print_level(root, x);
    return 0;
}
