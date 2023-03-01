/// Implementacao da classe CSimuladorCurvasIPR

/// Inclusao de bibliotecas
#include<iostream>      //< Biblioteca usada para iteracao tela e teclado
#include<fstream>       //< Biblioteca para entrada e saida de disco
#include<iomanip>       //< Biblioteca para a formatacao da saida de dados para tela e arquivo de disco   
#include<string>        //< Bibliteca para o uso de strings
#include<vector>        //< Biblioteca para o uso de vetores
#include<cmath>         //< Biblioteca para o uso de funcões matematicas
#include<cstdlib>       //< Biblioteca usada para a saida do programa e limpeza de dados da tela
#include "CGnuplot.h"   //< Biblioteca usada para a utilizacao de recursos graficos usando o software externo GnuPlot

/// Inclusao das demais classes
#include "CSimuladorCurvasIPR.h"
#include "CRocha.h"
#include "CFluido.h"
#include "CPoco.h"
#include "CReservatorio.h"
#include "CSkin.h"
#include "CSkinDano.h"
#include "CSkinCanhoneio.h"
#include "CSkinDesvio.h"

using namespace std;

string linha = "-------------------------------------------------------------------------------------------------------------------------------------------------";

/// Cabecalho do software
void CSimuladorCurvasIPR::Header(){
    
    system("clear");
    cout<<linha<<endl;
    cout<< "| UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE DARCY RIBEIRO"<<endl;
    cout<< "| CENTRO DE CIENCIAS E TECNOLOGIA - CTT"<<endl;
    cout<< "| LABORAToRIO DE ENGENHARIA E EXPLORACAO DE PETROLEO - LENEP"<<endl;
    cout<< "| DISCIPLINA: PROGRAMACAO PRATICA - PROJETO C++"<<endl;
    cout<< "| PROFESSOR: ANDRE DUARTE BUENO"<<endl;
    cout<< "| ALUNO: MATHEUS CARVALHO DUARTE"<<endl;
    cout<< "| SOFTWARE PARA ANALISE DO EFEITO DE PELICULA A PARTIR DE CURVAS DE INDICE DE PRODUTIVIDADE (IPR) EM POCOS VERTICAIS COM FLUXO MONOFASICO DE OLEO"<<endl;
    cout<<linha<<endl;
} //< encerra Header()

/// Menu Inicial
int CSimuladorCurvasIPR::Menu(){
    
    cout << linha;
    cout << "\n Menu de Inicializacao" << endl;
    cout<<"\n Selecione uma das opcoes abaixo: " << endl;

    cout<<"\n - Entrada de dados pelo teclado..................................1";
    cout<<"\n - Entrada de dados por arquivo (.dat)............................2";
    cout<<"\n - Visualizar dados de arquivo (.dat).............................3";
    cout<<"\n - Salvar dados de pressao e vazao (.dat).........................4";
    cout<<"\n - Plotar Curvas de IPR gerados pelo software.....................5";
    cout<<"\n - Plotar Curvas de IPR de um arquivo (.dat)......................6";
    cout<<"\n - Salvar grafico (.png)..........................................7";
    cout<<"\n - Sobre o programa...............................................8";
    cout<<"\n - Sair...........................................................9";
    cout<< endl;
    
    cout << "\n Opcao desejada: ";
    short int opcao{1};
    cin >> opcao; 
    cin.get();

    if (opcao<=9){
        switch (opcao){
        case 1: EntradaDadosTeclado();      break;
        case 2: EntradaDadosArquivoDisco(); break;
        case 3: LerDadosArquivoDisco();     break;
        case 4: SalvarDadosArquivoDisco();  break;
        case 5: Plotar();                   break;
        case 6: PlotarDadosDisco();         break;
        case 7: SalvarGrafico();            break;
        case 8: InformacaoPrograma();       break;
        case 9: exit(0);
        default: EntradaDadosTeclado();     break;
        }   //< encerra switch
    }   //< encerra if 
    else
    {
        cerr << "\n Opcao invalida. Tente novamente." << endl << endl << endl << endl << endl;
        return Menu();
    }//< encerra else

    return 0;

} //< encerra Menu()

