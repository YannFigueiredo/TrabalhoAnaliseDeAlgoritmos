#include <iostream>

using namespace std;

void couting_sort(int A[],int B[],int n,int k){
  int i,j,C[k];
  for(i=0;i<=k;i++)
    C[i] = 0;
  for(j=1;j<=n;j++)
    C[A[j]] = C[A[j]] + 1;
  for(i=1;i<=k;i++)
    C[i] = C[i] + C[i - 1];
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] -1;
  }
  for(i=1;i<=n;i++)
    cout << B[i] << " ";
}
int main() {
  int A[5],B[5],n,k;
  cout << "Informe a quantidade de elementos do vetor: ";
  cin >> n;
  cout << endl;
  for(int i=1;i<=n;i++){
    cout << "Informe o elemento " << i << " do vetor A: ";
    cin >> A[i];
    cout << endl;
    B[i] = 0;
  }
  cout << "\nVetor antes da ordenação:\n";
  for(int i=1;i<=n;i++)
    cout << A[i] << " ";
  cout << "\n\nInforme o maior numero do vetor A: ";
  cin >> k;
  cout << "\nVetor depois da ordenação:\n";
  couting_sort(A,B,n,k);
}
