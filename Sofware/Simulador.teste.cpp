/* Implementa��o da fun��o main() */

//Inclus�o de bibliotecas
#include<string>
#include<vector>
#include<cmath>

// Inclus�o das demais classes
#include "CSimuladorCurvasIPR.h"

int main (){
    
    CSimuladorCurvasIPR simulador;  // Objeto da classe CSimuladorCurvasIPR
    
    // Primeiro acesso ao rodar o software
    simulador.Header();
    simulador.Menu();
    
    short int opcaoMenu{1};
    
    while (opcaoMenu == 1){
    cout << "\n Deseja retornar ao Menu Inicial?";
    cout << "\n Digite 1 para SIM";
    cout << "\n Digite 2 para N�O";
    cout << "\n Op��o desejada: ";
    cin >> opcaoMenu; 
    cin.get();
    if (opcaoMenu == 1){simulador.Menu();}
    cout << endl;
    }
    return 0;
}  // Fim da fun��o main()
