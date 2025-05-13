#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <cmath>

class Node {
    int key;
    int difference;

public:
    Node(const int k, const int diff) : key{k}, difference{diff} {
    }

    [[nodiscard]] int getKey() const { return key; }
    [[nodiscard]] int getDifference() const { return difference; }
};

class MyHeap {
    std::vector<std::unique_ptr<Node> > heap;
    int current_size;
    int x;

    static int parent(const int i) { return (i - 1) / 2; }
    static int left(const int i) { return 2 * i + 1; }
    static int right(const int i) { return 2 * i + 2; }

    void heapify_up(int i) {
        while (i > 0) {
            const int p = parent(i);
            if (compare(*heap[i], *heap[p])) {
                std::swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
    }

    void heapify_down(int i) {
        while (true) {
            int smallest = i;
            const int l = left(i);
            const int r = right(i);

            if (l < current_size && compare(*heap[l], *heap[smallest])) smallest = l;
            if (r < current_size && compare(*heap[r], *heap[smallest])) smallest = r;

            if (smallest != i) {
                std::swap(heap[i], heap[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
    }

    // Comparison function: first by difference, then by key
    [[nodiscard]] static bool compare(const Node &a, const Node &b) {
        if (a.getDifference() != b.getDifference())
            return a.getDifference() < b.getDifference();
        return a.getKey() < b.getKey();
    }

public:
    explicit MyHeap(const int x) : current_size{0}, x{x} {
    }

    void insert(int key) {
        int diff = std::abs(key - x);
        heap.push_back(std::make_unique<Node>(key, diff));
        ++current_size;
        heapify_up(current_size - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            std::cerr << "Heap is empty!\n";
            return INT_MIN;
        }

        const int rootKey = heap[0]->getKey();

        if (current_size == 1) {
            heap.pop_back();
            current_size = 0;
            return rootKey;
        }

        heap[0] = std::move(heap.back());
        heap.pop_back();
        --current_size;
        heapify_down(0);
        return rootKey;
    }

    [[nodiscard]] bool isEmpty() const {
        return heap.empty();
    }
};

int main() {
    std::ifstream f("input.txt");
    int n, k, x;
    f >> n >> k >> x;

    MyHeap heap(x);
    int val;
    while (n--) {
        f >> val;
        heap.insert(val);
    }
    f.close();

    while (!heap.isEmpty() && k--) {
        std::cout << heap.extractMin() << " ";
    }
    std::cout << '\n';

    return 0;
}
