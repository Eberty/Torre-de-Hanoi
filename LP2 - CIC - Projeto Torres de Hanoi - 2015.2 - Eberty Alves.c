/****
*
* T�tulo: Torre de Han�i
*
* Autor: Eberty Alves da Silva
*
* Data de Cria��o: 19 de janeiro de 2016
* �ltima modifica��o: 12 de fevereiro de 2016
*
* Descri��o: O programa resolve o problema das Torres de Han�i para um n�mero arbitr�rio de discos,
*           mostrando a sequ�ncia de movimentos de forma gr�fica. Para valores muito grandes de discos
*           ocorrer� o desbordamento da tela, o programa funciona corretamente para 0 < ndiscos <= 10.
*           Adicionalmente, o programa cria um arquivo texto mostrando a sa�da de programa.
*
* Entrada:  Valor inteiro representando o n�mero de discos contidos na Torre de Han�i, e a op��o escolhida no menu
*           Caso o n�mero informado seja inv�lido � repetida a opera��o at� a informa��o correta ser apresentada
*
*   Exemplo: Informe o n�mero de discos a serem usados pela torre: 2
*
* Sa�da:    Al�m das informa��es contidas no menu, o programa mostra tamb�m a sequ�ncia de
*           movimentos para um n�mero arbitr�rio de discos de forma gr�?ca,
*           como pode ser visto no exemplo a seguir para n�mero de discos = 2.
*
*   Exemplo: Esta � a sequ�ncia de movimentos para 2 discos:
*
*     *    |    |
*    ***   |    |
*   --+----+----+--
*
*   Passo: 1
*   Disco movido da 1� haste para a 3� haste
*
*     |    |    |
*    ***   |    *
*   --+----+----+--
*
*   Passo: 2
*   Disco movido da 1� haste para a 2� haste
*
*     |    |    |
*     |   ***   *
*   --+----+----+--
*
*   Passo: 3
*   Disco movido da 3� haste para a 2� haste
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
* T�tulo: LerEVerificaNumD
*
* Autor: Eberty Alves
*
* Data de Cria��o: 23 de janeiro de 2016
* �ltima modifica��o: 27 de janeiro de 2016
*
* Descri��o: A fun��o l� e verifica o n�mero de discos a serem usados para resolver o problema em quest�o.
*
* Par�metros:
*   (entrada/sa�da)
*           int *nDiscos:   � um ponteiro que aponta para a vari�vel nDiscos (quantidade de discos) da fun��o main.
*
* Valor de retorno: Um inteiro ir� definir se a resolu��o pode ser executada ou n�o. Ela leva em conta a quantidade de discos informada.
*
****/
int LerEVerificaNumD (int *);


        //Modulo da Matriz
/****
*
* T�tulo: AlocaMatriz
*
* Autor: Dany Sanchez Dominguez - Altera��es feitas por Eberty Alves
*
* Data de Cria��o: 21 de janeiro de 2016
* �ltima modifica��o: 22 de janeiro de 2016
*
* Descri��o: A fun��o aloca uma matriz cujo o ponteiro fora definido na fun��o main.
*
* Par�metros:
*   (entrada)
*           int n:  Representa o n�mero de linhas (discos) da matriz.
*           H� ainda um Define (haste) que representa a quantidade de colunas (3)
*
* Valor de retorno: A fun��o retorna a matriz alocada.
*
****/
int ** AlocaMatriz(const int);

/****
*
* T�tulo: PreencheMatriz
*
* Autor: Eberty Alves
*
* Data de Cria��o: 21 de janeiro de 2016
* �ltima modifica��o: 3 de fevereiro de 2016
*
* Descri��o: Cria uma torre com os respectivos tamanhos dos discos na primeira coluna da matriz
*            As outras hastes s�o preenchidas com discos de tamanho zero (sem discos).
*
* Par�metros:
*   (entrada)
*           int **m:                � um ponteiro que aponta para a matriz que j� foi alocada e definida na fun��o AlocaMatriz.
*           int *discoRef:          Indica o tamanho para cada disco (Que s�o elaborados a partir da formula de n�mero �mpar).
*           const int totalDiscos:  indica a quantidade de linhas a serem percorridas.
*
* Valor de retorno: void (os valores de cada posi��o da matriz s�o preenchidos no decorrer da fun��o).
*
****/
void PreencheMatriz(int **, int *, const int);

