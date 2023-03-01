// Declaração da classe CReservatorio.h
/* Classe que representa o conceito de reservatório, assim como seus parâmetros e métodos */

#ifndef CReservatorio_h
#define CReservatorio_h

class CReservatorio{

// Atributos
    protected:
    double re;      // raio do reservatório
    double h;       // espessura do reservatório
    double h1;      // espessura da zona perfurada e não-canhoneada
    double hp;      // espessura da zona canhoneada
    double pi;      // pressão inicial

// Métodos
    public:
    // Construtor default
    CReservatorio(){};
    // Construtor sobrecarregado
    CReservatorio(double _re, double _h, double _h1, double _hp, double _pi):re(_re),h(_h),h1(_h1),hp(_hp),pi(_pi){};
    // Destrutor default
    ~CReservatorio(){};

    // Métodos Set e Get
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
