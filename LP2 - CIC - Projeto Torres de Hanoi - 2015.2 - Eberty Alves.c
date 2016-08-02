/****
*
* Título: Torre de Hanói
*
* Autor: Eberty Alves da Silva
*
* Data de Criação: 19 de janeiro de 2016
* Última modificação: 12 de fevereiro de 2016
*
* Descrição: O programa resolve o problema das Torres de Hanói para um número arbitrário de discos,
*           mostrando a sequência de movimentos de forma gráfica. Para valores muito grandes de discos
*           ocorrerá o desbordamento da tela, o programa funciona corretamente para 0 < ndiscos <= 10.
*           Adicionalmente, o programa cria um arquivo texto mostrando a saída de programa.
*
* Entrada:  Valor inteiro representando o número de discos contidos na Torre de Hanói, e a opção escolhida no menu
*           Caso o número informado seja inválido é repetida a operação até a informação correta ser apresentada
*
*   Exemplo: Informe o número de discos a serem usados pela torre: 2
*
* Saída:    Além das informações contidas no menu, o programa mostra também a sequência de
*           movimentos para um número arbitrário de discos de forma grá?ca,
*           como pode ser visto no exemplo a seguir para número de discos = 2.
*
*   Exemplo: Esta é a sequência de movimentos para 2 discos:
*
*     *    |    |
*    ***   |    |
*   --+----+----+--
*
*   Passo: 1
*   Disco movido da 1ª haste para a 3ª haste
*
*     |    |    |
*    ***   |    *
*   --+----+----+--
*
*   Passo: 2
*   Disco movido da 1ª haste para a 2ª haste
*
*     |    |    |
*     |   ***   *
*   --+----+----+--
*
*   Passo: 3
*   Disco movido da 3ª haste para a 2ª haste
*
*     |    *    |
*     |   ***   |
*   --+----+----+--
*
****/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#define hastes 3


        //Modulo de leitura
/****
*
* Título: LerEVerificaNumD
*
* Autor: Eberty Alves
*
* Data de Criação: 23 de janeiro de 2016
* Última modificação: 27 de janeiro de 2016
*
* Descrição: A função lê e verifica o número de discos a serem usados para resolver o problema em questão.
*
* Parâmetros:
*   (entrada/saída)
*           int *nDiscos:   É um ponteiro que aponta para a variável nDiscos (quantidade de discos) da função main.
*
* Valor de retorno: Um inteiro irá definir se a resolução pode ser executada ou não. Ela leva em conta a quantidade de discos informada.
*
****/
int LerEVerificaNumD (int *);


        //Modulo da Matriz
/****
*
* Título: AlocaMatriz
*
* Autor: Dany Sanchez Dominguez - Alterações feitas por Eberty Alves
*
* Data de Criação: 21 de janeiro de 2016
* Última modificação: 22 de janeiro de 2016
*
* Descrição: A função aloca uma matriz cujo o ponteiro fora definido na função main.
*
* Parâmetros:
*   (entrada)
*           int n:  Representa o número de linhas (discos) da matriz.
*           Há ainda um Define (haste) que representa a quantidade de colunas (3)
*
* Valor de retorno: A função retorna a matriz alocada.
*
****/
int ** AlocaMatriz(const int);

/****
*
* Título: PreencheMatriz
*
* Autor: Eberty Alves
*
* Data de Criação: 21 de janeiro de 2016
* Última modificação: 3 de fevereiro de 2016
*
* Descrição: Cria uma torre com os respectivos tamanhos dos discos na primeira coluna da matriz
*            As outras hastes são preenchidas com discos de tamanho zero (sem discos).
*
* Parâmetros:
*   (entrada)
*           int **m:                É um ponteiro que aponta para a matriz que já foi alocada e definida na função AlocaMatriz.
*           int *discoRef:          Indica o tamanho para cada disco (Que são elaborados a partir da formula de número ímpar).
*           const int totalDiscos:  indica a quantidade de linhas a serem percorridas.
*
* Valor de retorno: void (os valores de cada posição da matriz são preenchidos no decorrer da função).
*
****/
void PreencheMatriz(int **, int *, const int);

