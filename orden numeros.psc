Algoritmo orden
	escribir "Introduce 3 Numero";
	leer num1; leer num2; leer num3;
	si num1>num2 y num1>num3 Entonces
		escribir num1;
		si num2>num3 Entonces
			escribir num2;
			escribir num3;
		Sino
			escribir num3;
			escribir  num2;
		FinSi
	sino 
		si num2>num1 y num2>num3 entonces
			escribir num2;
			si num1>num3 Entonces
				escribir num1;
				escribir num3;
			Sino
				escribir num3;
				escribir num1;
			FinSi
		Sino
			escribir num3;
			si num1>num2 Entonces
				escribir num1;
				escribir num2;
			Sino
				escribir num2;
				escribir num1;
			FinSi
		FinSi
	finsi
FinAlgoritmo
