

#include "auclidian.h"





struct Polynom setPolynom(int a0, int a1 , int a2 , int a3, int a4, int a5, int a6, int a7)
{
  struct Polynom p = {a0,a1,a2,a3,a4,a5,a6,a7};
  return p;

};

struct PolynomDoubleDegree setPolynomDoubleDegree(int a0, int a1 , int a2 , int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  struct PolynomDoubleDegree p = {a0,a1,a2,a3,a4,a5,a6,a7, a8, a9,a10,a11,a12,a13,a14};
  return p;

};

struct PolynomIrreducible setPolynomIrreducible(int a0, int a1 , int a2 , int a3, int a4, int a5, int a6, int a7, int a8)
{
  struct PolynomIrreducible p = {a0,a1,a2,a3,a4,a5,a6,a7, a8};
  return p;
};





struct Polynom multiplicationModuloOfPolynom(struct Polynom p1, struct Polynom p2, struct PolynomIrreducible ird)
{
  struct PolynomDoubleDegree polynom = moduloPolynom(normalMultiplicationOfPolynomDoubleDegree(getPolynomDoubleDegreeFromPolynom(p1),getPolynomDoubleDegreeFromPolynom(p2)), ird) ;
  if(polynomDegree(polynom) < 8)
  {
    return setPolynom(polynom.a0, polynom.a1, polynom.a2, polynom.a3, polynom.a4, polynom.a5, polynom.a6, polynom.a7) ;
  }
  else
  {
    return setPolynom(0,0,0,0,0,0,0,0);
  }
};

struct PolynomDoubleDegree moduloPolynom(struct PolynomDoubleDegree p, struct PolynomIrreducible ird)
{
  struct PolynomDoubleDegree* result = malloc(sizeof(struct PolynomDoubleDegree) * 2);
  result = polynomDivision(p, ird);
  return *result;
};

struct Polynom findInverseOfPolynom(struct Polynom p, struct PolynomIrreducible PIR)
{

  struct PolynomDoubleDegree a = setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0) ;

  struct PolynomDoubleDegree u = getPolynomDoubleDegreeFromPolynomIrreducible(PIR);
  struct PolynomDoubleDegree v = getPolynomDoubleDegreeFromPolynom(p);

  struct PolynomDoubleDegree invers ;
  struct PolynomDoubleDegree X ;
  struct PolynomDoubleDegree Y ;



  struct PolynomDoubleDegree* result = malloc(sizeof(struct PolynomDoubleDegree) * 2);

  /*

                   N = 1 ; T = 0

  r0 = A*a0 + P    X0 = N0*a0 + T                                 #0

  r1 = r0*a1 + A   X1 = X0*a1 + N                                 #1

  r2 = r1*a2 + r0  X2 = X1*a2 + X0                                #2

  1  = r2*a3 + r1  X3 = X2*a3 + X1                                #3

  */


  int while_security = 0 ;

  result = polynomDivision(u, setPolynomIrreducible(v.a0, v.a1, v.a2, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8)) ;
  invers = *(result + 1) ;
  X = invers ;
  u = v ;
  v = *result ;

  result = polynomDivision(u, setPolynomIrreducible(v.a0, v.a1, v.a2, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8)) ;
  invers = normalMultiplicationOfPolynomDoubleDegree(invers, *(result + 1)) ;
  invers = polynomDoubleDegreeAddition(invers, a) ;

  u = v ;
  v = *result ;

  while(!isPolynomDoubleDegreeEqual(v, a) && while_security < 20)
  {
    Y = invers;
    result = polynomDivision(u, setPolynomIrreducible(v.a0, v.a1, v.a2, v.a3, v.a4, v.a5, v.a6, v.a7, v.a8)) ;
    invers = normalMultiplicationOfPolynomDoubleDegree(invers, *(result + 1)) ;
    invers = polynomDoubleDegreeAddition(invers, X);
    X = Y;
    u = v ;
    v = *result ;
    while_security++;
    free(result);
  }

  return setPolynom(invers.a0, invers.a1, invers.a2, invers.a3, invers.a4, invers.a5, invers.a6, invers.a7);

};


