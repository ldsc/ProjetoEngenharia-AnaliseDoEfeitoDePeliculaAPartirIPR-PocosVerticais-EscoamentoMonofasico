// Implementação da classe CSimuladorCurvasIPR

// Inclusão de bibliotecas
#include<iostream>      // Biblioteca usada para iteração tela e teclado
#include<fstream>       // Biblioteca para entrada e saída de disco
#include<iomanip>       // Biblioteca para a formatação da saída de dados para tela e arquivo de disco   
#include<string>        // Bibliteca para o uso de strings
#include<vector>        // Biblioteca para o uso de vetores
#include<cmath>         // Biblioteca para o uso de funções matemáticas
#include<cstdlib>       // Biblioteca usada para a saída do programa e limpeza de dados da tela
#include "CGnuplot.h"   // Biblioteca usada para a utilização de recursos gráficos usando o software externo GnuPlot

// Inclusão das demais classes
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

// Cabeçalho do software
void CSimuladorCurvasIPR::Header(){
    
    system("clear");
    cout<<linha<<endl;
    cout<< "| UNIVERSIDADE ESTADUAL DO NORTE FLUMINENSE DARCY RIBEIRO"<<endl;
    cout<< "| CENTRO DE CIÊNCIAS E TECNOLOGIA - CTT"<<endl;
    cout<< "| LABORATÓRIO DE ENGENHARIA E EXPLORAÇÃO DE PETRÓLEO - LENEP"<<endl;
    cout<< "| DISCIPLINA: PROGRAMAÇÃO PRÁTICA - PROJETO C++"<<endl;
    cout<< "| PROFESSOR: ANDRÉ DUARTE BUENO"<<endl;
    cout<< "| ALUNO: MATHEUS CARVALHO DUARTE"<<endl;
    cout<< "| SOFTWARE PARA ANÁLISE DO EFEITO DE PELÍCULA A PARTIR DE CURVAS DE ÍNDICE DE PRODUTIVIDADE (IPR) EM POCOS VERTICAIS COM FLUXO MONOFÁSICO DE ÓLEO"<<endl;
    cout<<linha<<endl;
} // encerra Header()

// Menu Inicial
int CSimuladorCurvasIPR::Menu(){
    
    cout << linha;
    cout << "\n Menu de Inicialização" << endl;
    cout<<"\n Selecione uma das opcoes abaixo: " << endl;

    cout<<"\n - Entrada de dados pelo teclado..................................1";
    cout<<"\n - Entrada de dados por arquivo (.dat)............................2";
    cout<<"\n - Visualizar dados de arquivo (.dat).............................3";
    cout<<"\n - Salvar dados de pressão e vazão (.dat).........................4";
    cout<<"\n - Plotar Curvas de IPR gerados pelo software.....................5";
    cout<<"\n - Plotar Curvas de IPR de um arquivo (.dat)......................6";
    cout<<"\n - Salvar gráfico (.png)..........................................7";
    cout<<"\n - Sobre o programa...............................................8";
    cout<<"\n - Sair...........................................................9";
    cout<< endl;
    
    cout << "\n Opção desejada: ";
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
        }   // encerra switch
    }   // encerra if 
    else
    {
        cerr << "\n Opção inválida. Tente novamente." << endl << endl << endl << endl << endl;
        return Menu();
    }// encerra else

    return 0;

} // encerra Menu()