/****
*
* Título: LiberaMatriz
*
* Autor: Dany Sanchez Dominguez - Alterações feitas por Eberty Alves
*
* Data de Criação: 21 de janeiro de 2016
* Última modificação: 21 de janeiro de 2016
*
* Descrição: Libera uma matriz alocada dinamicamente.
*
* Parâmetros:
*   (entrada)
*           int **m: Ponteiro que aponta para a matriz que foi alocada e definida na função AlocaMatriz.
*           Há ainda um Define (haste) que representa a quantidade de colunas (3) para serem liberadas.
*
* Valor de retorno: void.
*
****/
void LiberaMatriz(int **);


        //Modulo de resulução
/****
*
* Título: TorreHanoi
*
* Autor: Eberty Alves
*
* Data de Criação: 23 de janeiro de 2016
* Última modificação: 10 de fevereiro de 2016
*
* Descrição: Série de chamadas recursivas para resolver o problema em questão.
*
* Parâmetros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posição dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       int disco:              Indica qual execução a fazer (nesse caso disco == 1).
*       int ori:                Indica a haste de origem do disco a ser movido.
*       int dest:               Indica a haste de destino para onde será movido o disco.
*       int aux:                Indica a haste que servirá de auxiliar durante a movimentação dos discos de uma haste pra outra.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gráfico).
*       int *passo:             Ponteiro para a variável que inúmera a quantidade de passos que já foram feitos.
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
*
* Valor de retorno: Para o caso base ele define a haste (coluna) a qual um dos discos de outra haste será movido, chamando  então a função MoveDisco.
*
****/
void TorreHanoi(int **, const int, int, int, int, int, const int, int*, FILE *);

/****
*
* Título: MoveDisco
*
* Autor: Eberty Alves
*
* Data de Criação: 23 de janeiro de 2016
* Última modificação: 10 de fevereiro de 2016
*
* Descrição: A função define a posição do disco de origem através do parâmetro de entrada, depois verifica para onde ele deve ser copiado (linha de destino)
*            Então, copia o disco da posição de origem para a posição de destino, apagando depois o disco de origem (zero).
*            A função também indica a quantidade de passos já feitos, e o movimento realizado
*            Depois chama a função imprimeDiscos imprimir a nova posição dos discos na tela.
*
* Parâmetros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posição dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       int ori:                Indica a haste de origem do disco a ser movido.
*       int dest:               Indica a haste de destino para onde será movido o disco.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gráfico).
*       int *passo:             Ponteiro para a variável que inúmera a quantidade de passos que já foram feitos.
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
*
* Valor de retorno: Retorna as novas posições dos discos.
*
****/
void MoveDisco(int **, const int, int, int, const int, int*, FILE *);

/****
*
* Título: ImprimeDiscos
*
* Autor: Eberty Alves
*
* Data de Criação: 23 de janeiro de 2016
* Última modificação: 10 de fevereiro de 2016
*
* Descrição: A função imprime na tela e no arquivo ' ', '*' e/ou '|' a depender da entrada. Indicando graficamente a posição atual dos discos em relação a cada haste.
*            Apos isso ela chama a função ImprimeBase, para terminar a amostragem gráfica do passo.
*
* Parâmetros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posição dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gráfico).
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
*
* Valor de retorno: A função não possui retorno.
*
****/
void ImprimeDiscos(int **, const int, const int, FILE *);

/****
*
* Título: ImprimeBase
*
* Autor: Eberty Alves
*
* Data de Criação: 23 de janeiro de 2016
* Última modificação: 10 de fevereiro de 2016
*
* Descrição: A função imprime na tela e no arquivo uma base para a torre, a função também gera uma pausa antes que a tela do computador seja limpa para apresentar o próximo movimento.
*
* Parâmetros:
*   (entrada)
*       const int discoref: ajuda a definir a quantidade de '-' antes de cada '+'.
*       FILE *arquivo:      Ponteiro para o arquivo .txt criado no início do programa, usado para a função fprintf.
*
* Valor de retorno: A função não possui retorno.
*
****/
void ImprimeBase(const int, FILE *);


        //Modulo menu