struct PolynomDoubleDegree degreeDecalageOfPolynomDoubleDegree(struct PolynomDoubleDegree p, int decalage)
{
  int polynom_degree = polynomDegree(p);
  if((polynom_degree + decalage) < 15)
  {
    switch(decalage)
    {
      case 0:
        return p;
      case 1:
        return setPolynomDoubleDegree(0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, p.a9, p.a10, p.a11, p.a12, p.a13);
      case 2:
        return setPolynomDoubleDegree(0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, p.a9, p.a10, p.a11, p.a12);
      case 3:
        return setPolynomDoubleDegree(0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, p.a9, p.a10, p.a11);
      case 4:
        return setPolynomDoubleDegree(0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, p.a9, p.a10);
      case 5:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, p.a9);
      case 6:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8);
      case 7:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7);
      case 8:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6);
      case 9:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4, p.a5);
      case 10:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3, p.a4);
      case 11:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, p.a0, p.a1, p.a2, p.a3);
      case 12:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  p.a0, p.a1, p.a2);
      case 13:
        return setPolynomDoubleDegree(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  p.a0, p.a1);
      case 14:
        return setPolynomDoubleDegree(0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, p.a0);
      default:
        return  setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    }
  }
  else
  {
    return setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  }

};

struct PolynomDoubleDegree normalMultiplicationOfPolynomDoubleDegree(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2)
{

  struct PolynomDoubleDegree p = setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  struct PolynomDoubleDegree q = setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

  if((polynomDegree(p1) + polynomDegree(p2)) < 15)
  {
    if(p1.a14 == 1)
    {
      p = degreeDecalageOfPolynomDoubleDegree(p2, 14);
    }if(p1.a13 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 13);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a12 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 12);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a11 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 11);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a10 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 10);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a9 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 9);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a8 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 8);
      p = polynomDoubleDegreeAddition(q, p);
    }
    if(p1.a7 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 7);
      p = polynomDoubleDegreeAddition(q, p);
    }
    if(p1.a6 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 6);
      p = polynomDoubleDegreeAddition(q, p);
    }
    if(p1.a5 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 5);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a4 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 4);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a3 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 3);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a2 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 2);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a1 == 1)
    {
      q = degreeDecalageOfPolynomDoubleDegree(p2, 1);
      p = polynomDoubleDegreeAddition(q, p);
    }if(p1.a0 == 1)
    {
      p = polynomDoubleDegreeAddition(p, p2);
    }
    return p;
  }
  else
  {
    return setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  }


};


int polynomDegree(struct PolynomDoubleDegree p)
{
  if(p.a14 == 1)
    {
      return 14;
    }
    else if(p.a13 == 1)
    {
      return 13;
    }
    else if(p.a12 == 1)
    {
      return 12;
    }
    else if(p.a11 == 1)
    {
      return 11;
    }
    else if(p.a10 == 1)
    {
      return 10;
    }
    else if(p.a9 == 1)
    {
      return 9;
    }
    else if(p.a8 == 1)
    {
      return 8;
    }
    else if(p.a7 == 1)
    {
      return 7;
    }
    else if(p.a6 == 1)
    {
      return 6;
    }
    else if(p.a5 == 1)
    {
      return 5;
    }
    else if(p.a4 == 1)
    {
      return 4;
    }
    else if(p.a3 == 1)
    {
      return 3;
    }
    else if(p.a2 == 1)
    {
      return 2;
    }
    else if(p.a1)
    {
      return 1;
    }
    else
    {
      return 0;
    }

};

bool isPolynomDoubleDegreeEqual(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2)
{
  if(p1.a14 == p2.a14)
  {
    if(p1.a13 == p2.a13)
    {
      if(p1.a12 == p2.a12)
      {
        if(p1.a11 == p2.a11)
        {
          if(p1.a10 == p2.a10)
          {
            if(p1.a9 == p2.a9)
            {
              if(p1.a8 == p2.a8)
              {
                if(p1.a7 == p2.a7)
                {
                  if(p1.a6 == p2.a6)
                  {
                    if(p1.a5 == p2.a5)
                    {
                      if(p1.a4 == p2.a4)
                      {
                        if(p1.a3 == p2.a3)
                        {
                          if(p1.a2 == p2.a2)
                          {
                            if(p1.a1 == p2.a1)
                            {
                              if(p1.a0 == p2.a0)
                              {
                                return true;
                              }
                              else
                              {
                                return false ;
                              }
                            }
                            else
                            {
                              return false ;
                            }
                          }
                          else
                          {
                            return false ;
                          }
                        }
                        else
                        {
                          return false ;
                        }
                      }
                      else
                      {
                        return false ;
                      }
                    }
                    else
                    {
                      return false ;
                    }
                  }
                  else
                  {
                    return false ;
                  }
                }
                else
                {
                  return false ;
                }
              }
              else
              {
                return false ;
              }
            }
            else
            {
              return false ;
            }
          }
          else
          {
            return false ;
          }
        }
        else
        {
          return false ;
        }
      }
      else
      {
        return false ;
      }
    }
    else
    {
      return false ;
    }
  }
  else
  {
    return false ;
  }
};


struct PolynomDoubleDegree* polynomDivision(struct PolynomDoubleDegree p1, struct PolynomIrreducible p2)
{
  struct PolynomDoubleDegree* result = malloc(sizeof(struct PolynomDoubleDegree) * 2);
  struct PolynomDoubleDegree quetion = setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
  struct PolynomDoubleDegree q;
  struct PolynomDoubleDegree rest;
  struct PolynomDoubleDegree restQ;


  int security_end_while = 100;
  int i = 0 ;

  struct PolynomDoubleDegree dp2 = getPolynomDoubleDegreeFromPolynomIrreducible(p2) ;

  int degP1 = polynomDegree(p1);
  int degP2 = polynomDegree(dp2);

  if(isPolynomDoubleDegreeEqual(p1, setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0))|| isPolynomDoubleDegreeEqual(dp2, setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0)))
  {
    *result = setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0) ;
    *(result +1 ) = setPolynomDoubleDegree(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0) ;
    return result;
  }
  else
  {

    if(compareDegreeOfPolynomDoubleDegree(p1, dp2) > -1)
    {
      rest = p1;
      while((compareDegreeOfPolynomDoubleDegree(rest, dp2) > -1) && (i != security_end_while))
      {
        if(rest.a14 == 1)
        {
          quetion = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 14 - degP2) ;
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,quetion), p1);
        }
        else if(rest.a13 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 13 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }
        else if(rest.a12 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 12 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }
        else if(rest.a11 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 11 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a10 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 10 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a9 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 9 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a8 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 8 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a7 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 7 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a6 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 6 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a5 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 5 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a4 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 4 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a3 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 3 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a2 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 2 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }else if(rest.a1 == 1)
        {
          q = degreeDecalageOfPolynomDoubleDegree(setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0), 1 - degP2);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }
        else
        {
          q = setPolynomDoubleDegree(1,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
          rest = polynomDoubleDegreeAddition(normalMultiplicationOfPolynomDoubleDegree(dp2,q), rest);
          quetion = polynomDoubleDegreeAddition(q, quetion);
        }

        i++;

      }

      *result = rest ;
      *(result +1 ) = quetion ;
      return result;

    }
    else
    {
      return polynomDivision(dp2, setPolynomIrreducible(p1.a0, p1.a1, p1.a2, p1.a3, p1.a4, p1.a5, p1.a6, p1.a7, p1.a8)) ;
    }
  }
};



int bynarryAddition(int a, int b)
{
  if(a == b)
  {
    return 0;
  }
  else
  {
    return 1;
  }
};

struct Polynom polynomAddition(struct Polynom p1, struct Polynom p2)
{
  struct Polynom pSom = setPolynom(bynarryAddition(p1.a0, p2.a0), bynarryAddition(p1.a1, p2.a1) , bynarryAddition(p1.a2, p2.a2), bynarryAddition(p1.a3, p2.a3), bynarryAddition(p1.a4, p2.a4), bynarryAddition(p1.a5, p2.a5), bynarryAddition(p1.a6, p2.a6), bynarryAddition(p1.a7, p2.a7)) ;
  return pSom;
};

struct PolynomDoubleDegree polynomDoubleDegreeAddition(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2)
{
  struct PolynomDoubleDegree pSom = setPolynomDoubleDegree(bynarryAddition(p1.a0, p2.a0), bynarryAddition(p1.a1, p2.a1) , bynarryAddition(p1.a2, p2.a2), bynarryAddition(p1.a3, p2.a3), bynarryAddition(p1.a4, p2.a4), bynarryAddition(p1.a5, p2.a5), bynarryAddition(p1.a6, p2.a6), bynarryAddition(p1.a7, p2.a7),  bynarryAddition(p1.a8, p2.a8), bynarryAddition(p1.a9, p2.a9), bynarryAddition(p1.a10, p2.a10), bynarryAddition(p1.a11, p2.a11), bynarryAddition(p1.a12, p2.a12), bynarryAddition(p1.a13, p2.a13), bynarryAddition(p1.a14, p2.a14)) ;
  return pSom;
};

struct PolynomDoubleDegree getPolynomDoubleDegreeFromPolynom(struct Polynom p)
{
  return setPolynomDoubleDegree(p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, 0, 0, 0, 0, 0, 0, 0);
};

