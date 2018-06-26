/**
* @file   agencia.cpp
* @brief  Responsável por gerênciar todas  as contas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/
#include <iostream> /**<inclui a lib iostream*/
#include "../include/agencia.h" /**<inclui a classe agencia.h*/
#include "../include/conta.h"
#include "../include/contaCorrente.h"
#include "../include/contaPoupanca.h"
<<<<<<< HEAD
#include <limits>
=======
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3

using namespace std;

/**
* @brief Construtor padrão da classe
*/
Agencia::Agencia() {
}

/**
* @brief Destrutor da classe
*/
Agencia::~Agencia() {
}

/**
* @brief Método para adicionar conta corrente
* @return
*/
void Agencia::adicionar_conta_corrente() {
	ContaCorrente conta_corrente;
	try{
		if(!(cin >> conta_corrente))
			throw invalid_argument("agência ou numero invalido!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			adicionar_conta_corrente();
	}
	cout << "(0) - Conta Normal, (1) - Conta Especial" << endl;
	int status;
	try{
		if(!(cin >> status))
			throw invalid_argument("selecione um tipo normal ou especial de forma correta!");
		if(status != 1 && status != 0)
			throw invalid_argument("selecione um tipo normal com (1) ou (0)!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			erro_mensagem();
	}
	conta_corrente.setStatus(status);
	int tamanho = this->conta.size();
	bool existeIgual = false;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_corrente)
			existeIgual = true;

	}

	if(existeIgual == false){
		this->conta.push_back(conta_corrente);
		cout << "Conta adicionada com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Adicionadas---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Erro. Conta existente" << endl;
	}


}

/**
* @brief Método para adicionar conta poupança
* @return
*/
void Agencia::adicionar_conta_poupanca() {
	ContaPoupanca conta_poupanca;
	try{
		if(!(cin >> conta_poupanca))
			throw invalid_argument("agência ou numero invalido!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			adicionar_conta_poupanca();
	}
	cout << "(0) - Conta Normal, (1) - Conta Especial" << endl;
	int status;
	try{
		if(!(cin >> status))
			throw invalid_argument("agência ou numero invalido!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			adicionar_conta_poupanca();
	}
	conta_poupanca.setStatus(status);
	int tamanho = this->conta.size();
	bool existeIgual = false;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_poupanca)
			existeIgual = true;

	}

	if(existeIgual == false){
		this->conta.push_back(conta_poupanca);
		cout << "Conta adicionada com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Adicionadas---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Erro. Conta existente" << endl;
	}


}

/**
* @brief Método para exclusão de conta
* @return
*/
void Agencia::excluir_conta() {
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar excluir a conta!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			erro_mensagem();
	}
	int tamanho = this->conta.size();
	bool existeIgual = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existeIgual = true;
			posicao = i;
			break;
		}
	}

	if(existeIgual == true){
		this->conta.erase(this->conta.begin()+posicao);
		cout << "Conta Excluida com sucesso" << endl;
		tamanho = this->conta.size();
		cout << "---Contas Restantes---" << endl;
		for (int j = 0;j != tamanho; ++j)
		{
			cout << this->conta[j] << endl;
		}
	}else{
		cout << "Conta não existente no banco de dados." << endl;
	}
}


