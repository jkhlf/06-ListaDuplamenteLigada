#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void exibirReverso();
void inserirElemento();
void excluirPrimeiroElemento();
void excluirUltimoElemento();
void excluirElemento();
void inserirOrdenado();

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 10) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Exibir quantidade de elementos \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Exibir elementos na ordem reversa \n";
		cout << "6 - Excluir primeiro elemento \n";
		cout << "7 - Excluir ultimo elemento \n";
		cout << "8 - Excluir elemento \n";
		cout << "9 - Inserir ordenado \n";
		cout << "10 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:inserirElemento();
			break;
		case 3: exibirQuantidadeElementos(); 
			break;
		case 4: exibirElementos();
			break;
		case 5: exibirReverso();
			break;
		case 6: excluirPrimeiroElemento();
			break;
		case 7: excluirUltimoElemento();
			break;
		case 8: excluirElemento();
			break;
		case 9: inserirOrdenado();
			break;
		case 10:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		novo->ant = ultimo;
		ultimo->prox = novo;
		ultimo = novo;
	}
}


void exibirReverso()
{
	if (ultimo == NULL) {
		cout << "Lista vazia " << endl;
		return;
	}
	cout << "Elementos em ordem reversa : \n";
	NO* aux = ultimo;
	while (aux != NULL) {
		cout << aux->valor << endl;
		aux = aux->ant;
	}
}

void excluirPrimeiroElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia " << endl;
		return;
	}
	NO* paraExcluir = primeiro;
	primeiro = primeiro->prox;
	if (primeiro != NULL) {
		primeiro->ant = NULL;
	}
	else {
		ultimo = NULL;
	}
	free(paraExcluir);
	cout << " Primeiro elemento excluido" << endl;

}

void excluirUltimoElemento()
{
	if (ultimo == NULL) {
		cout << "Lista vazia " << endl;
		return;
	}
	NO* paraExcluir = ultimo;
	ultimo = ultimo->ant;
	if (ultimo != NULL) {
		ultimo->prox= NULL;
	}
	else {
		primeiro = NULL;
	}
	free(paraExcluir);
	cout << " Ultimo elemento excluido" << endl;
}


void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "A lista esta vazia" << endl;
		return;
	}

	int valor;
	cout << "Informe o elemento a ser excluido: ";
	cin >> valor;

	NO* atual = primeiro;
	NO* anterior = NULL;

	while (atual != NULL && atual->valor != valor) {
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL) {
		cout << "O elemento digitado nao foi encontrado." << endl;
		return;
	}

	if (anterior == NULL) {
		primeiro = atual->prox;
		if (primeiro != NULL)
			primeiro->ant = NULL;
		else
			ultimo = NULL;
	}
	else {
		anterior->prox = atual->prox;
		if (atual->prox != NULL)
			atual->prox->ant = anterior;
		else
			ultimo = anterior; 
	}

	cout << "O elemento " << valor << " foi excluido com sucesso." << endl;

	delete atual;  //ele esta fechando apos executar, não sei por qual motivo.
}


void inserirOrdenado() {
	NO* novo = new NO;
	if (novo == NULL) {
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL) {
		primeiro = novo;
		ultimo = novo;
		return;
	}

	NO* anterior = NULL;
	NO* atual = primeiro;
	while (atual != NULL && atual->valor < novo->valor) {
		anterior = atual;
		atual = atual->prox;
	}
	if (atual != NULL && atual->valor == novo->valor) {
		cout << "Elemento já existe na lista." << endl;
		delete novo;
		return;
	}
	if (anterior == NULL) {
		novo->prox = primeiro;
		primeiro->ant = novo;
		primeiro = novo;
	}
	else {
		anterior->prox = novo;
		novo->ant = anterior;
		novo->prox = atual;
		if (atual != NULL) {
			atual->ant = novo;
		}
		else {
			ultimo = novo;
		}
	}
}
