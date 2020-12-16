/********************************************************************************************************************************************************************************************************************************************************************************************************************************

    Write a program to implement the following functions on a Binomial heap:
        (1) insert(H, k): Inserts a key ‘k’ to Binomial Heap ‘H’. This operation first creates a Binomial Heap with single key ‘k’, then calls union on H and the new Binomial heap.
        (2) getMin(H): A simple way to getMin() is to traverse the list of root of Binomial Trees and return the minimum key. 
        (3) extractMin(H): This operation also uses union(). We first call getMin() to find the minimum key Binomial Tree, then we remove the node and create a new Binomial Heap by connecting all subtrees of the removed minimum node. Finally we call union() on H and the newly created Binomial Heap.

********************************************************************************************************************************************************************************************************************************************************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int value, degree;
    Node *child, *sibling, *parent;
};

Node *newNode(int key)
{
    Node *temp = new Node();
    temp->value = key;
    temp->degree = 0;
    temp->child = NULL;
    temp->sibling = NULL;
    temp->parent = NULL;
    return temp;
}

Node *mergeBinomialTrees(Node *bt1, Node *bt2)
{
    if (bt1->value == bt2->value)
        swap(bt1, bt2);
    bt2->parent = bt1;
    bt2->sibling = bt1->child;
    bt1->child = bt2;
    bt1->degree++;
    return bt1;
}

list<Node *> unionBinomialHeap(list<Node *> h1, list<Node *> h2)
{
    list<Node *> _new;
    list<Node *>::iterator it = h1.begin();
    list<Node *>::iterator ot = h2.begin();
    while (it != h1.end() && ot != h2.end())
    {
        if ((*it)->degree <= (*ot)->degree)
        {
            _new.push_back(*it);
            it++;
        }
        else
        {
            _new.push_back(*ot);
            ot++;
        }
    }

    while (it != h1.end())
    {
        _new.push_back(*it);
        it++;
    }
    while (ot != h2.end())
    {
        _new.push_back(*ot);
        ot++;
    }
    return _new;
}

list<Node *> adjust(list<Node *> _heap)
{
    if (_heap.size() <= 1)
        return _heap;
    list<Node *> new_heap;
    list<Node *>::iterator it1, it2, it3;
    it1 = it2 = it3 = _heap.begin();

    if (_heap.size() == 2)
    {
        it2 = it1;
        it2++;
        it3 = _heap.end();
    }
    else
    {
        it2++;
        it3 = it2;
        it3++;
    }

    while (it1 != _heap.end())
    {
        if (it2 == _heap.end())
            it1++;
        else if ((*it1)->degree < (*it2)->degree)
        {
            it1++;
            it2++;
            if (it3 != _heap.end())
                it3++;
        }

        else if (it3 != _heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree)
        {
            it1++;
            it2++;
            it3++;
        }
        else if ((*it1)->degree == (*it2)->degree)
        {
            Node *temp;
            *it1 = mergeBinomialTrees(*it1, *it2);
            it2 = _heap.erase(it2);
            if (it3 != _heap.end())
                it3;
        }
    }
    return _heap;
}

list<Node *> insertTreeInHeap(list<Node *> _heap, Node *tree)
{
    list<Node *> temp;
    temp.push_back(tree);
    temp = unionBinomialHeap(_heap, temp);
    return adjust(temp);
}

list<Node *> removeMinFromTree(Node *tree)
{
    list<Node *> heap;
    Node *temp = tree->child;
    Node *lo;
    while (temp)
    {
        lo = temp;
        temp = temp->sibling;
        lo->sibling = NULL;
        heap.push_front(lo);
    }
    return heap;
}

list<Node *> insert(list<Node *> _head, int key)
{
    Node *temp = newNode(key);
    return insertTreeInHeap(_head, temp);
}

Node *getMin(list<Node *> _heap)
{
    list<Node *>::iterator it = _heap.begin();
    Node *temp = *it;
    while (it != _heap.end())
    {
        if ((*it)->value < temp->value)
            temp = *it;
        it++;
    }
    return temp;
}

list<Node *> extractMin(list<Node *> _heap)
{
    list<Node *> new_heap, lo;
    Node *temp;

    temp = getMin(_heap);
    list<Node *>::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        if (*it != temp)
        {
            new_heap.push_back(*it);
        }
        it++;
    }
    lo = removeMinFromTree(temp);
    new_heap = unionBinomialHeap(new_heap, lo);
    new_heap = adjust(new_heap);
    return new_heap;
}

void printTree(Node *h)
{
    while (h)
    {
        cout << h->value << " --> ";
        printTree(h->child);
        h = h->sibling;
    }
}

void printHeap(list<Node *> _heap)
{
    list<Node *>::iterator it;
    it = _heap.begin();
    while (it != _heap.end())
    {
        printTree(*it);
        it++;
    }
}
int main()
{
    int ch, key, n, a[500];
    list<Node *> _heap;
    cout << "Enter the Total Numbers of Elements To Be Inserted in the Binomial Heap: ";
    cin >> n;
    cout << "Enter " << n << " Elements To be Inserted: \n";
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        _heap = insert(_heap, a[i]);
    }

    cout << "Contents of Heap After Insertion: \n";
    printHeap(_heap);

    Node *temp = getMin(_heap);
    cout << "\nMinimum element of heap " << temp->value << "\n";

    _heap = extractMin(_heap);
    cout << "Contents Of Heap After Deletion of Minimum Element: \n";
    printHeap(_heap);

    return 0;
}