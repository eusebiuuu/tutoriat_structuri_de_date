#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// SORTING ALGORITHMS
// Bubble, Count, Select, Insert, Quick, Merge, Heap, Bucket, Radix, Shell, Block, Intro, Tim


// 1. BUBBLE SORT
// time O(n^2), space O(1), stable
void bubbleSort(std::vector<int> &t) {
    const int n = t.size();
    for (int i = 0; i < n - 1; ++i) {
        bool ok = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (t[j] > t[j + 1]) {
                std::swap(t[j], t[j + 1]);
                ok = true;
            }
        }
        if (!ok) {
            return;
        }
    }
}


// 2. COUNT SORT
// time O(N+M), space O(N+M), stable
void countSort(std::vector<int> &t) {
    const int n = t.size();
    int maxValue = t[0];
    for (int i = 1; i < n; ++i) {
        if (t[i] > maxValue) {
            maxValue = t[i];
        }
    }

    std::vector count(maxValue + 1, 0);
    for (const auto &x: t) {
        ++count[x];
    }

    for (int i = 1; i <= maxValue; ++i) {
        count[i] += count[i - 1];
    }

    std::vector<int> aux(n);
    for (int i = n - 1; i >= 0; --i) {
        aux[count[t[i]] - 1] = t[i];
        --count[t[i]];
    }
    t = aux;
}


// 3. SELECT SORT
// time O(n^2), space O(1), unstable
void selectSort(std::vector<int> &t) {
    const int n = t.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (t[j] < t[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(t[i], t[minIndex]);
    }
}


// 4. INSERT SORT
// time O(n^2), space O(1), stable
void insertSort(std::vector<int> &t) {
    for (int i = 1; i < t.size(); ++i) {
        int j = i - 1;
        const int aux = t[i];
        while (j >= 0 && aux <= t[j]) {
            t[j + 1] = t[j];
            --j;
        }
        t[j + 1] = aux;
    }
}


// 5. QUICK SORT
// time O(nlogn), space O(logn), unstable
int medianThree(std::vector<int> &t, const int i, const int j, const int k) {
    // XOR TRICK
    if ((t[i] > t[j]) ^ (t[i] > t[k]))
        return i;
    if ((t[j] < t[i]) ^ (t[j] < t[k]))
        return j;
    return k;
}

int partition(std::vector<int> &t, const int left, const int right) {
    const int middle = (right - left) / 2 + left; // anti overflow
    const int pivot = medianThree(t, left, right, middle);
    std::swap(t[pivot], t[right]);

    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (t[j] < t[right]) {
            std::swap(t[++i], t[j]);
        }
    }
    std::swap(t[i + 1], t[right]);
    return i + 1;
}

void quickSort(std::vector<int> &t, const int left, const int right) {
    if (left < right) {
        const int index = partition(t, left, right);
        quickSort(t, left, index);
        quickSort(t, left + 1, right);
    }
}


// 6. MERGE SORT
// time O(nlogn), space O(n), stable
void merge(std::vector<int> &t, const int left, const int mid, const int right) {
    const int n1 = mid - left + 1; // include mijlocul
    const int n2 = right - mid;
    std::vector<int> leftArray, rightArray;

    for (int i = 0; i < n1; ++i) {
        leftArray.push_back(t[left + i]);
    }
    for (int j = 0; j < n2; ++j) {
        rightArray.push_back(t[j + mid + 1]);
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            t[k++] = leftArray[i++];
        } else {
            t[k++] = rightArray[j++];
        }
    }
    while (i < n1) {
        t[k++] = leftArray[i++];
    }
    while (j < n2) {
        t[k++] = rightArray[j++];
    }
}

void mergeSort(std::vector<int> &t, const int left, const int right) {
    if (left < right) {
        const int mid = (right - left) / 2 + left;
        mergeSort(t, left, mid);
        mergeSort(t, mid + 1, right);
        merge(t, left, mid, right);
    }
}


// 7. MERGE SORT (IN-PLACE)

void mergeInPlace(std::vector<int> &t, const int left, int mid, const int right) {
    // daca e deja sortat
    if (t[mid] <= t[mid + 1]) {
        return;
    }

    int p1 = left;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= right) {
        // elementul de la p1 este deja pozitionat corect
        if (t[p1] <= t[p2]) {
            p1++;
        } else {
            int auxIndex = p2;
            const int auxValue = t[p2];
            // mutam totul in fata cu o pozitie si il plasam pe p2
            while (auxIndex != p1) {
                t[auxIndex] = t[auxIndex - 1];
                --auxIndex;
            }
            t[p1] = auxValue;
            ++p1;
            ++p2;
            ++mid;
        }
    }
}

