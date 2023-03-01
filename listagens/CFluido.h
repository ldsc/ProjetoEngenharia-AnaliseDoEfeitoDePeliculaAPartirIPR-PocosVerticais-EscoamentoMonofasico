/// Classe correspondente aos parametros de fluidos

#ifndef CFluido_h
#define CFluido_h

/// Classe que representa o conceito de fluido, assim como seus atributos e métodos
class CFluido{


    protected:
    ///  fator volume-formacao
	double fvf=0.0;  
    /// viscosidade
	double mi=0.0;  
    
    public:
    /// Contrutor default
    CFluido(){};
    /// Construtor sobrecarregado
    CFluido(double _fvf, double _mi):fvf(_fvf),mi(_mi){};
    /// Destrutor default
    ~CFluido(){};

    /// Fator Volume Formacao
    void FVF (double _fvf){ fvf = _fvf;}
    /// Fator Volume Formacao
	double FVF () { return fvf;}
	
	/// Viscosidade
    void Mi (double _mi){ mi = _mi;}
    /// Viscosidade
	double Mi () { return mi;}
    
}; //< end class CFluido

#endif
