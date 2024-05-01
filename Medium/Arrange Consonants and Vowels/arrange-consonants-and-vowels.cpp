//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
     struct Node* arrangeCV(Node* head) {
        // Code here
        if(head==NULL ||head->next==NULL) return head;
        Node*p=head;
        vector<char>v;
        vector<char>k;
        while(p!=NULL)
        {
            if(p->data=='a'||p->data=='e'||p->data=='i'||p->data=='o'||p->data=='u')
            {
            k.push_back(p->data);
            p=p->next;
            }
            else
            {
            v.push_back(p->data);                
            p=p->next;
            }
        }  
        for(int i=0;i<v.size();i++)
        {
            k.push_back(v[i]);
        }
        p=head;
        int i=0;
        while(p!=NULL)
        {
            p->data=k[i];
            i++;
            p=p->next;
        }
        return head;
        
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends