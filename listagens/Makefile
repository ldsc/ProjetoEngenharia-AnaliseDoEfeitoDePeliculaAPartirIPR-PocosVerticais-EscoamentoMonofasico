# Arquivo makefile

all: simulador teste

simulador:
	g++ -std=c++11 -c CSimuladorCurvasIPR.cpp
	g++ -std=c++11 -c CGnuplot.cpp
	g++ -std=c++11 -c CSkinCanhoneio.cpp
	g++ -std=c++11 -c CSkinDesvio.cpp	
	ar -cru libSimuladorCurvasIPR.a CSimuladorCurvasIPR.o CGnuplot.o CSkinCanhoneio.o CSkinDesvio.o

teste: simulador
	g++ -std=c++11 Simulador.teste.cpp libSimuladorCurvasIPR.a -o Simulador.teste

clean:
	rm *.o *.a Simulador.teste

help :
#========= Sistema Simulador de Curvas IPR =========
# A classe CSimuladorCurvasIPR representa a simulação de curvas IPR
# A classe CSkinCanhoneio representa o conceito de skin causado por canhoneio parcial
# A classe CSkinDesvio representa o conceito de skin causado pela inclinação do poço
#
# Uso do make :
# all : compila todos os arquivos
# simulador : compila arquivos da hierarquia CSimuladorCurvasIPR e gera libSimuladorCurvasIPR.a
# teste : compila arquivo Simulador.teste.cpp anexa as libs e gera executável Simulador.teste
# clean : apaga arquivos ( rm *. o *. a Simulador.teste )
# help : mostra esta ajuda
