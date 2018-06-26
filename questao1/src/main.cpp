/**
* @file   main.cpp
* @brief  Arquivo Inicial
* @author Claudio da Cruz Silva Junior
* @since  12/05/2018
* @date   12/05/2018
*/

#include <iostream> /**< Inclusão da lib iostream*/
#include <vector> /**< Inclusão da lib vector*/
#include <memory> /**< Inclusão da lib memory*/
#include "../include/produto.h" /**< Inclusão da classe produto.h*/
#include "../include/fruta.h" /**< Inclusão da classe fruta.h*/
#include "../include/bebida.h" /**< Inclusão da bebida.h*/
#include "../include/roupa.h" /**< Inclusão da roupa.h*/
#include <fstream> /**< Inclusão da lib fstream*/
#include "../include/excecoes.h"
#include <stdexcept> 

using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::string;
using namespace std;

/**
* @brief Função que quebra a linha lida do arquivo
* @param[in] Recebe linha(str) do tipo string
* @param[in] Recebe valor que será procurado para quebra do tipo char
* @return result do tipo vetor
*/
std::vector<std::string> split_string(std::string str, const char* op) {
	std::vector<std::string> result;
	std::string rest = str, block;
	size_t operator_position = rest.find_first_of(op);
	while (operator_position != std::string::npos) {
		block = rest.substr(0, operator_position);
		rest = rest.substr(operator_position + 1);
		operator_position = rest.find_first_of(op);
		result.push_back(block);
	}

	if (rest.length() > 0)
		result.push_back(rest);

	return result;
}

/**
* @Executável do programa
* @param[in] Recebe int argc
* @param[in] Recebe ponteiro para cadeia de caracteres argv
* @return 0
*/
int main(int argc, char const *argv[])
{
	string line;
	std::vector<shared_ptr<Produto>> lista;
	bool produtoIgualEncontrado;

	//lendo arquivo de frutas - MOdificar o caminho para o caminho designado
	//OBS.: Adicionei o caminho completo pois tive problema e o fstream
	//não estava coseguindo ler o arquivo mesmo que ele tivesse no mesmo diretório do main
	fstream arqFrutas;
	arqFrutas.open("/home/claudio/Documentos/UFRN/LPI/laboratorio 3/questao1/frutas.dat");
	try{
		if (arqFrutas.is_open())
		{
			while (! arqFrutas.eof() )
			{
			  getline (arqFrutas,line);
			  std::vector<std::string> result = split_string(line, ",");
			  std::string _codigo = result[0];
			  std::string _descricao = result[1];
			  double _preco = atof(result[2].c_str());
			  std::string _data = result[3];
			  short _validade = atof(result[4].c_str());
	
			  try{
			  	Fruta * fruta = new Fruta(_codigo, _descricao, _preco, _data, _validade);
			  


				  produtoIgualEncontrado = false;
				  for (auto i = lista.begin(); i != lista.end(); ++i)
					{
						if(*fruta == **i){
							produtoIgualEncontrado = true;
						}
		
					}
		
				  if(produtoIgualEncontrado == false)
					  lista.push_back(make_shared<Fruta>(*fruta));
				  else
				  delete fruta;
			
				}catch(bad_alloc & ex){
			  		cerr << ex.what() << " Erro em alocação dinamica em memoria"<< endl;
			  	}		
	
	
			}
			arqFrutas.close();
		}else{
			//cout << "arquivo de frutas não encontrado. Verificar o caminho do arquivo." << endl;
			throw FalhaAberturaArquivo();
		}
	}catch(FalhaAberturaArquivo &ex){
		cerr << ex.what() << endl;
	}	
	//lendo arquivo de roupas - MOdificar o caminho para o caminho designado
	ifstream arqRoupas("/home/claudio/Documentos/UFRN/LPI/laboratorio 3/questao1/roupas.dat");
	try{
		if (arqRoupas.is_open())
			{
				while (! arqRoupas.eof() )
				{
				  getline (arqRoupas,line);
				  std::vector<std::string> result = split_string(line, ",");
				  std::string _codigo = result[0];
				  std::string _descricao = result[1];
				  double _preco = atof(result[2].c_str());
				  std::string _marca = result[3];
				  std::string _sexo = result[4];
				  int _tamanho = atoi(result[5].c_str());


				  	try{
						Roupa * roupa = new Roupa(_codigo, _descricao, _preco, _marca, _sexo, _tamanho);
				  

						produtoIgualEncontrado = false;
						for (auto i = lista.begin(); i != lista.end(); ++i)
						{
							if(*roupa == **i){
								produtoIgualEncontrado = true;
							}

						}

						if(produtoIgualEncontrado == false)
								lista.push_back(make_shared<Roupa>(*roupa));
						else
						delete roupa;

					}catch(bad_alloc & ex){
						cerr << ex.what() << " Erro em alocação dinamica em memoria"<< endl;
					}	
				}
				arqFrutas.close();
			}else{
				//cout << "arquivo de roupas não encontrado. Verificar o caminho do arquivo." << endl;
				throw FalhaAberturaArquivo();
			}
		}catch(FalhaAberturaArquivo &ex){
			cerr << ex.what() << endl;
		}	
	//lendo arquivo de bebidas - MOdificar o caminho para o caminho designado
	ifstream arqBebidas("/home/claudio/Documentos/UFRN/LPI/laboratorio 3/questao1/bebidas.dat");

	try{
		if (arqBebidas.is_open())
		{
			while (! arqBebidas.eof() )
			{
			  getline (arqBebidas,line);
			  std::vector<std::string> result = split_string(line, ",");
			  std::string _codigo = result[0];
			  std::string _descricao = result[1];
			  double _preco = atof(result[2].c_str());
			  double _teorAlcolico = atof(result[3].c_str());

				try{
					Bebida * bebida = new Bebida(_codigo, _descricao, _preco, _teorAlcolico);

					produtoIgualEncontrado = false;
					for (auto i = lista.begin(); i != lista.end(); ++i)
					{
						if(*bebida == **i){
							produtoIgualEncontrado = true;
						}

					}

					if(produtoIgualEncontrado == false)
						lista.push_back(make_shared<Bebida>(*bebida));
					else
						delete bebida;
				}catch(bad_alloc & ex){
					cerr << ex.what() << " Erro em alocação dinamica em memoria"<< endl;
				}

			}
			arqBebidas.close();
		}else{
			cout << "arquivo de bebidas não encontrado. Verificar o caminho do arquivo." << endl;
		}
	}catch(FalhaAberturaArquivo &ex){
		cerr << ex.what() << endl;
	}

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;	
	}

	return 0;
}
