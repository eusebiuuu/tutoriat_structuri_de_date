# Table of contents
- [Table of contents](#table-of-contents)
  - [1 - Introducere in algoritmica](#1---introducere-in-algoritmica)
  - [2 - Algoritmi si complexitati](#2---algoritmi-si-complexitati)
  - [3 - Teorema master](#3---teorema-master)
  - [4 - Algoritmi de sortare](#4---algoritmi-de-sortare)
  - [5 - Analiza probabilistica](#5---analiza-probabilistica)
  - [6 - Stiva](#6---stiva)
  - [7 - Coada](#7---coada)
  - [8 - Deque](#8---deque)
  - [9 - Heap](#9---heap)
  - [10 - Exercitii](#10---exercitii)
      - [Notes](#notes)

---

## 1 - Introducere in algoritmica
- Informatica presupune in principal lucrul cu instrumente, cele mai comune fiind **limbajele de programare**
- Limbajele de programare constau intr-o serie de instructiuni care sunt convertite, in final, intr-o sintaxa (cod masina, sir de 0 si 1) pe care calculatorul o poate intelege si executa
- Aceste instructiuni reprezinta o serie de pasi dati calculatorului pentru a obtine un rezultat (**output**) in functie de un set de date de intrare (**input**)
- Aceasta serie de pasi descrisa mai sus formeaza un **algoritm**, iar unul sau mai multi algoritmi alcatuiesc un program
- Deseori, in cadrul unui algoritm, avem nevoie sa stocam date, care pot fi obtinute fie din input, fie din procesari ale inputului. Stocarea datelor, insa, trebuie facuta astfel incat accesarea lor atunci cand e nevoie sa fie cat mai rapida, si teoretic (analizand complexitatile de timp si memorie) si practic (implementarea propriu-zisa a algoritmului stiind limitarile hardware-ului si limbajelor de programare)
- Pentru a rezolva problema, vom folosi ceea ce se numeste o **structura de date**; ea are rolul de a stoca datele pentru folosirea lor ulterioara in program
- Evident, nu exista o structura de date care poate satisface optim toate cazurile posibile, deci avem nevoie de una care sa se comporte cat mai bine pentru cazul nostru particular (si ideal sa fie cat mai robusta, adica daca volumul de date creste, complexitatea ei sa creasca liniar cu acesta sau sa ramana constanta); pentru aceasta putem fie sa cream una noi insine de la $0$ (bazandu-ne pe un suport teoretic sau nu - research position), fie sa le folosim pe cele existente care sunt implementate deja in limbajele de programare
- In cele ce urmeaza, pana la finalul semestrului, vom analiza teoria si implementarile din spatele celor mai comune structuri de date; dar pana atunci, inca putina algoritmica :)

---

## 2 - Algoritmi si complexitati
- Structurile de date se bazeaza si ele pe diversi algoritmi, deci pentru a le putea analiza pe ele, trebuie mai intai sa stim cum analizam algoritmii
- Cele mai comune metrici sunt timpul de executie si memoria utilizata, ce se transpun in complexitate de timp si, respectiv, complexitate de spatiu ocupat
- Pentru inceput, pentru un algoritm fie $f(n)$ numarul de operatii necesare terminarii algoritmului dandu-se un input de marime $n$
- Pentru a analiza complexitatea timpului de executie, exista 3 moduri de a le descrie 9:
1. **Big $O$**
    - fiind data o functie $g(n)$, $f(n) \in O(g(n))$ daca si numai daca $\exists c, n_0 \gt 0 \space astfel \space incat \space 0 \le f(n) \le cg(n), \forall n \ge n_0$
![](./images/bigO.png)
    - cu alte cuvinte, de la un $n_0$ incolo functia $g$ va fi mai mare decat $f$ (de cele mai multe ori cu o constanta in fata)
    - de exemplu $\frac{1}{2}n ^ 3 + 100n + 100000 \in O(n ^ 3)$, adica este marginita superior de $O(n ^ 3)$ de la un n incolo
    - de asemenea, avem si ca $n ^ 2 \in O(n ^ 3)$
    - in cazul in care limita nu este stransa, adica in cazul de mai sus, se va nota $o(n)$; **Atentie: chiar daca $n ^ 2 \in o(n^3)$, $n ^ 2 \notin o(n ^ 2)$!!! $f$ trebuie sa fie strict mai mica**
2. **Big $\Omega$**
    - fiind data o functie $g(n)$, $f(n) \in \Omega(g(n))$ daca si numai daca $\exists c, n_0 \gt 0 \space astfel \space incat \space 0 \le cg(n) \le f(n), \forall n \ge n_0$
![](./images/bigOmega.png)
    - cu alte cuvinte, de la un $n_0$ incolo functia $g$ va fi mai mica decat $f$ (de cele mai multe ori cu o constanta in fata)
    - de exemplu $\frac{4}{11}n ^ 3 + 4n ^ 2 \in \Omega(n ^ 3)$, adica este marginita inferior de $O(n ^ 3)$ de la un $n$ incolo
    - de asemenea, avem si ca $n ^ 2 \in \Omega(n)$
    - in cazul in care limita nu este stransa, adica in cazul de mai sus, se va nota $\omega(n)$; **Atentie: chiar daca $n ^ 2 \in \omega(n)$, $n ^ 2 \notin \omega(n^2)$!!! $f$ trebuie sa fie strict mai mare**
3. **Big $\Theta$**
    - fiind data o functie $g(n)$, $f(n) \in \Theta(g(n))$ daca si numai daca $\exists c_1, c_2, n_0 \gt 0 \space astfel \space incat \space c_1g(n) \le f(n) \le c_2g(n), \forall n \ge n_0$
    - in alte cuvinte, clasa de functii $\Theta$ reprezinta toate functiile $f$ care sunt marginite si superior si inferior de functia $g$ (deseori folosindu-se constante in fata)
    - de exemplu, $100n ^ 3 + 4n ^ 2 + 1000 \in \Theta(n ^ 3)$, dar $100n ^ 3 + 4n ^ 2 + 1000 \notin \Theta(n ^ 4) \space sau \space \Theta(n ^ 2)$

- Exercitiu: Este adevarat ca $2 ^ {n + 1} \in O(2 ^ n)$? Dar $2 ^ {2n} \in O(2 ^ n)$?

![](./images/bigTheta.png)

- **FOARTE IMPORTANT**: desi functia $g(n)$ are constante in fata de cele mai multe ori, observati ca in descrierea clasei ele nu exista, adica **CONSTANTELE SUNT IGNORATE ATUNCI CAND DESCRIEM CLASE DE COMPLEXITATI**; in particular, daca o functie a unui algoritm este constanta, de exemplu daca itereaza prin numerele de la $1$ la $100000$ mereu ca sa vada cate sunt divizibile cu un numar $x$ dat, ea apartine claselor $\Theta(1)$, $\Omega(1)$ si $O(1)$ (ultima fiind cea mai folosita)
- Probabil va intrebati de ce exista 3 clase de complexitate. Ce, doar $\Theta$ nu era suficienta? Ei bine, in multe cazuri, nu putem spune exact ca un algoritm este intr-una din clasele date de $\Theta$, ci putem doar demonstra ca este mai eficient decat o anumita functie, adica $f(n)$ este marginita doar superior sau stim sigur $f(n)$ este mai mare decat o alta functie, deci este marginita inferior
- De exemplu, in cazul algoritmului de Insertion Sort, daca sirul dat este sortat algoritmul are complexitatea $\Theta(n)$, iar in cazul in care este sortat descrescator algoritmul va fi in $\Theta(n ^ 2)$
- Totusi, daca vrem sa descriem general algoritmul, nu putem spune ca este in $\Theta(n ^ 2)$, decat daca analizam doar cel mai rau caz
- In exemplul prezentat, Insertion Sort va fi in $\Omega(n)$ si in $O(n^2)$, care reprezinta si limitele cele mai stranse (the most tight bounds)
- **Exercitiu:** Dati exemplu de un algoritm aflat in $\Theta(n ^ 3)$
- Complexitate de spatiu ocupat se face similar si este intuitiva dupa ce ati inteles-o pe cea de timp, de multe ori fiind cea mai usoara de aflat; un exemplu ar fi ca daca in cadrul programului avem o matrice de dimensiune $n ^ 2$ si un vector de dimensiune $10n$ atunci algoritmul va fi in $O(n ^ 2)$, chiar $\Theta(n ^ 2)$; daca sirul avea dimensiunea $m$ atunci complexitate finala era $O(n ^ 2 + m)$, la fel ca la timp ;)


## 3 - Teorema master
- Algoritmii se clasifica in 2 clase: cei iterativi si cei recursivi
- Pentru cei iterativi deseori nu este complicat sa aflam complexitatile, mai ales ca sunt mai usor de urmarit
- Pentru cei recursivi insa, trebuie sa tinem cont de mai multi factori, inclusiv de cate apeluri sunt facute si de ce complexitate au operatiile efective; pentru aceasta este foarte utila **Teorema Master**, invatata la Programarea Algoritmilor din semestrul I
- Pe scurt, pentru a afla numarul de pasi pe care ii realizeaza algoritmul in functie de inputul dat, se va folosi formula urmatoare: $T(n) = aT(\frac{n}{b}) + f(n)$, unde $a$ reprezinta numarul maxim de subprobleme apelate la un pas din recursivitate, $b$ reprezinta numarul de subprobleme egale in care este impartita problema la un pas din recursivitate, iar $f(n)$ este complexitatea, in functie de inputul $n$ al unui apel al functiei, fara a considera subapelurile; de asemenea, **$a$ si $b$ trebuie sa fie constante, daca nu sunt nu merge aplicata teorema**
- De aici, puteti fie sa folositi in continuare teorema ce va fi prezentata mai jos, fie faceti de mana toate calculele si obtineti o forma finala din care reiese complexitatea; exemplu:
- Pe baza formulei de mai sus, in functie de diferiti factori, se disting 3 cazuri (vom considera $\alpha = \log_b a$):
1. Primul caz:
    - Daca $f(n) = O(n ^ c), \space c < \alpha$ atunci $T(n) = \Theta(n ^ \alpha)$
    - De exemplu, pentru $T(n) = 8T(n / 2) + 1000 n ^ 2$ avem ca $T(n) \in \Theta(n ^ 3)$
2. Al doilea caz:
    - Daca $f(n) \in \Theta(n ^ \alpha (\log n) ^ k)$ atunci $T(n) = \Theta(n ^ \alpha (\log n) ^ {k + 1})$
    - De exemplu, $T(n) = 2T(\frac{n}{2}) + 10n$, avem ca $T(n) \in \Theta(n \log n)$
3. Al treilea caz:
    - Daca $f(n) = \Omega(n ^ c), \space c > \alpha$ atunci $T(n) \in \Theta(f(n))$
    - De exemplu, daca avem $T(n) = 2T(\frac{n}{2}) + n ^ 2$, atunci $T(n) \in \Theta(n ^ 2)$

- Din cate se poate observa, cele 3 cazuri **nu acopera toate posibilitatile**, deoarece intre cazul 1 si cazul 2 si cazul 2 si cazul 3, diferentele dintre complexitati trebuie sa fie polinomiale (adica sa fie de forma $n ^ d$ (luati $k = 0$ in cazul 2)); deci daca am avea $f(n) = O(n ^ c + m)$ atunci nu am intra in niciun caz, deci nu  putem rezolva problema cu teorema Master


## 4 - Algoritmi de sortare

* ### <ins>4.1. Bubble Sort</ins>

![Image](images/sorting-algs/bubblesort.png)

```cpp
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
```

* ### <ins>4.2. Count Sort<ins> 

![Image](images/sorting-algs/countsort.png)

```cpp
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
```

* ### <ins>4.3. Select Sort</ins>

![Image](images/sorting-algs/selectsort.png)

```cpp
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
```


* ### <ins>4.4. Insert Sort</ins>

![Image](images/sorting-algs/insertsort.png)

```cpp 
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
```

* ### <ins>4.5. Quick Sort (discutie pe pivot)</ins>

![Image](images/sorting-algs/quicksort.png)

```cpp
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
```

* ### <ins>4.6. Merge Sort</ins>

![Image](images/sorting-algs/mergesort.png)

```cpp 
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
```

* ### <ins>4.7. Heap Sort</ins>

![Image](images/sorting-algs/heapsort.png)

```cpp
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
```


* ### <ins>4.8. Bucket Sort</ins>

![Image](images/sorting-algs/bucketsort.png)

```cpp
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
```

* ### <ins>4.9. Radix Sort (MSD/LSD)</ins>

![Image](images/sorting-algs/radixsort.png)

```cpp
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
```

* ### <ins>4.10. Block Sort</ins>

* ### <ins>4.11. Shell Sort</ins>

![Image](images/sorting-algs/shellsort.png)

```cpp
void shellSort(std::vector<int>& t) {
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
```

* ### <ins>4.12. Intro Sort</ins>

* ### <ins>4.13. Tim Sort</ins>

---

## 5 - Analiza probabilistica
- Deseori, analiza de tip **worst case scenario** nu ne ofera informatii prea realiste cu privire la complexitatea pe care o sa o aiba un algoritm in practica, de cele mai multe ori
- De aceea, dorim sa analizam un algoritm si avand in vedere **average running time**-ul lui, iar acest lucru se face deseori tinand cont de anumite probabilitati ale formatului inputului
- Ca exemplu, o problema clasica este **hiring assistant problem**: aveti la dispozitie $n$ posibili angajati. Voi ii luati la rand si, in momentul in care cel curent este mai bun decat toti ceilalti, il dati afara pe cel existent si il angajati pe cel curent, insa la fiecare noua angajare platiti un cost $m$. Intrebarea importanta este cat va fi costul pe care trebuie sa-l platiti dupa ce ati procesat toti cei $n$ angajati (worst case este $nm$, dar este foarte improbabil caci avem $n!$ permutari din care putem alege)
- Acum, in functie de ce distributie are inputul, putem aplica analiza probabilistica sau nu. De exemplu, daca stim ca numerele corespunzatoare rank-urilor angajatilor sunt sortate crescator in majoritatea timpului, atunci este costul va fi $nm$ sau pe aproape, si nu putem folosi probabilistica. Daca inputul are o distributie aleatoare atunci putem, caci putem folosi putin din teoria probabilitatilor despre care veti invata in anul 2 sem 1
- Pentru a rezolva problema in continuare in mod probabilistic, presupunem ca inputul a fost generat random. Astfel, mai departem vom introduce o variabila $X_i$ ce reprezinta cati angajati ne asteptam sa avem cand procesam candidatul $i$; evident sunt fie 0 sau 1. Inmultind ambele numere cu probabilitatea ca acest candidat $i$ sa fie angajat (cum avem de ales din $i$ candidati dintre care exista un singur maxim, avem ca probabilitatea este $\frac{1}{i}$), obtinem ca $X_i$ = $\frac{1}{i}$. Aici am aplicat conceptul de **expected value** (exemplu aruncare moneda sau zar). La final, pentru fiecare $i$ adunam valorile lui $X_i$ si obtinem costul ca fiind exact $m\ln n$
- **Important de observat**: problema poate fi modificata astfel incat complexitatea de timp sa fie cea pe care dorim sa o aflam: inlocuind costul $m$ cu executia unui program de complexitate $O(m)$ atunci cand se angajeaza cineva. In acest mod, putem observa cum analiza probabilistica are relevanta in practica, desi nu este descrie toate cazurile. De exemplu, complexitatea in acest caz a algoritmului nu ar fi fost $O(nm)$ cu $O(n \log n)$
- In cazul in care distributia inputului nu este random, de exemplu stim ca este mereu sortat sau aproape sortat, putem sa generam random o permutare si astfel sa obtinem un nou input pe care complexitatea sa fie, in medie, mai buna. Astfel, adaugand aceasta reordonare, am obtinut un **algoritm randomizat**
- Alte probleme de analiza probabilistica cu rezultate neintuitive: **secretary problem**, **birthday paradox**

---

## 6 - Stiva
- Stiva este o structura de date care aranjeaza elementele dupa principiul **LIFO (Last In First Out)** (ganditi-va la cum se comporta o stiva de farfurii - puteti adauga sau extrage elemente doar din varf)
- Operatia de adaugare a unui element se numeste **PUSH**, cea de stergere din varful stivei **POP**, iar cea de aflare a elementului din varful **TOP** / **PEEK**
- Complexitatea de timp a adaugarii unui element este $O(1)$, iar a stergerii unui anumit element este $O(n)$
- Pentru a lucra cu stive eficient in C++, fie se va creati voi una (un exemplu este dat mai jos), fie se va folosi implementarea deja existenta din **STL**, si anume `std::stack` despre care puteti afla mai multe lucruri de [aici](https://en.cppreference.com/w/cpp/container/stack)
- **STL** este colectie de structuri de date, fiecare cu biblioteca ei ce trebuie importata, care are implementari abstracte (de exemplu, se pot defini pe diferite tipuri de date) pentru toate structurile de date uzuale
- Implementare STL pentru stiva:
```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Elements pushed to stack.\n";

    // Get top element
    std::cout << "Top element: " << stack.top() << "\n";

    // Pop elements
    std::cout << "Popped element: " << stack.top() << "\n";
    stack.pop();
    
    std::cout << "Top element after pop: " << stack.top() << "\n";
    
    // Check if stack is empty
    if (stack.empty()) {
        std::cout << "Stack is empty.\n";
    } else {
        std::cout << "Stack is not empty.\n";
    }
    
    return 0;
}
```
- Implementare OOP pentru stiva:
```cpp
#include <iostream>

int const MAX_SIZE = 100; // max size of stack

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1; // Constructor to initialize stack
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
        std::cout << value << " pushed to stack\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Top element: " << stack.peek() << "\n";
    std::cout << "Popped element: " << stack.pop() << "\n";
    std::cout << "Top element after pop: " << stack.peek() << "\n";
    
    return 0;
}
```

---

## 7 - Coada
- Coada este o structura de date ce organizeaza datele pe care le primeste, in ordine, dupa principiul **FIFO**
- Coada are 2 componente: capul (pe unde se extrag elementele) si coada (tail, pe unde se adauga elementele)
- Operatia de adaugare a unui element se numeste **ENQUEUE**, cea de stergere **DEQUEUE**, iar cea de aflare a elementului din cap **TOP** / **PEEK**, toate avand complexitatea de $O(1)$
- Pentru a lucra cu cozi eficient in C++, fie se va creati voi una (un exemplu este dat mai jos), fie se va folosi implementarea deja existenta din **STL**, si anume `std::queue` despre care puteti afla mai multe lucruri de [aici](https://en.cppreference.com/w/cpp/container/queue)
- Implementare STL pentru coada:
```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    std::cout << "Elements pushed to queue.\n";

    // Get front and back elements
    std::cout << "Front element: " << q.front() << "\n";
    std::cout << "Back element: " << q.back() << "\n";

    // Dequeue elements
    std::cout << "Dequeued element: " << q.front() << "\n";
    q.pop();
    
    std::cout << "Front element after dequeue: " << q.front() << "\n";
    
    // Check if queue is empty
    if (q.empty()) {
        std::cout << "Queue is empty.\n";
    } else {
        std::cout << "Queue is not empty.\n";
    }
    
    return 0;
}

```

---

## 8 - Deque
- Deque-ul este o structura de date foarte utila (desi de multe ori nu este necesara) care combina functionalitatile stivei si cozii; numele ei vine de la **Double Ended QUEue**
- Ea realizeaza stocarea inputului in ordinea data intr-un sir, insa permite modificarea datelor la ambele capete ale sirului: stergere + adaugare la inceput si stergere + adaugare la final
- In STL, este implementata de `std::deque` cu metode foarte similare celor 2 structuri descrise mai sus

---

## 9 - Heap

![Image](images/data-structures/heap.png)

---

## 10 - Exercitii
1. Valid parantheses problem.
2. Explain how to implement two stacks in one array $A[1 .. n]$ in such a way that neither stack overﬂows unless the total number of elements in both stacks together is $n$. The **PUSH** and **POP** operations should run in $O(1)$ time.
3. Given an array, find the next greater element for each element.
4. Given an array and window size k, find the maximum element in each window of size k.
5. Implement a stack using 2 queues (then try with 1 queue)

---

#### Notes 
* <b>Seria 13</b>: Algoritmi de sortare (Merge Sort, Insert Sort, Heap Sort, Quick Sort, Select Sort; Comparison Sorts), Heaps (implementare ca Array; Heapify(), BuildHeap()), Priority Queues (insert, pop), Decision Trees, Arrays, Vectors, Stacks (+array-based implementation), Queues, Deques.
* <b>Seria 14</b>: Algoritmi de sortare (Merge Sort, Quick Sort), clase de complexitati, teorema master, probabilitati (birthday paradox, secretary problem).
* <b>Seria 15</b>: Algoritmi de sortare (Merge Sort + in-place, Heap Sort, Quick Sort, Count Sort, Bucket Sort, Radix Sort, Block Sort, Intro Sort, Tim Sort), clase de complexitati, Heaps, Arrays, Vectors, Linked Lists.
