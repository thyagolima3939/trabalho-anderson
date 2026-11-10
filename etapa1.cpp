#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Limites do sistema
const int MAX_CONTAS = 100;
const int MAX_MOVIMENTACOES = 500;

// Dados das contas
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

int quantidadeContas = 0;

// Historico de movimentacoes
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];

int quantidadeMovimentacoes = 0;

// Declaracao das funcoes
void cadastrarConta();
void listarContas();
void consultarConta();
void depositar();
void sacar();
void transferir();
void registrarMovimentacao(int numero, char tipo, double valor);
void exibirExtrato();

// Funcao principal
int main() {

    int opcao;

    cout << fixed << setprecision(2);

    do {

        cout << "\n========== SISTEMA BANCARIO ==========\n";
        cout << "1 - Cadastrar conta\n";
        cout << "2 - Listar contas\n";
        cout << "3 - Consultar conta\n";
        cout << "4 - Realizar deposito\n";
        cout << "5 - Realizar saque\n";
        cout << "6 - Realizar transferencia\n";
        cout << "7 - Exibir extrato\n";
        cout << "0 - Sair\n";
        cout << "======================================\n";

        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1:
                cadastrarConta();
                break;

            case 2:
                listarContas();
                break;

            case 3:
                consultarConta();
                break;

            case 4:
                depositar();
                break;

            case 5:
                sacar();
                break;

            case 6:
                transferir();
                break;

            case 7:
                exibirExtrato();
                break;

            case 0:
                cout << "\nEncerrando o sistema bancario...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}

// FUNCAO PARA CADASTRAR CONTA
void cadastrarConta() {

    if (quantidadeContas >= MAX_CONTAS) {
        cout << "\nLimite de contas atingido!\n";
        return;
    }

    int numero;
    bool existe = false;

    cout << "\nNumero da conta: ";
    cin >> numero;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            existe = true;
            break;
        }
    }

    if (existe) {
        cout << "\nConta ja cadastrada!\n";
        return;
    }

    cin.ignore();

    numeroConta[quantidadeContas] = numero;

    cout << "Nome do cliente: ";
    getline(cin, nomeCliente[quantidadeContas]);

    cout << "CPF: ";
    getline(cin, cpf[quantidadeContas]);

    cout << "Tipo de conta (1 - Corrente / 2 - Poupanca): ";
    cin >> tipoConta[quantidadeContas];

    while (tipoConta[quantidadeContas] != 1 &&
           tipoConta[quantidadeContas] != 2) {

        cout << "Tipo invalido! Digite 1 ou 2: ";
        cin >> tipoConta[quantidadeContas];
    }

    cout << "Saldo inicial: R$ ";
    cin >> saldo[quantidadeContas];

    while (saldo[quantidadeContas] < 0) {
        cout << "Saldo invalido. Digite novamente: ";
        cin >> saldo[quantidadeContas];
    }

    contaAtiva[quantidadeContas] = true;

    quantidadeContas++;

    cout << "\nConta cadastrada com sucesso!\n";
}

// FUNCAO PARA LISTAR CONTAS
void listarContas() {

    if (quantidadeContas == 0) {
        cout << "\nNenhuma conta cadastrada!\n";
        return;
    }

    cout << "\n========== CONTAS CADASTRADAS ==========\n";

    for (int i = 0; i < quantidadeContas; i++) {

        cout << "\nNumero: " << numeroConta[i];
        cout << "\nCliente: " << nomeCliente[i];
        cout << "\nCPF: " << cpf[i];

        if (tipoConta[i] == 1) {
            cout << "\nTipo: Conta Corrente";
        } else {
            cout << "\nTipo: Conta Poupanca";
        }

        cout << "\nSaldo: R$ " << saldo[i];

        if (contaAtiva[i]) {
            cout << "\nSituacao: Ativa\n";
        } else {
            cout << "\nSituacao: Inativa\n";
        }

        cout << "----------------------------------------\n";
    }
}

// FUNCAO PARA CONSULTAR CONTA
void consultarConta() {

    int numero;
    int indice = -1;

    cout << "\nDigite o numero da conta: ";
    cin >> numero;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\nConta nao encontrada!\n";
        return;
    }

    cout << "\n========== DADOS DA CONTA ==========\n";
    cout << "Numero: " << numeroConta[indice] << endl;
    cout << "Cliente: " << nomeCliente[indice] << endl;
    cout << "CPF: " << cpf[indice] << endl;

    if (tipoConta[indice] == 1) {
        cout << "Tipo: Conta Corrente\n";
    } else {
        cout << "Tipo: Conta Poupanca\n";
    }

    cout << "Saldo: R$ " << saldo[indice] << endl;

    if (contaAtiva[indice]) {
        cout << "Situacao: Ativa\n";
    } else {
        cout << "Situacao: Inativa\n";
    }
}

// FUNCAO PARA REGISTRAR MOVIMENTACAO
void registrarMovimentacao(int numero, char tipo, double valor) {

    if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
        cout << "\nLimite de movimentacoes atingido!\n";
        return;
    }

    contaMovimentacao[quantidadeMovimentacoes] = numero;
    tipoMovimentacao[quantidadeMovimentacoes] = tipo;
    valorMovimentacao[quantidadeMovimentacoes] = valor;

    quantidadeMovimentacoes++;
}

