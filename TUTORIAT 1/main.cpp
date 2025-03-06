#include <iostream>
#include <vector>
#include <algorithm>

// SORTARI (in ordine)
// Counting, Select, Insert, Quick, Merge, Heap, Bucket, Radix, Block, Intro, Tim, Comparison??


// 1. COUNTING SORT
void countingSort(std::vector<int> &t) {
    int maxValue = t[0];
    for (int i = 1; i < t.size(); ++i) {
        if (t[i] > maxValue) {
            maxValue = t[i];
        }
    }

    std::vector freq(maxValue + 1, 0);
    for (const auto &x: t) {
        ++freq[x];
    }
    for (int i = 0; i <= maxValue; ++i) {
        for (int j = 0; j < freq[i]; ++j) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}


// 2. SELECT SORT
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

    for (const auto &x: t) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}


// 3. INSERT SORT
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
    for (const auto &x: t) {
        std::cout << x << " ";
    }
}


// 4. QUICK SORT
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


// 5. MERGE SORT


// 6. MERGE SORT (IN-PLACE)


// 7. HEAP SORT


// 8. BUCKET SORT


// 9. RADIX SORT (MSD/LSD)


// 10. BLOCK SORT


// 11. INTRO SORT


// 12. TIM SORT

int main() {
    std::vector v = {4, 5, 7, 1, 3, 8};
    // countingSort(v);
    // selectSort(v);
    // insertSort(v);

    quickSort(v, 0, v.size() - 1);
    for (const auto &x: v) {
        std::cout << x << " ";
    }
    return 0;
}
