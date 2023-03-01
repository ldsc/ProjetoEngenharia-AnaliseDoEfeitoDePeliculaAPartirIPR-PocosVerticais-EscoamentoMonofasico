// Declaração da classe CPoco.h
/* Classe que representa o conceito de poco, assim como seus parâmetros e métodos */

#ifndef CPoco_h
#define CPoco_h

// Inclusão de bilibotecas
#include <cmath>

class CPoco{

// Atributos
    protected:
    double pwf;       // pressão final do poco
    double deltaP;    // variacão de pressao    
    double rw;        // raio do poço
    double rs;        // raio da zona alterada
    double extensao;  // extensão do reservatório atingido pelo poço 
    double theta {0}; // ângulo de inclinação do poço. Por padrão o poço é perfeitamente vertical
    const double Pi = 3.1415;   // número irracional pi
    
// Métodos
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
    
    void Theta (double _theta){ theta = (Pi/180)*_theta;}   /* Funções trigonométricas no cmath possuem argumento em radianos */
     double Theta () { return theta;}

};  // Fim class CPoco

#endif
