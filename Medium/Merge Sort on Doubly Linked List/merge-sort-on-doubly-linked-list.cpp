//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    Node *funsplit(Node *h1)
{
    Node *fast = h1;
    Node *slow = h1;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = slow->next;
    slow->next = NULL;

    return temp; // Return head of the second linked list
}

Node *merge(Node *h1, Node *h2)
{
    Node *dummy = new Node(-1);
    Node *curr = dummy;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            curr->next = h1;
            h1->prev = curr;
            h1 = h1->next;
        }
        else
        {
            curr->next = h2;
            h2->prev = curr;
            h2 = h2->next;
        }
        curr = curr->next;
    }

    if (h1 != NULL)
    {
        curr->next = h1;
        h1->prev = curr;
    }
    if (h2 != NULL)
    {
        curr->next = h2;
        h2->prev = curr;
    }

    Node *ans = dummy->next;
    ans->prev = NULL;
    return ans;
}

struct Node *sortDoubly(struct Node *h1)
{
    if (h1 == NULL || h1->next == NULL) // If zero or one node is present
    {
        return h1;
    }

    // Split in two halves revursively
    Node *h2 = funsplit(h1);
    h1 = sortDoubly(h1);
    h2 = sortDoubly(h2);

    return merge(h1, h2);
}

};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends