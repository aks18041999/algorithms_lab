#include <stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#include <stdlib.h>

typedef struct _node {
   int data;
   struct _node *next1, *next2;
} node;

node *createlist1 ( int n, int a )
{
   int ma;
   node *A = NULL, *p;

   ma = a;
   while (ma <= n) {
      if (A == NULL) p = A = (node *)malloc(sizeof(node));   /* first node */
      else p = p -> next1 = (node *)malloc(sizeof(node));    /* extend list */
      p -> data = ma; p -> next1 = p -> next2 = NULL;
      ma += a;
   }

   return A;
}

node *createlist2 ( int n, int b, node *A )
{
   int mb;
   node *B = NULL, *q, *p;

   mb = b; p = A;
   while (mb <= n) {
      while ((p != NULL) && (p -> data < mb)) p = p -> next1;
      if ((p != NULL) && (p -> data == mb)) {  /* data exists in list A */
         if (B == NULL) q = B = p;  /* first node */
         else q = q -> next2 = p;   /* extend list */
      } else {                                 /* new node to be created */
         if (B == NULL) q = B = (node *)malloc(sizeof(node));  /* first node */
         else q = q -> next2 = (node *)malloc(sizeof(node));   /* extend list */
         q -> data = mb; q -> next1 = q -> next2 = NULL;
      }
      mb += b;
   }

   return B;
}

void prnlist ( node *p )
{
   int which;

   if (p) {
      if (p -> next2 == NULL) which = 1;
      else if (p -> next1 == NULL) which = 2;
      else {
         printf("Which list to print (1/2)? ");
         scanf("%d", &which);
      }
      while (p) {
         printf("%d ", p -> data);
         p = (which == 1) ? p -> next1 : p -> next2;
      }
   }
   printf("\n");
}

void prnboth ( node *A, node *B )
{
   while (A || B) {
      if (A == NULL) { printf("%d ", B -> data); B = B -> next2; }
      else if (B == NULL) { printf("%d ", A -> data); A = A -> next1; }
      else if (A == B) { printf("%d ", A -> data); A = A -> next1; B = B -> next2; }
      else if (A -> data < B -> data) { printf("%d ", A -> data); A = A -> next1; }
      else { printf("%d ", B -> data); B = B -> next2; }
   }
   printf("\n");
}

int main (  )
{
   int n, a, b;
   node *A, *B;

         scanf("%d%d%d", &n, &a, &b);
   
   printf("n = %d\na = %d\nb = %d\n", n, a, b);

   A = createlist1(n,a);
   B = createlist2(n,b,A);

   printf("\n"); prnlist(A);
   printf("\n"); prnlist(B);
   printf("\n"); prnboth(A,B);

   exit(0);
}