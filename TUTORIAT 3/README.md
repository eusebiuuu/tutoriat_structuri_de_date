# Table of contents
- [Binary Search Trees](#1---binary-search-trees)
- [Exercitii de examen](#2---exercitii-examen)
    - [Seria 13](#seria-13)
    - [Seria 14](#seria-14)
    - [Seria 15](#seria-15)

---

## 1 - Binary Search Trees

![Image](images/bst.png)

---

## 2 - Exercitii de examen

###  Seria 13

1. Traversarea in <b>postordine</b> a unui arbore binar de cautare este <b>15, 10, 23, 25, 20, 35, 42, 39, 30</b>. Care este traversarea in <b>inordine</b> pentru acelasi arbore?
2. Urmatoarele numere sunt inserate succesiv intr-un arbor binar de cautare gol: <b>1, 3, 5, 10, 15, 12, 16</b>. Care este inaltimea arborelui la final?
3. Se considera urmatoarele elemente: <b>(4322, 1334, 1471, 9679, 1989, 6171, 6173, 4199)</b> si functia de hash <b>h(x) = x mod 100</b>. Care dintre urmatoarele afirmatii sunt adevarate?
    -  <b>1471, 6171</b> produc o coliziune.
    -  <b>9679, 1989, 4199</b> se mapeaza pe aceeasi valoare.
    -  Toate elementele se mapeaza pe valori distincte.
    -  Incarcarea tabelei este de <b>7%</b>.
4. Care din urmatoarele secvente <b>NU</b> este una din traversarile in <b>preordine</b> sau <b>postordine</b> ale unui arbore binar de cautare in care s-au inserat valorile <b>(10, 20, 5, 30, 8, 25, 6, 4, 9)</b>?
    - <b>4, 5, 6, 8, 9, 10, 20, 25, 30</b>.
    - <b>10, 5, 8, 4, 6, 9, 20, 25, 30</b>.
    - <b>10, 5, 20, 4, 8, 30, 6, 9, 25</b>.
    - Raspunsurile de mai sus nu sunt corecte.
5. Care din urmatoarele secvente de operatii este <b>imposibila</b> intr-o stiva cu <b>4</b> elemente?
    - PUSH, POP, POP, POP, POP, PUSH.
    - PUSH, POP, POP, POP, PUSH, POP, POP.
    - PUSH, POP, POP, POP, POP, POP, PUSH, POP.
    - PUSH, PUSH, PUSH, PUSH, PUSH, PUSH.
    - POP, POP, POP, POP, POP, POP, POP.
6. Cand numarul de slot-uri intr-un hash table se tripleaza, iar numarul de elemente se dubleaza, ce se intampla cu load factor-ul ei?
    - Creste la <b>3/2</b> din cel initial.
    - Scade la <b>2/3</b> din cel initial.
    - Ramane la fel.
    - Raspunsurile de mai sus nu sunt corecte.
7. Sa presupunem ca vrem sa afisam in ordine descrescatoare elementele unui arbore binar de cautare. Care dintre urmatoarele metode ar fi potrivite?
    - Parcurgem arborele in <b>inordine</b> punand nodurile intr-o stiva. La sfarsit, le printam pe masura ce le scoatem din stiva.
    - Parcurgem arborele in <b>preordine</b> punand nodurile intr-o coada. La sfarsit, le printam pe masura ce le scoatem din coada.
    - Parcurgem arborele recursiv cu ordinea <b>RIGHT-VERTEX-LEFT</b>.
    - Raspunsurile de mai sus nu sunt corecte.
8. Care este complexitatea gasirii <b>elementului median</b> intr-o lista dublu inlantuita data prin pointerul head?
    - Θ(n).
    - Θ(nlogn).
    - Θ(n<sup>2</sup>).
    - Raspunsurile de mai sus nu sunt corecte.
9. Vrem sa reprezentam multimea <b>S = {1, 2, 3}</b> cu un arbore binar de cautare. In cate moduri distincte putem face acest lucru?
    - <b>1</b> mod.
    - <b>2</b> moduri.
    - <b>3</b> moduri.
    - <b>8</b> moduri.
    - Raspunsurile de mai sus nu sunt corecte.
10. Un skip list are elementele <b>1, 2, 3, 5, 8, 13, 21, 44</b>. In al catalea nod vom gasi elementul <b>8</b>?
    - Primul nod.
    - Al doilea nod.
    - Al patrulea nod.
    - Al optulea nod.
    - Raspunsurile de mai sus nu sunt corecte.
11. Se da o expresie aritmetica reprezentata ca un arbore sintactic (imagine). Care este ordinea in care sunt evaluate nodurile pentru a calcula valoarea expresiei?
![Image](images/expression_tree.png)
    - <b>a,+,b,*,c,root(+),7</b>.
    - <b>7,a,b,c,+,*,root(+)</b>.
    - <b>a,b,+,c,*7,root(+)</b>.
    - Raspunsurile de mai sus nu sunt corecte.
12. Pentru algoritmul <b>Heap Sort</b>, numarul minim de swap-uri de elemente se atinge cand:
    - Secventa initiala este sortata crescator.
    - Secventa initiala este sortata descrescator.
    - Secventa este una aleatoare.
    - Raspunsurile de mai sus nu sunt corecte.
13. In cate moduri putem pune numerele <b>1,2,3,4</b> intr-un vector, astfel incat vectorul rezultat sa poata fi vazut drept un min-heap?
    - <b>2</b> moduri.
    - <b>3</b> moduri.
    - <b>7</b> moduri.
    - Raspunsurile de mai sus nu sunt corecte.
14. Sa presupunem ca numerele <b>7,5,1,8,3,6,0,9,4,2</b> sunt inserate in aceasta ordine intr-un arbore binar de cautare. Care este lista elementelor in postordine?
    - <b>7 5 1 0 3 2 4 6 8 9</b>.
    - <b>0 2 4 3 1 6 5 9 8 7</b>.
    - <b>0 1 2 3 4 5 6 7 8 9</b>.
    - <b>9 8 6 4 2 3 0 1 5 7</b>.
15. Pentru a efectua o stergere intr-un arbore binar de cautare pentru un nod cu 2 copii, trebuie sa ii gasim succesorul (in inordine). Care dintre urmatoarele afirmatii este adevarata?
    - Succesorul este intotdeauna un nod frunza.
    - Succesorul este intotdeauna fie un nod frunza, fie un nod fara copil stang.
    - Succesorul poate fi un stramos al nodului.
    - Succesorul este intotdeauna fie un nod frunza, fie un nod fara copil drept.
16. Care dintre urmatoarele afirmatii sunt adevarate intr-un <b>Skip List</b>?
    - Probabilitatea ca un nod sa aiba cel putin doi pointeri este exact <b>1/4</b>.
    - Elementele sunt sortate in ordine crescatoare.
    - Nivelurile sunt spatiate in mod egal.
    - Raspunsurile de mai sus nu sunt corecte.
17. Presupunem ca avem arborele binar de cautare de la exercitiul 14. Care este elementul median?
18. Sa presupunem ca modificam algoritmul de parcurgere in latime (<b>BFS</b>) a unui arbore binar in felul urmator: in loc de o coada, folosim o coada dubla (<b>deque</b>); cand scoatem primul nod din coada, mai intai il vizitam, iar vecinii nodului respectiv ii adaugam in varful cozii duble. Modificarea astfel descrisa este echivalenta cu o parcurgere a arborelui:
    - In preordine.
    - In inordine.
    - In postordine.
    - In adancime.
    - Raspunsurile de mai sus nu sunt corecte.
19. Sa presupunem ca modificam un <b>Skip List</b> ca sa putem face salturi inainte si inapoi, folosind intuitiv liste dublu inlantuite pe fiecare nivel. Ne vom limita la patru nivele de pointeri. Nivelul unui nod va fi ales in mod obisnuit. Numarul total mediu de pointeri in aceasta varianta de implementare este:
    - Θ(n).
    - Θ(nlogn).
    - Θ(n<sup>2</sup>).
    - Raspunsurile de mai sus nu sunt corecte.
20. Sa consideram o schema de double hashing care mapeaza elementele unui univers <b>U</b> pe multimea de indecsi <b>{0, 1, ..., m-1}</b> via functia <b>h(x,i) = (h1(x) + i * h2(x)) (mod m)</b>, unde <b>m</b> este marimea tabelei, iar <b>h1</b> si <b>h2</b> sunt niste functii de hashing. Sa consideram functiile <b>H1(x,i) = (h2(x) + i * h1(x)) (mod m)</b> si <b>H2(x,i) = (h2(x) - 1 + i * (h1(x) + 1)) (mod m)</b>. Care dintre functiile <b>H1, H2</b> sunt potrivite, in principiu, in loc de <b>h</b> pentru <b>double hashing</b>?
    - Doar <b>H1</b>.
    - Doar <b>H2</b>.
    - <b>H1</b> si <b>H2</b>.
    - Niciuna.
21. Ce face urmatorul cod?
    - Printeaza toate valorile listei.
    - Printeaza toate valorile listei in ordine inversa.
    - Printeaza valorile cu index par ale listei.
    - Printeaza valorile cu index par ale listei in ordine inversa.

```cpp
void f(struct node* head) {
    if (!head) {
        return;
    }
    f(head->next);
    std::cout<<head->data;
}
```

### Seria 14

1. Exprimati functiile urmatoare in notatie Θ:
    - <b>log(sqrt(n))</b>.
    - <b>(n + 2<sup>200</sup>)<sup>500</sup></b>.
    - <b>n<sup>4</sup> - n<sup>4</sup>/2 + 10000 * n + 10</b>.
    - <b>ln(ln n) + ln n</b>.
    - <b>n<sup>3</sup>/2000 + n<sup>2</sup> * 2<sup>100000</sup> + 10000 * n + 10</b>.
    - <b>ln<sup>2</sup>n + sqrt(n)</b>.
2. <b>o(f(n)) INTERSECT ω(f(n))</b> = ?
3. Cate muchii are un arbore binar complet cu <b>n</b> noduri?
4. Sa se construiasca un <b>min-heap</b> obtinut prin insertia pe rand a urmatoarelor chei: <b>{40, 22, 2, 18, 19, 5, 3}</b>. Apoi, sa se extraga radacina din heap-ul rezultat.
5. Sa se construiasca arborele binar obtinut prin insertia pe rand a urmatoarelor chei: <b>{15, 22, 2, 18, 19, 40, 30, 16, 50}</b>. Sa se stearga nodul <b>22</b>.
6. Demonstrati ca orice algoritm de sortare bazat pe comparatii intre chei are timp de rulare <b>Ω(nlogn)</b>.
7. Rezolvati urmatoarele recurente si demonstrati: 
    - <b>T(n) = T(n/4) + T(3n/4) + logn</b>.
    - <b>T(n) = T(n/100) + T(99n/100) + n</b>.
    - <b>T(n) = T(n - 1) + n</b>.
8. Demonstrati ca <b>logn = o(sqrt(n))</b>.
9. Se da un arbore binar cu <b>n</b> noduri in urmatorul format: se specifica radacina, iar pentru fiecare nod se dau fiul stang si fiul drept, daca acestia exista. De asemenea, fiecarui nod ii este asociat un numar intreg. Sa se decida daca acest arbore binar este <b>arbore binar de cautare</b>. Timp de rulare: <b>O(n<sup>2</sup>)</b>=0,5p, <b>O(nlogn)</b>=1p, <b>O(n)</b>=1,5p.
10. Care este numarul minim si numarul maxim de noduri intr-un <b>Heap</b> de inaltime <b>h</b>?
11. Este adevarat ca <b>f(n) + g(n) = Θ(max{f(n), g(n)})</b>? Demonstrati.
12. Demonstrati ca orice algoritm care construieste un arbore binar de cautare cu <b>n</b> numere ruleaza in timp <b>Ω(n)</b>.
13. Cum se poate implementa o <b>coada</b> folosind un <b>heap</b>? Dar o <b>stiva</b>?
14. Se dau <b>n</b> numere intre <b>0</b> si <b>k</b>. Descrieti un algoritm care preproceseaza input-ul in timp <b>O(n + k)</b> si raspunde in <b>O(1)</b> la intrebari de forma: "Se citesc 2 numere <b>0 <= a, b <= k</b>. Cate din cele <b>n</b> numere date ca input se gasesc in intervalul <b>[a..b]</b>?".
15. Cum putem sorta <b>n</b> numere in intervalul <b>[0..(n<sup>3</sup> - 1)]</b> in timp <b>O(n)</b>?
16. Desenati un arbore binar complet cu <b>7</b> noduri si desenati matricea de adiacenta corespunzatoare.
17. Se dau urmatoarele structuri de date: o stiva <b>S</b> si doua cozi <b>C1, C2</b> ce contin caractere. Cele trei structuri sunt initial vide si se considera de capacitate infinita. Cozile se considera cu capatul pentru inserare in dreapta si cel pentru stergere in stanga, iar stiva are capatul pentru inserare si stergere in dreapta. Se considera urmatoarele operatii: <b>(1)</b> daca <b>S</b> e nevida, se extrage un element si se introduce <b>C1</b>; altfel, nu se face nimic. <b>(2)</b> Daca <b>S</b> e nevida, se extrage un element si se introduce <b>C2</b>; altfel, nu se face nimic. <b>(3)</b> Daca <b>C1</b> e nevida, se extrage un element si se introduce in <b>C2</b>; altfel, nu se face nimic. <b>(4)</b> Daca <b>C2</b> e nevida, se extrage un element si se introduce in <b>S</b>; altfel, nu se face nimic.
    - Sa se scrie continutul stivei <b>S</b> si al cozilor <b>C1, C2</b> dupa executarea urmatoarei secvente de operatii: <b>C 1 3 K 2 S T A Q U 1 2 U N 1 1 E U 2 2 4 4</b>.
    - Sa se scrie o secventa de operatii care are ca rezultat cuvantul <b>"ROSU"</b> in stiva <b>S</b>, cuvantul <b>VERDE</b> in coada <b>C2</b>, iar <b>C1</b> este vida.
18. Demonstrati ca <b>ln(n!) = Θ(n * ln n)</b>.
19. Fie <b>T</b> un arbore binar de cautare si <b>x</b> un nod care are doi copii. Demonstrati ca succesorul lui <b>x</b> nu are fiu stang, iar predecesorul lui <b>x</b> nu are fiu drept.
20. Scrieti un algoritm in pseudocod care sa rezolve urmatoarea problema: se da o multime <b>S</b> ce contine <b>n</b> numere naturale distincte si un numar natural <b>x</b>. Decideti daca numarul <b>x</b> poate fi exprimat ca suma de 2 numere distincte din <b>S</b>. Pentru un algoritm <b>O(n<sup>2</sup>)</b>, se primesc 0,25p; pentru <b>O(nlogn)</b> sau <b>O(n)</b>, se primeste punctaj intreg.

### Seria 15

1. Dintre inserare, cautare si stergerea minimului, ce operatie are complexitatea cea mai mare intr-un <b>min-heap</b> si ce complexitate are? Explicati cum se face aceasta operatie si daca este uzuala pentru heap-uri.
2. Intr-un arbore binar de cautare, se fac urmatoarele operatii: <b>{I(5), I(3), I(14), I(11), I(31), del(3), I(7), del(11), I(9), I(8), I(16), I(17), del(14)}</b>. Aratati arborele dupa fiecare 2 operatii.
3. Inserati intr-un <b>Hash Table</b> valorile <b>{19, 20, 4, 23, 1, 42, 81, 67, 219, 192, 87}</b> folosind functia de dispersie <b>h(x) = x % 20</b> si <b>adresare directa</b> pentru rezolvarea coliziunilor.
4. Ce inaltime poate sa aiba un heap cu <b>30</b> de elemente? Desenati schita arborelui de inaltime minima si schita pentru cel de inaltime maxima.
5. Construiti un arbore binar cu <b>12</b> noduri si diametrul <b>5</b>.
6. Exemplificati cum functioneaza <b>Merge Sort</b> pe vectorul <b>{16, 14, 9, 23, 3, 141, 19, 11}</b>.
7. Exemplificati cum functioneaza <b>Radix Sort (MSD)</b> in baza 10 pe vectorul <b>{16, 14, 39, 23, 3, 141, 19, 911, 151, 91, 209, 49, 206}</b>.
8. Daca vrem sa sortam <b>10<sup>6</sup></b> numere reale mai mici sau egale cu <b>245859</b>, ce algoritm ar fi bine sa folosim? De ce?
9. Cat ne costa sa gasim cel mai mic element dintr-un <b>Deque</b>? Cum il gasim?
10. Inserati intr-un <b>Skip List</b> urmatoarele valori: <b>{6, 29, 3, 15, 7, 14, 22, 19, 14}</b>. Aruncati cu banul si obtineti valorile <b>{B, S, S, B, S, S, B, S, B, S, S, S, B, S, S, S, S, S, B, S, B, B, S, S, S, S, B}</b>. Cand dati <b>B</b>, va opriti si inserati la nivelul respectiv; altfel, continuati.
11. Cati arbori binari distincti cu valorile <b>{1,2,3,4,5,6}</b> putem avea?
12. Desenati un <b>Max-Heap</b> in care un element aflat la distanta <b>3</b> fata de radacina este mai mare decat un element aflat la distanta <b>1</b> fata de radacina.
13. Exemplificati cum functioneaza <b>cautarea binara</b> pe un vector de 8 elemente, ales de voi.
14. Rezolvati (in pseudocod) urmatoarea problema: se dau niste litere acceptate si o lista de cuvinte. Ce cuvinte din lista au doar litere acceptate?
15. Rezolvati (in pseudocod): se da un vector. Pentru fiecare element, spuneti care este primul element din stanga mai mare decat el.
16. Rezolvati (in pseudocod): se da un vector; pentru fiecare element, spuneti cate elemente din dreapta sa sunt mai mici decat el.
17. Ce inaltime poate sa aiba un arbore binar cu <b>24</b> de elemente? Desenati arborele de inaltime minima si cel de inaltime maxima.
18. Se da un arbore binar. Gasiti suma maxima a unor elemente care nu se invecineaza.
19. Cat ne costa sa aflam al doilea cel mai mic element dintr-un <b>Min-Heap</b>?
20. Se da un vector cu valori intregi. Eliminati duplicatele.

---

#### Notes 
- <b>Seria 13</b>: BSTs (Binary Search Trees).
- <b>Seria 14</b>: Sortari in timp liniar (Count Sort, Bucket Sort, Radix Sort; toate discutate la Tutoriat 1), limite inferioare pentru sortare.
- <b>Seria 15</b>: Hash Tables (discutate la Tutoriat 2).