#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define m_START_TIME 20
//#define m_DURATION 10
//#define VERBOSE 1
using namespace std;

typedef struct {
   int s;
   int f;
} intrvl;

typedef struct _node {
   intrvl I;        
   int count;          
   int m;           
   struct _node *L;    
   struct _node *R;    
} node;

typedef node *t;

int intrvlcmp ( intrvl I, intrvl J )
{
   if (I.s < J.s) return -1;
   if (I.s > J.s) return 1;
   if (I.f < J.f) return -1;
   if (I.f > J.f) return 1;
   return 0;
}


t insert ( t T, intrvl I )
{
   node *p, *q;
   int cmpres;

   printf("(%d,%d) ", I.s, I.f);

   
   p = T; q = NULL;
   while (p) {
      cmpres = intrvlcmp(I, p->I);
      if (cmpres == 0) {  
         ++(p -> count);   
         return T;        
      }
      if (I.f > p -> m) p -> m = I.f;
      q = p;
      if (cmpres < 0) p = p -> L; else p = p -> R;
   }

   p = (node *)malloc(sizeof(node));
   p -> I = I;
   p -> count = 1;
   p -> m = I.f;
   p -> L = p -> R = NULL;

   if (T == NULL) return p;

   if (cmpres < 0) q -> L = p; else q -> R = p;
   return T;
}

int preorder ( t T, int nprinted )
{
   if (T == NULL) return nprinted;
   printf("[(%2d,%-2d),%d,%2d] ", (T -> I).s, (T -> I).f, T -> count, T -> m);
   ++nprinted; if (nprinted == 5) { printf("\n               "); nprinted = 0; }
   nprinted = preorder(T -> L, nprinted);
   nprinted = preorder(T -> R, nprinted);
   return nprinted;
}

int inorder ( t T, int nprinted )
{
   if (T == NULL) return nprinted;
   nprinted = inorder(T -> L, nprinted);
   printf("[(%2d,%-2d),%d,%2d] ", (T -> I).s, (T -> I).f, T -> count, T -> m);
   ++nprinted; if (nprinted == 5) { printf("\n               "); nprinted = 0; }
   nprinted = inorder(T -> R, nprinted);
   return nprinted;
}


int overlap ( intrvl I, intrvl J )
{
   return ((I.s < J.f) && (J.s < I.f));
}
int overlapcnt ( t T, intrvl I, int verbose, int *nprinted )
{
   int cnt = 0;

   if (T == NULL) return 0;

   /* I overlaps with the intrvl stored at the root */
   if (overlap(T -> I, I)) {
      if (verbose) {
         printf("[(%2d,%-2d),%d] ", (T->I).s, (T->I).f, T->count);
         ++(*nprinted);
         if (*nprinted == 5) {
            printf("\n                      ");
            *nprinted = 0;
         }
      }
      cnt = T -> count;
   }
   if ((T -> L) && (I.s < T -> L -> m))
      cnt += overlapcnt(T -> L, I, verbose, nprinted);

   if ((T -> R) && (I.s < T -> R -> m) && (I.f > (T->I).s))
      cnt += overlapcnt(T -> R, I, verbose, nprinted);

   return cnt;
}
void minclasscnt ( t T, t p, intrvl *I, int *gm )
{
   int m;
   intrvl J;

   if (p == NULL) return;

   J.s = (p -> I).s; J.f = J.s + 1;
   m = overlapcnt(T, J, 0, NULL);

   if (m > *gm) {
      *gm = m;
      *I = J;
   }

   minclasscnt(T, p->L, I, gm);
   minclasscnt(T, p->R, I, gm);
}

int main ( int argc, char *argv[] )
{
   int i, n, s, f, q, c;
   t T = NULL;
   intrvl I;

   srand((unsigned int)time(NULL));

   if (argc >= 3) {
      n = atoi(argv[1]);
      q = atoi(argv[2]);
   } else {
      printf("n = "); scanf("%d", &n);
      printf("q = "); scanf("%d", &q);
   }

   printf("\nInsert   : ");
   for (i=0; i<n; ++i) {
      cout<<endl<<i<<"th entry "<<endl;
      cout<<"Enter the start time "<<endl;
      cin>>s;
      cout<<"Enter the finishing time "<<endl;
      cin>>f;
     T = insert(T,(intrvl){s,f});
   }

   printf("\n\n");
   printf("Preorder : "); preorder(T,0); printf("\n");
   printf("Inorder  : "); inorder(T,0); printf("\n\n");

   for (i=0; i<q; ++i) {
      cout<<endl<<"for q "<<i<<"th entry "<<endl;
      cout<<"Enter the start time "<<endl;
      cin>>s;
      cout<<"Enter the finishing time "<<endl;
      cin>>f;
      printf("Overlap (%2d,%-2d) : ", s, f); n = 0;
      c = overlapcnt(T, (intrvl){s,f}, 1, &n);
      if (n) printf("\n                      ");
      printf("Overlap count = %d\n", c);
   }

   c = -1; minclasscnt(T,T,&I,&c);
   printf("\nMinimum class count is %d\n", c);
   printf("A busiest hour is (%d,%d)\n", I.s, I.f);
   printf("Overlap (%2d,%-2d) : ", I.s, I.f); n = 0;
   c = overlapcnt(T, I, 1, &n);
   if (n) printf("\n                      ");
   printf("Overlap count = %d\n", c);

   exit(0);
}
