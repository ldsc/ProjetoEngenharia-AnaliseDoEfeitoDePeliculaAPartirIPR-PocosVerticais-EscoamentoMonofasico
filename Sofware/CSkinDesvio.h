// Declaracao da classe CDesvio.h
/* Classe que representa o conceito de skin causado pela inclina��o do po�o, assim como seus par�metros e m�todos */

#ifndef CSkinDesvio_h
#define CSkinDesvio_h

#include "CSkin.h"	// Classe-base

class CSkinDesvio: public CSkin{

// Atributos
    protected:
    double skinDesvio {0};  // skin calculado pela f�rmula proposta por Besson (1990)
    double beta;            // constante
    double gamma;           // constante
    
// M�todos
    public:
    // Construtor default
    CSkinDesvio(){};
    // Destrutor default
    ~CSkinDesvio(){};
    
    double Beta(double _kv,double _kh);
    double Gamma(double _h, double _extensao);
    double Skin(double _rw,double _h, double _extensao);

}; // Fim class CSkinDesvio
#endif
