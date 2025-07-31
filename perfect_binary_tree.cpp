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
    if(val == -1)  root = NULL;
    else root = new Node(val);
    queue<Node*> q;
    if(root) q.push(root);  
    while(!q.empty())
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
int max_height(Node* root) {
    if (!root) return -1;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return 1 + max(l, r);
}

int count_nodes(Node* root) {
    if (!root) return 0;
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return 1 + l + r;
}
int main()
{
    Node* root = input_tree();
    if (!root) {
        cout << "NO";
        return 0;
    }
    int h = max_height(root);
    long long expected = ( (long long)1 << (h + 1) ) - 1;
    long long actual = count_nodes(root);
    if (actual == expected)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
