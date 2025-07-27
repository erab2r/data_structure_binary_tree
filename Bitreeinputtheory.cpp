#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void input_Tree(){
  int val;
  cin >> val;
  Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
}
int main(){
  
    return 0;
}
