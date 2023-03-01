
#ifndef CSimuladorCurvasIPR_h
#define CSimuladorCurvasIPR_h

#include <vector>
#include <string>
#include "CGnuplot.h"

#include "CRocha.h"
#include "CFluido.h"
#include "CPoco.h"
#include "CReservatorio.h"
#include "CSkin.h"
#include "CSkinDano.h"
#include "CSkinCanhoneio.h"
#include "CSkinDesvio.h"


using namespace std;

/// Classe que simula a analise do efeito de pelicula a partir de curvas de IPR

class CSimuladorCurvasIPR{

    protected:
    /// vetor que armazena pressoes do poco
    vector <double> pressaoPoco;
	/// vetor que armazena vazao do poco considerando skin	
    vector <double> vazaoPocoSkin;
	/// vetor que armazena vazao do poco considerando skin nulo
    vector <double> vazaoPocoNullSkin;
	/// pressao medida no poco
    double pressao=0.0;
	/// vazao do poco considerando skin
    double vazaoSkin=0.0;                    
    /// vazao do poco considerando skin nulo
	double vazaoNullSkin=0.0;                
    /// tempo de producao do reservatorio em regime transiente
	double tempo=0.0;                        
	/// tempo final do reservatorio em regime transiente
	double tpss=0.0;                             
	/// skin total
	double skinTotal=0.0;                    
    
	/// Objeto da classe CPoco
    CPoco poco;                     
    /// Objeto da classe CReservatorio
	CReservatorio reservatorio;     
    /// Objeto da classe CFluido
	CFluido oleo;                   
    /// Objeto da classe CRocha
	CRocha rocha;                   
    /// Objeto da classe CSkin
	CSkin skin;                     
    /// Objeto da classe CSkinDano
	CSkinDano danoSkin;             
    /// Objeto da classe CSkinCanhoneio
	CSkinCanhoneio canhoneioSkin;   
    /// Objeto da classe CSkinDesvio
	CSkinDesvio desvioSkin;         
    /// Objeto da classe CGnuplot
	CGnuplot grafico;               
     
	/// Para salvar dados ou abrir dados salvos anteriormente	
    string nomeArquivo;             
    /// Para salvar grafico gerado
	string nomeGrafico;             
    /// Para entrar com parametros por arquivo de disco
	string entradaDados;            
    
public:
    /// Construtor default
    CSimuladorCurvasIPR(){};
    /// Destrutor default
    ~CSimuladorCurvasIPR(){};
     
    /// Cabecalho do programa
    void Header();
    
     /// Maiores informacoes sobre o programa
    void InformacaoPrograma();
    
    /// Menu de execucao
    int Menu();
    
    /// Metodo que solicita a entrada de dados comuns a todos os regimes pelo teclado
    void EntradaDadosTeclado();

    /// Metodo que solicita a entrada de parametros pelo arquivo de disco
    void EntradaDadosArquivoDisco();
    
    /// Metodo que faz leitura de dados de pressao e vazao de um arquivo de disco
    void LerDadosArquivoDisco();
    
    /// Metodo que salva arquivos no disco
    void SalvarDadosArquivoDisco();
    
    /// Metodo que plota curvas de IPR
    void Plotar();
    
    /// Plotar dados de arquivo de disco
    void PlotarDadosDisco();

    /// Metodo que salva grafico
    void SalvarGrafico();

    /// Metodos relacionado ao calculo da vazao com reservatorio em regime transiente
    void RegimeTransiente();
    /// Metodos relacionado ao calculo da vazao com reservatorio em regime pseudopermanente
	void RegimePseudoPermanente();
    /// Metodos relacionado ao calculo da vazao com reservatorio em regime permanente
	void RegimePermanente();
    /// Tempo final do reservatorio em regime transiente
	double TPSS(double _phi, double _mi, double _ct, double _re, double _kh);
    /// Tempo de producao do reservatorio em regime transiente
    void Tempo(double _tempo){tempo = _tempo;};
    /// Metodo para calculo do skin total
    double SkinTotal();
    
}; //< encerra class CSimuladorCurvasIPR

#endif