/**
* @brief Método de acesso as funcionalidades
* @return
*/
void Agencia::funcionalidades() {
	int escolha;
	do{

		cout << "---AGÊNCIA FUNCIONALIDADES---" << endl;

		cout << " -- CONTA CORRENTE -- " << endl;
		cout << "	(1) +    Adicionar Conta Corrente" << endl;
		cout << "	(2) ->   Efetuar Saque Conta Corrente" << endl;
		cout << "	(3) <-   Efetuar Deposito Conta Corrente" << endl;
		cout << "	(4) <-   Consultar limite" << endl;

		cout << " -- CONTA POUPANÇA -- " << endl;
		cout << "	(5) +    Adicionar Conta Poupança" << endl;
		cout << "	(6) ->   Efetuar Saque Conta Poupança" << endl;
		cout << "	(7) <-   Efetuar Deposito Conta Poupança" << endl;

		cout << " -- GERAIS -- " << endl;
		cout << "	(8) -    Excluir conta" << endl;
		cout << "	(9) $    Consultar Saldo" << endl;
		cout << "	(10) #    Extrato" << endl;
		cout << "	(11) $-> Transferência" << endl;
		cout << "	(0) SAIR" <<endl;
<<<<<<< HEAD
		try{
			if(!(cin >> escolha))
				throw invalid_argument("Parametro de tipo diferente de inteiro");
			try{
				switch (escolha)
				{
					case 0:
						break;
					case 1:
						adicionar_conta_corrente();
						break;
					case 2:
						saque_conta_corrente();
						break;
					case 3:
						deposito_conta_corrente();
						break;
					case 4:
						limite_conta_corrente();
						break;
					case 5:
						adicionar_conta_poupanca();
						break;
					case 6:
						saque_conta_poupanca();
						break;
					case 7:
						deposito_conta_poupanca();
						break;
					case 8:
						excluir_conta();
						break;
					case 9:
						saldo();
						break;
					case 10:
						extrato();
						break;
					case 11:
						transferencia();
						break;
					default:
						cout <<"Opção invalida! "<< endl;
						escolha = 0;
				}
			}catch(invalid_argument &ex){
				cerr<<"Erro: "<<ex.what()<<endl;
				cerr<<"Tente novamente!"<<endl;
			}
		}catch(invalid_argument &err){
			cerr<<"Erro: "<<err.what()<<endl;
			cerr<<"Tente novamente!"<<endl;
			escolha = 10;
			cin.clear();
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
=======
		cin >> escolha;
		switch (escolha)
		{
			case 0:
				break;
			case 1:
				adicionar_conta_corrente();
				break;
			case 2:
				saque_conta_corrente();
				break;
			case 3:
				deposito_conta_corrente();
				break;
			case 4:
				limite_conta_corrente();
				break;
			case 5:
				adicionar_conta_poupanca();
				break;
			case 6:
				saque_conta_poupanca();
				break;
			case 7:
				deposito_conta_poupanca();
				break;
			case 8:
				excluir_conta();
				break;
			case 9:
				saldo();
				break;
			case 10:
				extrato();
				break;
			case 11:
				transferencia();
				break;
			default:
				cout <<"Opção invalida! "<< endl;
				escolha = 0;
		}
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
	}while(escolha > 0);
}

/**
* @brief Método para saque em conta corrente
* @return
*/
void Agencia::saque_conta_corrente(){
	cout << "Digite os dados da conta corrente para saque." << endl;
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 0){
			cout << "Digite o valor para saque" << endl;
			double valor;
<<<<<<< HEAD
			try{
			if(!(cin >> valor))
				throw invalid_argument("Um erro foi detectado ao tentar processar o valor para saque!");
			}catch(invalid_argument &ex){
				cerr<<"Erro: "<<ex.what()<<endl;
				erro_mensagem();
			}
=======
			cin >> valor;
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
			ContaCorrente* conta_corrente = (ContaCorrente*)(&(this->conta[posicao]));
			if(conta_corrente->saque(valor)){
				cout << "saque efetuado com sucesso" << endl;
			}else{
				cout << "Erro no saque. Verifique se há quantia disponível na conta" << endl;
			}

<<<<<<< HEAD
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é Corrente" << endl;
=======
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é Corrente" << endl;
		}

	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para saque em conta poupança
* @return
*/
void Agencia::saque_conta_poupanca(){
	cout << "Digite os dados da conta poupança para saque." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 1){
			cout << "Digite o valor para saque" << endl;
			double valor;
			cin >> valor;
			ContaPoupanca* conta_poupanca = (ContaPoupanca*)(&(this->conta[posicao]));
			if(conta_poupanca->saque(valor)){
				cout << "saque efetuado com sucesso" << endl;
			}else{
				cout << "Erro no saque. Verifique se há quantia disponível na conta" << endl;
			}
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é poupança" << endl;
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
		}

	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para saque em conta poupança
* @return
*/
void Agencia::saque_conta_poupanca(){
	cout << "Digite os dados da conta poupança para saque." << endl;
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 1){
			cout << "Digite o valor para saque" << endl;
			double valor;
			try{
				if(!(cin >> valor))
					throw invalid_argument("Um erro foi detectado ao tentar processar o valor para saque!");
				}catch(invalid_argument &ex){
					cerr<<"Erro: "<<ex.what()<<endl;
					erro_mensagem();
				}
			ContaPoupanca* conta_poupanca = (ContaPoupanca*)(&(this->conta[posicao]));
			if(conta_poupanca->saque(valor)){
				cout << "saque efetuado com sucesso" << endl;
			}else{
				cout << "Erro no saque. Verifique se há quantia disponível na conta" << endl;
			}
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é poupança" << endl;
		}

	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}


/**
* @brief Método para depósito em conta corrente
* @return
*/
void Agencia::deposito_conta_corrente(){
	cout << "Digite os dados da conta corrente para depósito." << endl;
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 0){
			cout << "Digite o valor para deposito" << endl;
			double valor;
			try{
				if(!(cin >> valor))
					throw invalid_argument("Um erro foi detectado ao tentar processar o valor para saque!");
				}catch(invalid_argument &ex){
					cerr<<"Erro: "<<ex.what()<<endl;
					erro_mensagem();
				}
			ContaCorrente* conta_corrente = (ContaCorrente*)(&(this->conta[posicao]));
			conta_corrente->deposito(valor);
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é corrente" << endl;
		}

	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}