// Entrada de dados pelo teclado
void CSimuladorCurvasIPR::EntradaDadosTeclado(){

    cout << linha << endl;
    cout<<"\n Selecione o regime do reservatório: " << endl;
    cout<<"\n - Regime Transiente..............................................1";
    cout<<"\n - Regime Pseudopermanente........................................2";
    cout<<"\n - Regime Permanente..............................................3";
    cout<<"\n - Voltar.........................................................4";
    cout<< endl;
    
    cout << "\n Opção desejada: ";
    short int opcaoRegime;           // retorna o regime selecionado
    cin >> opcaoRegime; 
    cin.get();

    if (opcaoRegime == 1){
        
    // Cabeçalho para o regime transiente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatório em Regime Transiente\n";
    cout << linha;
    
    cout << "\n Informe a pressão inicial do reservatório (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 2){
        
    // Cabeçalho para o regime pseudopermanente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatório em Regime Pseudopermanente\n";
    cout << linha;
    
    /* O nome da pressão muda de acordo com o regime (pressão inicial,média ou na fronteira), mas no programa um único método recebe o valor */
    
    cout << "\n Informe a pressão média do reservatório (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 3){
        
   // Cabeçalho para o regime permanente
    system("clear");
    cout << linha;
    cout << "\n " << setw(90) << "Reservatório em Regime Permanente\n";
    cout << linha;
    
    /* O nome da pressão muda de acordo com o regime ( pressão inicial,média ou na fronteira), mas no programa um único método recebe o valor */
    
    cout << "\n Informe a pressão na fronteira do reservatório (psi): ";
    double _pi;
    cin >> _pi;
    cin.get();
    reservatorio.Pi(_pi);
    };
    
    if (opcaoRegime == 4) {Menu();}
    
    if (opcaoRegime > 4){
        cerr << "\n Opção inválida. Tente novamente." << endl << endl << endl << endl << endl;
        return EntradaDadosTeclado();
    };
    
    cout << "\n Informe a pressão final do poço (psi): ";
    double _pwf;
    cin >> _pwf;
    cin.get();
    poco.Pwf(_pwf);

    // A pressão final do poço deve ser menor que a pressão inicial
    if ( poco.Pwf() > reservatorio.Pi() ) {cerr << "\n Atenção! A pressão do poço cai ao longo do tempo de produção. Portanto, a pressão final deve ser menor que a pressão inicial. Você será redirecionado para o Menu anterior a fim de se redefinir os parmâmetros." << endl;
    return EntradaDadosTeclado();
    }
    
    
    cout << "\n Informe a variação de pressão em que irá ser medida a vazão do poço (psi): ";
    double _deltaP;
    cin >> _deltaP;
    cin.get();
    poco.DeltaP(_deltaP);

    cout << "\n Informe o raio do reservatório (ft): ";
    double _re;
    cin >> _re;
    cin.get();
    reservatorio.Re(_re);

    cout << "\n Informe o raio do poço (ft): ";
    double _rw;
    cin >> _rw;
    cin.get();
    poco.Rw(_rw);

    cout << "\n Informe o raio da zona alterada (ft): ";
    double _rs;
    cin >> _rs;
    cin.get();
    poco.Rs(_rs);
    
    cout << "\n Informe a inclinação do poço (graus): ";
    double _theta;
    cin >> _theta;
    cin.get();
    poco.Theta(_theta);

    cout << "\n Informe a espessura do reservatório (ft): ";
    double _h;
    cin >> _h;
    cin.get();
    reservatorio.H(_h);

    cout << "\n Informe a espessura da zona canhoneada (ft): ";
    double _hp;
    cin >> _hp;
    cin.get();
    reservatorio.HP(_hp);

    cout << "\n Informe a espessura da zona perfurada e não-canhoneada (ft): ";
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

    cout << "\n Informe o fator volume-formação do fluido (bbl/STB): ";
    double _fvf;
    cin >> _fvf;
    cin.get();
    oleo.FVF(_fvf);

    cout << "\n Informe a viscosidade do fluido (cp): ";
    double _mi;
    cin >> _mi;
    cin.get();
    oleo.Mi(_mi);
    
    /* Para o regime transiente são necessários mais parâmetros. Estes não foram adicionados no primeiro if apenas para se manter a entrada de dados padronizada para todos os regimes. */
    
    if (opcaoRegime == 1){
        
    cout << "\n Informe a porosidade do reservatório: ";
    double _phi;
    cin >> _phi;
    cin.get();
    rocha.Phi(_phi);

    cout << "\n Informe a compressibilidade total (1/psi): ";
    double _ct;
    cin >> _ct;
    cin.get();
    rocha.Ct(_ct);
    
    /* O software informa ao usuário o tempo final do regime transiente. Este deve ser o tempo máximo que o usuário deve definir para que a solução do regime transiente seja satisfeita. */
    cout << "\n Tempo final do regime transiente (hr): " << TPSS(rocha.Phi(),oleo.Mi(),rocha.Ct(),reservatorio.Re(),rocha.Kh()) << ". Informe o tempo de produção do poço (este deve ser menor ou igual ao tempo final): ";
    
    double _tempo;
    cin >> _tempo;
    cin.get();
    
    if (_tempo<= tpss){
    Tempo(_tempo);
    }
    else {
      cerr << "\n Atenção! Tempo maior que o de duração do regime transiente. Insira tempo inferior ao limite ou selecine outro regime";
      cout << endl << "\n Pressione ENTER para retornar ao iní­cio." << endl;
      cin.get();
      return EntradaDadosTeclado();
    }; // endif tpss
    
    }; // endif opcaoRegime
    
    // Cálculo do skin total
    SkinTotal(); 
    
    // Cálculo da vazão em função da queda de pressão de acordo com regime definido pelo usuário.
    switch (opcaoRegime){
    case 1: RegimeTransiente();            break;
    case 2: RegimePseudoPermanente();      break;
    case 3: RegimePermanente();            break;
    };// encerra switch
   
} // encerra EntradaDadosTeclado()

