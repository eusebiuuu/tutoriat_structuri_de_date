#include <iostream>
#include <algorithm>
#include <random>

class Node {
public:
    int data;

    // each node has an array of pointers
    // forward[n] = next node of current node on level n
    // node Y is on X levels, so it has X forward pointers, one forward pointer for each level
    std::vector<Node *> forward;

    Node(int, int);
};

Node::Node(const int data, const int level) : data{data} {
    for (int i = 0; i <= level; ++i)
        forward.push_back(nullptr);
}

class SkipList {
    // max level for this skip list
    int maxLevel;

    // current highest level (<= maxLevel)
    int level;

    // pointer to header node
    Node *head;

public:
    explicit SkipList(int);

    [[nodiscard]] int randomLevel() const;

    static Node *createNode(int, int);

    [[nodiscard]] bool searchElement(int) const;

    void insertElement(int);

    void deleteElement(int);

    void print() const;

    ~SkipList();
};

SkipList::SkipList(const int maxLevel) : maxLevel{maxLevel} {
    level = 0;

    // create header node and initialize its value to -inf / INT_MIN
    head = new Node(INT_MIN, maxLevel);
}

int SkipList::randomLevel() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::geometric_distribution<> geomDist(0.5);

    int lvl = 0;
    while (lvl < maxLevel && geomDist(gen) == 0) ++lvl;
    return lvl;
}

Node *SkipList::createNode(const int nodeData, const int nodeLevel) {
    auto *newNode = new Node(nodeData, nodeLevel);
    return newNode;
}

bool SkipList::searchElement(const int nodeData) const {
    const Node *current = head;
    for (int i = level; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->data < nodeData) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    return current && current->data == nodeData;
}

void SkipList::insertElement(const int nodeData) {
    Node *current = head;

    // when inserting an element, the node before it (on every single level) must update its forward pointer
    // we will keep track of the nodes to be updated by storing them in a vector
    std::vector<Node *> update;

    // starting from the first element of the highest level
    // find the position where to insert the new node (the position has to be on level 0)
    for (int i = level; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->data < nodeData) {
            current = current->forward[i];
        }
        update.push_back(current);
    }
    std::reverse(update.begin(), update.end());

    // we are now at level 0, right before the place where we want to insert
    // current->forward[0] is where we want to insert
    current = current->forward[0];

    // only insert if we are at the end of the list OR if the element to be inserted doesn't already exist
    if (!current || current->data != nodeData) {
        const int rlevel = randomLevel();

        // it is possible for the randomly generated level to be higher than our SkipList's current level
        // that would mean: 0 <= level <= rlevel <= maxLevel
        // EXAMPLE: level = 3, rlevel = 5; that means the headers on level 4 and 5 will have to be updated to point to
        // the newly inserted node
        if (rlevel > level) {
            for (int i = level + 1; i <= rlevel; ++i)
                update.push_back(head);

            // update the SkipList's current level
            level = rlevel;
        }

        // create the new node to be inserted
        Node *newNode = createNode(nodeData, rlevel);

        // the newly inserted node will have its pointers on each level updated to point to the old "next" of the
        // previous node
        for (int i = 0; i <= rlevel; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

void SkipList::deleteElement(const int nodeData) {
    Node *current = head;
    std::vector<Node *> update;

    for (int i = level; i >= 0; --i) {
        while (current->forward[i] && current->forward[i]->data < nodeData) {
            current = current->forward[i];
        }
        update.push_back(current);
    }
    std::reverse(update.begin(), update.end());

    current = current->forward[0];
    if (current && current->data == nodeData) {
        for (int i = 0; i <= level; ++i) {
            // "current" is actually a node ahead (because of line 142)
            // the previous node could be pointing to INF, to a higher value, or to the node to be deleted
            // once we find a level that points to something greater, break the loop
            if (update[i]->forward[i] != current) {
                break;
            }
            update[i]->forward[i] = current->forward[i];
        }
        while (level > 0 && !head->forward[level]) {
            --level;
        }
        // free(current);
        delete current;
    }
}

void SkipList::print() const {
    for (int i = 0; i <= level; i++) {
        const Node *aux = head->forward[i];
        std::cout << "Level " << i << ": ";
        while (aux) {
            std::cout << aux->data << " ";
            aux = aux->forward[i];
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

SkipList::~SkipList() {
    const Node *current = head;
    while (current) {
        const Node *aux = current;
        // std::cout<<"Deleted node "<<aux->data<<"\n";
        current = current->forward[0];
        delete aux;
    }
}


int main() {
    SkipList list(5);
    list.insertElement(3);
    list.insertElement(6);
    list.insertElement(7);
    list.insertElement(9);
    list.insertElement(12);
    list.insertElement(19);
    list.insertElement(17);
    list.insertElement(26);
    list.insertElement(21);
    list.insertElement(25);

    list.print();

    std::cout << list.searchElement(5) << "\n";
    std::cout << list.searchElement(1) << "\n";
    std::cout << list.searchElement(3) << "\n";
    std::cout << list.searchElement(19) << "\n\n";

    list.deleteElement(17);
    list.deleteElement(25);
    list.deleteElement(6);

    list.print();
    return 0;
}
