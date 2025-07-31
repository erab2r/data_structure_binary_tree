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


void collect_leaves(Node* root, vector<int>& leaves) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        leaves.push_back(root->val);
        return;
    }
    collect_leaves(root->left, leaves);
    collect_leaves(root->right, leaves);
}

int main()
{
   Node* root = input_tree();

    vector<int> leaves;
    collect_leaves(root, leaves);

    sort(leaves.begin(), leaves.end());    
    reverse(leaves.begin(), leaves.end());

    for (int val : leaves) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}