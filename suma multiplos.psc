Algoritmo multiplos
	Definir cont,mult,n,s Como Entero
	cont<-2
	n<-462/7
	s<-0
	Mientras  cont<=n Hacer
		mult<-7*cont
		Si mult <203 O mult>301 Entonces
			s<-(s+mult)
		FinSi
		cont<-cont+1
	FinMientras
	Escribir 'la suma es:', s
FinAlgoritmo