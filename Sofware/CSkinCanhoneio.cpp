// Implementação da classe CSkinCanhoneio

// Inclusão de bibliotecas
#include "CSkinCanhoneio.h"
#include <cmath>

const double Pi = 3.1415;   // número irracional pi
    
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
    constanteA = 1/(h1d+(hpd/4));
    return constanteA;
};

double CSkinCanhoneio::B(){
    constanteB = 1/(h1d+(3*hpd/4));
    return constanteB;
};

double CSkinCanhoneio::Skin(double _rw,double _h,double _hp, double _kv, double _kh){
    skinCanhoneio = ((1/HPD(_hp,_h))-1)*log(Pi/(2*RD(_rw,_h,_kv,_kh))) + (1/HPD(_hp,_h))*log((HPD(_hp,_h)/(2+HPD(_hp,_h)))*sqrt((A()-1)/(B()-1)));
    return skinCanhoneio;
};
