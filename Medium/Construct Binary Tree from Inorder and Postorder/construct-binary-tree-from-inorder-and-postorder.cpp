//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

   Node *buildTreePostIn(int in[], int is, int ie, int post[], int ps, int pe, unordered_map<int, int> &hm)
{
    if (is > ie || ps > pe)
    {
        return NULL;
    }

    Node *root = new Node(post[pe]);
    int inRoot = hm[post[pe]];
    int numsLeft = inRoot - is;

    root->left = buildTreePostIn(in, is, inRoot - 1, post, ps, ps + numsLeft - 1, hm);
    root->right = buildTreePostIn(in, inRoot + 1, ie, post, ps + numsLeft, pe - 1, hm);

    return root;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    unordered_map<int, int> hm;
    for (int i = 0; i < n; i++)
    {
        hm[in[i]] = i;
    }

    return buildTreePostIn(in, 0, n - 1, post, 0, n - 1, hm);
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends