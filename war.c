#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define TAM_STRING 50
#define QTD_TERRITORIOS 5

struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/*while ((c = getchar()) != '\n' && c != EOF);

getchar() lê um caractere do buffer do teclado.

O while continua lendo até encontrar o Enter ('\n') ou o fim do arquivo (EOF),
o que indica que o usuário terminou de digitar.

O ponto e vírgula ; no final indica que o corpo do while é vazio — ele só faz a repetição sem executar mais nada.
*/

int main() {

    struct Territorio territorios[QTD_TERRITORIOS];
    int i;

    printf("=== Cadastro de Territórios ===\n\n");

    for (i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);

        printf("Digite o nome do território: ");
        fgets(territorios[i].nome, TAM_STRING, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
		//stdin quer dizer que vai ler a entrada do teclado
        printf("Digite a cor do exército: ");
        fgets(territorios[i].cor, TAM_STRING, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        /*    mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        Estamos dizendo :

        “Procure o \n na string e substitua por \0 (fim da string).”

            Isso remove o ENTER que o fgets coloca automaticamente.
        */
        printf("Digite o número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBufferEntrada();

        printf("\n");
    }

    printf("\n=== Estado Atual do Mapa ===\n");
    for (i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}
