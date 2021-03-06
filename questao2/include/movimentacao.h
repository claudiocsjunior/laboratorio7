/**
* @file   movimentacao.h
* @brief  Classe responsável por gerênciar os movimentos por conta
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/
#ifndef _MOVIMENTACAO_H_ /**< Verifica se a variável _MOVIMENTACAO_H_ foi definida*/
#define _MOVIMENTACAO_H_ /**< Define a variável _MOVIMENTACAO_H_*/

#include <iostream> /**<inclui a lib iostream*/

using namespace std; /**< usando namespace std*/

class Movimentacao
{
private:
	std::string descricao; /**< Variável para armazenar a descrição*/
	double valor; /**< Variável para armazenar o valor*/
	std::string tipo; /**< Variável para armazenar o tipo*/
public:
	Movimentacao(); /**< Construtor padrão da Classe*/
	Movimentacao(std::string descricao, double valor, std::string tipo); /**< Construtor parâmetrizado da Classe*/
	~Movimentacao(); /**< Destrutor padrão da Classe*/
	/**
	* @brief Método de acesso para o atributo descrição
	* @return atributo descrição
	*/
	const std::string& getDescricao() const;

	/**
	* @brief método de modificação do valor do atributo descrição
	* @param[in] Recebe descrição do tipo string
	* @return
	*/
	void setDescricao(const std::string& descricao);

	/**
	* @brief Método de acesso para o atributo valor
	* @return atributo valor
	*/
	double getValor() const;

	/**
	* @brief método de modificação do valor do atributo valor
	* @param[in] Recebe codigo do tipo double
	* @return
	*/
	void setValor(double valor);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend ostream& operator<<(ostream &e, Movimentacao const m);
};

#endif
