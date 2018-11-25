#include <stdio.h>

 #define tam_bucket 100
 #define num_bucket 10
 #define max 10

 typedef struct {
    int topo;
    int balde[tam_bucket];
 }bucket;

 void bucket_sort(int v[],int tam);                   //cabeçalho das funções
 void bubble(int v[],int tam);

 void bucket_sort(int v[],int tam){
    bucket b[num_bucket];
    int i,j,k;
    for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
      b[i].topo=0;

    for(i=0;i<tam;i++){                          //verifica em que balde o elemento deve ficar
      j=(num_bucket)-1;
      while(1){
        if(j<0)
          break;
        if(v[i]>=j*10){
          b[j].balde[b[j].topo]=v[i];
          (b[j].topo)++;
          break;
        }
        j--;
      }
    }

    for(i=0;i<num_bucket;i++)                     //ordena os baldes
      if(b[i].topo)
        bubble(b[i].balde,b[i].topo);
    i=0;
    for(j=0;j<num_bucket;j++){                    //põe os elementos dos baldes de volta no vetor
      for(k=0;k<b[j].topo;k++){
        v[i]=b[j].balde[k];
        i++;
      }
    }
 }

 void bubble(int v[],int tam){
    int i,j,temp;
    if(tam)
      for(j=0;j<tam-1;j++){
        for(i=0;i<tam-1;i++){
          if(v[i+1]<v[i]){
            temp=v[i];
            v[i]=v[i+1];
            v[i+1]=temp;
          }
        }
      }
 }
int main(int argc, char *argv[])
{
  int vetor[100],tam;

  printf("Informe o tamanho do vetor: ");
  scanf("%i",&tam);
  for(int i=0;i<tam;i++){
    printf("Informe o elemento %i do vetor: ",i+1);
    scanf("%i",&vetor[i]);
  }
  printf("\nVetor desordenado: ");
  for(int i=0;i<tam;i++)
    printf("%i, ", vetor[i]);
  bucket_sort(vetor, tam);
  printf("\nVetor ordenado: ");
  for(int i=0;i<tam;i++)
    printf("%i, ", vetor[i]);
}
