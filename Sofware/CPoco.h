// Declara��o da classe CPoco.h
/* Classe que representa o conceito de poco, assim como seus par�metros e m�todos */

#ifndef CPoco_h
#define CPoco_h

// Inclus�o de bilibotecas
#include <cmath>

class CPoco{

// Atributos
    protected:
    double pwf;       // press�o final do poco
    double deltaP;    // variac�o de pressao    
    double rw;        // raio do po�o
    double rs;        // raio da zona alterada
    double extensao;  // extens�o do reservat�rio atingido pelo po�o 
    double theta {0}; // �ngulo de inclina��o do po�o. Por padr�o o po�o � perfeitamente vertical
    const double Pi = 3.1415;   // n�mero irracional pi
    
// M�todos
    public:
    // Construtor default
    CPoco(){};
    // Construtor sobrecarregado
    CPoco(double _pwf, double _deltaP, double _rw, double _rs, double _extensao):pwf(_pwf),deltaP(_deltaP),rw(_rw),rs(_rs),extensao(_extensao){};
    /// Destrutor default
    ~CPoco(){};
    
    void Pwf (double _pwf){ pwf = _pwf;}
    double Pwf () { return pwf;}

    void DeltaP (double _deltaP){ deltaP = _deltaP;}
    double DeltaP () { return deltaP;}

    void Rw (double _rw){ rw = _rw;}
    double Rw () { return rw;}

    void Rs (double _rs){ rs = _rs;}
    double Rs () { return rs;}

    inline double Extensao(double _h){extensao = _h/cos(theta); return extensao;}
    
    void Theta (double _theta){ theta = (Pi/180)*_theta;}   /* Fun��es trigonom�tricas no cmath possuem argumento em radianos */
     double Theta () { return theta;}

};  // Fim class CPoco

#endif