/**
<<<<<<< HEAD
* @brief Método para depósito em conta poupança
* @return
*/
void Agencia::deposito_conta_poupanca(){
	cout << "Digite os dados da conta poupança para depósito." << endl;
=======
* @brief Método para depósito em conta corrente
* @return
*/
void Agencia::deposito_conta_corrente(){
	cout << "Digite os dados da conta corrente para depósito." << endl;
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
<<<<<<< HEAD
		if(this->conta[posicao].getTipoConta() == 1){
			cout << "Digite o valor para deposito" << endl;
			double valor;
			try{
				if(!(cin >> valor))
					throw invalid_argument("Um erro foi detectado ao tentar processar o valor para saque!");
				}catch(invalid_argument &ex){
					cerr<<"Erro: "<<ex.what()<<endl;
					erro_mensagem();
				}
=======
		if(this->conta[posicao].getTipoConta() == 0){
			cout << "Digite o valor para deposito" << endl;
			double valor;
			cin >> valor;
			ContaCorrente* conta_corrente = (ContaCorrente*)(&(this->conta[posicao]));
			conta_corrente->deposito(valor);
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é corrente" << endl;
		}

	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}


/**
* @brief Método para depósito em conta poupança
* @return
*/
void Agencia::deposito_conta_poupanca(){
	cout << "Digite os dados da conta poupança para depósito." << endl;
	Conta conta;
	cin >> conta;
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 1){
			cout << "Digite o valor para deposito" << endl;
			double valor;
			cin >> valor;
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
			ContaPoupanca* conta_poupanca = (ContaPoupanca*)(&(this->conta[posicao]));
			conta_poupanca->deposito(valor);
		}else{
			cout << "Impossível realizar operação. A conta encontrada não é corrente" << endl;
		}

	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para verificação do saldo de conta
* @return
*/
void Agencia::saldo(){
	cout << "Digite os dados da conta para consultar o saldo." << endl;
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Saldo: " << this->conta[posicao].consultar_saldo()   << endl;
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}

}

/**
* @brief Método para verificação do extrato de conta
* @return
*/
void Agencia::extrato(){
	cout << "Digite os dados da conta para retirar o extrato." << endl;
	Conta conta;
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		cout << "Extrato da conta:" << endl;
		this->conta[posicao].consultar_extrato();
	}else{
		cout << "Conta corrente não encontrada no banco de dados da aplicação" << endl;
	}
}

/**
* @brief Método para transferências entra contas
* @return
*/
void Agencia::transferencia(){
	cout << "Digite os dados da conta que será retirado o saldo." << endl;
	Conta conta_subtrair;
	try{
		if(!(cin >> conta_subtrair))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	int tamanho = this->conta.size();
	bool existe_conta_subtrair = false;
	int posicao1 = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta_subtrair){
			existe_conta_subtrair = true;
			posicao1 = i;
			break;
		}
	}

	cout << "Digite os dados da conta que será adicionado o saldo." << endl;
	Conta conta_adicionar;
	try{
		if(!(cin >> conta_adicionar))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
	bool existe_conta_adicionar = false;
	int posicao2 = 0;
	for (int j = 0;j != tamanho; ++j)
	{
		if(this->conta[j] == conta_adicionar){
			existe_conta_adicionar = true;
			posicao2 = j;
			break;
		}
	}

	if(existe_conta_adicionar == true && existe_conta_subtrair == true){
		cout << "Digite o valor da tranferencia" << endl;
		int valor;
		try{
			if(!(cin >> valor))
				throw invalid_argument("Um erro foi detectado ao tentar processar o valor para saque!");
			}catch(invalid_argument &ex){
				cerr<<"Erro: "<<ex.what()<<endl;
				erro_mensagem();
			}
		this->conta[posicao1].tranferencia( this->conta[posicao2],valor);
	}

}

/**
* @brief Método para consultar limite de conta corrente
* @return tipo da conta
*/
void Agencia::limite_conta_corrente() {
	cout << "Digite os dados da conta corrente para saque." << endl;
	Conta conta;
<<<<<<< HEAD
	try{
		if(!(cin >> conta))
			throw invalid_argument("Um erro foi detectado ao tentar encontrar a conta selecionada!");
	}catch(invalid_argument &ex){
			cerr<<"Erro: "<<ex.what()<<endl;
			cerr<<"tente novamente" << endl;
			funcionalidades();
	}
=======
	cin >> conta;
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
	int tamanho = this->conta.size();
	bool existe_conta = false;
	int posicao = 0;
	for (int i = 0;i != tamanho; ++i)
	{
		if(this->conta[i] == conta){
			existe_conta = true;
			posicao = i;
			break;
		}
	}

	if(existe_conta == true){
		if(this->conta[posicao].getTipoConta() == 0){
			ContaCorrente* conta_corrente = (ContaCorrente*)(&(this->conta[posicao]));
			conta_corrente->consultar_limite();

		}else{
			cout << "Impossível realizar operação. A conta encontrada não é Corrente" << endl;
		}

	}else{
		cout << "Conta não encontrada no banco de dados da aplicação" << endl;
	}
}
<<<<<<< HEAD

void Agencia::erro_mensagem(){
	cerr<<"tente novamente" << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	funcionalidades();
}
=======
>>>>>>> 85c5e8161ceadd72e43f46b875edb1026f8ffbb3
