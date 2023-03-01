/// Classe correspondente aos parametros de skin por canhoneio parcial

#ifndef CSkinCanhoneio_h
#define CSkinCanhoneio_h

/// Classe-base
#include "CSkin.h"	

/// Classe que representa o conceito de skin causado por canhoneio parcial, assim como seus atributos e metodos
class CSkinCanhoneio: public CSkin{

    protected:
    
    /// skin calculado pela formula proposta por Papatzacos (1987)
    double skinCanhoneio {0}; 
    /// espessura adimensional da zona canhoneada
    double hpd=1.0;
	/// espessura adimensional da zona perfurada e nao-canhoneada	
    double h1d=1.0;          
    /// raio adimensional proposto na formula de Papatzacos
	double rd=1.0;            
    /// constante
	double constanteA=1.0;    
    /// constante
	double constanteB=1.0;   
   
    public:
    /// Construtor default
    CSkinCanhoneio(){};
    /// Destrutor default
    ~CSkinCanhoneio(){};
    
	/// Skin calculado pela formula proposta por Papatzacos (1987)
    double Skin(double _rw, double _h,double _hp, double _kv, double _kh);
    /// Espessura adimensional da zona canhoneada
	double HPD(double _hp, double _h);
    /// Espessura adimensional da zona perfurada e nao-canhoneada
	double H1D(double _h1, double _h);
    /// Raio adimensional proposto na formula de Papatzacos
	double RD(double _rw, double _h, double _kv, double _kh);
    /// Constante
	double A();
    /// Constante
	double B();

};  //< Fim CSkinCanhoneio

#endif
