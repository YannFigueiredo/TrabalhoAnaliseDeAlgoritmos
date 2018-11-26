#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void couting_sort(int A[],int B[],int n,int k){
  int i,j,C[k+1];
  for(i=0;i<=k;i++)
    C[i] = 0;
  for(j=0;j<n;j++)
    C[A[j]] = C[A[j]] + 1;
  for(i=1;i<=k;i++)
    C[i] = C[i] + C[i - 1];
  for(j=n-1;j>=0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  cout << B[5] << endl;
  for(i=0;i<n;i++)
    cout << B[i] << " ";
}
int main() {
  int A[]={2,2,3,1,0,1},X[7],B[6],n,k;
  //clock_t Ticks[2];
  n = 6;
  k = 3;
  //for(int i=1;i<=n;i++)
  //  A[i] = X[i-1];
  cout << "Vetor antes da ordenacao:\n";
  for(int i=0;i<n;i++)
    cout << A[i] << " ";
  cout << "\n\nVetor depois da ordenacao:\n";
  //Ticks[0] = clock();
  couting_sort(A,B,n,k);
  //Ticks[1] = clock();
  //double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
  //printf("\n\nTempo gasto: %g ms.", Tempo);
  //getchar();
}
