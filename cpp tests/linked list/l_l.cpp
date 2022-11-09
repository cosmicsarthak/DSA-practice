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
        // we want the `index-1` node to be able to add the `newNode` as the `next` of this `index-1` node so that our `newNode` becomes the `indexNode`

        for (int i = 1; i <= (index - 1); i++) // ⚠️ (index - 1) is the node which is before the indexNode;    /* `i` starts with "1" as   '0' is already the head */
        /* ⚠️starting from `0` so that `beforeIndexNode` starts with head[as head is already at 0] and then `beforeIndexNode->next` will be pointing to the exact index and thus makes it easier for us to understand */
        /*  We do this so that we can access the `beforeIndexNode` & also we will be making  `newNode` as (newNode = beforeIndexNode->next) */
        {
            // `beforeIndexNode->next` means the `indexNode` where we want to add the 'newNode'
            beforeIndexNode = beforeIndexNode->next; /* beforeIndex is actually (index-2) but then `beforeIndex`is getting updated to `beforeIndex->next` here */
            /* ⚠️⚠️⚠️⚠️ there is NO 'i=0' as its `HEAD` so,  beforeIndexNode would become (beforeIndexNode->next)=1 which we don't want */
            // i=1 ⇢⇢  beforeIndexNode=0 ⇢⇢  (beforeIndexNode->next)=1
            // i=2 ⇢⇢  beforeIndexNode=1 ⇢⇢  (beforeIndexNode->next)=2
            // ...
        }

        /* ⭐⭐ "Reference to a Pointer": It DOES'T CHNAGE AS POINTER CHANGES ⭐⭐ */
        Node *&indexNode = beforeIndexNode->next; // MUST BE ADDED 'AFTER' FINDING THE 'beforeIndexNode'
        // getting the indexNode by `beforeIndexNode->next`
        // ❌❌ if added before the value of `beforeIndexNode` then will be wrong as DOES'NT UPDATE AS POINTER CHANGES

        newNode->next = indexNode; // Node *&indexNode = (beforeIndexNode->next)
        indexNode = newNode;       // Node *&indexNode = (beforeIndexNode->next)
    }

    void delete_at_index(int index)
    {
        Node *tmp = head;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
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
    obj->delete_at_index(4);
    obj->linked_list_traversal(obj->head);

    LinkedList *obj2 = new LinkedList();
    obj2->add_at_Head(1);
    obj2->add_at_tail(2);
    obj2->add_at_tail(7);
    obj2->add_at_Head(3);
    obj2->add_at_tail(4);

    return 0;
}
