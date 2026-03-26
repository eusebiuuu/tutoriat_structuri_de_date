#include <iostream>

class Node {
    friend class BST;

    int key;
    Node *left;
    Node *right;

public:
    explicit Node(int);
};

Node::Node(const int k) : key{k}, left{nullptr}, right{nullptr} {}

// -----------------------------------------------------------------------------------------------------------------

class BST {
    Node *head;

    static void inorderHelper(const Node *);

    static void preorderHelper(const Node *);

    static void postorderHelper(const Node *);

    static void destructorHelper(const Node *);

    static Node *findSuccessor(Node *);

    static Node *deleteHelper(Node *, int);

public:
    // constructor fara parametri: un BST gol
    BST();

    // constructor parametrizat: facem un BST cu radacina
    explicit BST(int);

    [[nodiscard]] bool searchNode(int) const;

    void insertNode(int);

    void deleteNode(int) const;

    void inorder() const;

    void preorder() const;

    void postorder() const;

    ~BST();
};

BST::BST() : head(nullptr) {}

BST::BST(const int key) : head{new Node(key)} {}

BST::~BST() {
    destructorHelper(head);
    std::cout << "\n";
}

void BST::destructorHelper(const Node *node) {
    // stergere in postordine (stergem fiecare frunza pe rand)
    if (node) {
        destructorHelper(node->left);
        destructorHelper(node->right);
        std::cout << "del(" << node->key << ") ";
        delete node;
    }
}

bool BST::searchNode(const int key) const {
    const Node *aux = head;
    while (aux) {
        if (aux->key == key) {
            return true;
        }
        aux = (key < aux->key) ? (aux->left) : (aux->right);
    }
    return false;
}

void BST::insertNode(const int key) {
    if (!head) {
        this->head = new Node(key);
        return;
    }
    Node *aux = head;
    Node *parent;
    do {
        if (key == aux->key) {
            return;
        }
        parent = aux;
        aux = (key < aux->key) ? (aux->left) : (aux->right);
    } while (aux);
    (key < parent->key ? parent->left : parent->right) = new Node(key);
}

void BST::deleteNode(const int key) const {
    deleteHelper(head, key);
}

Node *BST::deleteHelper(Node *node, const int key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = deleteHelper(node->left, key);
    } else if (key > node->key) {
        node->right = deleteHelper(node->right, key);
    } else {
        if (!node->left) { // are 0 copii sau doar copilul drept
            Node *aux = node->right;
            delete node;
            return aux;
        }
        if (!node->right) { // are 0 copii sau doar copilul stang
            Node *aux = node->left;
            delete node;
            return aux;
        }
        // altfel, are 2 copii
        const Node *successor = findSuccessor(node);
        node->key = successor->key; // !NU DAM SWAP INTRE CHEI! stergerea continua in node->right, si pastram ordinea BST-ului
        node->right = deleteHelper(node->right, successor->key);
    }
    return node;
}

void BST::inorder() const {
    inorderHelper(head);
}

void BST::inorderHelper(const Node *node) {
    if (!node) {
        return;
    }
    inorderHelper(node->left);
    std::cout << node->key << " ";
    inorderHelper(node->right);
}

void BST::preorder() const {
    preorderHelper(head);
}

void BST::preorderHelper(const Node *node) {
    if (node) {
        std::cout << node->key << " ";
        preorderHelper(node->left);
        preorderHelper(node->right);
    }
}

void BST::postorder() const {
    postorderHelper(head);
}

void BST::postorderHelper(const Node *node) {
    if (node) {
        postorderHelper(node->left);
        postorderHelper(node->right);
        std::cout << node->key << " ";
    }
}


Node *BST::findSuccessor(Node *node) {
    node = node->right;
    while (node->left) {
        node = node->left;
    }
    return node;
}


int main() {
    BST tree;
    std::cout<<tree.searchNode(0)<<"\n";
    tree.inorder();
    tree.preorder();
    tree.postorder();
    tree.deleteNode(0);

    tree.insertNode(1);
    tree.insertNode(5);
    tree.insertNode(2);
    tree.insertNode(0);
    tree.insertNode(10);
    tree.insertNode(1);
    tree.insertNode(8);

    tree.inorder();
    std::cout << "\n";

    std::cout << tree.searchNode(0) << " ";
    std::cout << tree.searchNode(1) << " ";
    std::cout << tree.searchNode(3) << " ";
    std::cout << tree.searchNode(4) << " ";
    std::cout << tree.searchNode(5) << "\n";

    tree.deleteNode(5);
    tree.inorder();
    std::cout << "\n";

    tree.deleteNode(0);
    tree.inorder();
    std::cout << "\n";

    tree.insertNode(4);
    tree.inorder();
    std::cout << "\n";

    tree.deleteNode(4);
    tree.inorder();
    std::cout << "\n\n";

    tree.insertNode(6);
    std::cout << "inorder: ";
    tree.inorder();
    std::cout << "\n";
    std::cout << "preorder: ";
    tree.preorder();
    std::cout << "\n";
    std::cout << "postorder: ";
    tree.postorder();
    std::cout << "\n";
    return 0;
}
