#include <stdio.h>
#include <stdlib.h>

#define CMAX 50

typedef struct {
    char nom[CMAX];
    char prenom[CMAX];
    int salaire_brut;
    int salaire_net;
    int anciennete;
    int ir;
    int cimr;
    int amo;
    int prime;
    int cnss;
} employe;

void calcul_prime(employe *e) {
    {if (e->anciennete < 2) {
        e->prime = 0;
    } else if (e->anciennete >= 2 && e->anciennete < 5) {
        e->prime = e->salaire_brut * 0.05;
    } else if (e->anciennete >= 5 && e->anciennete < 12) {
        e->prime = e->salaire_brut * 0.1;
    } else if (e->anciennete >= 12 && e->anciennete < 25) {
        e->prime = e->salaire_brut * 0.15;
    } else if (e->anciennete >= 25) {
        e->prime = e->salaire_brut * 0.25;
    }
    }
}

void calcul_amo(employe *e) {
    e->amo = e->salaire_brut * 0.0226;
}

void calcul_cnss(employe *e) {
    if (e->salaire_brut < 6000) {
        e->cnss = e->salaire_brut * 0.064;
    } else {
        e->cnss = 384;
    }
}

void calcul_salaire(employe *e) {
    calcul_prime(e);
    calcul_amo(e);
    calcul_cnss(e);
    e->salaire_net = e->salaire_brut + e->prime - e->ir - e->cimr - e->amo - e->cnss;
}

void saisir_employe(employe *e) {
    printf("Saisir le nom: ");
    scanf("%s", e->nom);
    printf("\nSaisir le prenom: ");
    scanf("%s", e->prenom);
    printf("\nSaisir le salaire brut: ");
    scanf("%d", &(e->salaire_brut));
    printf("\nSaisir l'anciennete: ");
    scanf("%d", &(e->anciennete));
    printf("\nSaisir l'IR: ");
    scanf("%d", &(e->ir));
    printf("\nSaisir le CIMR: \n");
    scanf("%d", &(e->cimr));
}

void ecrire_bulletin(employe *e, FILE *f) {
    fprintf(f, "Nom: %s\n", e->nom);
    fprintf(f, "Prénom: %s\n", e->prenom);
    fprintf(f, "Salaire Brut: %d\n", e->salaire_brut);
    fprintf(f, "Prime: %d\n", e->prime);
    fprintf(f, "IR: %d\n", e->ir);
    fprintf(f, "CIMR: %d\n", e->cimr);
    fprintf(f, "AMO: %d\n", e->amo);
    fprintf(f, "CNSS: %d\n", e->cnss);
    fprintf(f, "Salaire Net: %d\n", e->salaire_net);
    fprintf(f, "-------------------------------\n");
}

int main() {
    employe e;
    FILE *f;

   printf("Saisir les informations de votre employe:\n");
    saisir_employe(&e);

    f = fopen("bulletin_de_paie.txt", "w");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier! \n");
        return 1;
    }
    
        calcul_salaire(&e);
        ecrire_bulletin(&e, f);


    fclose(f);
    printf("Les bulletins de paie ont ete ecrits dans bulletin_de_paie.txt \n");

    return 0;
}