// Entrada de dados por aquivo de disco
void CSimuladorCurvasIPR::EntradaDadosArquivoDisco(){
    
    cout << linha << endl;
    cout<<"\n Selecione o regime do reservatório: " << endl;
    cout<<"\n - Regime Transiente..............................................1";
    cout<<"\n - Regime Pseudopermanente........................................2";
    cout<<"\n - Regime Permanente..............................................3";
    cout<<"\n - Voltar.........................................................4";
    cout<< endl;
    
    cout << "\n Opção desejada: ";
    short int opcaoRegime;           // retorna o regime selecionado
    cin >> opcaoRegime; 
    cin.get();
    
    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo com os parâmetros: ";
    getline(cin, entradaDados);
    
    ifstream fin (entradaDados +".dat");
    if (! fin){cerr << "\n Arquivo não encontrado. Por favor, insira um nome de arquivo válido: ";
                getline(cin, entradaDados); 
                fin.open(entradaDados +".dat");}
    
    string numero;
    double data;
    int contador = 0;
    
    cout << linha;
    cout << "\n Dados de entrada carregados pelo arquivo de disco: " << endl;
    cout << linha;
    
    while (!fin.eof()){     // leitura até o final do arquivo de disco
        
           contador++;
           getline(fin,numero);         // leitura do linha
           data = atof(numero.c_str()); // converte string para double
                                 
        // Switch armazena os dados nos devidos métodos e mostra na tela
        // Dados de entrada comuns a todos os regimes
           
        switch(contador){
        case 1:  cout << "\n Pressao inicial (psi): " << data; reservatorio.Pi(data);         break;   
        case 2:  cout << "\n Pressao final do poço (psi): " << data; poco.Pwf(data);          break;   
        case 3:  cout << "\n Variação de pressão (psi): " << data;poco.DeltaP(data);          break;   
        case 4:  cout << "\n Raio do reservatório (ft): " << data;reservatorio.Re(data);      break;
        case 5:  cout << "\n Raio do poço (ft): " << data; poco.Rw(data);                     break;  
        case 6:  cout << "\n Raio da zona alterada (ft): " << data;poco.Rs(data);             break;  
        case 7:  cout << "\n Inclinação do poço (graus): " << data; poco.Theta(data);         break;   
        case 8:  cout << "\n Espessura do reservatório (ft): " << data; reservatorio.H(data); break;   
        case 9:  cout << "\n Espessura da zona canhoneada: " << data; reservatorio.HP(data);  break;   
        case 10: cout << "\n Espessura da zona perfurada e não-canhoneada (ft): " << data; reservatorio.H1(data);     break;   
        case 11: cout << "\n Permeabilidade horizontal (mD): " << data; rocha.Kh(data);       break;   
        case 12: cout << "\n Permeabilidade vertical (mD): " << data; rocha.Kv(data);         break;   
        case 13: cout << "\n Permeabilidade da zona alterada (mD): " << data;rocha.Ks(data);  break;   
        case 14: cout << "\n Fator volume-formação (bbl/STB): " << data; oleo.FVF(data);      break;   
        case 15: cout << "\n Viscosidade (cp): " << data; oleo.Mi(data);                      break;   
                    
        // Para o regime transiente estes dados são obrigatórios
        case 16: cout << "\n Porosidade do reservatório: " << data; rocha.Phi(data);         break;
        case 17: cout << "\n Compressibilidade total (1/psi): " << data; rocha.Ct(data);     break;
        case 18: cout << "\n Tempo de produção (hr): " << data; Tempo(data);                 break;
        } // end switch
    } // end while
    
    fin.close();    // fecha arquivo de disco
    cout << endl << "\n Para continuar pressione ENTER" << endl;
    cin.get();
    
    // Cálculo do skin total
    SkinTotal(); 
    
    // Cálculo da vazão em função da queda de pressão de acordo com regime definido pelo usuário.
    switch (opcaoRegime){
    case 1: RegimeTransiente();            break;
    case 2: RegimePseudoPermanente();      break;
    case 3: RegimePermanente();            break;
    };// encerra switch
   
}  // encerra EntradaDadosArquivoDisco()

