 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "auclidian.c"

struct Matrice
{
  struct Polynom p0;
  struct Polynom p1;
  struct Polynom p2;
  struct Polynom p3;
  struct Polynom p4;
  struct Polynom p5;
  struct Polynom p6;
  struct Polynom p7;
};

typedef struct Matrice Matrice;

struct Matrice setMatrice(struct Polynom p0, struct Polynom p1, struct Polynom p2, struct Polynom p3, struct Polynom p4, struct Polynom p5, struct Polynom p6, struct Polynom p7);

Polynom matriceMultiplication(Matrice m, Polynom p);

void printMatrice(struct Matrice m);

Polynom subByteLayer(struct Polynom p, Matrice m, PolynomIrreducible eri);

void printVector(Polynom p);


int main() {

    Polynom p1 = setPolynom(0,0,1,1,0,0,1,1);
    Polynom p2 = setPolynom(1,1,0,1,1,0,0,0);

    Matrice affineMatrice = setMatrice( setPolynom(1,0,0,0,1,1,1,1),
        setPolynom(1,1,0,0,0,1,1,1),
        setPolynom(1,1,1,0,0,0,1,1),
        setPolynom(1,1,1,1,0,0,0,1),
        setPolynom(1,1,1,1,1,0,0,0),
        setPolynom(0,1,1,1,1,1,0,0),
        setPolynom(0,0,1,1,1,1,1,0),
        setPolynom(0,0,0,1,1,1,1,1)
    );



    PolynomIrreducible dp2 = setPolynomIrreducible(1,1,0,1,1,0,0,0,1) ;

    Polynom k = setPolynom(1,1,0,0,0,0,1,0) ;

    printVector(findInverseOfPolynom(k, dp2));



   // printVector(subByteLayer(k, affineMatrice, dp2));


  return 0;
}


 Polynom subByteLayer(struct Polynom p, Matrice m, PolynomIrreducible eri)
{
  return matriceMultiplication(m, findInverseOfPolynom(p,eri)) ;
};

Matrice setMatrice(struct Polynom p0,struct Polynom p1,struct Polynom p2,struct Polynom p3,struct Polynom p4,struct Polynom p5,struct Polynom p6,struct Polynom p7)
{
  struct Matrice m = {p0, p1, p2, p3, p4, p5, p6, p7} ;
  return m;
};

void printMatrice(struct Matrice m)
{
  printf("\n| %d %d %d %d %d %d %d %d |\n", m.p0.a0, m.p0.a1, m.p0.a2, m.p0.a3, m.p0.a4, m.p0.a5, m.p0.a6, m.p0.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p1.a0, m.p1.a1, m.p1.a2, m.p1.a3, m.p1.a4, m.p1.a5, m.p1.a6, m.p1.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p2.a0, m.p2.a1, m.p2.a2, m.p2.a3, m.p2.a4, m.p2.a5, m.p2.a6, m.p2.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p3.a0, m.p3.a1, m.p3.a2, m.p3.a3, m.p3.a4, m.p3.a5, m.p3.a6, m.p3.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p4.a0, m.p4.a1, m.p4.a2, m.p4.a3, m.p4.a4, m.p4.a5, m.p4.a6, m.p4.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p5.a0, m.p5.a1, m.p5.a2, m.p5.a3, m.p5.a4, m.p5.a5, m.p5.a6, m.p5.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p6.a0, m.p6.a1, m.p6.a2, m.p6.a3, m.p6.a4, m.p6.a5, m.p6.a6, m.p6.a7);
  printf("| %d %d %d %d %d %d %d %d |\n", m.p7.a0, m.p7.a1, m.p7.a2, m.p7.a3, m.p7.a4, m.p7.a5, m.p7.a6, m.p7.a7);

};

Polynom matriceMultiplication(Matrice m, Polynom p)
{

    int a0 = (p.a0*m.p0.a0 + p.a1*m.p0.a1 + p.a2*m.p0.a2 + p.a3*m.p0.a3 + p.a4*m.p0.a4 + p.a5*m.p0.a5 + p.a6*m.p0.a6 + p.a7*m.p0.a7)%2 ;
    int a1 = (p.a0*m.p1.a0 + p.a1*m.p1.a1 + p.a2*m.p1.a2 + p.a3*m.p1.a3 + p.a4*m.p1.a4 + p.a5*m.p1.a5 + p.a6*m.p1.a6 + p.a7*m.p1.a7)%2 ;
    int a2 = (p.a0*m.p2.a0 + p.a1*m.p2.a1 + p.a2*m.p2.a2 + p.a3*m.p2.a3 + p.a4*m.p2.a4 + p.a5*m.p2.a5 + p.a6*m.p2.a6 + p.a7*m.p2.a7)%2 ;
    int a3 = (p.a0*m.p3.a0 + p.a1*m.p3.a1 + p.a2*m.p3.a2 + p.a3*m.p3.a3 + p.a4*m.p3.a4 + p.a5*m.p3.a5 + p.a6*m.p3.a6 + p.a7*m.p3.a7)%2 ;
    int a4 = (p.a0*m.p4.a0 + p.a1*m.p4.a1 + p.a2*m.p4.a2 + p.a3*m.p4.a3 + p.a4*m.p4.a4 + p.a5*m.p4.a5 + p.a6*m.p4.a6 + p.a7*m.p4.a7)%2 ;
    int a5 = (p.a0*m.p5.a0 + p.a1*m.p5.a1 + p.a2*m.p5.a2 + p.a3*m.p5.a3 + p.a4*m.p5.a4 + p.a5*m.p5.a5 + p.a6*m.p5.a6 + p.a7*m.p5.a7)%2 ;
    int a6 = (p.a0*m.p6.a0 + p.a1*m.p6.a1 + p.a2*m.p6.a2 + p.a3*m.p6.a3 + p.a4*m.p6.a4 + p.a5*m.p6.a5 + p.a6*m.p6.a6 + p.a7*m.p6.a7)%2 ;
    int a7 = (p.a0*m.p7.a0 + p.a1*m.p7.a1 + p.a2*m.p7.a2 + p.a3*m.p7.a3 + p.a4*m.p7.a4 + p.a5*m.p7.a5 + p.a6*m.p7.a6 + p.a7*m.p7.a7)%2 ;

    return setPolynom(a0, a1, a2, a3, a4, a5, a6, a7);
};


void printVector(Polynom p)
{
  printf("\n|%d|\n", p.a0);
  printf("|%d|\n", p.a1);
  printf("|%d|\n", p.a2);
  printf("|%d|\n", p.a3);
  printf("|%d|\n", p.a4);
  printf("|%d|\n", p.a5);
  printf("|%d|\n", p.a6);
  printf("|%d|\n", p.a7);
};


