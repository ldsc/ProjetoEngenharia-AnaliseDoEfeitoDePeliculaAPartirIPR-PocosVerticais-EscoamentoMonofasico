/// Implementacao da classe CSkinCanhoneio

/// Inclusao de bibliotecas
#include "CSkinCanhoneio.h"
#include <cmath>
    
double CSkinCanhoneio::HPD(double _hp, double _h){
    hpd = _hp/_h; 
    return hpd;
};

double CSkinCanhoneio::H1D(double _h1, double _h){
    h1d = _h1/_h; 
    return h1d;
};

double CSkinCanhoneio::RD(double _rw, double _h, double _kv, double _kh){
    rd = (_rw/_h)*sqrt(_kv/_kh); 
    return rd;
};

double CSkinCanhoneio::A(){
    constanteA = 1.0/(h1d+(hpd/4.0));
    return constanteA;
};

double CSkinCanhoneio::B(){
    constanteB = 1.0/(h1d+(3.0*hpd/4.0));
    return constanteB;
};

double CSkinCanhoneio::Skin(double _rw,double _h,double _hp, double _kv, double _kh){
    skinCanhoneio = ((1.0/HPD(_hp,_h))-1.0)*log(M_PI/(2.0*RD(_rw,_h,_kv,_kh))) + (1.0/HPD(_hp,_h))*log((HPD(_hp,_h)/(2.0+HPD(_hp,_h)))*sqrt((A()-1.0)/(B()-1.0)));
    return skinCanhoneio;
};
