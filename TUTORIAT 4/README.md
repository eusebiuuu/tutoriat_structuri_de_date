# Table of contents
- [1 - AVL Trees](#1---avl-trees)
- [2 - Splay Trees](#2---splay-trees)
- [3 - RMQ (Range Minimum Queries)](#3---rmq-range-minimum-queries)
- [4 - Binomial Heaps](#4---binomial-heaps)
- [5 - Fibonacci Heaps](#5---fibonacci-heaps)

---

## 1 - AVL Trees 

### <ins>1.1 - Ce este un AVL Tree?</ins>
- Un <b>AVL Tree</b> este un <b>Binary Search Tree</b> cu o proprietate in plus: pentru orice nod, diferenta dintre inaltimea subarborelui stang si inaltimea subarborelui drept este de maxim un nod. Aceasta proprietate asigura faptul ca inaltimea arborelui ramane mereu aproximativ <b>logn</b> => operatiile de <b>insert/search/delete</b> o sa aiba complexitate <b>O(logn)</b>.
- Inserarea si stergerea de noduri pot afecta aceasta proprietate, deoarece se modifica inaltimea subarborelui; asadar, ne folosim de <b>rotatii</b> ca sa corectam diferentele de inaltime dintre subarbori.

![Image](images/avl-trees/example.png)

### <ins>1.2 - Rotatii</ins>
- Rotatiile inseamna schimbarea pozitionarii nodurilor, astfel incat sa fie indeplinita din nou proprietatea de arbore echilibrat. 
- Exista <b>4</b> cazuri de dezechilibru in structura arborilor, care pot fi rezolvate cu rotatii, si pe care le-am ilustrat in poza.

![Image](images/avl-trees/rotations.png)

### <ins>1.3 - Search</ins>
- Nu exista nimic in plus de explicat; cautarea este <b>exact la fel</b> ca la BST-uri (vezi <b>Tutoriat 3</b>).
- <b>Complexitate O(logn)</b>.

### <ins>1.4 - Insert</ins>
- <b>Pasul 1</b>: inseram nodul ca la un BST normal (vezi <b>Tutoriat 3</b>).
- <b>Pasul 2</b>: incepand de la nodul inserat anterior, mergem in sus spre radacina, cautand primul nod care este dezechilibrat, pe care il vom nota cu <b>A</b>. Odata ce l-am localizat pe <b>A</b>, obtinem fiul, pe care il notam cu <b>B</b>, care se afla in drum spre nodul inserat. Apoi, obtinem fiul lui <b>B</b>, pe care il notam cu <b>C</b>, care se afla in drum spre nodul inserat (important sa nu ne abatem de la drum).
- <b>Pasul 3</b>: Odata ce am obtinut nodurile <b>A</b>, <b>B</b> si <b>C</b>, determinam cazul in care ne aflam si aplicam rotatiile necesare. Ne folosim de inaltimile subarborilor lui <b>A</b>:
    - <b>left_subtree_height - right_subtree_height > 1</b>: ne aflam in <b>Left-Left</b> sau <b>Left-Right</b>. Ca sa ne dam seama, comparam valoarea nodului inserat cu valoarea lui <b>B</b>.
    - <b>left_subtree_height - right_subtree_height < -1</b>: ne aflam in <b>Right-Right</b> sau <b>Right-Left</b>. Ca sa ne dam seama, comparam valoarea nodului inserat cu valoarea lui <b>B</b>.
- <b>Pasul 4</b>: am identificat cazul; aplicam una sau doua rotatii (in functie de caz), iar arborele devine din nou echilibrat.

### <ins>1.5 - Delete</ins>

### <ins>1.6 - Alte operatii</ins>

---

## 2 - Splay Trees 
- Un splay tree este un arbore binar de cautare (**nu este balansat!!!**) ce permite accesarea rapida a ultimelor elemente inserate.
- La fel ca ceilalti arbori binari de cautare, complexitatea accesarii, stergerii si inserarii este $O(log n)$ **in medie** (care este worst case-ul?). Totusi, ele depind foarte mult de **entropia** input-ului, adica cat de mult se vor repeta query-urile si ce pattern au ele.
- Important de precizat este ca, fata de ceilalti BST, acestia isi pot schimba structura si pe operatiile de accesare.
- Pentru a putea detalia cum se realizeaza mai exact operatiile pe arbore, trebuie sa introducem conceptul de **splaying**.
- Atunci cand un element este accesat el va fi mutat aproape de radacina prin operatia de **splay**. Aceasta consta intr-o serie de pasi ce presupun mutarea elementului respectiv, nivel dupa nivel, pana la radacina. Acesti pasi sunt de 3 tipuri, depinzand de pozitia nodului accesat (nodul $p$ este parintele nodului curent $x$):
1. $p$ este radacina (**Zig step**):
![](./images/splay_trees/zig.png)
2. $p$ nu este radacina si $p$ si $x$ sunt ambii pe partea stanga / dreapta a unui nod $g$:
![](./images/splay_trees/zig_zig.png)
3. $p$ nu este radacina si $p$ si $x$ sunt pe aceeasi parte, insa unul este fiu stang, iar celalalt fiu drept:
![](./images/splay_trees/zig_zag.png)
**IMPORTANT**: Exemplele descriu cazuri in care pe partea stanga se incepe operatia, insa algoritmii sunt simetrici, adica este aceeasi idee daca privim din dreapta in stanga.
> **Intrebare**: care sunt cazurile in care se va realiza **zig step**??
- **Join**: Operatia de join intre 2 splay trees $S$ si $T$, in care toate valorile nodurilor din $S$ sunt mai mici decat cele din $T$, se poate face realizand operatia de **splaying** in arborele $S$, aducandu-l pe cel mai mare in radacina (astfel avand fiul drept `null`), iar mai apoi adaugand ca fiu drept pe radacina arborelui din $T$.
- **Inserare**: Operatia de inserare se realizeaza ca intr-un BST normal, doar ca dupa ce am adaugat elementul, facem **splaying** pe el si il facem radacina
- **Stergerea**: Operatia de stergere se realizeaza ca intr-un BST, doar ca parintelui lui i se va face splaying spre radacina
> **Cerinta**: Dati exemplu de o secventa de inserari si accesari pentru care complexitatea este $O(n^2)$. Pentru a vizualiza operatiile, puteti accesa urmatorul [site](https://www.cs.usfca.edu/~galles/visualization/SplayTree.html).


## 3 - RMQ (Range Minimum Queries)
- Descriere problema: fie un sir de $n$ numere $A$ ordonate aleator. Dorim sa facem interogari pe el de forma $(a, b)$, iar rezultatul sa fie numarul minim din $A$ in intervalul determinat de pozitiile $a$ si $b$ ($a < b$).
- Pentru moment vom presupune ca nu se pot face update-uri pe elementele din sir (pentru asta va fi nevoie sa folosim niste structuri de date pe care le invatam mai tarziu sau ceva mai ineficient despre care gasiti mai multe informatii [aici](https://cp-algorithms.com/data_structures/sqrt_decomposition.html)).
- Pentru acestea vom folosi un **sparse table**. Ideea din spatele ei e intentia de a reprezenta segmente din array de tipul $[i, j]$ sub forma $min_elem[i][e_1], min_elem[i + 2 ^ {e_1}][e_2] ...$ cu semnificatia ca $min_elem[i][j]$ reprezinta valoarea minima din intervalul $[i, i + 2 ^ j - 1]$. Astfel, se poate descompune un interval in puteri de 2 si sa se inlantuiasca pana se acopera tot intervalul; in acest mod complexitatea de timp este $O(log_2(j - i))$.
- Pentru mai multe informatii si implementari consultati site-ul [asta](https://cp-algorithms.com/data_structures/sparse-table.html).

## 4 - Binomial Heaps 

### <ins>4.1 - Introducere</ins>
- Un <b>Binomial Heap</b> este o colectie de <b>arbori binomiali</b>, legati intre ei, fiecare arbore respectand proprietatea de <b>min-heap</b> (sau <b>max-heap</b>). Arborii sunt "sortati" in ordine crescatoare, dupa numarul de noduri.
- Radacinile arborilor sunt legate intre ele, ca intr-un <b>Linked List</b>.
- Un arbore binomial are <b>2<sup>k</sup></b> noduri => ii putem privi ca fiind niste puteri de 2. Deoarece orice numar are o unica reprezentare in binar, deducem ca orice numar de noduri are o unica reprezentare ca si colectie de arbori binomiali (ca si <b>Binomial Heap</b>).
- Fiecare nod are urmatoarele campuri:
    - <ins><b>key</ins></b>: cheia/valoarea nodului respectiv.
    - <ins><b>parent</ins></b>: un pointer catre parinte.
    - <ins><b>sibling</ins></b>: un pointer catre sibling (radacinile arborilor sunt legate in acest fel; de asemenea, copiii aceluiasi parinte sunt legati intre ei).
    - <ins><b>child</ins></b>: un pointer catre copilul cel mai din stanga.
    - <ins><b>degree</ins></b>: numarul de copii.

![Image](images/binomial-heap/structure.png)

### <ins>4.2 - Union</ins>
- <b>Pasul 1</b>: unim toate radacinile arborilor din ambele heap-uri intr-o lista, <b>sortata crescator</b> dupa <b>gradul radacinii</b>.
- <b>Pasul 2</b>: exista posibilitatea de a avea perechi de cate 2 arbori cu acelasi ordin, ceea ce incalca proprietatea de a avea un singur arbore de un anumit ordin. Procedam la fel ca la o adunare in binar: <b>(01)<sub>2</sub> + (01)<sub>2</sub> = (10)<sub>2</sub></b>, adica 2 arbori de ordinul <b>K</b> produc un arbore de ordin <b>K+1</b>. <b>Ce se intampla cand avem 3 arbori?</b> De exemplu - avem 2 arbori de ordinul <b>K</b> care produc un arbore de ordin <b>K+1</b>, dar mai avem si alti 2 arbori de ordin <b>K+1</b>. Idee - lasam in pace arborele pe care il avem ca si "<b>carry</b>" (arborele de ordin <b>K+1</b> obtinut anterior) si unim ceilalti 2 arbori, obtinand astfel un arbore de ordin <b>K+2</b>;  <b>(011)<sub>2</sub> + (011)<sub>2</sub> = (010)<sub>2</sub> + (010)<sub>2</sub> + (010)<sub>2</sub> = (100)<sub>2</sub> + (010)<sub>2</sub> = (110)<sub>2</sub></b>. Repetam incontinuu acest pas, pana cand ajungem la ultimul nod si nu mai avem nimic de facut.
- <b>Complexitate O(logn)</b>.

![Image](images/binomial-heap/union.png)

### <ins>4.3 - Extract min</ins>
- <b>Pasul 1</b>: cautam minimul. Simplu - parcurgem lista de radacini, pana cand il gasim. Complexitate? Numarul de biti necesar pentru reprezentarea in binar a unui numar <b>n</b> este <b>[log<sub>2</sub>n] + 1</b>, la fel ca numarul de arbori binomiali necesar pentru reprezentarea unui numar de noduri <b>n</b> => trecem prin <b>[log<sub>2</sub>n] + 1</b> radacini => <b>O(logn)</b>.
- <b>Pasul 2</b>: Stergem radacina gasita (atentie la toti pointerii!) si obtinem 2 heap-uri binomiale:
    - <b>H1</b> = heap-ul obtinut daca excludem arborele care contine radacina respectiva.
    - <b>H2</b> = heap-ul obtinut din toti subarborii binomiali ramasi dupa stergerea radacinii (si fara arborii din <b>H1</b>).
- <b>Pasul 3</b>: apelam <b>union(H1,H2)</b>.
- <b>Complexitate O(logn)</b>.

![Image](images/binomial-heap/extract-min.png)

### <ins>4.4 - Decrease key (un nod ia o valoare mai mica)
- <b>Cum functioneaza operatia</b>? Actualizam valoarea unui nod, sa fie mai mica decat valoarea initiala (exemplu practic: daca pe un graf am gasit un drum mai bun intre 2 noduri, vrem sa actualizam distanta).
- <b>Pasul 1</b>: modificam valoarea nodului respectiv.
- <b>Pasul 2</b>: dam swap cu parintele, pana cand este indeplinita din nou proprietatea de <b>min/max-heap</b>.

### <ins>4.5 - Insert</ins>
- <b>Pasul 1</b>: facem un nou heap <b>H'</b>, care sa contina nodul respectiv (un singur arbore binomial de ordin 0).
- <B>Pasul 2</b>: apelam <b>union(H,H')</b>. 
- <b>Complexitate O(logn)</b>: crearea unui heap este <b>O(1)</b> si <b>union</b> este <b>O(logn)</b>.

### <ins>4.6 - Delete</ins>
- <b>Pasul 1</b>: apelam <b>decreaseKey(H,x,-inf)</b>, ca nodul respectiv sa devina radacina arborelui in care se afla si sa fie si radacina de valoare minima in acelasi timp.
- <b>Pasul 2</b>: apelam <b>extractMin(H)</b>, ca sa scoatem nodul.

---

## 5 - Fibonacci Heaps 

### <ins>5.1 - Introducere</ins>
- Un <b>Fibonacci Heap</b> este o colectie de arbori, legati intre ei, care respecta proprietatea de <b>min-heap</b> (sau <b>max-heap</b>), dar unde un nod oarecare pot avea orice numar de copii => <b>NU</b> sunt arbori binari sau binomiali.
- Orice nod are urmatoarele campuri/proprietati:
    - <b><ins>key</ins></b>: cheia nodului.
    - <b><ins>value</ins></b>: valoarea nodului.
    - <b><ins>parent</ins></b>: un pointer catre parintele nodului (<b>nullptr</b> daca nu are parinte).
    - <b><ins>child</ins></b>: un pointer catre <b>unul</b> din copii (<b>nullptr</b> daca nu are copii).
    - <b><ins>left</ins></b>: un pointer catre nodul din stanga (sau catre finalul listei, daca ne aflam la inceput si e lista circulara).
    - <b><ins>right</ins></b>: un pointer catre nodul din dreapta (sau catre inceputul listei, daca ne aflam la final si e listsa circulara).
    - <b><ins>mark</ins></b>: o valoare booleana, implicit, <b>false</b>. Daca se sterge copilul unui nod, nodul respectiv devine <b>marked</b>, adica <b>mark=true</b>.
    - <b><ins>degree</ins></b>: numarul de copii pentru un nod (implicit <b>0</b>). Un nod are maxim gradul <b>log(n)</b> (demonstratie naspa cu chestii fibonacci).
- Am atasat un exemplu de structura pentru un Fibonacci Heap.

![Image](images/fibonacci-heap/structure.png)

### <ins>5.2 - Insert</ins>
- <b>Pasul 1</b>: facem un nod nou cu o <b>cheie+valoare</b>, fara <b>parent/child/left/right</b>, cu <b>mark=false</b> si <b>degree=0</b> (pentru ca nu are copii). Acum avem un arbore format dintr-un singur nod (o radacina).
- <b>Pasul 2</b>: il adaugam in lista de radacini a heap-ului si actualizam pointerul de minim (daca este cazul).
- <b>Complexitate: O(1)</b>.

### <ins>5.3 - Find minimum</ins>
- Avem un pointer care retine minimul. Afisam valoarea respectiva.
- <b>Complexitate: O(1)</b>.

### <ins>5.4 - Union</ins>
- Daca avem heap-urile <b>H1</b> si <b>H2</b>, adaugam radacinile/arborii din <b>H2</b> in lista din <b>H1</b> (doar modificam niste pointeri). Este important sa actualizam pointerul de minim (daca este cazul).
- <b>Complexitate: O(1)</b>.

### <ins>5.5 - Extract minimum</ins>
- Este cea mai importanta operatie.
- <b>Pasul 1</b>: avem pointer catre minim. Stergem nodul respectiv, iar fiii sai devin arbori liberi.
- <b>Pasul 2</b>: adaugam noii arbori rezultanti in lista de radacini a heap-ului.
- <b>Pasul 3</b>: parcurgem lista de radacini. Daca gasim o radacina care are acelasi grad cu alta radacina din trecut, le unim ca sa facem un singur arbore. Avem grija sa actualizam pointerul sa arate catre noul minim.
- <b>Complexitate: O(n)</b> pentru prima extragere (deoarece toti arborii au doar radacina => este o lista dublu inlantuita cu <b>n</b> elemente). Ulterior, devine <b>O(logn)</b> (dupa ce unim arborii).

### <ins>5.6 - Decrease key</ins>
- <b>Pasul 1</b>: micsoram valoarea nodului.
- <b>Pasul 2</b>: daca noua valoare incalca proprietatea de <b>min-heap</b> fiind mai mica decat parintele (sau invers pentru <b>max-heap</b>), o aducem in lista de radacini si marcam parintele. Daca parintele era deja marcat, il aducem si pe el in lista de radacini. Avem grija sa actualizam pointerul de minim.
- <b>Complexitate: O(1) amortizat</b>.

### <ins>5.7 - Delete</ins>
- <b>Pasul 1</b>: apelam <b>decreaseKey(node, -inf)</b> ca sa micsoram valoarea nodului sa fie <b>-inf</b>.
- <b>Pasul 2</b>: apelam <b>extractMin()</b> ca sa extragem nodul respectiv.
- <b>Complexitate: O(n)</b> prima oara, <b>O(logn)</b> ulterior.

---

#### Notes 
- <b>Seria 13</b>: AVL Trees, Splay Trees.
- <b>Seria 14</b>: Range Minimum Queries (RMQ).
- <b>Seria 15</b>: Binomial Heaps, Fibonacci Heaps.