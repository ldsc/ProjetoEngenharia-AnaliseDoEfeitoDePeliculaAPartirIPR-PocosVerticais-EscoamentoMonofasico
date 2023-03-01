// Declara��o da classe CSkinCanhoneio.h
/* Classe que representa o conceito de skin causado por canhoneio parcial, assim como seus par�metros e m�todos */

#ifndef CSkinCanhoneio_h
#define CSkinCanhoneio_h

#include "CSkin.h"	// Classe-base

class CSkinCanhoneio: public CSkin{

// Atributos
    protected:
    
    // Vari�veis dimensionais
    double skinCanhoneio {0}; // skin calculado pela f�rmula proposta por Papatzacos (1987)
    
    // Variaveis adimensionais
    double hpd;          // espessura adimensional da zona canhoneada
    double h1d;          // espessura adimensional da zona perfurada e nao-canhoneada
    double rd;           // raio adimensional proposto na formula de Papatzacos 
    double constanteA;   // constante 
    double constanteB;   // constante
   
    
// M�todos
    public:
    // Construtor default
    CSkinCanhoneio(){};
    // Destrutor default
    ~CSkinCanhoneio(){};
    
    double Skin(double _rw, double _h,double _hp, double _kv, double _kh);
    double HPD(double _hp, double _h);
    double H1D(double _h1, double _h);
    double RD(double _rw, double _h, double _kv, double _kh);
    double A();
    double B();

};  // Fim CSkinCanhoneio

#endif
