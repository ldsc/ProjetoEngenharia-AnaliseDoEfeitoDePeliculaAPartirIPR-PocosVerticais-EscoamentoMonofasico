/// Classe correspondente aos parametros de poco

#ifndef CPoco_h
#define CPoco_h

#include <cmath>

/// Classe que representa o conceito de poco, assim como seus parametros e metodos
class CPoco{

    protected:
    /// pressao final do poco
	double pwf=0.0;
	/// variacao de pressao
    double deltaP=0.0;
	/// raio do poco	
    double rw=0.0;       
	/// raio da zona alterada
    double rs0.0;
	/// extensao do reservatorio atingido pelo poco
    double extensao=0.0;
    /// angulo de inclinacao do poco. Por padrao o poco e perfeitamente vertical	
    double theta {0}; 
    
    public:
    /// Construtor default
    CPoco(){};
    /// Construtor sobrecarregado
    CPoco(double _pwf, double _deltaP, double _rw, double _rs, double _extensao):pwf(_pwf),deltaP(_deltaP),rw(_rw),rs(_rs),extensao(_extensao){};
    /// Destrutor default
    ~CPoco(){};
    
	/// Pressao final do poco
    void Pwf (double _pwf){ pwf = _pwf;}
    /// Pressao final do poco
	double Pwf () { return pwf;}
    /// Variacao de pressao
    void DeltaP (double _deltaP){ deltaP = _deltaP;}
    /// Variacao de pressao
	double DeltaP () { return deltaP;}
	/// Raio do poco
    void Rw (double _rw){ rw = _rw;}
    /// Raio do poco
	double Rw () { return rw;}
	/// Raio da zona alterada
    void Rs (double _rs){ rs = _rs;}
    /// Raio da zona alterada
	double Rs () { return rs;}
    /// Extensao do reservatorio atingido pelo poco
    inline double Extensao(double _h){extensao = _h/cos(theta); return extensao;}
    /// Inclinacao do poco
    void Theta (double _theta){ theta = (M_PI/180.0)*_theta;}   //< Funções trigonométricas no cmath possuem argumento em radianos
    /// Inclinacao do poco
	double Theta () { return theta;}

};  //< Fim class CPoco

#endif
