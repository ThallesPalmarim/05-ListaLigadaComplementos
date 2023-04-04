#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO*ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
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
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* aux = primeiro;
	while (aux != NULL)
	{
		if (aux->valor == novo->valor)
		{
			cout << "ELEMENTO DUPLICADO\n";
			return;
		}
		aux = aux->prox;
	}
	if (primeiro == NULL) {
		primeiro = novo;
		ultimo = novo;
	}
	else if (novo->valor < primeiro->valor) {
		novo->prox = primeiro;
		primeiro = novo;
	}
	else if (novo->valor > ultimo->valor) {
		ultimo->prox = novo;
		ultimo = novo;
	}
	else {
		NO* aux = primeiro->prox;
		NO* anterior = primeiro;

		while (aux != NULL) {
			if (aux->valor >= novo->valor) {
				anterior->prox = novo;
				novo->prox = aux;
				break;
			}
			anterior = aux;
			aux = aux->prox;
		}
	}
}

void excluirElemento()
{
	int valor;
	NO* exclu = NULL;
	NO* aux = primeiro;
	NO* anterior = NULL;

	if (primeiro == NULL) {
		cout << "Lista vazia\n";
		return;
	}

	cout << "Qual elemento deseja excluir?\n";
	cin >> valor;

	if (valor < primeiro->valor)
	{
		cout << "ELEMENTO NAO ENCONTRADO\n";
		return;
	}
	else if (valor > ultimo->valor)
	{
		cout << "ELEMENTO NAO ENCONTRADO\n";
		return;
	}
	else
	{
		while (aux != NULL) {
			if (aux->valor == valor) {
				if (anterior == NULL) {
					primeiro = aux->prox;
				}
				else {
					anterior->prox = aux->prox;
				}
				cout << "EXCLUIDO\n";
				free(aux);
				return;
			}
			anterior = aux;
			aux = aux->prox;
		}
	}
	cout << "NAO ENCONTRADO\n";
}

void buscarElemento()
{
	NO* busca = (NO*)malloc(sizeof(NO));
	if (busca == NULL)
	{
		return;
	}

	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}

	cout << "Qual elemento deseja buscar?\n";
	cin >> busca->valor;
	busca->prox = NULL;
	int x = 0;

	NO* aux = primeiro;

	if (busca->valor > ultimo->valor)
	{
		cout << "NAO ENCONTRADO\n";
	}
	else
	{
		if (busca->valor < primeiro->valor)
		{
			cout << "NAO ENCONTRADO\n";
		}
		else
		{
			while (aux != NULL)
			{
				if (aux->valor == busca->valor)
				{
					x++;
				}
				aux = aux->prox;
			}
			if (x == 0)
			{

				cout << "NAO ENCONTRADO\n";
			}
			else
			{
				cout << "ENCONTRADO\n";
			}
		}
	}
}