/****
*
* Título: Menu
*
* Autor: Eberty Alves
*
* Data de Criação: 21 de janeiro de 2016
* Última modificação: 25 de janeiro de 2016
*
* Descrição: Imprime o menu com as opções que o usuário pode escolher.
*
* Parâmetros:
*   (entrada) - dentro da própria função
*       int opcao: Informa (lê) qual opção do menu foi escolhida pelo usuário.
*
* Valor de retorno: a opção escolhida.
*
****/
int Menu(void);

/****
*
* Título: SobreProblema
*         LendaHanoi
*         Curiosidades
*
* Autor: Eberty Alves
*
* Data de Criação: 21 de janeiro de 2016
* Última modificação: 23 de janeiro de 2016
*
* Descrição: Essas funções são complementares ao menu de opções,
*            Possuem como única finalidade apresentar na tela informações sobre o problema em questão.
*            Essas funções ajudam a manter a função main enxuta.
*
* Parâmetros: funções sem parâmetros, com exceção da função Curiosidades, que possui outro menu de opções dentro dela.
*
* Valor de retorno: funções sem valores de retorno.
*
****/
void SobreProblema(void);
void LendaHanoi(void);
void Curiosidades(void);


int main(){
    int nDiscos; //Numero de Discos da Torre
    int **matrizHanoi; //Matriz onde ira ser armazenado os discos da Torre de Hanoi
    int discoRef; // Vai dizer o tamanho do disco durante o preenchimento de cada linha da matriz e depois servira como referencia
    int continua; //Representa se o numero de disco foi aceito durante a leitura e a verificaçao
    int op; // Opção do menu escolhida pelo usuario
    int passo; //Quantidade de movimentos realizados
    FILE *arquivo; //arquivo texto

    setlocale(LC_ALL, "portuguese"); //uso de acentos

    if ((arquivo = fopen("Torre de Hanoi.txt", "w")) == NULL){ //cria arquivo para escrita e verifica
        printf("Erro ao criar o arquivo texto onde os dados desse programa serão gravados!!!\n");
        exit (-1);
    }

    do{
        system("cls");
        op = Menu();

        switch(op){ //executa cada iteracao de acordo com a opçao esolhida pelo usuario
            case 1 :
                system("cls");
                discoRef = 1;
                passo = 0;
                continua = LerEVerificaNumD(&nDiscos);

                if(continua == 1){ //Se o numero de disco foi aceito durante a leitura e a verificaçao o codigo é executado
                    fprintf(arquivo, "Esta é a sequência de movimentos para %d discos:\n\n", nDiscos);
                    matrizHanoi = AlocaMatriz(nDiscos);
                    PreencheMatriz(matrizHanoi, &discoRef, nDiscos);
                    //discoRef = (disco maior: 2*nDiscos - 1) + 2

                    system("cls");
                    printf("\n\n\n");
                    ImprimeDiscos(matrizHanoi, nDiscos, discoRef, arquivo); //imprime a posição inicial dos discos antes dos movimentos serem realizados

                    TorreHanoi(matrizHanoi, nDiscos, nDiscos, 0, 1, 2, discoRef, &passo, arquivo);//Primeira chamada antes das chamadas recursivas

                    printf("\n%d passos são nessesários para resolver o problema para %d discos\n", (int)pow(2, nDiscos)-1, nDiscos);
                    fprintf(arquivo, "\n\n%d passos são nessesários para resolver o problema para %d discos\n\n\n", (int)pow(2, nDiscos)-1, nDiscos);

                    LiberaMatriz(matrizHanoi);
                }//fim do if continua
                printf("\n");
                break; //fim do primeiro case

            case 2 :
                system("cls");
                SobreProblema();
                break;

            case 3 :
                system("cls");
                LendaHanoi();
                break;

            case 4 :
                system("cls");
                Curiosidades();
                break;

            case 5 : //case de saída
                system("cls");
                printf("Parabéns, todos as execuções da torre feitas nessa sessão agora\n"
                       "estão disponiveis em um arquivo de nome Torre de Hanoi.txt\n"
                       "na própria pasta do executável\n\n"
                       "Obrigado por desfrutar de nosso programa, esperamos vê-lo novamente em breve\n\n");
                fprintf(arquivo, "Obrigado por desfrutar de nosso programa, esperamos vê-lo novamente em breve");
                break;

            default :
                printf("\nOpção Inválida\n");
                break;
        } //fim do switch case
        system("pause");
    } while (op != 5); //fim do Do While

    fclose(arquivo);//fecha arquivo de escrita

    return 0;
}


