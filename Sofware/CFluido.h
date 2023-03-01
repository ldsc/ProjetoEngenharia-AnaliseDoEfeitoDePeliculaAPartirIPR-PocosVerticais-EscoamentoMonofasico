// Declaracao da classe CFluido.h
/* Classe que representa o conceito de fluido, assim como seus atributos e métodos */ 

#ifndef CFluido_h
#define CFluido_h

class CFluido{

//  Atributos
    protected:
    double fvf;  // fator volume-formacao
    double mi;  // viscosidade
    
//  Metodos
    public:
    // Contrutor default
    CFluido(){};
    // Construtor sobrecarregado
    CFluido(double _fvf, double _mi):fvf(_fvf),mi(_mi){};
    // Destrutor default
    ~CFluido(){};

    // Metodos Set e Get
    void FVF (double _fvf){ fvf = _fvf;}
    double FVF () { return fvf;}

    void Mi (double _mi){ mi = _mi;}
    double Mi () { return mi;}
    
}; // end class CFluido

#endif
