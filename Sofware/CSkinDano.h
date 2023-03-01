// Declara��o da classe CSkinDano.h
/* Classe que representa o conceito de skin devido altera��o da permeabilidade nas proximidades do po�o, assim como seus par�metros e m�todos */

#ifndef CSkinDano_h
#define CSkinDano_h

#include <cmath>  	// Para retorno do logaritmo neperiano
#include "CSkin.h"	// Classe-base

class CSkinDano: public CSkin{

// Atributos
    protected:
    double skinDano {0};
    
// Metodos
    public:
    CSkinDano(){}   // Construtor default
    ~CSkinDano(){}; // Destrutor default
        
    inline double Skin(double _kh, double _ks, double _rw, double _rs){skinDano = ((_kh/_ks) - 1.0)*(log(_rs/_rw)); return skinDano;}

}; // Fim CSkinDano
#endif