/****
*
* T�tulo: LiberaMatriz
*
* Autor: Dany Sanchez Dominguez - Altera��es feitas por Eberty Alves
*
* Data de Cria��o: 21 de janeiro de 2016
* �ltima modifica��o: 21 de janeiro de 2016
*
* Descri��o: Libera uma matriz alocada dinamicamente.
*
* Par�metros:
*   (entrada)
*           int **m: Ponteiro que aponta para a matriz que foi alocada e definida na fun��o AlocaMatriz.
*           H� ainda um Define (haste) que representa a quantidade de colunas (3) para serem liberadas.
*
* Valor de retorno: void.
*
****/
void LiberaMatriz(int **);


        //Modulo de resulu��o
/****
*
* T�tulo: TorreHanoi
*
* Autor: Eberty Alves
*
* Data de Cria��o: 23 de janeiro de 2016
* �ltima modifica��o: 10 de fevereiro de 2016
*
* Descri��o: S�rie de chamadas recursivas para resolver o problema em quest�o.
*
* Par�metros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posi��o dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       int disco:              Indica qual execu��o a fazer (nesse caso disco == 1).
*       int ori:                Indica a haste de origem do disco a ser movido.
*       int dest:               Indica a haste de destino para onde ser� movido o disco.
*       int aux:                Indica a haste que servir� de auxiliar durante a movimenta��o dos discos de uma haste pra outra.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gr�fico).
*       int *passo:             Ponteiro para a vari�vel que in�mera a quantidade de passos que j� foram feitos.
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
*
* Valor de retorno: Para o caso base ele define a haste (coluna) a qual um dos discos de outra haste ser� movido, chamando  ent�o a fun��o MoveDisco.
*
****/
void TorreHanoi(int **, const int, int, int, int, int, const int, int*, FILE *);

/****
*
* T�tulo: MoveDisco
*
* Autor: Eberty Alves
*
* Data de Cria��o: 23 de janeiro de 2016
* �ltima modifica��o: 10 de fevereiro de 2016
*
* Descri��o: A fun��o define a posi��o do disco de origem atrav�s do par�metro de entrada, depois verifica para onde ele deve ser copiado (linha de destino)
*            Ent�o, copia o disco da posi��o de origem para a posi��o de destino, apagando depois o disco de origem (zero).
*            A fun��o tamb�m indica a quantidade de passos j� feitos, e o movimento realizado
*            Depois chama a fun��o imprimeDiscos imprimir a nova posi��o dos discos na tela.
*
* Par�metros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posi��o dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       int ori:                Indica a haste de origem do disco a ser movido.
*       int dest:               Indica a haste de destino para onde ser� movido o disco.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gr�fico).
*       int *passo:             Ponteiro para a vari�vel que in�mera a quantidade de passos que j� foram feitos.
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
*
* Valor de retorno: Retorna as novas posi��es dos discos.
*
****/
void MoveDisco(int **, const int, int, int, const int, int*, FILE *);

/****
*
* T�tulo: ImprimeDiscos
*
* Autor: Eberty Alves
*
* Data de Cria��o: 23 de janeiro de 2016
* �ltima modifica��o: 10 de fevereiro de 2016
*
* Descri��o: A fun��o imprime na tela e no arquivo ' ', '*' e/ou '|' a depender da entrada. Indicando graficamente a posi��o atual dos discos em rela��o a cada haste.
*            Apos isso ela chama a fun��o ImprimeBase, para terminar a amostragem gr�fica do passo.
*
* Par�metros:
*   (entrada)
*       int **m:                Ponteiro que aponta para a matriz que contem a posi��o dos discos.
*       const int totalDiscos:  Indica a quantidade de linhas da matriz.
*       const int discoRef:     Disco de referencia (2 casas maior do que o maior disco, para auxiliar no desenho gr�fico).
*       FILE *arquivo:          Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
*
* Valor de retorno: A fun��o n�o possui retorno.
*
****/
void ImprimeDiscos(int **, const int, const int, FILE *);

