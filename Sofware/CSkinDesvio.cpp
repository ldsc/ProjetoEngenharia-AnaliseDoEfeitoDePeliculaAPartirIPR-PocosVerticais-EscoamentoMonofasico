// Implementação da classe CSkinDesvio

// Inclusão de bibliotecas
#include "CSkinDesvio.h"
#include <cmath>

double CSkinDesvio::Beta(double _kv,double _kh){
    beta = sqrt(_kv/_kh); 
    return beta;
};

double CSkinDesvio::Gamma(double _h, double _extensao){
    gamma = sqrt((1/pow(beta,2))+(pow(_h,2)/pow(_extensao,2))*(1.0-(1/pow(beta,2)))); 
    return gamma;
};

double CSkinDesvio::Skin(double _rw,double _h, double _extensao){
    skinDesvio = log((4*_rw)/(_extensao*beta*gamma))+((_h)/(gamma*_extensao))*log((sqrt(_extensao*_h))/(4*_rw)*((2*beta*sqrt(gamma))/(1+(1/gamma))));
    return skinDesvio;
};