// Visualizar dados de arquivo de disco
void CSimuladorCurvasIPR::LerDadosArquivoDisco(){

    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo: ";
    getline(cin, entradaDados);
    
    ifstream fin (entradaDados +".dat");
    if (! fin){cerr << "\n Arquivo não encontrado. Por favor, insira um nome de arquivo válido: ";
                getline(cin, entradaDados);
                fin.open(entradaDados +".dat");}
    
    string data;
    
    cout << endl;
    while (!fin.eof()){                 
        getline(fin, data);      // Leitura de cada linha do arquivo
        cout << data << endl;    // Mostra na tela
    }// end while

    cin.get();
    
} // encerra LerDadosArquivoDisco()

// Salvar dados em arquivo de disco
void CSimuladorCurvasIPR::SalvarDadosArquivoDisco(){
    
    cout << "\n Informe o nome que deseja salvar o arquivo: ";
    getline(cin, nomeArquivo);
    ofstream fout (nomeArquivo +".dat");
    
    // CabeÃ§alho do arquivo
    fout << setw(40) << right << "Pressao(psi)" << setw(40) << right << "Vazao c/ skin (STB/day)" << setw(40) << right << "Vazao s/ skin (STB/day)" << endl;
    
    // Saída de Dados
    cout.precision(4); // Número de algarismos significativos
    for (int i=0; i<pressaoPoco.size();i++){
        fout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i]<<endl;
    }
    fout.close();   // fecha arquivo de disco
    cout << "\n Dados salvos em arquivo com sucesso. \n" << linha;
    
    cin.get();

} // encerra SalvarDadosArquivoDisco()

// Método para plot das curvas de IPR
void CSimuladorCurvasIPR::Plotar(){

    grafico.ResetPlot();    // reseta último plot aberto
    grafico.Style("lines"); // gráfico em linha
    grafico.PlotVector(vazaoPocoNullSkin,pressaoPoco,"Skin nulo"); // plot de vetores 
    grafico.PlotVector(vazaoPocoSkin,pressaoPoco,"Skin nao-nulo"); // plot de vetores
    grafico.Title("Analise do Efeito de Pelicula a partir de curvas de IPR");   // título do gráfico
    grafico.XLabel("Vazao (STB/d)");  // título eixo x
    grafico.YLabel("Pressao (psi)");  // título eixo y
    grafico.Grid(1);   // ativa grid
    cin.get();

} // encerra Plotar()

