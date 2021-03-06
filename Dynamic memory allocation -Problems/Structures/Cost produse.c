/*
    Programmer : Anamaria Andra Pescaru
    Cerinta : Cost produse
Sunteți responsabili de crearea unui soft pentru gestiunea comenzilor pentru un magazin online.
Date de intrare:
Se vor citi de la tastatură linii separate conținând următoarele date, în ordine:
● Un număr natural 𝑛 ϵ {1, 2}reprezentând o comandă;
● Până la întâlnirea EOF se vor citi linii conținând datele tranzacțiilor diferite efectuate de clienți sub forma:
<nume_client> <nr_produse> <pret_produs>
unde:
<nume_client> este un șir de maxim 50 de caractere fără spații reprezentând numele clientului
<nr_produse> este o valoare întreagă fără semn reprezentând numărul de produse din tranzacție
<pret_produs> este o valoare întreagă fără semn reprezentând prețul fiecărui produs din tranzacție
Un client poate face mai multe achiziții, iar prețurile produselor pot varia între achiziții diferite.
În funcție de valorea comenzii (1 sau 2), se vor executa diferite procese:
● Valoarea 1 – Se vor afișa pe ecran, în ordinea primei introduceri de la tastatură, numele tuturor clienților care
au achiziționat în total cel puțin 20 produse sau care au cheltuit o sumă mai mare sau egală cu 1000. Fiecare
nume se va afișa pe o nouă linie, urmat de caracterul newline. Pentru a simplifica afișarea, fiecare linie (inclusiv
ultima) va fi urmată de un caracter newline (tasta Enter). Dacă nu există niciun client care să satisfacă aceste
cerințe se va afișa '-' pe ecran.
● Valoarea 2 – Magazinul oferă reduceri la achiziția mai multor produse de același fel astfel: la fiecare 5 produse
de același fel cumpărate se scade valoarea unuia dintre produse. Să se determine dacă există mai mulți clienți
ce au cheltuit aceeași sumă. În caz afirmativ, să se afișeze pe ecran tuplete formate din numele clienților care
au cheltuit aceeași sumă, în ordinea primei introduceri de la tastatură a primului nume din tuplet. Pentru a
simplifica afișarea, fiecare nume va fi urmat de caracterul ' ' (spațiu) și fiecare linie (inclusiv ultima) va fi urmată
de un caracter newline (tasta Enter). În caz contrar, se va afișa '-' pe ecran.

*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef long long ll;
typedef struct tranzactii tranzactii;

struct tranzactii{
char *nume;
int nr_produse;
int pret;
};

int main(){

   //FILE *input, *output;
   // input = fopen("input.txt", "rt");
   // output = fopen("output.txt", "wt");
    
    int n;
    scanf("%d", &n);

    tranzactii *p = (tranzactii*)malloc(100*sizeof(tranzactii));
    int i = 0, ok = 0;
    (p + i)->nume = (char*)malloc(51*sizeof(char));

    while(scanf("%s", (p + i)->nume) != EOF){
        scanf("%d", &((p+i)->nr_produse));
        scanf("%d", &((p+i)->pret));
        ((p+i)->pret) = ((p+i)->pret) * ((p+i)->nr_produse);
        i++;
         (p + i)->nume = (char*)malloc(51*sizeof(char));
    }

    tranzactii *copie = (tranzactii*)malloc(100*sizeof(tranzactii));

    int m = i, l = 0;
    for(i = 0; i < m ; i++){
        if(((p + i)->nr_produse) != -1){
            for(int j = i + 1;j < m; j ++){
            if(*((p + i)->nume) == *((p + j)->nume)){
                ((p + i)->nr_produse) += ((p + j)->nr_produse);
                ((p + i)->pret) += ((p + j)->pret) ;
                (p + j)->nr_produse = -1;
            }
        }
        (copie + l)->nume = (char*)malloc(51*sizeof(char));
        (copie + l)->nume = (p + i)->nume;
        ((copie + l)->nr_produse) = ((p + i)->nr_produse);
        ((copie + l)->pret) = ((p + i)->pret);
        l ++;
        }
        
    }
    for(i = 0; i < l;i ++){
        if(((copie + i)->nr_produse)>= 20 || ((copie + i)->pret) >= 1000)
         printf("%s\n", (copie + i)->nume );
    }

	return 0;
}


