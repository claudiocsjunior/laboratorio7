/**
* @file   bebida.h
* @brief  Classe responsável por gerenciar os produtos dos tipos bebidas
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#ifndef _BEBIDA_H_  /**< Verifica se a variável _BEBIDA_H_ foi definida*/
#define _BEBIDA_H_	 /**< Define a variável _BEBIDA_H_*/

#include "produto.h" /**< Inclusão da classe produto.h*/

class Bebida : public Produto
{
public:
	Bebida(); /**< Construtor padrão da Classe*/
	Bebida(std::string _codigo, std::string _descricao, double _preco, double _teorAlcolico); /**< Construtor parãmetrizado da Classe*/
	~Bebida(); /**< Destrutor da Classe*/
private: /**< Local para declaração de atributos privados*/
	double m_teorAlcolico; /**< Variável para armazenar o teor alcólico*/
public:
	/**
	* @brief Método de acesso para o atributo teor alcólico
	* @return atributo teor alcolico
	*/
	double getTeorAlcolico();
	/**
	* @brief método de modificação do valor do atributo teor alcólico
	* @param[in] Recebe teor alcólico do tipo double
	* @return
	*/
	void setTeorAlcolico(double _teorAlcolico);

	/**
	* @brief Efetua a sobrecarga do operador <<
	* @param[in] variável para o <<
	* @param[in] Constante para guardar o objeto
	* @return valor do cout
	*/
	friend std::ostream& operator<< (std::ostream &o, Bebida const &t);
private: /**< Local para declaração de métodos privados*/
	/**
	* @brief Efetua a impressão dos dados
	* @param[in] variável para o <<
	* @return valor do cout
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif
