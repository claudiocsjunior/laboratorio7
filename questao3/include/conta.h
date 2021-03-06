/**
* @file   conta.h
* @brief  Classe responsável por gerênciar as contas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/
#ifndef _CONTA_H_ /**< Verifica se a variável _CONTA_H_ foi definida*/
#define _CONTA_H_ /**< Define a variável _CONTA_H_*/

#include <iostream> /**<inclui a lib iostream*/
#include "movimentacao.h" /**<inclui a classe movimentacao.h*/
#include <vector> /**<inclui a lib vector*/
#include <stdlib.h> /**<inclui a lib stdlib.h*/

using namespace std; /**<Usa namespace std*/

class Conta
{
protected:
	std::string agencia;/**< Variável para armazenar a agencia*/
	std::string numero;/**< Variável para armazenar o numero*/
	double saldo;/**< Variável para armazenar o saldo*/
	int status; /**< Variável para armazenar o status, 0 - normal; 1 - especial; */
	std::vector<Movimentacao> movimentacao;/**< Vetor para armazenar as movimentações*/
	int tipo_conta;/**< Variável para armazenar o tipo da conta - 0 para corrente e 1 para poupanca*/
	double limite; /**< Variável para armazenar o limite, 2000 - default */
public:
	/**
	* @brief Construtor padrão da classe
	*/
	Conta();
	/**
	* @brief Construtor parâmetrizado da classe
	*/
	Conta(int tipo_conta);

	/**
	* @brief Destrutor da classe
	*/
	virtual ~Conta();

	/**
	* @brief Método para exclusão de conta corrente
	* @return agencia
	*/
	const std::string& getAgencia() const;

	/**
	* @brief Método de modificação para o atributo agencia
	* @param[in] variável agencia
	* @return
	*/
	void setAgencia(const std::string& agencia);

	/**
	* @brief Método de acesso para as movimentações
	* @return movimentacao
	*/
	const std::vector<Movimentacao>& getMovimentacao() const;

	/**
	* @brief Método de modificação para o atributo movimentação
	* @param[in] variável movimentacão
	* @return
	*/
	void setMovimentacao(const std::vector<Movimentacao>& movimentacao);

	/**
	* @brief Método de acesso ao numero da conta
	* @return numero
	*/
	const std::string& getNumero() const;

	/**
	* @brief Método de modificação para o atributo numero
	* @param[in] variável numero
	* @return
	*/
	void setNumero(const std::string& numero);

	/**
	* @brief Método de acesso ao saldo
	* @return saldo
	*/
	double getSaldo() const;

	/**
	* @brief Método de modificação para o atributo saldo
	* @param[in] variável saldo
	* @return
	*/
	void setSaldo(double saldo);

	/**
	* @brief Método de acesso para o status da conta
	* @return status
	*/
	const int getStatus() const;

	/**
	* @brief Método de modificação para o atributo status
	* @param[in] variável status
	* @return
	*/
	void setStatus(const int status);

	/**
	* @brief Método para realizar transferências
	* @param[in] conta a tranferir
	* @param[in] variável valor
	* @return agencia
	*/
	void tranferencia(Conta &conta_tranferir, double valor);

	/**
		* @brief Método para consulta do saldo
		* @return
		*/
	double consultar_saldo();
	/**
	* @brief Método para consulta do extrato
	* @return
	*/
	void consultar_extrato();

	/**
	* @brief Método para adicionar movimentação na tranferência
	* @return
	*/
	void add_movimentacao(std::string descricao, double valor, std::string tipo);

	/**
	* @brief Efetua a sobrecarga do operador >>
	* @param[in] variável para o >>
	* @param[in] Constante para guardar o objeto
	* @return valor do cin
	*/
	friend istream& operator>>(istream &a, Conta &c);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, Conta const c);

	/**
	* @brief Efetua a sobrecarga do operador ==
	* @param[in] Constante para guardar o objeto a ser comparado
	* @return booleano
	*/
	bool operator==(Conta &conta_comparada);

	/**
	* @brief Método de acesso ao tipo da conta
	* @return tipo da conta
	*/
	int getTipoConta() const;
};

#endif