/****
*
* T�tulo: ImprimeBase
*
* Autor: Eberty Alves
*
* Data de Cria��o: 23 de janeiro de 2016
* �ltima modifica��o: 10 de fevereiro de 2016
*
* Descri��o: A fun��o imprime na tela e no arquivo uma base para a torre, a fun��o tamb�m gera uma pausa antes que a tela do computador seja limpa para apresentar o pr�ximo movimento.
*
* Par�metros:
*   (entrada)
*       const int discoref: ajuda a definir a quantidade de '-' antes de cada '+'.
*       FILE *arquivo:      Ponteiro para o arquivo .txt criado no in�cio do programa, usado para a fun��o fprintf.
*
* Valor de retorno: A fun��o n�o possui retorno.
*
****/
void ImprimeBase(const int, FILE *);


        //Modulo menu
/****
*
* T�tulo: Menu
*
* Autor: Eberty Alves
*
* Data de Cria��o: 21 de janeiro de 2016
* �ltima modifica��o: 25 de janeiro de 2016
*
* Descri��o: Imprime o menu com as op��es que o usu�rio pode escolher.
*
* Par�metros:
*   (entrada) - dentro da pr�pria fun��o
*       int opcao: Informa (l�) qual op��o do menu foi escolhida pelo usu�rio.
*
* Valor de retorno: a op��o escolhida.
*
****/
int Menu(void);

/****
*
* T�tulo: SobreProblema
*         LendaHanoi
*         Curiosidades
*
* Autor: Eberty Alves
*
* Data de Cria��o: 21 de janeiro de 2016
* �ltima modifica��o: 23 de janeiro de 2016
*
* Descri��o: Essas fun��es s�o complementares ao menu de op��es,
*            Possuem como �nica finalidade apresentar na tela informa��es sobre o problema em quest�o.
*            Essas fun��es ajudam a manter a fun��o main enxuta.
*
* Par�metros: fun��es sem par�metros, com exce��o da fun��o Curiosidades, que possui outro menu de op��es dentro dela.
*
* Valor de retorno: fun��es sem valores de retorno.
*
****/
void SobreProblema(void);
void LendaHanoi(void);
void Curiosidades(void);