/// Entrada de dados pelo teclado
void CSimuladorCurvasIPR::EntradaDadosTeclado(){

    cout << linha << endl;
    cout<<"\n Selecione o regime do reservatorio: " << endl;
    cout<<"\n - Regime Transiente..............................................1";
    cout<<"\n - Regime Pseudopermanente........................................2";
    cout<<"\n - Regime Permanente..............................................3";
    cout<<"\n - Voltar.........................................................4";
    cout<< endl;
    
    cout << "\n Opcao desejada: ";
    short int opcaoRegime;           //< retorna o regime selecionado
    cin >> opcaoRegime; 
    cin.get();

    if (opcaoRegime == 1){
        
    /// Cabecalho para o regime transiente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatorio em Regime Transiente\n";
    cout << linha;
    
    cout << "\n Informe a pressao inicial do reservatorio (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 2){
        
    /// Cabecalho para o regime pseudopermanente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatorio em Regime Pseudopermanente\n";
    cout << linha;
    
    /// O nome da pressao muda de acordo com o regime (pressao inicial,media ou na fronteira), mas no programa um unico metodo recebe o valor
    
    cout << "\n Informe a pressao media do reservatorio (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 3){
        
   /// Cabecalho para o regime permanente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatorio em Regime Permanente\n";
    cout << linha;
    
    /// O nome da pressao muda de acordo com o regime ( pressao inicial,media ou na fronteira), mas no programa um unico metodo recebe o valor
    
    cout << "\n Informe a pressao na fronteira do reservatorio (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 4) {Menu();}
    
    if (opcaoRegime > 4){
        cerr << "\n Opcao invalida. Tente novamente." << endl << endl << endl << endl << endl;
        return EntradaDadosTeclado();
    };
    
    cout << "\n Informe a pressao final do poco (psi): ";
    double _pwf;
    cin >> _pwf;
    cin.get();
    poco.Pwf(_pwf);

    /// A pressao final do poco deve ser menor que a pressao inicial
    if ( poco.Pwf() > reservatorio.Pi() ) {cerr << "\n Atencao! A pressao do poco cai ao longo do tempo de producao. Portanto, a pressao final deve ser menor que a pressao inicial. VocE sera redirecionado para o Menu anterior a fim de se redefinir os parmametros." << endl;
    return EntradaDadosTeclado();
    }
    
    
    cout << "\n Informe a variacao de pressao em que ira ser medida a vazao do poco (psi): ";
    double _deltaP;
    cin >> _deltaP;
    cin.get();
    poco.DeltaP(_deltaP);

    cout << "\n Informe o raio do reservatorio (ft): ";
    double _re;
    cin >> _re;
    cin.get();
    reservatorio.Re(_re);

    cout << "\n Informe o raio do poco (ft): ";
    double _rw;
    cin >> _rw;
    cin.get();
    poco.Rw(_rw);

    cout << "\n Informe o raio da zona alterada (ft): ";
    double _rs;
    cin >> _rs;
    cin.get();
    poco.Rs(_rs);
    
    cout << "\n Informe a inclinacao do poco (graus): ";
    double _theta;
    cin >> _theta;
    cin.get();
    poco.Theta(_theta);

    cout << "\n Informe a espessura do reservatorio (ft): ";
    double _h;
    cin >> _h;
    cin.get();
    reservatorio.H(_h);

    cout << "\n Informe a espessura da zona canhoneada (ft): ";
    double _hp;
    cin >> _hp;
    cin.get();
    reservatorio.HP(_hp);

    cout << "\n Informe a espessura da zona perfurada e nao-canhoneada (ft): ";
    double _h1;
    cin >> _h1;
    cin.get();
    reservatorio.H1(_h1);

    cout << "\n Informe a permeabilidade horizontal (mD): ";
    double _kh;
    cin >> _kh;
    cin.get();
    rocha.Kh(_kh);

    cout << "\n Informe a permeabilidade vertical (mD): ";
    double _kv;
    cin >> _kv;
    cin.get();
    rocha.Kv(_kv);

    cout << "\n Informe a permeabilidade da zona alterada (mD): ";
    double _ks;
    cin >> _ks;
    cin.get();
    rocha.Ks(_ks);

    cout << "\n Informe o fator volume-formacao do fluido (bbl/STB): ";
    double _fvf;
    cin >> _fvf;
    cin.get();
    oleo.FVF(_fvf);

    cout << "\n Informe a viscosidade do fluido (cp): ";
    double _mi;
    cin >> _mi;
    cin.get();
    oleo.Mi(_mi);
    
    /// Para o regime transiente sao necessarios mais parametros. Estes nao foram adicionados no primeiro if apenas para se manter a entrada de dados padronizada para todos os regimes.
    
    if (opcaoRegime == 1){
        
    cout << "\n Informe a porosidade do reservatorio: ";
    double _phi;
    cin >> _phi;
    cin.get();
    rocha.Phi(_phi);

    cout << "\n Informe a compressibilidade total (1/psi): ";
    double _ct;
    cin >> _ct;
    cin.get();
    rocha.Ct(_ct);
    
    /// O software informa ao usuario o tempo final do regime transiente. Este deve ser o tempo maximo que o usuario deve definir para que a solucao do regime transiente seja satisfeita.
    cout << "\n Tempo final do regime transiente (hr): " << TPSS(rocha.Phi(),oleo.Mi(),rocha.Ct(),reservatorio.Re(),rocha.Kh()) << ". Informe o tempo de producao do poco (este deve ser menor ou igual ao tempo final): ";
    
    double _tempo;
    cin >> _tempo;
    cin.get();
    
    if (_tempo<= tpss){
    Tempo(_tempo);
    }
    else {
      cerr << "\n Atencao! Tempo maior que o de duracao do regime transiente. Insira tempo inferior ao limite ou selecine outro regime";
      cout << endl << "\n Pressione ENTER para retornar ao inicio." << endl;
      cin.get();
      return EntradaDadosTeclado();
    }; //< endif tpss
    
    }; //< endif opcaoRegime
    
    /// Calculo do skin total
    SkinTotal(); 
    
    /// Calculo da vazao em funcao da queda de pressao de acordo com regime definido pelo usuario.
    switch (opcaoRegime){
    case 1: RegimeTransiente();            break;
    case 2: RegimePseudoPermanente();      break;
    case 3: RegimePermanente();            break;
    };/// encerra switch
   
} //< encerra EntradaDadosTeclado()

/// Entrada de dados por aquivo de disco
void CSimuladorCurvasIPR::EntradaDadosArquivoDisco(){
    
    cout << linha << endl;
    cout<<"\n Selecione o regime do reservatorio: " << endl;
    cout<<"\n - Regime Transiente..............................................1";
    cout<<"\n - Regime Pseudopermanente........................................2";
    cout<<"\n - Regime Permanente..............................................3";
    cout<<"\n - Voltar.........................................................4";
    cout<< endl;
    
    cout << "\n Opcao desejada: ";
    short int opcaoRegime;           //< retorna o regime selecionado
    cin >> opcaoRegime; 
    cin.get();
    
    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo com os parametros: ";
    getline(cin, entradaDados);
    
    ifstream fin (entradaDados +".dat");
    if (! fin){cerr << "\n Arquivo nao encontrado. Por favor, insira um nome de arquivo valido: ";
                getline(cin, entradaDados); 
                fin.open(entradaDados +".dat");}
    
    string numero;
    double data;
    int contador = 0;
    
    cout << linha;
    cout << "\n Dados de entrada carregados pelo arquivo de disco: " << endl;
    cout << linha;
    
    while (!fin.eof()){     //< leitura ate o final do arquivo de disco
        
           contador++;
           getline(fin,numero);         //< leitura do linha
           data = atof(numero.c_str()); //< converte string para double
                                 
        /// Switch armazena os dados nos devidos metodos e mostra na tela
        /// Dados de entrada comuns a todos os regimes
           
        switch(contador){
        case 1:  cout << "\n Pressao inicial (psi): " << data; reservatorio.Pi(data);         break;   
        case 2:  cout << "\n Pressao final do poco (psi): " << data; poco.Pwf(data);          break;   
        case 3:  cout << "\n Variacao de pressao (psi): " << data;poco.DeltaP(data);          break;   
        case 4:  cout << "\n Raio do reservatorio (ft): " << data;reservatorio.Re(data);      break;
        case 5:  cout << "\n Raio do poco (ft): " << data; poco.Rw(data);                     break;  
        case 6:  cout << "\n Raio da zona alterada (ft): " << data;poco.Rs(data);             break;  
        case 7:  cout << "\n Inclinacao do poco (graus): " << data; poco.Theta(data);         break;   
        case 8:  cout << "\n Espessura do reservatorio (ft): " << data; reservatorio.H(data); break;   
        case 9:  cout << "\n Espessura da zona canhoneada: " << data; reservatorio.HP(data);  break;   
        case 10: cout << "\n Espessura da zona perfurada e nao-canhoneada (ft): " << data; reservatorio.H1(data);     break;   
        case 11: cout << "\n Permeabilidade horizontal (mD): " << data; rocha.Kh(data);       break;   
        case 12: cout << "\n Permeabilidade vertical (mD): " << data; rocha.Kv(data);         break;   
        case 13: cout << "\n Permeabilidade da zona alterada (mD): " << data;rocha.Ks(data);  break;   
        case 14: cout << "\n Fator volume-formacao (bbl/STB): " << data; oleo.FVF(data);      break;   
        case 15: cout << "\n Viscosidade (cp): " << data; oleo.Mi(data);                      break;   
                    
        /// Para o regime transiente estes dados sao obrigatorios
        case 16: cout << "\n Porosidade do reservatorio: " << data; rocha.Phi(data);         break;
        case 17: cout << "\n Compressibilidade total (1/psi): " << data; rocha.Ct(data);     break;
        case 18: cout << "\n Tempo de producao (hr): " << data; Tempo(data);                 break;
        } //< end switch
    } //< end while
    
    fin.close();    //< fecha arquivo de disco
    cout << endl << "\n Para continuar pressione ENTER" << endl;
    cin.get();
    
    /// Calculo do skin total
    SkinTotal(); 
    
    /// Calculo da vazao em funcao da queda de pressao de acordo com regime definido pelo usuario.
    switch (opcaoRegime){
    case 1: RegimeTransiente();            break;
    case 2: RegimePseudoPermanente();      break;
    case 3: RegimePermanente();            break;
    };//< encerra switch
   
}  //< encerra EntradaDadosArquivoDisco()

/// Visualizar dados de arquivo de disco
void CSimuladorCurvasIPR::LerDadosArquivoDisco(){

    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo: ";
    getline(cin, entradaDados);
    
    ifstream fin (entradaDados +".dat");
    if (! fin){cerr << "\n Arquivo nao encontrado. Por favor, insira um nome de arquivo valido: ";
                getline(cin, entradaDados);
                fin.open(entradaDados +".dat");}
    
    string data;
    
    cout << endl;
    while (!fin.eof()){                 
        getline(fin, data);      //< Leitura de cada linha do arquivo
        cout << data << endl;    //< Mostra na tela
    }//< end while

    cin.get();
    
} //< encerra LerDadosArquivoDisco()

/// Salvar dados em arquivo de disco
void CSimuladorCurvasIPR::SalvarDadosArquivoDisco(){
    
    cout << "\n Informe o nome que deseja salvar o arquivo: ";
    getline(cin, nomeArquivo);
    ofstream fout (nomeArquivo +".dat");
    
    /// Cabecalho do arquivo
    fout << setw(40) << right << "Pressao(psi)" << setw(40) << right << "Vazao c/ skin (STB/day)" << setw(40) << right << "Vazao s/ skin (STB/day)" << endl;
    
    /// Saida de Dados
    cout.precision(4); //< Numero de algarismos significativos
    for (int i=0; i<pressaoPoco.size();i++){
        fout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i]<<endl;
    }
    fout.close();   /// fecha arquivo de disco
    cout << "\n Dados salvos em arquivo com sucesso. \n" << linha;
    
    cin.get();

} //< encerra SalvarDadosArquivoDisco()

