#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val)
    {
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

int count_leaf_nodes(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = count_leaf_nodes(root->left);
    int r = count_leaf_nodes(root->right);
    return l + r;
}

void print_left_boundary(Node* root) {
    Node* f = root->left;
    while (f) {
        if (!(f->left == NULL && f->right == NULL))
            cout << f->val << " ";
        if (f->left)
            f = f->left;
        else
            f = f->right;
    }
}

void print_leaves(Node* root) {
    if (!root) return;
    if (root->left == NULL && root->right == NULL) {
        cout << root->val << " ";
        return;
    }
    print_leaves(root->left);
    print_leaves(root->right);
}

void print_right_boundary(Node* root) {
    Node* f = root->right;
    vector<int> temp;
    while (f) {
        if (!(f->left == NULL && f->right == NULL))
            temp.push_back(f->val);
        if (f->right)
            f = f->right;
        else
            f = f->left;
    }
    reverse(temp.begin(), temp.end());
    for (int val : temp) {
        cout << val << " ";
    }
}

int main() {
    Node* root = input_tree();
    if (!root) return 0;
    if (!(root->left == NULL && root->right == NULL))
        cout << root->val << " ";

    print_left_boundary(root);
    print_leaves(root);
    print_right_boundary(root);

    cout << endl;
    return 0;
}