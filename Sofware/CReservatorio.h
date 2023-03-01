// Declara��o da classe CReservatorio.h
/* Classe que representa o conceito de reservat�rio, assim como seus par�metros e m�todos */

#ifndef CReservatorio_h
#define CReservatorio_h

class CReservatorio{

// Atributos
    protected:
    double re;      // raio do reservat�rio
    double h;       // espessura do reservat�rio
    double h1;      // espessura da zona perfurada e n�o-canhoneada
    double hp;      // espessura da zona canhoneada
    double pi;      // press�o inicial

// M�todos
    public:
    // Construtor default
    CReservatorio(){};
    // Construtor sobrecarregado
    CReservatorio(double _re, double _h, double _h1, double _hp, double _pi):re(_re),h(_h),h1(_h1),hp(_hp),pi(_pi){};
    // Destrutor default
    ~CReservatorio(){};

    // M�todos Set e Get
    void Re (double _re){ re = _re;}
    double Re () { return re;}

    void H (double _h){ h = _h;}
    double H () { return h;}

    void H1 (double _h1){ h1 = _h1;}
    double H1 () { return h1;}

    void HP (double _hp){ hp = _hp;}
    double HP () { return hp;}

    void Pi (double _pi){ pi = _pi;}
    double Pi () { return pi;}

};  // Fim class CReservatorio

#endif 