int LerEVerificaNumD(int *nDiscos){
    char resp; //em caso de número muito grande ela define se a execução continua ou não
    printf("Informe o número de discos a serem usados pela torre: ");
    scanf("%d", nDiscos); //recebe o número de discos

    if (*nDiscos < 1){
        printf("Erro!!!\nA torre não pode conter menos de 1 disco.\n");
        return 0;
    } //verifica se o numero é válido

    if (*nDiscos > 10){
        printf("Aviso!!!\nCaso o número de discos seja maior que 10,\n"
               "o programa pode ficar extenso e apresentar falhas durante a exibição das torres.\n"
               "Deseja continuar?[s/n].\n");
        do{
            fflush(stdin);
            resp = getchar();
            if (resp == 's' || resp == 'S')
                return 1;
            else if (resp == 'n' || resp == 'N')
                return 0;
            else
                printf("Opção inválida, digite novamente: ");
        }while (resp != 's' || resp != 'S'|| resp != 'n'|| resp != 'N'); //recebimento da resposta válida
    } //verifica se o usuário quer continuar para mais de 10 discos
    return 1;
}

int ** AlocaMatriz(const int n){
    int **m; //ponteiro para matriz de retorno
    int i; //contador

    m = malloc(n * sizeof(int *)); //alocação linhas
    if (m == NULL){
        printf("Erro!!! \nVocê alcançou toda a memória disponível e infelizmente o programa travou\n");
        exit(-1);
    } //if verificação linhas

    for(i = 0; i < n; i++){ //alocação colunas
        m[i] = malloc(hastes * sizeof(int));
        if (m[i] == NULL){
            printf("Erro!!! \nVocê alcançou toda a memória disponível e infelizmente o programa travou\n");
            exit(-1);
        } //if verificação colunas
    }
    return m; //Retorno (matriz)
}

void PreencheMatriz(int **m, int *discoRef, const int totalDiscos){
    int i; //contador
    for(i = totalDiscos - 1 ; i >= 0 ; i--){ //percorre a matriz (linhas)
        m[i][0] = *discoRef; //cria torre na coluna 0 da matriz
        *discoRef += 2; //aumenta o tamanho do próximo disco
        m[i][1] = 0; //deixa as outras colunas vazias
        m[i][2] = 0;
    }
}

void LiberaMatriz(int **m){
    int i;
    for(i = 0; i < hastes; i++)
        free(m[i]);
    free(m);
}

void TorreHanoi(int **m, const int totalDiscos, int disco, int ori, int dest, int aux, const int discoRef, int *passo, FILE *arquivo){
    if (disco == 1){
        MoveDisco (m, totalDiscos, ori, dest, discoRef, passo, arquivo);
    } //caso base
    else{
        TorreHanoi (m, totalDiscos, disco-1, ori, aux, dest, discoRef, passo, arquivo);
        TorreHanoi (m, totalDiscos, 1, ori,  dest, aux, discoRef, passo, arquivo);
        TorreHanoi (m, totalDiscos, disco-1, aux, dest, ori, discoRef, passo, arquivo);
    } //chamadas recursivas
}

