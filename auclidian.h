#ifndef AUCLIDIAN_H_INCLUDED
#define AUCLIDIAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Polynom
{
  int a0;
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
};

struct PolynomDoubleDegree
{
  int a0;
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
  int a8;
  int a9;
  int a10;
  int a11;
  int a12;
  int a13;
  int a14;
};

struct PolynomIrreducible
{
  int a0;
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
  int a8;
};



typedef struct Polynom Polynom;

typedef struct PolynomDoubleDegree PolynomDoubleDegree;

typedef struct PolynomIrreducible PolynomIrreducible;


int bynarryAddition(int a, int b);

extern struct Polynom setPolynom(int a0, int a1 , int a2 , int a3, int a4, int a5, int a6, int a7);

extern struct PolynomIrreducible setPolynomIrreducible(int a0, int a1 , int a2 , int a3, int a4, int a5, int a6, int a7, int a8);

extern int comparePolynomDegree(struct Polynom p1, struct Polynom p2);

extern struct Polynom polynomAddition(struct Polynom p1, struct Polynom p2);

extern int polynomDegree(struct PolynomDoubleDegree p);

extern struct Polynom polynomLimitedMultiplication(struct Polynom p1 , struct Polynom p2);

extern struct PolynomDoubleDegree polynomDoubleDegreeAddition(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2);

extern struct PolynomDoubleDegree getPolynomDoubleDegreeFromPolynom(struct Polynom p);

extern struct PolynomIrreducible getPolynomIrreducibleFromPolynom(struct Polynom p);

extern struct PolynomDoubleDegree getPolynomDoubleDegreeFromPolynomIrreducible(struct PolynomIrreducible p);

extern int compareDegreeOfPolynomDoubleDegree(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2);

extern struct PolynomDoubleDegree degreeDecalageOfPolynomDoubleDegree(struct PolynomDoubleDegree p, int decalage);

extern struct PolynomDoubleDegree normalMultiplicationOfPolynomDoubleDegree(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2);

extern struct PolynomDoubleDegree * polynomDivision(struct PolynomDoubleDegree p1, struct PolynomIrreducible p2);

extern struct Polynom findInverseOfPolynom(struct Polynom p, struct PolynomIrreducible PIR);

extern bool isPolynomDoubleDegreeEqual(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2);

extern struct PolynomDoubleDegree moduloPolynom(struct PolynomDoubleDegree p, struct PolynomIrreducible ird);

struct Polynom multiplicationModuloOfPolynom(struct Polynom p1, struct Polynom p2, struct PolynomIrreducible ird);

extern void printPolynom(struct Polynom p1);

extern void printDoubleDegreePolynom(struct PolynomDoubleDegree p1);

extern void printPolynomIrreducible(struct PolynomIrreducible p1);

extern struct Polynom multiplicationModuloOfPolynom(struct Polynom p1, struct Polynom p2, struct PolynomIrreducible ird);

#endif // AUCLIDIAN_H_INCLUDED
