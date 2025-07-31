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

Node* input_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node*> q;
    if (root)
        q.push(root);
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;

        Node* myLeft = (l == -1) ? NULL : new Node(l);
        Node* myRight = (r == -1) ? NULL : new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (myLeft)
            q.push(myLeft);
        if (myRight)
            q.push(myRight);
    }
    return root;
}

bool isLeaf(Node* node) {
    return node && node->left == NULL && node->right == NULL;
}
void traverse_left(Node* root, vector<int>& nodes) {
    if (!root) return;

    if (isLeaf(root)) {
        nodes.push_back(root->val);
        return;
    }

    if (root->left) {
        traverse_left(root->left, nodes);
        nodes.push_back(root->val);
    } else if (root->right) {
        traverse_left(root->right, nodes);
        nodes.push_back(root->val);
    } else {
        nodes.push_back(root->val);
    }
}

void traverse_right(Node* root, vector<int>& nodes) {
    if (!root) return;

    if (isLeaf(root)) {
        nodes.push_back(root->val);
        return;
    }

    nodes.push_back(root->val);
    if (root->right) {
        traverse_right(root->right, nodes);
    } else if (root->left) {
        traverse_right(root->left, nodes);
    }
}

int main() {
    Node* root = input_tree();
    if (!root) return 0;

    vector<int> traverses_left;
    vector<int> traverses_right;
    traverse_left(root->left, traverses_left);

    traverse_right(root->right, traverses_right);

    for (int val : traverses_left)
        cout << val << " ";

    cout << root->val << " ";

    for (int val : traverses_right)
        cout << val << " ";

    return 0;
}