/// Metodo para plot das curvas de IPR
void CSimuladorCurvasIPR::Plotar(){

    grafico.ResetPlot();    //< reseta ultimo plot aberto
    grafico.Style("lines"); //< grafico em linha
    grafico.PlotVector(vazaoPocoNullSkin,pressaoPoco,"Skin nulo"); //< plot de vetores 
    grafico.PlotVector(vazaoPocoSkin,pressaoPoco,"Skin nao-nulo"); //< plot de vetores
    grafico.Title("Analise do Efeito de Pelicula a partir de curvas de IPR");   //< titulo do grafico
    grafico.XLabel("Vazao (STB/d)");  //< titulo eixo x
    grafico.YLabel("Pressao (psi)");  //< titulo eixo y
    grafico.Grid(1);   //< ativa grid
    cin.get();

} //< encerra Plotar()

/// Plotar grafico de arquivo de disco
void CSimuladorCurvasIPR::PlotarDadosDisco(){
    
    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo: ";
    getline(cin, nomeArquivo);

    ifstream fin (nomeArquivo +".dat");
    if (! fin){cerr << "\n Arquivo de disco nao encontrado. Por favor, insira um nome de arquivo valido: ";
                getline(cin, nomeArquivo);
                fin.open(nomeArquivo +".dat");}
                
    grafico.ResetPlot(); //< reseta ultimo plot aberto
    grafico.Style("lines"); //< grafico em linha
    grafico.PlotFile(nomeArquivo +".dat",3,1,"skin nulo");  //< plot de y(coluna 1) versus x (coluna 3)
    grafico.PlotFile(nomeArquivo +".dat",2,1,"skin nao-nulo"); //< plot de y (coluna 1) versus x (coluna 2)
    grafico.Title("Analise do Efeito de Pelicula a partir de curvas de IPR");   //< titulo do grafico
    grafico.XLabel("Vazao (STB/d)");    //< titulo eixo x
    grafico.YLabel("Pressao (psi)");    //< titulo eixo y
    grafico.Grid(1);    //< ativa grid
    
    fin.close();    //< fecha o arquivo de disco
    
    cin.get();

} //< encerra PlotarDadosDisco()

