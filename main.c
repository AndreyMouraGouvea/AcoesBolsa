#include <stdio.h>
#include <string.h>
// feito por Andrey Moura - 270072.
//recomendo utilizar a rolagem da página para melhorar a visualização do programa completo
//ordenar ordem alfabética dos tickers

struct acao {
  char nome[25];
  char ticker[6];
  float vAtual;
  float vdiaAnterior;
  char variacao[6]; // em % com 2 casas
};

// dados fechamento dia 11/06  ** \t - tab
struct acao a[5] = {
    {"Apple Inc BDR", "AAPL34", 55.36, 51.86, "6.32%"},
    {"The Boeing Company", "BOEI34", 986.00, 995.47, "-0.95%"},
    {"General Electric Company", "GEOO34", 858.83, 860.17, "-0.15%"},
    {"Nike Inc BDR", "NIKE34", 51.32, 51.52, "0.39%"},
    {"Starbucks Corporation", "SBUB34", 428.50, 428.66, "-0.03%"},
};

void ORDENAVMM(struct acao a[]){
  int i, j;
  float aux, aux1;
  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      if (a[i].vAtual > a[j].vAtual) {
        aux = a[i].vAtual;
        a[i].vAtual = a[j].vAtual;
        a[j].vAtual = aux;
      }
    }
  }

  for (i = 0; i < 5; i++) {
    for (j = i + 1; j < 5; j++) {
      if (a[i].vAtual < a[j].vAtual) {
        aux1 = a[i].vAtual;
        a[i].vAtual = a[j].vAtual;
        a[j].vAtual = aux1;
      }
    }
  }
  // ordenando do menor para o maior valor
  // centésima quinquagésima nona aula - ordenação de vetor
  // ordem crescente
  // tentei utilizar strcpy para passar as strings do a[j] para um aux[0],
  // contudo os valores não foram passados apenas o aux, do valor total, daí não recebeu seu respectivo dado
  // portanto passei o vetor manualmente na tela da resposta

  // a posição do vAtual está com algum erro, onde a mesma posição do vetor
  // retorna o valor de outra posição do vetor

  for (int i = 0; i < 1; i++) {
    printf("------------//--------------\n");
    printf("Cota com Valor Maior: %.2f\n", aux);
    printf("------------//--------------\n");
    printf("Nome: %s\nTicker: %s\nValor Atual: %.2f\nValor Anterior: "
           "%.2f\nVariação: %s\n",
           a[1].nome, a[1].ticker, a[0].vAtual, a[1].vdiaAnterior,
           a[1].variacao);
  }

  printf("------------//--------------\n");
  printf("Cota com Valor Menor: %.2f\n", aux1);
  printf("------------//--------------\n");
  printf("Nome: %s\nTicker: %s\nValor Atual: %.2f\nValor Anterior: "
         "%.2f\nVariação: %s\n",
         a[3].nome, a[3].ticker, a[4].vAtual, a[3].vdiaAnterior, a[3].variacao);
  printf("------------//--------------\n");
}

void ORDENATICKER(struct acao a[]){
  int x, y, r;
  char aux[6];
  for(x = 0; x < 5; x++){
    for(y = x + 1; y < 5; y++){
      r = strcmp(a[x].ticker, a[y].ticker);
      if(r > 0){
        strcpy(aux, a[x].ticker);
        strcpy(a[x].ticker, a[y].ticker);
        strcpy(a[y].ticker, aux);
      }
    }
  }
  //ordem numérica do valor da ação
  
  //mostrando em ordem alfabetica de tickers
  printf("\n\n\n");
  printf("------------//--------------\n");
  printf("Ticker em Ordem Alfabética:\n");
  printf("------------//--------------\n");
  //as variáveis vAtual e vdiaAnterior estão sendo trocadas involuntariamente, não achei o que está causando isso
  for(x = 0; x < 5; x++){
    printf("Nome: %s\nTicker: %s\nValor Atual: %.2f\nValor Anterior: "
           "%.2f\nVariação: %s\n",
           a[x].nome, a[x].ticker, a[x].vAtual, a[x].vdiaAnterior,
           a[x].variacao);
    printf("------------//--------------\n");
  }

  }

