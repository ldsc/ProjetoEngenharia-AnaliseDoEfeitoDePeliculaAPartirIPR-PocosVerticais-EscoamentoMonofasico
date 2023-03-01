/* Classe que simula a an�lise do efeito de pel�cula a partir de curvas de IPR  */

#ifndef CSimuladorCurvasIPR_h
#define CSimuladorCurvasIPR_h

// Inclus�o de bibliotecas
#include <vector>
#include <string>
#include "CGnuplot.h"

// Inclus�o das demais classes
#include "CRocha.h"
#include "CFluido.h"
#include "CPoco.h"
#include "CReservatorio.h"
#include "CSkin.h"
#include "CSkinDano.h"
#include "CSkinCanhoneio.h"
#include "CSkinDesvio.h"


using namespace std;

class CSimuladorCurvasIPR{

    protected:
    // Atributos referentes ao Regime do Reservat�rio
    vector <double> pressaoPoco;         // vetor que armazena press�es do po�o
    vector <double> vazaoPocoSkin;       // vetor que armazena vaz�o do po�o considerando skin
    vector <double> vazaoPocoNullSkin;   // vetor que armazena vaz�o do po�o considerando skin nulo
    double pressao;                      // retorna press�o medida no po�o
    double vazaoSkin;                    // retorna vaz�o do po�o considerando skin
    double vazaoNullSkin;                // retorna vaz�o do po�o considerando skin nulo
    double tempo;                        // tempo de produ�o do reservat�rio em regime transiente
    double tpss;                         // tempo final do reservat�rio em regime transiente
    double skinTotal;                    // retorna o skin total;
    
    CPoco poco;                     // Objeto da classe CPoco
    CReservatorio reservatorio;     // Objeto da classe CReservatorio
    CFluido oleo;                   // Objeto da classe CFluido
    CRocha rocha;                   // Objeto da classe CRocha
    CSkin skin;                     // Objeto da classe CSkin
    CSkinDano danoSkin;             // Objeto da classe CSkinDano
    CSkinCanhoneio canhoneioSkin;   // Objeto da classe CSkinCanhoneio
    CSkinDesvio desvioSkin;         // Objeto da classe CSkinDesvio
    CGnuplot grafico;               // Objeto da classe CGnuplot
             
    // Demais atributos
    string nomeArquivo;             // Para salvar dados ou abrir dados salvos anteriormente
    string nomeGrafico;             // Para salvar gr�fico gerado
    string entradaDados;            // Para entrar com par�metros por arquivo de disco
    
public:
    // Construtor default
    CSimuladorCurvasIPR(){};
    // Destrutor default
    ~CSimuladorCurvasIPR(){};
    
    // M�todos referentes a execucao do simulador
    
    // Cabe�alho do programa
    void Header();
    
     // Maiores informa��es sobre o programa
    void InformacaoPrograma();
    
    // Menu de execu��o
    int Menu();
    
    // Metodo que solicita a entrada de dados comuns a todos os regimes pelo teclado
    void EntradaDadosTeclado();

    // Metodo que solicita a entrada de parametros pelo arquivo de disco
    void EntradaDadosArquivoDisco();
    
    // Metodo que faz leitura de dados de pressao e vazao de um arquivo de disco
    void LerDadosArquivoDisco();
    
    // Metodo que salva arquivos no disco
    void SalvarDadosArquivoDisco();
    
    // Metodo que plota curvas de IPR
    void Plotar();
    
    // Plotar dados de arquivo de disco
    void PlotarDadosDisco();

    // Metodo que salva grafico
    void SalvarGrafico();

    // Metodos relacionados ao calculo da vazao de acordo com o regime do reservatorio
    void RegimeTransiente();
    void RegimePseudoPermanente();
    void RegimePermanente();
    double TPSS(double _phi, double _mi, double _ct, double _re, double _kh);
    //double SkinTotal();
    void Tempo(double _tempo){tempo = _tempo;};
    
    // Metodo para calculo do skin total
    double SkinTotal();
    
}; // encerra class CSimuladorCurvasIPR

#endif