/// Salvar grafico
void CSimuladorCurvasIPR::SalvarGrafico(){
    
    cout << "\n Informe o nome do arquivo que deseja salvar o grafico: ";
    getline(cin, nomeGrafico);
    grafico.savetopng(nomeGrafico);
    cout << "\n Grafico salvo com sucesso.";
    cin.get();
    
} //< encerra SalvarGrafico()

/// Informacoes sobre o programa para usuario iniciante
void CSimuladorCurvasIPR::InformacaoPrograma(){
    
    cout << linha;
    cout << "\n Este programa analisa o efeito de pelicula a partir de curvas de indice de Produtividade (IPR) em pocos verticais com fluxo monofasico de oleo." << endl;
    cout << "\n A partir dos parametros de entrada realiza-se uma estimativa dos efeitos de pelicula." << endl;
    cout << "\n Os efeitos de pelicula calculados sao:" << endl;
    cout << "\n - Efeito de pelicula devido alteracao da permeabilidade nas proximidades do poco calculado pela Formula de Hawkins (1956)." << endl;
    cout << "\n - Efeito de pelicula causado pelo canhoneio parcial do reservatorio a partir de formulas propostas por Papatzacos (1987)." << endl;
    cout << "\n - Efeito de pelicula causado pela inclinacao do poco a partir de formulas propostas por Besson (1990)." << endl;
    cout << "\n - Efeito de pelicula total (soma dos anteriores)." << endl;
    cout << "\n A partir destas estimativas o programa calcula o vazao no fundo do poco para pocos verticais de oleo em regime transiente, pseudopermanente ou permanente (definido pelo usuario) considerando efeito de pelicula nulo e nao-nulo para avaliar se ha um dano ou estimulo a formacao." << endl;
    cout << "\n O usuario podera ler,salvar e vizualizar os dados em '.dat', plotar graficos e salva-los em '.png' para melhor analise do efeito de pelicula total." << endl << linha;
    cin.get();
    
}  //< encerra InformacaoPrograma()

