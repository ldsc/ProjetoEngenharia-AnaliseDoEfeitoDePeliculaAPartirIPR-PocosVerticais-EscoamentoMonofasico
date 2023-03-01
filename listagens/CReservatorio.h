/// Classe correspondente aos parametros do reservatorio

#ifndef CReservatorio_h
#define CReservatorio_h

/// Classe que representa o conceito de reservatorio, assim como seus parametros e metodos
class CReservatorio{

    protected:
	/// raio do reservatorio
    double re=0.0;
	/// espessura do reservatorio	
    double h=0.0;
	/// espessura da zona perfurada e nao-canhoneada	
    double h1=0.0;
    /// espessura da zona canhoneada	
    double hp=0.0;
	/// pressao inicial	
    double pi=0.0;      

    public:
    /// Construtor default
    CReservatorio(){};
    /// Construtor sobrecarregado
    CReservatorio(double _re, double _h, double _h1, double _hp, double _pi):re(_re),h(_h),h1(_h1),hp(_hp),pi(_pi){};
    /// Destrutor default
    ~CReservatorio(){};

    /// Raio do reservatorio
    void Re (double _re){ re = _re;}
    /// Raio do reservatorio
	double Re () { return re;}
	/// Espessura do reservatorio
    void H (double _h){ h = _h;}
    /// Espessura do reservatorio
	double H () { return h;}
	/// Espessura da zona perfurada e nao-canhoneada
    void H1 (double _h1){ h1 = _h1;}
    /// Espessura da zona perfurada e nao-canhoneada
	double H1 () { return h1;}
	/// Espessura da zona canhoneada
    void HP (double _hp){ hp = _hp;}
    /// Espessura da zona canhoneada
	double HP () { return hp;}
	/// Pressao inicial
    void Pi (double _pi){ pi = _pi;}
    /// Pressao inicial
	double Pi () { return pi;}

};  //< Fim class CReservatorio

#endif 
