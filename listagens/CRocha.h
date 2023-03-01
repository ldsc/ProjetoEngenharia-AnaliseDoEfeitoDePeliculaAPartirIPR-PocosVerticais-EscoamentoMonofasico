/// Classe correspondente aos parametros de rocha

#ifndef CRocha_h
#define CRocha_h

/// Classe que representa o conceito de rocha, assim como seus atributos e metodos
class CRocha{

    protected:
	/// permeabilidade vertical
    double kv=0.0;  
	/// permeabilidade horizontal
    double kh=0.0;
	/// permeabilidade da zona alterada
    double ks=0.0; 
	/// porosidade	
    double phi=0.0;
	/// compressibilidade total	
    double ct=0.0;  
    
    public:
    /// Contrutor default
    CRocha(){};
    /// Construtor sobrecarregado
    CRocha(double _kv, double _kh, double _ks, double _phi, double _ct):kv(_kv),kh(_kh),ks(_ks),phi(_phi),ct(_ct){};
    /// Destrutor default
    ~CRocha(){};

    /// Permeabilidade vertical
    void Kv (double _kv){ kv = _kv;}
    /// Permeabilidade vertical
	double Kv () { return kv;}
	/// Permeabilidade horizontal
    void Kh (double _kh){ kh = _kh;}
    /// Permeabilidade horizontal
	double Kh () { return kh;}
	/// Permeabilidade da zona alterada
    void Ks (double _ks){ ks = _ks;}
    /// Permeabilidade da zona alterada
	double Ks () { return ks;}
	/// Porosidade
    void Phi (double _phi){ phi = _phi;}
    /// Porosidade
	double Phi () { return phi;}
	/// Compressibilidade total
    void Ct (double _ct){ ct = _ct;}
    /// Compressibilidade total
	double Ct () { return ct;}

};  //< Fim class CRocha

#endif