/// Implementacao dos Regimes do Reservatorio

void CSimuladorCurvasIPR::RegimeTransiente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; //< numero de medidas de vazao a serem feitas
    
    /// Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             //< Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            //< Armazena queda de pressao      
        
        /// Vazao considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/(162.6*oleo.FVF()*oleo.Mi()*(log10(tempo) + log10(rocha.Kh()/(rocha.Phi()*oleo.Mi()*rocha.Ct()*pow(poco.Rw(),2))) - 3.23 + 0.87*skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        /// Vazao considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/( 162.6*oleo.FVF()*oleo.Mi()*(log10(tempo) + log10(rocha.Kh()/(rocha.Phi()*oleo.Mi()*rocha.Ct()*pow(poco.Rw(),2))) -3.23));
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    /// Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); //< Numero de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   /// encerra RegimeTransiente()

void CSimuladorCurvasIPR::RegimePseudoPermanente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; // numero de medidas de vazao a serem feitas
    
    /// Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             //< Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            //< Armazena queda de pressao      
        
        /// Vazao considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) - (3./4.) + skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        /// Vazao considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) - (3./4.)));;
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    /// Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); //< Numero de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   /// encerra RegimePseudoPermanente()

void CSimuladorCurvasIPR::RegimePermanente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; //< numero de medidas de vazao a serem feitas
    
    /// Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             //< Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            //< Armazena queda de pressao      
        
        /// Vazao considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) + skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        /// Vazao considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw())));;
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    /// Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); //< Numero de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   //< encerra RegimePermanente()

