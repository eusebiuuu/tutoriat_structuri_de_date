# Table of contents
- [Table of contents](#table-of-contents)
  - [1 - BST-uri construite aleator](#1---bst-uri-construite-aleator)
  - [2 - Order Statistics Trees](#2---order-statistics-trees)
  - [3 - Interval Trees](#3---interval-trees)
  - [4 - Exercitii examen](#4---exercitii-examen)
    - [Seria 13](#seria-13)
    - [Seria 13 - rezolvari](#seria-13---rezolvari)
    - [Seria 14](#seria-14)
    - [Seria 14 - rezolvari](#seria-14---rezolvari)
    - [Seria 15](#seria-15)
    - [Seria 15 - rezolvari](#seria-15---rezolvari)

---

## <ins>1 - BST-uri construite aleator</ins>

--- 

## <ins>2 - Order Statistics Trees</ins>

### <ins>2.1 - Introducere</ins>
- **Order Statistics** se refera la al k-lea cel mai mic/mare element dintr-o multime. Un **Order Statistics Tree** este un arbore binar echilibrat (**AVL Tree**, **Red-Black Tree**, etc.) cu o proprietate in plus: fiecare nod retine **dimensiunea subarborelui inradacinat in nodul respectiv**. 
- Aceasta proprietate ne permite sa facem urmatoarele lucruri:
    - Putem gasi **rank-ul** unui element din arbore (adica index-ul la care s-ar afla elementul in vectorul sortat).
    - Putem gasi al k-lea cel mai mic/mare element.
- Cand inseram/stergem noduri, va trebui sa actualizam campul **size**.

### <ins>2.2 - Select</ins>
- **select(k)** gaseste al k-lea cel mai mic element din arbore.
- Verificam dimensiunea subarborelui stang. Exista 3 cazuri:
    - **k == size(node->left) + 1**: al k-lea cel mai mic element este chiar nodul curent.
    - 

### <ins>2.3 - Insert</ins>

### <ins>2.4 - Delete</ins>

---

## <ins>3 - Interval Trees</ins>

---

## <ins>4 - Exercitii examen</ins>

### <ins>Seria 13</ins>

### <ins>Seria 13 - rezolvari</ins>

### <ins>Seria 14</ins>

### <ins>Seria 14 - rezolvari</ins>

### <ins>Seria 15</ins>

### <ins>Seria 15 - rezolvari</ins>
