#include <cstddef>
#include <iostream>

template <class T>
class Node
{
public:
    Node(const T &e = T(), Node *n = nullptr) : element(e), next(n) {}
    T element;
    Node *next;

    Node *operator++(int)
    {
        return this->next;
    }
};

template <class T>
class LList
{
private:
    Node<T> *dummyHead;

public:
    LList()
    {
        dummyHead = new Node<T>(T(), nullptr);
    };
    Node<T> *first() const { return dummyHead->next; };
    Node<T> *zeroth() const { return dummyHead; };
    bool isEmpty() const { return first() == nullptr; }

    void insert(const T &data, Node<T> *p)
    {
        Node<T> *newNode = new Node<T>(data, p->next);
        p->next = newNode;
    }

    Node<T> *find(const T &data)
    {
        Node<T> *p = first();
        while (p)
        {
            if (p->element == data)
            {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    Node<T> *findPrevious(const T &data)
    {
        Node<T> *p = zeroth();
        if (!p)
            return nullptr;
        while (p->next)
        {
            if (p->next->element == data)
                return p;
            p = p->next;
        }
        return nullptr;
    }

    void remove(const T &data)
    {
        Node<T> *prev = findPrevious(data);

        if (prev->next != nullptr)
        {
            Node<T> *temp = prev->next;
            prev->next = temp->next;
            delete temp;
        }
    }

    void print() const
    {
        const Node<T> *p = first();
        while (p)
        {
            std::cout << p->element << std::endl;
            p = p->next;
        }
    }

    void makeEmpty()
    {
        while (!isEmpty())
        {
            remove(first()->element);
        }
    }

    ~LList()
    {
        makeEmpty();
        delete dummyHead;
    }

    LList &operator=(const LList &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            const Node<T> *r = rhs.first();
            Node<T> *p = zeroth();

            while (r)
            {
                insert(r->element, p);
                r = r->next;
                p = p->next;
            }
        }
        return *this;
    }

    LList(const LList &rhs)
    {
        dummyHead = new Node<T>();
        *this = rhs;
    }

    ///////////////////////////////////////////////////////////////////////////////
    ///
    /// SORU ÇÖZÜMLERİ
    ///////////////////////////////////////////////////////////////////////////////

    // SONDAN N İNCİ ELEMANI GETİ
    Node<T> *nthToLas(int n)
    {
        Node<T> *a = first();
        Node<T> *b = first();

        for (int i = 0; i < n; i++)
        {
            if (a == nullptr)
                return nullptr;
            a = a->next;
        }

        while (a != nullptr)
        {
            a = a->next;
            b = b->next;
        }

        return b;
    }

    // DÖNGÜYE SAHİP Mİ (Floyd’un “Tavşan ve Kaplumbağa” algoritması)
    bool hasLoop() const
    {
        Node<T> *fast = first();
        Node<T> *slow = first();

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // listeyi tersten yazdır.
    void printReverseHelper(Node<T> *node) const
    {
        if (node == nullptr)
            return;
        printReverseHelper(node->next);
        std::cout << node->element << std::endl;
    }

    void printReverse() const
    {
        printReverseHelper(first());
    }

    // listeyi terse çevir
    void reverse()
    {
        Node<T> *prevNode = nullptr;
        Node<T> *currNode = first();
        Node<T> *nextNode = nullptr;

        while (currNode != nullptr)
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        dummyHead = prevNode;
    }

    // 2 listeyi birleştirme ama sırayla (bi ondan bi ondan)
    void alternateWith(LList &l2)
    {
        Node<T> *p = first();

        while (p && l2.first())
        {
            Node<T> *l2First = l2.first(); // her döngüde güncel al
            if (l2First == nullptr)
                break; // ekstra güvenlik

            insert(l2First->element, p);
            l2.remove(l2First->element);

            if (p->next != nullptr) // ilerlediğimiz düğüm
                p = p->next->next;  // bir kendi, bir eklenen düğüm
            else
                break;
        }
    }
};