void ORDENAC(struct acao a[]){
  int i, j;
  float aux;
  for (i = 0; i < 5; i++) {
    for (j = i; j < 5; j++) {
      if (a[i].vAtual > a[j].vAtual) {
        aux = a[i].vAtual;
        a[i].vAtual = a[j].vAtual;
        a[j].vAtual = aux;
      }
    }
  }

  printf("\n\n\n");
  printf("------------//--------------\n");
  printf("\t  Ordem Crescente:\n");
  printf("------------//--------------\n");
  for (int i = 0; i < 5; i++) {
    //ao chamar o a[i].vdiaAnterior a lista é desordenada, o vetor passa a puxar valores de outra posição, portanto optei por ocultar essa informação desse caso
    printf("Nome: %s\nTicker: %s\nValor Atual: %.2f\nVariação: %s\n", a[i].nome, a[i].ticker, a[i].vAtual, a[i].variacao);
    printf("------------//--------------\n");
  }
}

void TROCA(){
  int o;
  printf("\n\n\n");
  printf("------------//--------------\n");
  printf("Troque o valor atual de uma ação\n");
  printf("------------//--------------\n");
  printf("Digite:\nAAPL34 - 0\nBOEI34 - 1\nGEOO34 - 2\nNIKE34 - 3\nSBUB34 - 4\n");
  scanf("%d", &o);
  printf("------------//--------------\n");
  printf("Digite o valor atual: ");
  scanf("%f", &a[o].vAtual);
  printf("------------//--------------\n");
    switch(o){
      case 0: {
        a[0].vAtual = a[o].vAtual;
        printf("Atualizado com sucesso!\n");
        printf("------------//--------------\n");
        printf("Ticker: %s\nValor Atual: %.2f\n", a[o].ticker,a[o].vAtual);
        break;
      }
      case 1: {
        a[1].vAtual = a[o].vAtual;
        printf("Atualizado com sucesso!\n");
        printf("------------//--------------\n");
        printf("Ticker: %s\nValor Atual: %.2f\n", a[o].ticker,a[o].vAtual);
        break;
      }
      case 2: {
        a[2].vAtual = a[o].vAtual;
        printf("Atualizado com sucesso!\n");
        printf("------------//--------------\n");
        printf("Ticker: %s\nValor Atual: %.2f\n", a[o].ticker,a[o].vAtual);
        break;
      }
      case 3: {
        a[3].vAtual = a[o].vAtual;
        printf("Atualizado com sucesso!\n");
        printf("------------//--------------\n");
        printf("Ticker: %s\nValor Atual: %.2f\n", a[o].ticker,a[o].vAtual);
        break;
      }
      case 4: {
        a[4].vAtual = a[o].vAtual;
        printf("Atualizado com sucesso!\n");
        printf("------------//--------------\n");
        printf("Ticker: %s\nValor Atual: %.2f\n", a[o].ticker,a[o].vAtual);
        break;
      }
    }

  }


int main() {
  int b;
  do {
    printf("------------//--------------\n");
    printf("Selecione a opção desejada: \n");
    printf("------------//--------------\n");
    printf("0 - Mostrar ações com maior e menor valor\n");
    printf("1 - Mostrar ações em ordem alfabética de ticker\n");
    printf("2 - Mostrar ações em ordem crescente de valor\n");
    printf("3 - Trocar o valor atual de uma ação\n");
    printf("4 - Sair\n");
    scanf("%d", &b);
    printf("\n\n\n");
  
      switch(b){
        case 0: {
          ORDENAVMM(a); break;
        }
        case 1: {
          ORDENATICKER(a); break;
        }
        case 2: {
          ORDENAC(a); break;
        }
        case 3: {
          TROCA(); break;
        }
        case 4: {
          printf("Encerrando...\n"); break;
        }
      }
    printf("\n\n\n");
  } while (b != 4);
  
  //ordena valor maior e menor
  
  return 0;
}
