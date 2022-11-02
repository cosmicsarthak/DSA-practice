#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Node
{
    int val;    /* int is '4 bytes' */
    Node *next; // stores address of the 'next Node' : 'next' relative to the 'current Node with value "val" '
    /* here pointer is of type int* : 'int*' pinter is '4 bytes' */

    Node(int x) : val(x), next(nullptr) {} // 'Paramter Constructor' of short style
                                           /* Refer to  "Constructors" page of my Notes */

    /* so, size of '1 Node' on memory is (4+4 = 8 bytes) */
};

struct LinkedList
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    void linked_list_traversal(Node *node)
    { // printing linked_list
        Node *tmp = node;

        while (tmp != nullptr)
        {
            cout << tmp->val << " "; // (*tmp).val
            tmp = tmp->next;         // (*tmp).next   /* next is a ptr, tmp is also a pointer */
        }
        cout << endl;
    }

    void add_at_Head(int val)
    {
        Node *nnode = new Node(val);
        nnode->next = head;
        head = nnode;
        if (size == 0)
        {
            tail = nnode;
        }
        ++size;
    }

    void add_at_tail(int val)
    {
        Node *newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
        if (size == 0)
        {
            head = newNode;
        }
        ++size;
    }

    void add_at_index(int index, int val)
    {
        Node *newNode = new Node(val);
        Node *beforeIndexNode = head; // node at (index - 1)

        // ⭐ we want the `index-1` node to be able to add the `newNode` as the `next` of this `index-1` node so that our `newNode` becomes the `Index-node`
        // also we can get the Index-node by `beforeIndexNode->next`
        for (int i = 1; i <= (index - 1); i++) // (index - 1) is the Node which is before the Index-node;    /* `i` starts with "1" as   '0' is already the head */
        /*  We do this so that we can access the `beforeIndexNode` & also the `newNode` as (newNode = beforeIndexNode->next) */
        {
            // `beforeIndexNode->next` means the Index-node where we want to ad the 'newNode'
            beforeIndexNode = beforeIndexNode->next; /* beforeIndex is actually (index-2) but then `beforeIndex`is getting updated to `beforeIndex->next` here */
            /* ⚠⚠⚠  there is NO 'i=0' as its `HEAD` so,  beforeIndexNode would become (beforeIndexNode->next)=1 which we don't want */
            // i=1 ⇢ beforeIndexNode=1 (beforeIndexNode->next)=2
            // i=2 ⇢ beforeIndexNode=2 (beforeIndexNode->next)=3
            // ...

            cerr << i << ": .. " << beforeIndexNode->val << endl;
        }

        newNode->next = beforeIndexNode->next;
        beforeIndexNode->next = newNode;
    }

    void delete_at_index(int index)
    {
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // LinkedList *myll;
    // myll->add_at_Head(55);
    // // myll->linked_list_traversal(myll);

    LinkedList *obj = new LinkedList();
    obj->add_at_Head(1);
    obj->add_at_tail(2);
    obj->add_at_tail(7);
    obj->add_at_Head(3);
    obj->add_at_tail(4);

    obj->add_at_index(3, 99);
    obj->linked_list_traversal(obj->head);

    LinkedList *obj2 = new LinkedList();
    obj2->add_at_Head(1);
    obj2->add_at_tail(2);
    obj2->add_at_tail(7);
    obj2->add_at_Head(3);
    obj2->add_at_tail(4);

    // obj->deleteAtIndex(index)

    return 0;
}