// Plotar gráfico de arquivo de disco
void CSimuladorCurvasIPR::PlotarDadosDisco(){
    
    cout << "\n O arquivo deve estar na pasta raiz do software. Informe o nome do arquivo: ";
    getline(cin, nomeArquivo);

    ifstream fin (nomeArquivo +".dat");
    if (! fin){cerr << "\n Arquivo de disco não encontrado. Por favor, insira um nome de arquivo válido: ";
                getline(cin, nomeArquivo);
                fin.open(nomeArquivo +".dat");}
                
    grafico.ResetPlot(); // reseta último plot aberto
    grafico.Style("lines"); // gráfico em linha
    grafico.PlotFile(nomeArquivo +".dat",3,1,"skin nulo");  // plot de y(coluna 1) versus x (coluna 3)
    grafico.PlotFile(nomeArquivo +".dat",2,1,"skin nao-nulo"); // plot de y (coluna 1) versus x (coluna 2)
    grafico.Title("Analise do Efeito de Pelicula a partir de curvas de IPR");   // título do gráfico
    grafico.XLabel("Vazao (STB/d)");    // título eixo x
    grafico.YLabel("Pressao (psi)");    // título eixo y
    grafico.Grid(1);    // ativa grid
    
    fin.close();    // fecha o arquivo de disco
    
    cin.get();

} // encerra PlotarDadosDisco()

// Salvar gráfico
void CSimuladorCurvasIPR::SalvarGrafico(){
    
    cout << "\n Informe o nome do arquivo que deseja salvar o gráfico: ";
    getline(cin, nomeGrafico);
    grafico.savetopng(nomeGrafico);
    cout << "\n Gráfico salvo com sucesso.";
    cin.get();
    
} // encerra SalvarGrafico()

// Informações sobre o programa para usuário iniciante
void CSimuladorCurvasIPR::InformacaoPrograma(){
    
    cout << linha;
    cout << "\n Este programa analisa o efeito de película a partir de curvas de Índice de Produtividade (IPR) em poços verticais com fluxo monofásico de óleo." << endl;
    cout << "\n A partir dos parâmetros de entrada realiza-se uma estimativa dos efeitos de pelí­cula." << endl;
    cout << "\n Os efeitos de película calculados são:" << endl;
    cout << "\n - Efeito de película devido alteração da permeabilidade nas proximidades do poço calculado pela Fórmula de Hawkins (1956)." << endl;
    cout << "\n - Efeito de pelí­cula causado pelo canhoneio parcial do reservatório a partir de fórmulas propostas por Papatzacos (1987)." << endl;
    cout << "\n - Efeito de pelí­cula causado pela inclinação do poço a partir de fórmulas propostas por Besson (1990)." << endl;
    cout << "\n - Efeito de pelí­cula total (soma dos anteriores)." << endl;
    cout << "\n A partir destas estimativas o programa calcula o vazão no fundo do poço para poços verticais de óleo em regime transiente, pseudopermanente ou permanente (definido pelo usuário) considerando efeito de pelí­cula nulo e não-nulo para avaliar se há um dano ou estí­mulo à formação." << endl;
    cout << "\n O usuário poderá ler,salvar e vizualizar os dados em '.dat', plotar gráficos e salvá-los em '.png' para melhor análise do efeito de pelí­cula total." << endl << linha;
    cin.get();
    
}  // encerra InformacaoPrograma()

// Implementação dos Regimes do Reservatório

void CSimuladorCurvasIPR::RegimeTransiente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; // numero de medidas de vazao a serem feitas
    
    // Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             // Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            // Armazena queda de pressao      
        
        // Vazão considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/(162.6*oleo.FVF()*oleo.Mi()*(log10(tempo) + log10(rocha.Kh()/(rocha.Phi()*oleo.Mi()*rocha.Ct()*pow(poco.Rw(),2))) - 3.23 + 0.87*skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        // Vazão considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/( 162.6*oleo.FVF()*oleo.Mi()*(log10(tempo) + log10(rocha.Kh()/(rocha.Phi()*oleo.Mi()*rocha.Ct()*pow(poco.Rw(),2))) -3.23));
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    // Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); // Número de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   // encerra RegimeTransiente()

void CSimuladorCurvasIPR::RegimePseudoPermanente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; // numero de medidas de vazao a serem feitas
    
    // Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             // Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            // Armazena queda de pressao      
        
        // Vazão considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) - (3./4.) + skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        // Vazão considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) - (3./4.)));;
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    // Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); // Número de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   // encerra RegimePseudoPermanente()