/// Metodo que retorna o tempo limite para o regime transiente
double CSimuladorCurvasIPR::TPSS(double _phi, double _mi, double _ct,double _re,double _kh){
    tpss = (1200*_phi*_mi*_ct*pow(_re,2))/_kh;
    return tpss;
}   //< encerra TPSS

/// Metodo que retorna o calculo do skin total
double CSimuladorCurvasIPR::SkinTotal(){
   
    /// Skin de dano
    danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs());
    
    
    /// Skin por canhoneio parcial
    canhoneioSkin.HPD(reservatorio.HP(),reservatorio.H());
    canhoneioSkin.H1D(reservatorio.H1(),reservatorio.H());
    canhoneioSkin.RD(poco.Rw(),reservatorio.H(),rocha.Kv(),rocha.Kh());
    canhoneioSkin.A();
    canhoneioSkin.B();
    canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh());
    
    /// Skin por desvio do poco
    desvioSkin.Beta(rocha.Kv(),rocha.Kh());
    poco.Extensao(reservatorio.H());
    desvioSkin.Gamma(reservatorio.H(),poco.Extensao(reservatorio.H()));
    desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
    
    /// Skin total
    skinTotal = danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs())+ canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh()) + desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
        
    cout << endl << linha << "\n Calculo dos efeitos de peli­cula" << endl << linha;
    cout << "\n Efeito de pelicula por dano a permeabilidade nas proximidades do poco: " << danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs());
    cout << "\n Efeito de pelicula causado por completacao parcial do reservatorio: " << canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh());
    cout << "\n Efeito de pelicula causado pela inclinacao do poco: " << desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
    cout << "\n Efeito de pelicula total: " << skinTotal;
    
    if (skinTotal > 0){
      cout << "\n Efeito de pelicula resultante causa dano a formacao (skin total positivo)." << endl;  
    }
    else{
      cout << "\n Efeito de pelicula resultante causa estimulo a formacao (skin total negativo)." << endl;  
    }
    
    cout << "\n Pressione ENTER para continuar";
    cin.get();
    
    return skinTotal;
}   //< encerra SkinTotal

