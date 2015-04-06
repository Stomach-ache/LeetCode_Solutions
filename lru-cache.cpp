#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
class LRUCache{
public:
    class Node {
    public:
        int key, value;
        Node *prv, *nxt;
        Node():key(0), value(0), prv(NULL), nxt(NULL) {}
        Node(int key, int val):key(key), value(val), prv(NULL), nxt(NULL) {}
    };
    class DoubleLinkedList {
    public:
        Node *head, *tail;
        int size, capacity;
        DoubleLinkedList():size(0), capacity(0), head(NULL), tail(NULL) {}
        DoubleLinkedList(int c):size(0), capacity(c), head(NULL), tail(NULL) {}
		/*
        ~DoubleLinkedList() {
            while (head != NULL) {
                Node *tmp = head;
                head = head->nxt;
                delete tmp;
            }
        }
		*/
        void erase(Node *it) {
            if (size == 0) return ;
            if (it->prv != NULL && it->nxt != NULL) {
                it->prv->nxt = it->nxt;
                it->nxt->prv = it->prv;
            }
            if (it->prv == NULL) {
                head = it->nxt;
                if (head != NULL)
                    head->prv = NULL;
            }
            if (it->nxt == NULL) {
                tail = it->prv;
                if (tail != NULL)
                    tail->nxt = NULL;
            }
            size--;
        }
        int insert(Node *it) {
            if (tail != NULL) {
                tail->nxt = it;
				it->nxt = NULL;
                it->prv = tail;
                tail = it;
            } else {
                head = tail = it;
            }
            size++;
            if (size > capacity && size > 0) {
				int key = head->key;
                if (size == 1) {
                    delete head;
                    head = tail = NULL;
                } else {
                    Node *tmp = head;
                    head = head->nxt;
                    head->prv = NULL;
                    delete tmp;
					tmp = NULL;
                }
                size--;
				return  key;
            }
			return -1;
        }
    };
    LRUCache(int capacity) {
        //DoubleLinkedList DLL(capacity);
        DLL.capacity = capacity;
    }
    
    int get(int key) {
        if (HashMap.find(key) == HashMap.end()) {
            return -1;
        } else {
            Node *it = HashMap[key];
            DLL.erase(it);
            DLL.insert(it);
            return (it->value);
        }
    }
    
    void set(int key, int value) {
        if (HashMap.find(key) != HashMap.end()) {
            Node *it = HashMap[key];
            it->value = value;
            DLL.erase(it);
            DLL.insert(it);
        } else {
            Node *tmp = new Node(key, value);
            HashMap[key] = tmp;
            int k = DLL.insert(tmp);
			if (k != -1) HashMap.erase(k);
        }
    }
    
private:
    unordered_map<int, Node*> HashMap;
    DoubleLinkedList DLL;
};

int main(void) {
	int cap, op;
	cin >> cap;
	LRUCache test(cap);
	while (cin >> op) {
		if (op == 1) {
			int k, v;
			cin >> k >> v;
			test.set(k, v);
		} else {
			int k;
			cin >> k;
			cout << test.get(k) << endl;
		}
	}
	return 0;
}
