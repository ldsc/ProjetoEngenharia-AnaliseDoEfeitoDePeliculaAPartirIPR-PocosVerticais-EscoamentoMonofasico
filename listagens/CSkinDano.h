/// Classe correspondente aos parametros de skin por dano ou estimulo a formacao

#ifndef CSkinDano_h
#define CSkinDano_h

#include <cmath>  
/// Classe-base	
#include "CSkin.h"	

/// Classe que representa o conceito de skin devido alteracao da permeabilidade nas proximidades do poco, assim como seus parametros e metodos

class CSkinDano: public CSkin{

    protected:
	/// skin devido alteracao da permeabilidade nas proximidades do poco
    double skinDano {0}; 
    
    public:
	/// Construtor default
    CSkinDano(){}
	/// Destrutor default	
    ~CSkinDano(){}; 
    /// Skin devido alteracao da permeabilidade nas proximidades do poco    
    inline double Skin(double _kh, double _ks, double _rw, double _rs){skinDano = ((_kh/_ks) - 1.0)*(log(_rs/_rw)); return skinDano;}

}; //< Fim CSkinDano
#endif
