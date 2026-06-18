#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& first) {
    if (node == nilNode || node->isNil) return;
    if (!first) cout << " ";
    cout << node->key;
    first = false;
    preorder(node->left, nilNode, first);
    preorder(node->right, nilNode, first);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& first) {
    if (node == nilNode || node->isNil) return;
    inorder(node->left, nilNode, first);
    if (!first) cout << " ";
    cout << node->key;
    first = false;
    inorder(node->right, nilNode, first);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nilNode, bool& first) {
    if (node == nilNode || node->isNil) return;
    postorder(node->left, nilNode, first);
    postorder(node->right, nilNode, first);
    if (!first) cout << " ";
    cout << node->key;
    first = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    RedBlackTree tree;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (!tree.contains(val)) {
            tree.insert(val);
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        string type;
        cin >> type;

        if (tree.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        if (type == "PREORDER" || type == "ALL") {
            cout << "[Preorder] : ";
            bool first = true;
            preorder(tree.root(), tree.nil(), first);
            cout << "\n";
        }
        if (type == "INORDER" || type == "ALL") {
            cout << "[Inorder] : "; 
            bool first = true;
            inorder(tree.root(), tree.nil(), first);
            cout << "\n";
        }
        if (type == "POSTORDER" || type == "ALL") {
            cout << "[Postorder]: "; 
            bool first = true;
            postorder(tree.root(), tree.nil(), first);
            cout << "\n";
        }
    }

    return 0;
}