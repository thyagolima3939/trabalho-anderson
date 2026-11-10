#include <iostream>
using namespace std;

int main()
{
    //variáveis para controle de contas
    const int MAX_CONTAS = 100; // é previsto um limite máximo de 100 contas
    
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

int quantidadeContas = 0;

const int MAX_MOVIMENTACOES = 500;

int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];

int quantidadeMovimentacoes = 0;

int opcao;

// MENU
do{
    cout << "Escolha uma opção: " << endl;
    cout << "1 - Cadastrar contas " << endl;
    cout << "2 - Listar contas cadastrais " << endl;
    cout << "3 - Sair " << endl;
    cin >> opcao;
    
    switch (opcao){
        case 1:
        if(quantidadeContas<=MAX_CONTAS);
            cout << "Digite o número da conta: " << endl; 
            cin >> numeroConta[quantidadeContas];
            cout << "Nome do Cliente: ";
            cin.ignore();
            getline (cin, nomeCliente[quantidadeContas]);
            cout << "CPF: ";
            getline(cin, cpf[quantidadeContas]);
            
            quantidadeContas++; // quantidadeContas = quantidadeContas + 1;
            break;
        case 2:
            // cout / cin para Listar
            if()
            for (int i=0; i < quantidadeContas; i++){
                cout << "---------------------------------" << endl;
                cout << " CONTA " << i << ":" << endl;
                cout << "Número da Conta: " << numeroConta[i] << endl;
                cout << "Cliente: " <<nomeCliente[i] << endl;
                cout << "CPF: " << cpf[i] <<endl;
                
            }
            break;
        case 3:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida. Digite novamente. " << endl;
            break;
    }
    
} while (opcao != 3);

    

    return 0;
}
