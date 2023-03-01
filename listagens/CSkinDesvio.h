/// Classe correspondente aos parametros do skin devido inclinacao do poco

#ifndef CSkinDesvio_h
#define CSkinDesvio_h

/// Classe-base
#include "CSkin.h"	

/// Classe que representa o conceito de skin causado pela inclinacao do poco, assim como seus parametros e metodos
class CSkinDesvio: public CSkin{

    protected:
	/// skin calculado pela formula proposta por Besson (1990)
    double skinDesvio {0};  
    /// constante
	double beta=1.0;            
    /// constante
	double gamma=1.0;           
    
    public:
    /// Construtor default
    CSkinDesvio(){};
    /// Destrutor default
    ~CSkinDesvio(){};
    
	/// Constante
    double Beta(double _kv,double _kh);
    /// Constante
	double Gamma(double _h, double _extensao);
    /// Skin calculado pela formula proposta por Besson (1990)
	double Skin(double _rw,double _h, double _extensao);

}; //< Fim class CSkinDesvio
#endif
