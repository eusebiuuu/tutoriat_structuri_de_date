# Table of contents
- [1 - Red-Black Trees](#1---red-black-trees)
- [2 - Interval Trees](#2---interval-trees)
- [3 - Lowest Common Ancestor](#3---lowest-common-ancestor)
- [4 - Exercitii examen](#4---exercitii-examen)
    - [Seria 13](#seria-13)
    - [Seria 13 - rezolvari](#seria-13---rezolvari)
    - [Seria 14](#seria-14)
    - [Seria 14 - rezolvari](#seria-15---rezolvari)
    - [Seria 15](#seria-15)
    - [Seria 15 - rezolvari](#seria-15---rezolvari)

---

## 1 - Red-Black Trees 
### <ins>1.1 - Introducere</ins>
- Un **Red-Black Tree** este un **BST**, in care fiecare nod are o proprietate in plus: **culoarea**, care poate sa fie **red** sau **black**. Exista cateva reguli pentru colorarea nodurilor, care ne asigura ca arborele va ramane mereu "echilibrat", iar operatiile vor fi **O(logn)**.
- Orice nod va avea urmatoarele campuri/atribute/proprietati:
    - **<ins>key</ins>**: cheia nodului.
    - **<ins>val</ins>**: valoarea nodului.
    - **<ins>color</ins>**: culoarea nodului, care poate fi rosu sau negru.
    - **<ins>left</ins>**: copilul stang.
    - **<ins>right</ins>**: copilul drept.
    - **<ins>parent</ins>**: parintele nodului.
- Cum determinam culoarea unui nod?
    - **Radacina** va fi **mereu** colorata cu **negru**.
    - Orice nod **NULL** este colorat cu **negru**.
    - Daca un nod este colorat cu **rosu**, atunci **copiii** sai sunt neaparat colorati cu **negru**.
    - **Black-height**: pentru un nod oarecare, orice drum de la nodul respectiv catre o frunza **NULL** va parcurge acelasi numar de noduri colorate cu negru. Exemplu: daca din nodul **X** putem ajunge in 3 frunze diferite **F1**, **F2** si **F3**, atunci drumurile **X->F1**, **X->F2** si **X->F3** parcurg acelasi numar de noduri colorate cu negru. Aceasta este **proprietatea de echilibru**.
- **Teorema**: un RB-Tree cu **n** noduri are inaltimea maxim **2*log(n+1)**.
- Am atasat o imagine care exemplifica cum ar trebui sa arate un **RB-Tree**:

![Image](images/rb-trees/example.png)

### <ins>1.2 - Search</ins>
- Este identica cu cea de la **BST-uri** (Tutoriat 3) si **AVL Trees** (Tutoriat 4); nu exista nimic de adaugat.
- **Complexitate O(logn)**.

### <ins>1.3 - Insert</ins>
- **Pasul 1**: inseram nodul ca intr-un BST normal.
- **Pasul 2**: daca arborele este gol, atunci nodul inserat este radacina => il coloram cu **negru** (proprietatea 1). Altfel, il coloram cu **rosu**, iar la pasii urmatori verificam daca am incalcat vreo proprietate.
- **Pasul 3**: daca parintele nodului inserat este colorat cu **negru**, ne putem opri (deoarece proprietatea de **black-height** nu a fost incalcata). Altfel, daca parintele este colorat cu **rosu**, am incalcat proprietatea 3 (parintele este rosu, deci **nu** poate avea copii rosii). Notam nodul recent inserat cu **T**, parintele sau cu **P**, bunicul cu **G** (parintele lui **P**, care va fi colorat cu **negru**, deoarece **P** este rosu) si fratele lui **P** cu **S** (adica celalalt copil al lui G).
	- **Cazul 1**:

### <ins>1.4 - Delete</ins>

--- 

## 2 - Interval Trees 

---

## 3 - Lowest Common Ancestor 

---

## 4 - Exercitii examen

### <ins>Seria 13</ins>

### <ins>Seria 13 - rezolvari</ins>

### <ins>Seria 14</ins>

### <ins>Seria 14 - rezolvari</ins>

### <ins>Seria 15</ins>

### <ins>Seria 15 - rezolvari</ins>

---

#### Notes 
- **Seria 13**: Red-Black Trees **(R.I.P.)**.
- **Seria 14**: RMQ (Range Minimum Queries, din nou).
- **Seria 15**: Interval Trees (arbori de intervale), LCA (Lowest Common Ancestor), RMQ (Range Minimum Queries).