void MoveDisco(int **m, const int totalDiscos, int ori, int dest, const int discoRef, int *passo, FILE *arquivo){
    int linhaOri = totalDiscos - 1;
    int linhaDest = 0;

    while(m[linhaOri][ori] == 0) //procura o disco que fica na posição mais alta da haste de origem
        linhaOri--;

    while(m[linhaDest][dest] != 0) //fica uma posição acima do disco mais alto da linha de destino
        linhaDest++;

    m[linhaDest][dest] = m[linhaOri][ori]; //Copia o Disco mais alto da Origem pra posição Destino
    m[linhaOri][ori] = 0; //remove o disco da origem

    system("cls"); //limpa a tela para apresentar o próximo passo
    *passo+=1; //acrescenta para contar quantos passos já foram feitos
    printf("Passo: %d\n", *passo);
    fprintf(arquivo, "\nPasso: %d\n", *passo);
    printf("Disco movido da %dª haste para a %dª haste\n\n", ori+1, dest+1); //apresenta o movimento de forma escrita
    fprintf(arquivo, "Disco movido da %dª haste para a %dª haste\n\n", ori+1, dest+1);
    ImprimeDiscos(m, totalDiscos, discoRef, arquivo); //imprime graficamente a posição dos discos
}

void ImprimeDiscos(int **m, const int totalDiscos, const int discoRef, FILE *arquivo){
    int i, j, k, espaco; //contadores
    for(i = totalDiscos - 1 ; i >= 0 ; i--){
        for(j = 0; j < hastes; j++){
            espaco = (discoRef - m[i][j]) / 2; //quantidade de espaços antes de imprimir os '*'

            for(k = 0; k < espaco; k++){
                printf(" ");
                fprintf(arquivo, " ");
            } //espaços a esquerda

            for(k = 0; k < m[i][j]; k++){
                printf("*");
                fprintf(arquivo, "*");
            } //impresão de cada discos

            if (m[i][j] == 0){
                printf ("|");
                fprintf(arquivo, "|");
            } //caso não houver disco

            for(k = 0; k < espaco; k++){
                printf(" ");
                fprintf(arquivo, " ");
            } //espaços a direita

        } //fim do for que percorre as 3 hastes (colunas)
        printf("\n"); //pula para próxima linha grafica
        fprintf(arquivo, "\n");
    }//fim do for que percorre as linhas
    ImprimeBase (discoRef, arquivo); //após a impressão dos discos imprime a base para eles
}

void ImprimeBase(const int discoref, FILE *arquivo){
    int i,j; //contadores
    for (i = 0; i < hastes; i++){
        for (j = 0; j < discoref / 2; j++){
            printf("-");
            fprintf(arquivo, "-");
        } //base esquerda de cada haste

        printf("+"); //imprime a parte do meio de cada uma das 3 hastes
        fprintf(arquivo, "+");

        for (j = 0; j < discoref / 2; j++){
            printf("-");
            fprintf(arquivo, "-");
        } //base direita de cada haste

    } //fim do for das 3 hastes

    printf ("\n");
    fprintf(arquivo, "\n");
    Sleep(1000); //pausa antes que a tela seja limpa para apresentar o próximo passo

}

int Menu(void){
    int opcao; //escolha
    printf("Olá Bem-vindo ao programa Torres de Hanói.\n\n"
           "Nesse programa você encontrará as principais informações sobre a torre\n"
           "Encontrará também métodos de resolução para os mais diversos números de discos\n"
           "Caso aceite executar o programa, basta informar a quantidade dos mesmos\n"
           "O programa será capaz de mostrar-lhe o passo a passo da resolução do problema\n\n"
           "   Copyright Eberty Alves v1.0\n\n"
           "Escolha a opção:\n"
           "(1) Para executar o programa\n"
           "(2) Para entender esse problema clássico em Ciências da Computação\n"
           "(3) Para conhecer mais sobre a Lenda de Hanói\n"
           "(4) Para curiosidades\n"
           "(5) Para sair do programa\n");
    printf("\nVocê escolheu: ");
    scanf("%d", &opcao);
    return opcao;
}