void CSimuladorCurvasIPR::RegimePermanente(){
 
    int num_medidas = (reservatorio.Pi() - poco.Pwf()) / poco.DeltaP() ; // numero de medidas de vazao a serem feitas
    
    // Limpeza dos vetores
    pressaoPoco.clear();
    vazaoPocoSkin.clear();
    vazaoPocoNullSkin.clear();
    
    for (int i = 0; i <= num_medidas; i++){
        
        pressao = reservatorio.Pi() - i*poco.DeltaP();             // Queda de pressao medida no poco
        
        pressaoPoco.push_back(pressao);                            // Armazena queda de pressao      
        
        // Vazão considerando skin
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw()) + skinTotal));
        
        vazaoPocoSkin.push_back(vazaoSkin);
        
        // Vazão considerando skin nulo
        vazaoSkin = (rocha.Kh()*reservatorio.H()*(reservatorio.Pi() - pressaoPoco[i]))/        (141.2*oleo.FVF()*oleo.Mi()*(log(reservatorio.Re()/poco.Rw())));;
        
        vazaoPocoNullSkin.push_back(vazaoSkin);
    };
    
    // Retorna medidas na tela
    cout << endl;
    cout << linha << endl;
    cout << setw(40) << right << "Pressao (psi)" << setw(40) << right << "Vazao com Skin (STB/day)" << setw(40) << right << "Vazao sem Skin (STB/day)" << endl;
    cout << linha << endl;
    
    cout.precision(4); // Número de algarismos significativos
    for (int i = 0; i <= num_medidas; i++){
        cout << setw(40) << right << pressaoPoco[i] << setw(40) << right << vazaoPocoSkin[i] << setw(40) << right << vazaoPocoNullSkin[i] << endl;
    };
    cout << linha;
    
}   // encerra RegimePermanente()

// Método que retorna o tempo limite para o regime transiente
double CSimuladorCurvasIPR::TPSS(double _phi, double _mi, double _ct,double _re,double _kh){
    tpss = (1200*_phi*_mi*_ct*pow(_re,2))/_kh;
    return tpss;
}   // encerra TPSS

// Método que retorna o cálculo do skin total
double CSimuladorCurvasIPR::SkinTotal(){
   
    // Skin de dano
    danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs());
    
    
    // Skin por canhoneio parcial
    canhoneioSkin.HPD(reservatorio.HP(),reservatorio.H());
    canhoneioSkin.H1D(reservatorio.H1(),reservatorio.H());
    canhoneioSkin.RD(poco.Rw(),reservatorio.H(),rocha.Kv(),rocha.Kh());
    canhoneioSkin.A();
    canhoneioSkin.B();
    canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh());
    
    // Skin por desvio do poco
    desvioSkin.Beta(rocha.Kv(),rocha.Kh());
    poco.Extensao(reservatorio.H());
    desvioSkin.Gamma(reservatorio.H(),poco.Extensao(reservatorio.H()));
    desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
    
    // Skin total
    skinTotal = danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs())+ canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh()) + desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
        
    cout << endl << linha << "\n Cálculo dos efeitos de pelí­cula" << endl << linha;
    cout << "\n Efeito de pelí­cula por dano à permeabilidade nas proximidades do poço: " << danoSkin.Skin(rocha.Kh(),rocha.Ks(),poco.Rw(), poco.Rs());
    cout << "\n Efeito de película causado por completação parcial do reservatório: " << canhoneioSkin.Skin(poco.Rw(),reservatorio.H(),reservatorio.HP(),rocha.Kv(),rocha.Kh());
    cout << "\n Efeito de película causado pela inclinação do poço: " << desvioSkin.Skin(poco.Rw(),reservatorio.H(),poco.Extensao(reservatorio.H()));
    cout << "\n Efeito de película total: " << skinTotal;
    
    if (skinTotal > 0){
      cout << "\n Efeito de pelí­cula resultante causa dano à formação (skin total positivo)." << endl;  
    }
    else{
      cout << "\n Efeito de pelí­cula resultante causa estimulo à formação (skin total negativo)." << endl;  
    }
    
    cout << "\n Pressione ENTER para continuar";
    cin.get();
    
    return skinTotal;
}   // encerra SkinTotal

