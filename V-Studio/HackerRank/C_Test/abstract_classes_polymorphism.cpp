#include "abstract_classes_polymorphism.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <sstream>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        this->cp = capacity;
    }

    void set(int key, int value) {
        if (this->mp.size() == 0) {
            auto newNode = new Node(key, value);
            this->mp.insert(make_pair(key, newNode));
        }
        else {
            int result = this->get(key);
            if (result != -1) {
                auto target = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.first == key; });
                auto initial = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.second->prev == NULL; });
                target->second->value = value;

                if (target->second->prev != NULL && target->second->next != NULL) {
                    target->second->prev = target->second->next;
                    target->second->prev->next = target->second->next;

                    target->second->prev = NULL;
                    target->second->next = initial->second;
                }
                else if (target->second->key == initial->second->key) {
                    initial->second->value = value;
                }
                else {
                    target->second->prev = NULL;
                    target->second->next = initial->second;
                    initial->second->prev = target->second;
                    initial->second->next = NULL;
                }
            }
            else if (result == -1 && this->mp.size() == this->cp) {
                auto last = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.second->next == NULL; });
                auto init = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.second->prev == NULL; });

                last->second->prev->next = NULL;
                delete last->second;
                this->mp.erase(last);

                auto newNode = new Node(NULL, init->second, key, value);
                init->second->prev = newNode;

                this->mp.insert(make_pair(key, newNode));
            }
            else {
                auto init = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.second->prev == NULL; });
                auto newNode = new Node(NULL, init->second, key, value);
                init->second->prev = newNode;
                this->mp.insert(make_pair(key, newNode));
            }
        }
    }

    int get(int key) {
        auto itr = find_if(this->mp.begin(), this->mp.end(), [&key](pair<int, Node*> p) { return p.first == key; });
        if (itr != this->mp.end()) return itr->second->value;
        return -1;
    }
};

int a_c_p() {
    int n, capacity, i;
    string line;
    cin >> n >> capacity;
    LRUCache l(capacity);
    ofstream myOutputfile;
    ifstream myInputfile("C:\\Users\\amjad\\Desktop\\input01.txt");
    myOutputfile.open("C:\\Users\\amjad\\Desktop\\Output.txt");
    int count{0};

    if (myInputfile.is_open())
    {
        while (getline(myInputfile, line))
        {
            string command; int key, value;
            istringstream stream(line);
            while (stream >> command) {
                if (command == "get") {
                    ++count;
                    stream >> key;
                    myOutputfile << l.get(key) << "\n";
                }
                else if (command == "set") {
                    stream >> key >> value;
                    l.set(key, value);
                }
            }
        }
    }
    myOutputfile.close();
    myInputfile.close();
    return 0;
}