void SobreProblema(void){
    printf("Você escolheu a opção:\n"
           "(2) Entender esse problema clássico em Ciências da Computação"
           "\n\n   Eis um problema em que a recursividade múltipla realmente ajuda. Esse problema consiste em uma base contendo 3 hastes, em uma das quais estão dispostos n discos, em ordem crescente de diâmetro."
           "\n   O objetivo é mover todos os n discos de uma haste para outra qualquer, usando uma delas como auxiliar."
           "\n   Parece fácil, não? Mas não é tão simples, porque você deve respeitar as seguintes restrições:"
           "\n     1. Nunca colocar um disco maior sobre um disco menor;"
           "\n     2. Pode-se mover um único disco por vez;"
           "\n     3. Nunca colocar um disco em outro lugar que não seja numa das três hastes."
           "\n   Você pode achar que esse problema não é terrivelmente importante. Ao contrário! Conheça a lenda de Hanói voltando ao menu e escolhendo a opção 3."
           "\n   Primeiro, vamos entender a solução recursiva para esse problema. A começar com um caso realmente fácil: um disco (n=1), esse será nosso caso base. Você sempre pode mover o disco 1 da haste A para qualquer outra haste, porque sabe que quaisquer discos abaixo dele devem ser maiores."
           "\n   E quanto a dois ou mais discos? Como você pode solucionar o problema quando n>=2? Por isso existe a haste C, um local para colocar os discos menores de forma que possamos expor ao disco mais no fundo."
           "\n   Mais ao ponto, movendo (n-1) discos menores da haste original para uma auxiliar, você recursivamente resolveu um subproblema: mover os discos 1 até n-1. Uma vez que você resolveu esse subproblema, você pode mover o disco maior. Agora, para finalizar, você precisa resolver recursivamente o subproblema dos discos 1 a n-1 que se deslocam para a haste auxiliar C e colocá-las no destino B. A haste A será a nova auxiliar."
           "\n   Você concorda que pode mover qualquer quantidade de discos de qualquer haste para qualquer outra haste seguindo as restrições? Diga SIM e escolha a opção 1 do menu principal."
           "\n\nFonte: https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/\n\n");
}

void LendaHanoi(void){
    printf("Você escolheu a opção:\n"
           "(3) Conhecer mais sobre a Lenda de Hanói"
           "\n\n   Existem várias lendas a respeito da origem do jogo:"
           "\n\n   Em geral elas afirmam que, em algum lugar da Ásia (Tibete, Vietnã, Índia - escolha na internet a lenda que preferir), monges estão solucionando esse problema com um conjunto de 64 discos, e os monges acreditam que quando terminarem de mover todos os 64 discos do pino A para o pino B de acordo com as regras, o mundo vai acabar. Se os monges tiverem razão, deveríamos estar correndo pelas ruas em pânico?"
           "\n   Eles estão usando n=64 discos, e assim eles vão precisar mover os discos 2^ {64} - 1 vezes (entenda a formula voltando ao menu e escolhendo a opção 4 curiosidades). Estes monges são ágeis e fortes: Eles podem mover um disco a cada segundo, noite e dia. Quanto tempo é 2^ {64} - 1 segundos? Usando a estimativa aproximada de 365,25 dias por ano, trata-se de mais de 584 bilhões de anos."
           "\n   O sol tem apenas cerca de mais cinco a sete biliões de anos antes de virar supernova e explodir sobre nós. Então, sim, o mundo vai acabar. Não importa os quão rápidos sejam os monges, isso vai acontecer muito antes deles poderem mover todos os 64 discos das hastes A para B."
           "\n   Quer saber como mais podemos usar esse algoritmo, além de prever o fim do mundo? (Retorne ao menu principal e escolha a opção 4)"
           "\n\nFonte: https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/\n\n");
}

