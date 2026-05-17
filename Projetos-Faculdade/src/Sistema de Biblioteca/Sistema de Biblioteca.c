#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define LIMITE_LIVROS 100

typedef struct {
int id;
char nome[100];
char escritor[100];
int emprestado;
} RegistroLivro;

RegistroLivro biblioteca[LIMITE_LIVROS];
int qtd_livros = 0;


int localizarPosicao(int codigoBusca) {
for (int i = 0; i < qtd_livros; i++) {
if (biblioteca[i].id == codigoBusca) {
return i;
  }
 }
return -1;
}

void limparEntrada() {
int c;
while ((c = getchar()) != '\n' && c != EOF);
}

void adicionarNovoLivro() {
system("cls");
if (qtd_livros >= LIMITE_LIVROS) {
printf("!! Capacidade maxima atingida !!\n");
return;
}
    
printf(">>> NOVO CADASTRO <<<\n");
printf("Cod. Identificador: ");
scanf("%d", &biblioteca[qtd_livros].id);
limparEntrada();

printf("Nome da Obra: ");
fgets(biblioteca[qtd_livros].nome, 100, stdin);
biblioteca[qtd_livros].nome[strcspn(biblioteca[qtd_livros].nome, "\n")] = 0;

printf("Nome do Autor: ");
fgets(biblioteca[qtd_livros].escritor, 100, stdin);
biblioteca[qtd_livros].escritor[strcspn(biblioteca[qtd_livros].escritor, "\n")] = 0;

biblioteca[qtd_livros].emprestado = 0;
qtd_livros++;

printf("\n[Sucesso] Livro registrado no sistema!\n");
}

void buscarDadosLivro() {
system("cls");
int busca;
printf(">>> CONSULTA DE ACERVO <<<\n");
printf("Informe o codigo: ");
scanf("%d", &busca);
limparEntrada();

int pos = localizarPosicao(busca);
if (pos != -1) {
printf("\n==========================\n");
printf("LIVRO:  %s\n", biblioteca[pos].nome);
printf("AUTOR:  %s\n", biblioteca[pos].escritor);
printf("STATUS: %s\n", biblioteca[pos].emprestado ? "EMPRESTADO" : "DISPONIVEL");
printf("==========================\n");
  } else {
        printf("\n[!] Codigo %d nao localizado.\n", busca);
 }
}

void realizarEmprestimo() {
system("cls");
int busca;
printf(">>> AREA DE EMPRESTIMO <<<\n");
printf("Codigo do livro desejado: ");
scanf("%d", &busca);
limparEntrada();

int pos = localizarPosicao(busca);

if (pos != -1) {
if (biblioteca[pos].emprestado == 0) {
biblioteca[pos].emprestado = 1;
printf("\n[OK] Livro retirado com sucesso!\n");
} else {
printf("\n[Aviso] Este item ja se encontra emprestado.\n");
 }
} else {
printf("\n[!] Codigo inexistente.\n");
 }
}

void realizarDevolucao() {
system("cls");
int busca;
printf(">>> AREA DE DEVOLUCAO <<<\n");
printf("Código do livro para entrega: ");
scanf("%d", &busca);
limparEntrada();

int pos = localizarPosicao(busca);
if (pos != -1) {
if (biblioteca[pos].emprestado == 1) {
biblioteca[pos].emprestado = 0;
printf("\n[OK] Devolucao confirmada!\n");
} else {
printf("\n[Aviso] O livro ja consta como disponivel no sistema.\n");
 }
} else {
printf("\n[!] Codigo inexistente.\n");
 }
}

void exibirTodos() {
system("cls");
printf(">>> LISTAGEM COMPLETA <<<\n\n");
if (qtd_livros == 0) {
printf("Nenhum dado cadastrado ate o momento.\n");
} else {
printf("%-6s | %-25s | %-15s\n", "ID", "TITULO", "SITUACAO");
printf("------------------------------------------------------------\n");
for (int i = 0; i < qtd_livros; i++) {
printf("%-6d | %-25.25s | %s\n", 
biblioteca[i].id, 
biblioteca[i].nome, 
biblioteca[i].emprestado ? "Emprestado" : "Livre");
  }
 }
}

int main() {
setlocale(LC_ALL, "Portuguese");
int selecao;

do {
system("cls");
printf("  --- GESTAO DE BIBLIOTECA ---  \n");
printf("  1. Cadastrar livro\n");
printf("  2. Consultar livro\n");
printf("  3. Emprestar livro\n");
printf("  4. Devolver livro\n");
printf("  5. Listar livros\n");
printf("  0. Sair\n");
printf("  ----------------------------\n");
printf("  Sua opcao: ");
        
if (scanf("%d", &selecao) != 1) {
selecao = -1;
limparEntrada();
} else {
limparEntrada();
}

switch (selecao) {
case 1: adicionarNovoLivro(); break;
case 2: buscarDadosLivro(); break;
case 3: realizarEmprestimo(); break;
case 4: realizarDevolucao(); break;
case 5: exibirTodos(); break;
case 0: printf("\nFinalizando aplicacao...\n"); break;
default: printf("\nComando invalido.\n");
}

if (selecao != 0) {
printf("\nTecle ENTER para prosseguir...");
getchar();
}

} while (selecao != 0);

return 0;
}