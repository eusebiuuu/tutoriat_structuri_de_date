# Table of contents
- [Table of contents](#table-of-contents)
  - [1 - Convex Hulls (infasuratori convexe)](#1---convex-hulls-infasuratori-convexe)
    - [1.1 - Introducere](#11---introducere)
    - [1.2 - Graham's Scan](#12---grahams-scan)
    - [1.3 - Jarvis' March](#13---jarvis-march)
  - [2 - Alegerea medianei in O(n). Mediane si statistici de ordine](#2---alegerea-medianei-in-on-mediane-si-statistici-de-ordine)
    - [Notiuni teoretice](#notiuni-teoretice)
    - [Formularea problemei](#formularea-problemei)
  - [3 - Coduri Huffman](#3---coduri-huffman)
  - [4 - Exercitii examen](#4---exercitii-examen)
    - [Seria 13](#seria-13)
    - [Seria 13 - rezolvari](#seria-13---rezolvari)
    - [Seria 14](#seria-14)
    - [Seria 14 - rezolvari](#seria-14---rezolvari)
    - [Seria 15](#seria-15)
    - [Seria 15 - rezolvari](#seria-15---rezolvari)
      - [Notes](#notes)

---

## <ins>1 - Convex Hulls (infasuratori convexe)</ins>

### <ins>1.1 - Introducere</ins>

### <ins>1.2 - Graham's Scan</ins>

### <ins>1.3 - Jarvis' March</ins>

--- 

## <ins>2 - Alegerea medianei in O(n). Mediane si statistici de ordine</ins>
### Notiuni teoretice
- **A i-a statistica de ordine** pentru un sir este al i-lea cel mai mic element al sirului.
- **Mediana** unui sir impar este elementul din mijloc in ordinea sortarii, iar pentru un sir par este media aritmetica a elementelor din mijloc in ordinea sortarii.

### Formularea problemei
- Ni se da un sir de n elemente nesortate distincte (pentru simplitate, metodele de mai jos se pot generaliza si pentru cazurile cand se repeta elementele). Dorim sa aflam a i-a statistica de ordine.
- Evident, o modalitate de a face asta este sa sortam, insa asta ar fi in $O(nlogn)$ sau $O(nb)$ pentru radix sort. Totusi, noi vrem mai rapid de atat. Preferabil $O(n)$
- Solutia la aceasta problema este sa folosim ideea de la quicksort (vezi **tutoriatul 1**), dar sa mergem doar pe o ramura a partitionarii sirului de catre pivot, iar pe acesta sa-l generam random. Pe langa asta, la fiecare pas din recursivitate tinem minte a cata pozitie vrem sa aflam din respectivul subsir continuu $(l, r)$. Pentru mai multe detalii consultati implementare de mai jos. Aceasta implementare are complexitate in $O(n)$, demonstratia este foarte matematica, nu o voi pune aici.
- **Sarcina pentru voi**: modificati algoritmul de mai jos sa tina cont si de duplicate, ele reprezentand aceleasi pozitii in lista sortata.

```cpp
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ifstream fin("sdo.in");
ofstream fout("sdo.out");

int generate_random(int start, int end) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start, end);
    return dis(gen);
}

int get_pivot_position(vector<int> &a, int l, int r) {
    int pivot = generate_random(l, r);
    swap(a[pivot], a[r]);
    int idx = l;
    for (int i = l; i < r; ++i) {
        if (a[i] < a[r]) {
            swap(a[i], a[idx]);
            idx++;
        }
    }
    swap(a[r], a[idx]);
    return idx;
}

int get_i_smallest(vector<int> &a, int l, int r, int i) {
    if (l >= r) {
        return a[l];
    }
    int pivot_pos = get_pivot_position(a, l, r);
    int local_ord = pivot_pos - l + 1;
    if (local_ord == i) {
        return a[pivot_pos];
    } else if (local_ord < i) {
        return get_i_smallest(a, pivot_pos + 1, r, i - local_ord);
    }
    return get_i_smallest(a, l, pivot_pos - 1, i);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    fin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }
    fout << get_i_smallest(a, 1, n, k) << '\n';
    return 0;
}
```
---

## <ins>3 - Coduri Huffman</ins>
- Fie urmatoarea problema: avem un text format din diferite simboluri pe care dorim sa-l codificam binar. Totusi, vrem sa facem acest lucru cat mai eficient i.e. folosind cat mai putina memorie. Aceasta problema este exact cea de la ASC din sem 1.
- Pe scurt, solutia consta in determinarea frecventelor tuturor simbolurilor in setul de date si condificare lor intr-un mod neambiguu si folosind siruri binare de lungime variabila.
- Prin neambiguitate ma refer la evitarea tuturor situatiilor in care un sir este prefix al altui sir. In acest fel, daca vom scrie toate sirurile lipite si incercam sa parsam apoi sa decodificam textul, vom obtine exact aceleasi simboluri. Aceste siruri se mai cheama si **prefix codes**.
- Codificare lor in sir binar se bazeaza pe constructia unui arbore binar in care valorile nodurilor intermediare reprezinta suma frunzelor din subarborele a carui radacina este el, iar valorile frunzelor reprezinta frecventa unui simbol in setul de date. Pe frunze se afla valorile 0 (fiul stang) si 1, iar encoding-ul unui simbol reprezinta concatenarea caracterelor de pe muchii, din drumul de la radacina la simbolul dorit.
![](./images/huffman_tree.png)
- Desi codificarile obtinute din acest arbore sunt foarte eficient, modul cum se construieste acesta este destul de simplu:
  - Prima data se formeaza nodurile cu frecventele simbolurilor
  - Apoi se vor adauga aceste noduri intr-o structura de date (de obicei **priority_queue**)
  - Cat timp mai sunt cel putin 2 noduri in coada se vor extrage cele 2 noduri cu frecventele cele mai mici, se va crea un alt nod ce va fi parintele celor doi, iar acesta din urma se va adauga inapoi in coada avand ca valoare suma frecventelor fiilor.
![](./images/huffman_algorithm.png)
- Pentru implementare consultati [acest link](https://github.com/eusebiuuu/assembler-and-executor/blob/main/encoder/huffman.cpp).
- **Sarcina**: rezolvati problema [aceasta](https://www.infoarena.ro/problema/huffman) fara sa mai consultati implementarea data.


---

## <ins>4 - Exercitii examen</ins>

### <ins>Seria 13</ins>

### <ins>Seria 13 - rezolvari</ins>

### <ins>Seria 14</ins>

### <ins>Seria 14 - rezolvari</ins>

### <ins>Seria 15</ins>

### <ins>Seria 15 - rezolvari</ins>

---

#### <ins>Notes</ins>
- **Seria 13**: Convex Hulls (Graham's Scan, Jarvis' March).
- **Seria 14**: Alegerea medianei in **O(n)** (algoritm aleator, algoritm determinist).
- **Seria 15**: BSTs (**Tutoriat 3**), coduri Huffman.
