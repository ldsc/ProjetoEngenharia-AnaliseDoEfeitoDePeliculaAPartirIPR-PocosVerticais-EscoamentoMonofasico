// Declaração da classe CRocha.h
/* Classe que representa o conceito de rocha, assim como seus atributos e métodos */

#ifndef CRocha_h
#define CRocha_h

class CRocha{

// Atributos
    protected:
    double kv;  // permeabilidade vertical
    double kh;  // permeabilidade horizontal
    double ks;  // permeabilidade da zona alterada
    double phi; // porosidade
    double ct;  // compressibilidade total
    
// Métodos
    public:
    // Contrutor default
    CRocha(){};
    // Construtor sobrecarregado
    CRocha(double _kv, double _kh, double _ks, double _phi, double _ct):kv(_kv),kh(_kh),ks(_ks),phi(_phi),ct(_ct){};
    // Destrutor default
    ~CRocha(){};

    // Métodos Set e Get
    void Kv (double _kv){ kv = _kv;}
    double Kv () { return kv;}

    void Kh (double _kh){ kh = _kh;}
    double Kh () { return kh;}

    void Ks (double _ks){ ks = _ks;}
    double Ks () { return ks;}

    void Phi (double _phi){ phi = _phi;}
    double Phi () { return phi;}

    void Ct (double _ct){ ct = _ct;}
    double Ct () { return ct;}

};  // Fim class CRocha

#endif