int main(){
    int nDiscos; //Numero de Discos da Torre
    int **matrizHanoi; //Matriz onde ira ser armazenado os discos da Torre de Hanoi
    int discoRef; // Vai dizer o tamanho do disco durante o preenchimento de cada linha da matriz e depois servira como referencia
    int continua; //Representa se o numero de disco foi aceito durante a leitura e a verifica�ao
    int op; // Op��o do menu escolhida pelo usuario
    int passo; //Quantidade de movimentos realizados
    FILE *arquivo; //arquivo texto

    setlocale(LC_ALL, "portuguese"); //uso de acentos

    if ((arquivo = fopen("Torre de Hanoi.txt", "w")) == NULL){ //cria arquivo para escrita e verifica
        printf("Erro ao criar o arquivo texto onde os dados desse programa ser�o gravados!!!\n");
        exit (-1);
    }

    do{
        system("cls");
        op = Menu();

        switch(op){ //executa cada iteracao de acordo com a op�ao esolhida pelo usuario
            case 1 :
                system("cls");
                discoRef = 1;
                passo = 0;
                continua = LerEVerificaNumD(&nDiscos);

                if(continua == 1){ //Se o numero de disco foi aceito durante a leitura e a verifica�ao o codigo � executado
                    fprintf(arquivo, "Esta � a sequ�ncia de movimentos para %d discos:\n\n", nDiscos);
                    matrizHanoi = AlocaMatriz(nDiscos);
                    PreencheMatriz(matrizHanoi, &discoRef, nDiscos);
                    //discoRef = (disco maior: 2*nDiscos - 1) + 2

                    system("cls");
                    printf("\n\n\n");
                    ImprimeDiscos(matrizHanoi, nDiscos, discoRef, arquivo); //imprime a posi��o inicial dos discos antes dos movimentos serem realizados

                    TorreHanoi(matrizHanoi, nDiscos, nDiscos, 0, 1, 2, discoRef, &passo, arquivo);//Primeira chamada antes das chamadas recursivas

                    printf("\n%d passos s�o nesses�rios para resolver o problema para %d discos\n", (int)pow(2, nDiscos)-1, nDiscos);
                    fprintf(arquivo, "\n\n%d passos s�o nesses�rios para resolver o problema para %d discos\n\n\n", (int)pow(2, nDiscos)-1, nDiscos);

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

            case 5 : //case de sa�da
                system("cls");
                printf("Parab�ns, todos as execu��es da torre feitas nessa sess�o agora\n"
                       "est�o disponiveis em um arquivo de nome Torre de Hanoi.txt\n"
                       "na pr�pria pasta do execut�vel\n\n"
                       "Obrigado por desfrutar de nosso programa, esperamos v�-lo novamente em breve\n\n");
                fprintf(arquivo, "Obrigado por desfrutar de nosso programa, esperamos v�-lo novamente em breve");
                break;

            default :
                printf("\nOp��o Inv�lida\n");
                break;
        } //fim do switch case
        system("pause");
    } while (op != 5); //fim do Do While

    fclose(arquivo);//fecha arquivo de escrita

    return 0;
}


int LerEVerificaNumD(int *nDiscos){
    char resp; //em caso de n�mero muito grande ela define se a execu��o continua ou n�o
    printf("Informe o n�mero de discos a serem usados pela torre: ");
    scanf("%d", nDiscos); //recebe o n�mero de discos

    if (*nDiscos < 1){
        printf("Erro!!!\nA torre n�o pode conter menos de 1 disco.\n");
        return 0;
    } //verifica se o numero � v�lido

    if (*nDiscos > 10){
        printf("Aviso!!!\nCaso o n�mero de discos seja maior que 10,\n"
               "o programa pode ficar extenso e apresentar falhas durante a exibi��o das torres.\n"
               "Deseja continuar?[s/n].\n");
        do{
            fflush(stdin);
            resp = getchar();
            if (resp == 's' || resp == 'S')
                return 1;
            else if (resp == 'n' || resp == 'N')
                return 0;
            else
                printf("Op��o inv�lida, digite novamente: ");
        }while (resp != 's' || resp != 'S'|| resp != 'n'|| resp != 'N'); //recebimento da resposta v�lida
    } //verifica se o usu�rio quer continuar para mais de 10 discos
    return 1;
}

int ** AlocaMatriz(const int n){
    int **m; //ponteiro para matriz de retorno
    int i; //contador

    m = malloc(n * sizeof(int *)); //aloca��o linhas
    if (m == NULL){
        printf("Erro!!! \nVoc� alcan�ou toda a mem�ria dispon�vel e infelizmente o programa travou\n");
        exit(-1);
    } //if verifica��o linhas

    for(i = 0; i < n; i++){ //aloca��o colunas
        m[i] = malloc(hastes * sizeof(int));
        if (m[i] == NULL){
            printf("Erro!!! \nVoc� alcan�ou toda a mem�ria dispon�vel e infelizmente o programa travou\n");
            exit(-1);
        } //if verifica��o colunas
    }
    return m; //Retorno (matriz)
}

void PreencheMatriz(int **m, int *discoRef, const int totalDiscos){
    int i; //contador
    for(i = totalDiscos - 1 ; i >= 0 ; i--){ //percorre a matriz (linhas)
        m[i][0] = *discoRef; //cria torre na coluna 0 da matriz
        *discoRef += 2; //aumenta o tamanho do pr�ximo disco
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

    while(m[linhaOri][ori] == 0) //procura o disco que fica na posi��o mais alta da haste de origem
        linhaOri--;

    while(m[linhaDest][dest] != 0) //fica uma posi��o acima do disco mais alto da linha de destino
        linhaDest++;

    m[linhaDest][dest] = m[linhaOri][ori]; //Copia o Disco mais alto da Origem pra posi��o Destino
    m[linhaOri][ori] = 0; //remove o disco da origem

    system("cls"); //limpa a tela para apresentar o pr�ximo passo
    *passo+=1; //acrescenta para contar quantos passos j� foram feitos
    printf("Passo: %d\n", *passo);
    fprintf(arquivo, "\nPasso: %d\n", *passo);
    printf("Disco movido da %d� haste para a %d� haste\n\n", ori+1, dest+1); //apresenta o movimento de forma escrita
    fprintf(arquivo, "Disco movido da %d� haste para a %d� haste\n\n", ori+1, dest+1);
    ImprimeDiscos(m, totalDiscos, discoRef, arquivo); //imprime graficamente a posi��o dos discos
}

void ImprimeDiscos(int **m, const int totalDiscos, const int discoRef, FILE *arquivo){
    int i, j, k, espaco; //contadores
    for(i = totalDiscos - 1 ; i >= 0 ; i--){
        for(j = 0; j < hastes; j++){
            espaco = (discoRef - m[i][j]) / 2; //quantidade de espa�os antes de imprimir os '*'

            for(k = 0; k < espaco; k++){
                printf(" ");
                fprintf(arquivo, " ");
            } //espa�os a esquerda

            for(k = 0; k < m[i][j]; k++){
                printf("*");
                fprintf(arquivo, "*");
            } //impres�o de cada discos

            if (m[i][j] == 0){
                printf ("|");
                fprintf(arquivo, "|");
            } //caso n�o houver disco

            for(k = 0; k < espaco; k++){
                printf(" ");
                fprintf(arquivo, " ");
            } //espa�os a direita

        } //fim do for que percorre as 3 hastes (colunas)
        printf("\n"); //pula para pr�xima linha grafica
        fprintf(arquivo, "\n");
    }//fim do for que percorre as linhas
    ImprimeBase (discoRef, arquivo); //ap�s a impress�o dos discos imprime a base para eles
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
    Sleep(1000); //pausa antes que a tela seja limpa para apresentar o pr�ximo passo

}

int Menu(void){
    int opcao; //escolha
    printf("Ol� Bem-vindo ao programa Torres de Han�i.\n\n"
           "Nesse programa voc� encontrar� as principais informa��es sobre a torre\n"
           "Encontrar� tamb�m m�todos de resolu��o para os mais diversos n�meros de discos\n"
           "Caso aceite executar o programa, basta informar a quantidade dos mesmos\n"
           "O programa ser� capaz de mostrar-lhe o passo a passo da resolu��o do problema\n\n"
           "   Copyright Eberty Alves v1.0\n\n"
           "Escolha a op��o:\n"
           "(1) Para executar o programa\n"
           "(2) Para entender esse problema cl�ssico em Ci�ncias da Computa��o\n"
           "(3) Para conhecer mais sobre a Lenda de Han�i\n"
           "(4) Para curiosidades\n"
           "(5) Para sair do programa\n");
    printf("\nVoc� escolheu: ");
    scanf("%d", &opcao);
    return opcao;
}

void SobreProblema(void){
    printf("Voc� escolheu a op��o:\n"
           "(2) Entender esse problema cl�ssico em Ci�ncias da Computa��o"
           "\n\n   Eis um problema em que a recursividade m�ltipla realmente ajuda. Esse problema consiste em uma base contendo 3 hastes, em uma das quais est�o dispostos n discos, em ordem crescente de di�metro."
           "\n   O objetivo � mover todos os n discos de uma haste para outra qualquer, usando uma delas como auxiliar."
           "\n   Parece f�cil, n�o? Mas n�o � t�o simples, porque voc� deve respeitar as seguintes restri��es:"
           "\n     1. Nunca colocar um disco maior sobre um disco menor;"
           "\n     2. Pode-se mover um �nico disco por vez;"
           "\n     3. Nunca colocar um disco em outro lugar que n�o seja numa das tr�s hastes."
           "\n   Voc� pode achar que esse problema n�o � terrivelmente importante. Ao contr�rio! Conhe�a a lenda de Han�i voltando ao menu e escolhendo a op��o 3."
           "\n   Primeiro, vamos entender a solu��o recursiva para esse problema. A come�ar com um caso realmente f�cil: um disco (n=1), esse ser� nosso caso base. Voc� sempre pode mover o disco 1 da haste A para qualquer outra haste, porque sabe que quaisquer discos abaixo dele devem ser maiores."
           "\n   E quanto a dois ou mais discos? Como voc� pode solucionar o problema quando n>=2? Por isso existe a haste C, um local para colocar os discos menores de forma que possamos expor ao disco mais no fundo."
           "\n   Mais ao ponto, movendo (n-1) discos menores da haste original para uma auxiliar, voc� recursivamente resolveu um subproblema: mover os discos 1 at� n-1. Uma vez que voc� resolveu esse subproblema, voc� pode mover o disco maior. Agora, para finalizar, voc� precisa resolver recursivamente o subproblema dos discos 1 a n-1 que se deslocam para a haste auxiliar C e coloc�-las no destino B. A haste A ser� a nova auxiliar."
           "\n   Voc� concorda que pode mover qualquer quantidade de discos de qualquer haste para qualquer outra haste seguindo as restri��es? Diga SIM e escolha a op��o 1 do menu principal."
           "\n\nFonte: https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/\n\n");
}

void LendaHanoi(void){
    printf("Voc� escolheu a op��o:\n"
           "(3) Conhecer mais sobre a Lenda de Han�i"
           "\n\n   Existem v�rias lendas a respeito da origem do jogo:"
           "\n\n   Em geral elas afirmam que, em algum lugar da �sia (Tibete, Vietn�, �ndia - escolha na internet a lenda que preferir), monges est�o solucionando esse problema com um conjunto de 64 discos, e os monges acreditam que quando terminarem de mover todos os 64 discos do pino A para o pino B de acordo com as regras, o mundo vai acabar. Se os monges tiverem raz�o, dever�amos estar correndo pelas ruas em p�nico?"
           "\n   Eles est�o usando n=64 discos, e assim eles v�o precisar mover os discos 2^ {64} - 1 vezes (entenda a formula voltando ao menu e escolhendo a op��o 4 curiosidades). Estes monges s�o �geis e fortes: Eles podem mover um disco a cada segundo, noite e dia. Quanto tempo � 2^ {64} - 1 segundos? Usando a estimativa aproximada de 365,25 dias por ano, trata-se de mais de 584 bilh�es de anos."
           "\n   O sol tem apenas cerca de mais cinco a sete bili�es de anos antes de virar supernova e explodir sobre n�s. Ent�o, sim, o mundo vai acabar. N�o importa os qu�o r�pidos sejam os monges, isso vai acontecer muito antes deles poderem mover todos os 64 discos das hastes A para B."
           "\n   Quer saber como mais podemos usar esse algoritmo, al�m de prever o fim do mundo? (Retorne ao menu principal e escolha a op��o 4)"
           "\n\nFonte: https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/\n\n");
}

void Curiosidades(void){
    int menu2; //escolha para o segundo menu (curiosidades)
    printf("Voc� escolheu a op��o:\n"
           "(4) Curiosidades"
           "\n\nSelecione a curisidade que preferir:"
           "\n  (1)Origens"
           "\n  (2)Prova para o n�mero de movimentos"
           "\n  (3)Aplica��es"
           "\n  (4)Formas de Resolu��o"
           "\n  (5)Retornar ao menu principal");
    printf("\n\nVoc� escolheu: ");
    scanf("%d", &menu2);
    switch (menu2){
        case 1 :
            printf("\nO problema foi inventado pelo matem�tico franc�s �douard Lucas em 1883. O nome foi inspirado na torre s�mbolo da cidade de Han�i, no Vietn� . N�o � claro se Lucas inventou a lenda ou se foi inspirada por ele."); break;
        case 2 :
            printf("\nA sucess�o formada pela soma dos movimentos � uma sucess�o (1,2,4...2^n) que � uma progress�o geom�trica, ou seja, essa soma equivale a: [a * (q^ (n) � 1) ] / (q - 1), onde a � o primeiro termo e q � a raz�o. J� que a raz�o � 2 e o primeiro termo � 1 temos que [1 * (2^ (n) � 1) ] / (2 - 1) = 2^ (n) � 1."
                   "\n\nVamos provar por indu��o em n que o n�mero m�nimo de movimentos para conseguir transferir todos os discos da primeira estaca � terceira � 2^ (n) - 1, sendo n o n�mero de discos:"
                   "\n\nA solu��o � verdadeira para a base n = 1, pois 2^1 - 1 = 1 e precis�vamos de um movimento. Suponha que � poss�vel resolver um problema para n-1 discos em 2^ {n-1} - 1 movimentos, ent�o � poss�vel resolver um problema para n discos em 2^n - 1 movimentos. Precisa-se de 2^ {n-1} - 1 movimentos para resolver de forma recursiva o primeiro subproblema de mover os discos 1 a n-1, um movimento para mover o disco n e outro 2^ {n-1} - 1 movimentos para resolver de forma recursiva o segundo subproblema de mover discos de 1 a n-1. Se voc� somar os movimentos, voc� tem 2^n - 1."
                   "\n\nEnt�o, para solucionar um Han�i de 64 discos, como diz a lenda, s�o necess�rios 18.446.744.073.709.551.615 movimentos."); break;
        case 3 :
            printf("\nA Torre de Han�i pode ser trabalhada em n�veis de desenvolvimento com crian�as. Na pr�-escola, com regras simples de separa��o de cores e tamanhos, a torre de Han�i ajuda em quest�es cognitivas como: coordena��o motora, identifica��o de formas, ordem crescente e decrescente, entre outras formas de aprendizado."
                   "\n\nA Torre de Han�i tem sido tradicionalmente considerada como um procedimento para avalia��o da capacidade de mem�ria de trabalho, e principalmente de planejamento e solu��o de problemas."
                   "\n\nIniciando com um n�mero menor de pe�as, ou seja, resolvendo problemas mais simples, teremos oportunidade de desenvolver a l�gica e experimentar uma das mais importantes formas de racioc�nio matem�tico."); break;
        case 4 :
            printf("\nA resolu��o recursiva � mais limitada quanto ao tempo de realiza��o, j� que sua execu��o depender� de alguns fatores para tornar-se mais eficaz. J� a resolu��o Iterativa utiliza algumas estruturas de repeti��o (for, whiles), existe ainda a possibilidade de algumas estruturas adicionais (mais complexas) as quais tornam o algoritmo mais r�pido."); break;
        case 5 : break; //op��o de saida
        default :
            printf ("Op��o Inv�lida\n"); break;
    } // fim do switch case do segundo menu
    if ((menu2<=4) && (menu2>0)){
        printf("\n\nFonte:"
               "\n  https://pt.khanacademy.org/computing/computer-science/algorithms/towers-of-hanoi/"
               "\n  https://pt.wikipedia.org/wiki/Torre_de_Han�i\n\n");
    } //if que apresenta as fontes caso o usu�rio escolha ver alguma curiosidade
}
