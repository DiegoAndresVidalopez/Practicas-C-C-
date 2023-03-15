Algoritmo punto2
	n,i,s,a1,a2,a3 Son Enteros
	
	Repetir
		Escribir 'Digite n'
		Leer n
	Hasta Que n>0
	
	i<-1 
	s<-1 
	a1<-1 
	a2<-1 
	a3<-1 
	Repetir
		
		Si i=1 | i=2 Entonces
			Escribir s
		Sino 
			
			Si s MOD 2 = 0 Entonces 
				s<-a1+a2+a3
			Sino                    
				s<-a2+a3			   
			Fin Si
			Escribir s 			
			a1<-a2				
			a2<-a3
			a3<-s
		Fin Si
		i<-i+1 
	Mientras Que i<=n

FinAlgoritmo