struct PolynomDoubleDegree getPolynomDoubleDegreeFromPolynomIrreducible(struct PolynomIrreducible p)
{
  return setPolynomDoubleDegree(p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, p.a8, 0, 0, 0, 0, 0, 0);
};

struct PolynomIrreducible getPolynomIrreducibleFromPolynom(struct Polynom p)
{
  return setPolynomIrreducible(p.a0, p.a1, p.a2, p.a3, p.a4, p.a5, p.a6, p.a7, 0);
};

int comparePolynomDegree(struct Polynom p1, struct Polynom p2)
{
  if(p1.a7 > p2.a7)
  {
    return 1;
  }
  else if(p1.a7 < p2.a7)
  {
    return -1;
  }
  else
  {
    if(p1.a6 > p2.a6)
    {
      return 1;
    }
    else if(p1.a6 < p2.a6)
    {
      return -1;
    }
    else
    {
      if(p1.a5 > p2.a5)
      {
        return 1;
      }
      else if(p1.a5 < p2.a5)
      {
        return -1;
      }
      else
      {
        if(p1.a4 > p2.a4)
        {
          return 1;
        }
        else if(p1.a4 < p2.a4)
        {
          return -1;
        }
        else
        {
          if(p1.a3 > p2.a3)
          {
            return 1;
          }
          else if(p1.a3 < p2.a3)
          {
            return -1;
          }
          else
          {
            if(p1.a2 > p2.a2)
            {
              return 1;
            }
            else if(p1.a2 < p2.a2)
            {
              return -1;
            }
            else
            {
              if(p1.a1 > p2.a1)
              {
                return 1;
              }
              else if(p1.a1 < p2.a1)
              {
                return -1;
              }
              else
              {
                if(p1.a0 > p2.a0)
                {
                  return 1;
                }
                else if(p1.a0 < p2.a0)
                {
                  return -1;
                }
                else
                {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }

};



int compareDegreeOfPolynomDoubleDegree(struct PolynomDoubleDegree p1, struct PolynomDoubleDegree p2)
{

  if(polynomDegree(p1) > polynomDegree(p2))
  {
    return 1;
  }
  else if(polynomDegree(p1) < polynomDegree(p2))
  {
    return -1;
  }
  else
  {
    return 0;
  }

};



void printPolynom(struct Polynom p1)
{
   char text[100] = "";
  bool test = false ;
    if(p1.a7 == 1)
    {
      test = true ;
      strcat(text, " x⁷ ");
    }
    if(p1.a6 == 1)
    {
     if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁶ ");
    }
    if(p1.a5 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁵ ");
    }if(p1.a4 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁴ ");
    }if(p1.a3 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x³ ");
    }if(p1.a2 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x² ");
    }if(p1.a1 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x ");
    }if(p1.a0 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " 1 ");
    }
    printf("\np(x) = %s\n",text);
};

void printPolynomIrreducible(struct PolynomIrreducible p1)
{
  char text[100] = "";
  bool test = false ;
  if(p1.a8 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁸ ");
    }
    if(p1.a7 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁷ ");
    }
    if(p1.a6 == 1)
    {
     if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁶ ");
    }
    if(p1.a5 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁵ ");
    }if(p1.a4 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁴ ");
    }if(p1.a3 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x³ ");
    }if(p1.a2 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x² ");
    }if(p1.a1 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x ");
    }if(p1.a0 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " 1 ");
    }
    printf("\np(x) = %s\n",text);
};

void printDoubleDegreePolynom(struct PolynomDoubleDegree p1)
{
    char text[100] = "";
    bool test = false ;
    if(p1.a14 == 1)
    {
      strcat(text, " x¹⁴ ");
      test = true ;
    }if(p1.a13 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x¹³ ");
    }if(p1.a12 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x¹² ");
    }if(p1.a11 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x¹¹ ");
    }if(p1.a10 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x¹⁰ ");
    }if(p1.a9 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁹ ");
    }if(p1.a8 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁸ ");
    }
    if(p1.a7 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁷ ");
    }
    if(p1.a6 == 1)
    {
     if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁶ ");
    }
    if(p1.a5 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁵ ");
    }if(p1.a4 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x⁴ ");
    }if(p1.a3 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x³ ");
    }if(p1.a2 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x² ");
    }if(p1.a1 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " x ");
    }if(p1.a0 == 1)
    {
      if(test)
      {
        strcat(text, "+");
      }
      else
      {
        test = true ;
      }
      strcat(text, " 1 ");
    }
    printf("\np(x) = %s\n",text);
};