void Curiosidades(void){
    int menu2; //escolha para o segundo menu (curiosidades)
    printf("Você escolheu a opção:\n"
           "(4) Curiosidades"
           "\n\nSelecione a curisidade que preferir:"
           "\n  (1)Origens"
           "\n  (2)Prova para o número de movimentos"
           "\n  (3)Aplicações"
           "\n  (4)Formas de Resolução"
           "\n  (5)Retornar ao menu principal");
    printf("\n\nVocê escolheu: ");
    scanf("%d", &menu2);
    switch (menu2){
        case 1 :
            printf("\nO problema foi inventado pelo matemático francês Édouard Lucas em 1883. O nome foi inspirado na torre símbolo da cidade de Hanói, no Vietnã . Não é claro se Lucas inventou a lenda ou se foi inspirada por ele."); break;
        case 2 :
            printf("\nA sucessão formada pela soma dos movimentos é uma sucessão (1,2,4...2^n) que é uma progressão geométrica, ou seja, essa soma equivale a: [a * (q^ (n) – 1) ] / (q - 1), onde a é o primeiro termo e q é a razão. Já que a razão é 2 e o primeiro termo é 1 temos que [1 * (2^ (n) – 1) ] / (2 - 1) = 2^ (n) – 1."
                   "\n\nVamos provar por indução em n que o número mínimo de movimentos para conseguir transferir todos os discos da primeira estaca à terceira é 2^ (n) - 1, sendo n o número de discos:"
                   "\n\nA solução é verdadeira para a base n = 1, pois 2^1 - 1 = 1 e precisávamos de um movimento. Suponha que é possível resolver um problema para n-1 discos em 2^ {n-1} - 1 movimentos, então é possível resolver um problema para n discos em 2^n - 1 movimentos. Precisa-se de 2^ {n-1} - 1 movimentos para resolver de forma recursiva o primeiro subproblema de mover os discos 1 a n-1, um movimento para mover o disco n e outro 2^ {n-1} - 1 movimentos para resolver de forma recursiva o segundo subproblema de mover discos de 1 a n-1. Se você somar os movimentos, você tem 2^n - 1."
                   "\n\nEntão, para solucionar um Hanói de 64 discos, como diz a lenda, são necessários 18.446.744.073.709.551.615 movimentos."); break;
        case 3 :
            printf("\nA Torre de Hanói pode ser trabalhada em níveis de desenvolvimento com crianças. Na pré-escola, com regras simples de separação de cores e tamanhos, a torre de Hanói ajuda em questões cognitivas como: coordenação motora, identificação de formas, ordem crescente e decrescente, entre outras formas de aprendizado."
                   "\n\nA Torre de Hanói tem sido tradicionalmente considerada como um procedimento para avaliação da capacidade de memória de trabalho, e principalmente de planejamento e solução de problemas."
                   "\n\nIniciando com um número menor de peças, ou seja, resolvendo problemas mais simples, teremos oportunidade de desenvolver a lógica e experimentar uma das mais importantes formas de raciocínio matemático."); break;
        case 4 :
            printf("\nA resolução recursiva é mais limitada quanto ao tempo de realização, já que sua execução dependerá de alguns fatores para tornar-se mais eficaz. Já a resolução Iterativa utiliza algumas estruturas de repetição (for, whiles), existe ainda a possibilidade de algumas estruturas adicionais (mais complexas) as quais tornam o algoritmo mais rápido."); break;
        case 5 : break; //opção de saida
        default :
            printf ("Opção Inválida\n"); break;
    } // fim do switch case do segundo menu
    if ((menu2<=4) && (menu2>0)){
        printf("\n\nFonte:"
               "\n  https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/"
               "\n  https://pt.wikipedia.org/wiki/Torre_de_Hanói\n\n");
    } //if que apresenta as fontes caso o usuário escolha ver alguma curiosidade
}
