#include <exception>
using std::exception;

class FalhaAberturaArquivo : public exception {
public:
	const char* what() {
		return "Falha na abertura do arquivo!";
	}
};