// FUNCAO PARA DEPOSITAR
void depositar() {

    int numero;
    int indice = -1;
    double valor;

    cout << "\nNumero da conta: ";
    cin >> numero;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\nConta nao encontrada!\n";
        return;
    }

    if (!contaAtiva[indice]) {
        cout << "\nConta inativa!\n";
        return;
    }

    if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
        cout << "\nLimite de movimentacoes atingido!\n";
        return;
    }

    cout << "Valor do deposito: R$ ";
    cin >> valor;

    if (valor <= 0) {
        cout << "\nValor invalido!\n";
        return;
    }

    saldo[indice] += valor;

    registrarMovimentacao(numeroConta[indice], 'D', valor);

    cout << "\nDeposito realizado com sucesso!\n";
    cout << "Novo saldo: R$ " << saldo[indice] << endl;
}

// FUNCAO PARA SACAR
void sacar() {

    int numero;
    int indice = -1;
    double valor;

    cout << "\nNumero da conta: ";
    cin >> numero;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\nConta nao encontrada!\n";
        return;
    }

    if (!contaAtiva[indice]) {
        cout << "\nConta inativa!\n";
        return;
    }

    if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
        cout << "\nLimite de movimentacoes atingido!\n";
        return;
    }

    cout << "Valor do saque: R$ ";
    cin >> valor;

    if (valor <= 0) {
        cout << "\nValor invalido!\n";
    }
    else if (saldo[indice] < valor) {
        cout << "\nSaldo insuficiente!\n";
    }
    else {

        saldo[indice] -= valor;

        registrarMovimentacao(numeroConta[indice], 'S', valor);

        cout << "\nSaque realizado com sucesso!\n";
        cout << "Novo saldo: R$ " << saldo[indice] << endl;
    }
}

// FUNCAO PARA TRANSFERIR
void transferir() {

    int contaOrigem, contaDestino;
    int indiceOrigem = -1;
    int indiceDestino = -1;
    double valor;

    cout << "\nConta de origem: ";
    cin >> contaOrigem;

    cout << "Conta de destino: ";
    cin >> contaDestino;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == contaOrigem) {
            indiceOrigem = i;
        }

        if (numeroConta[i] == contaDestino) {
            indiceDestino = i;
        }
    }

    if (indiceOrigem == -1 || indiceDestino == -1) {
        cout << "\nUma das contas nao foi encontrada!\n";
        return;
    }

    if (!contaAtiva[indiceOrigem] ||
        !contaAtiva[indiceDestino]) {

        cout << "\nUma das contas esta inativa!\n";
        return;
    }

    if (indiceOrigem == indiceDestino) {
        cout << "\nNao e possivel transferir para a mesma conta!\n";
        return;
    }

    if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
        cout << "\nEspaco insuficiente no historico!\n";
        return;
    }

    cout << "Valor da transferencia: R$ ";
    cin >> valor;

    if (valor <= 0) {
        cout << "\nValor invalido!\n";
        return;
    }

    if (saldo[indiceOrigem] < valor) {
        cout << "\nSaldo insuficiente!\n";
        return;
    }

    // Atualizar saldos
    saldo[indiceOrigem] -= valor;
    saldo[indiceDestino] += valor;

    // Registrar saida e entrada
    registrarMovimentacao(contaOrigem, 'S', valor);
    registrarMovimentacao(contaDestino, 'D', valor);

    cout << "\nTransferencia realizada com sucesso!\n";

    cout << "Saldo da origem: R$ "
         << saldo[indiceOrigem] << endl;

    cout << "Saldo do destino: R$ "
         << saldo[indiceDestino] << endl;
}

// FUNCAO PARA EXIBIR EXTRATO
void exibirExtrato() {

    int numero;
    int indice = -1;
    bool encontrou = false;

    cout << "\nDigite o numero da conta: ";
    cin >> numero;

    for (int i = 0; i < quantidadeContas; i++) {

        if (numeroConta[i] == numero) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        cout << "\nConta nao encontrada!\n";
        return;
    }

    cout << "\n========== EXTRATO BANCARIO ==========\n";
    cout << "Conta: " << numeroConta[indice] << endl;
    cout << "Cliente: " << nomeCliente[indice] << endl;

    for (int i = 0; i < quantidadeMovimentacoes; i++) {

        if (contaMovimentacao[i] == numero) {

            encontrou = true;

            if (tipoMovimentacao[i] == 'D') {

                cout << "Deposito/Transferencia recebida: R$ "
                     << valorMovimentacao[i] << endl;
            }
            else if (tipoMovimentacao[i] == 'S') {

                cout << "Saque/Transferencia enviada: R$ "
                     << valorMovimentacao[i] << endl;
            }
        }
    }

    if (!encontrou) {
        cout << "Nenhuma movimentacao encontrada.\n";
    }

    cout << "--------------------------------------\n";
    cout << "Saldo atual: R$ " << saldo[indice] << endl;
    cout << "======================================\n";
}