void mergeSortInPlace(std::vector<int> &t, const int left, const int right) {
    if (left < right) {
        const int mid = (right - left) / 2 + left;
        mergeSortInPlace(t, left, mid);
        mergeSortInPlace(t, mid + 1, right);
        mergeInPlace(t, left, mid, right);
    }
}


// 8. HEAP SORT
// time O(nlogn), space O(1), unstable
void heapify(std::vector<int> &t, const int n, const int node) {
    int largest = node;
    const int left = 2 * node + 1;
    const int right = 2 * node + 2;

    if (left < n && t[left] > t[largest]) {
        largest = left;
    }
    if (right < n && t[right] > t[largest]) {
        largest = right;
    }
    if (largest != node) {
        std::swap(t[largest], t[node]);
        heapify(t, n, largest);
    }
}

void heapSort(std::vector<int> &t) {
    const int n = t.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(t, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(t[0], t[i]);
        heapify(t, i, 0);
    }
}


// 9. BUCKET SORT
//
void bucketSort(std::vector<double> &t) {
    std::vector<std::vector<double> > buckets(10);

    double maxValue = t[0];
    for (int i = 1; i < t.size(); ++i) {
        if (t[i] > maxValue) {
            maxValue = t[i];
        }
    }

    for (const auto &x: t) {
        buckets[static_cast<int>((x * 10) / maxValue) - 1].push_back(x);
    }

    // aici poate intra orice algoritm de sortare stabil
    for (int i = 0; i < 10; ++i) {
        std::ranges::sort(buckets[i]);
    }

    int j = 0;
    for (int i = 0; i < 10; ++i) {
        for (const auto &x: buckets[i]) {
            t[j++] = x;
        }
    }
}


// 10. RADIX SORT (MSD/LSD)
//
void countSortAux(std::vector<int> &t, int &n, const int exp) {
    std::vector count(10, 0);
    std::vector<int> aux(n);

    for (const auto &x: t) {
        ++count[(x / exp) % 10];
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = t.size() - 1; i >= 0; --i) {
        aux[count[(t[i] / exp) % 10] - 1] = t[i];
        --count[(t[i] / exp) % 10];
    }
    t = aux;
}

void radixSort(std::vector<int> &t) {
    int maxValue = t[0];
    for (const auto &x: t) {
        if (x > maxValue) {
            maxValue = x;
        }
    }
    int n = t.size();
    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        countSortAux(t, n, exp);
    }
}


// 11. SHELL SORT
void shellSort(std::vector<int> &t) {
    const int n = t.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            const int aux = t[i];
            int j;
            for (j = i; j >= gap && t[j - gap] > aux; j -= gap) {
                t[j] = t[j - gap];
            }
            t[j] = aux;
        }
    }
}


// 12. BLOCK SORT
// timp O(nlogn), spatiu O(1), stabil
void blockSort(std::vector<int> &t) {
    const int blockSize = 3;
    const int n = t.size();
    std::vector<std::vector<int> > blocks;
    for (int i = 0; i < n; i += blockSize) {
        std::vector<int> auxBlock;
        for (int j = i; j < i + blockSize && j < n; ++j) {
            auxBlock.push_back(t[j]);
        }
        // aici intra orice sortare
        std::ranges::sort(auxBlock);
        blocks.push_back(auxBlock);
    }
    int m = blocks.size();
    int j = 0;
    while (!blocks.empty()) {
        int minIndex = 0;
        for (int i = 1; i < m; ++i) {
            if (blocks[i][0] < blocks[minIndex][0]) {
                minIndex = i;
            }
        }
        t[j++] = blocks[minIndex][0];
        blocks[minIndex].erase(blocks[minIndex].begin());
        if (blocks[minIndex].empty()) {
            blocks.erase(blocks.begin() + minIndex);
            --m;
        }
    }
}


// 13. INTRO SORT


// 14. TIM SORT


int main() {
    std::vector v = {170, 45, 75, 90, 802, 24, 2, 66};
    // std::vector v = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    // bubbleSort(v);
    // countingSort(v);
    // selectSort(v);
    // insertSort(v);
    // quickSort(v, 0, v.size() - 1);
    // mergeSort(v, 0, v.size() - 1);
    // mergeSortInPlace(v, 0, v.size() - 1);
    // heapSort(v);
    // radixSort(v);
    // bucketSort(v);
    // shellSort(v);
    blockSort(v);

    for (const auto &x: v) {
        std::cout << x << " ";
    }
    return 0;
}
