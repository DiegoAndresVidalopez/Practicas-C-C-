
#include <iostream>
#include <stdio.h>
#include <string>
#define nf 20
using namespace std;


struct fecha {
	int dd,mm,yyyy;
};
struct empleado {
	int cedula;
	string nombres;
	double salario;
};
struct departamento{
	int idDepartamento;
	string nombre;
	empleado empleados[nf];
	int Cempleados;
};
struct sede{
	int idsede;
	string nombre;
	double telefono;
	int ndepartamentos;
	fecha creacion;
	string direccion;
	departamento departamentos[nf];
};

void llenar( sede v[], int n){
	int dia, mes;
	for (int i=0; i<n; i++){
		cout<<"DIGITE DATOS DE LA SEDE: ["<<i+1<<"] "<<endl;
		cout<<"INGRESE EL CODIGO DE LA SEDE: " ;
		cin>>v[i].idsede;
		cout<<"INGRESE EL NOBRE DE LA SEDE: " ;
		cin>>v[i].nombre;
		cout<<"INGRESE EL NUMERO TELEFONICO DE LA SEDE: " ;
		cin>>v[i].telefono;
		cout<<"INGRESE FECHA CREACION:"<<endl;
		cout<<" DIGITE EL DIA: ";
		cin>> dia;
		while(dia<=0 || dia>31){
			cout<<"ERROR! DIGITE CORRECTAMENTE EL DIA";
			cin>>dia;
		}
		v[i].creacion.dd=dia;
		cout<<"DIGITE EL MES:";
		cin>>mes;
		while(mes<=0 || mes>12){
			cout<<"ERROR! DIGITE CORRECTAMENTE EL MES";
			cin>>mes;
		}
		v[i].creacion.mm=mes;
		cout<<"DIGITE EL AÑO:";
		cin>>v[i].creacion.yyyy;
		
		cout<<"DIGITE EL NUMERO DE DEPARTAMENTOS QUE DESEA INGRESAR:";
		
		cin>>v[i].ndepartamentos;
		for(int j=0; j<v[i].ndepartamentos;j++){
			
			cout<<"INGRESE LOS DATOS DEL DEPARTAMENTO: ["<<j+1<<"] "<<endl;
			cout<<"INGRES EL CODIGO DEL DEPARTAMENTO:";
			cin>>v[i].departamentos[j].idDepartamento;
			cout<<"INGRESE EL NOMBRE DEL DEPARTAMENTO:";
			cin>>v[i].departamentos[j].nombre;
			
			cout<<"INGRESE EL NUMERO DE EMPLEADOS DEL DEPARTAMENTO:";
			cin>>v[i].departamentos[j].Cempleados;
			for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
				cout<<"INGRESE LOS DATOS: ["<<k+1<<"]"<<endl;
				cout<<"INGRESE LA CEDULA DEL EMPLEADO:";
				cin>> v[i].departamentos[j].empleados[k].cedula;
				cout<<"INGRESE NOMBRE EMPLEADO:";
				cin>>v[i].departamentos[j].empleados[k].nombres;
				cout<<"INGRESE SALARIO DEL EMPLEADO:" ;
				cin>>v[i].departamentos[j].empleados[k].salario;
			}
		}
		
	}
}

void imprimir(sede v[],int n){
	for (int i=0; i<n; i++){
		cout<<"CODIGO SEDE:";
		cout<<v[i].idsede<<endl;
		cout<<"NOMBRE SEDE";
		cout<<v[i].nombre<<endl;
		cout<<"TELEFONO SEDE:";
		printf("%.0f", v[i].telefono);
		cout<<endl<<"FECHA CREACION:";
		cout<<v[i].creacion.dd<<"/"<<v[i].creacion.mm<<"/"<<v[i].creacion.yyyy<<endl;
		
		for(int j=0; j<v[i].ndepartamentos;j++){
			cout<<"CODIGO DEPARTAMENTO:";
			cout<<v[i].departamentos[j].idDepartamento<<endl;
			cout<<"NOMBRE DEPARTAMENTO:";
			cout<<v[i].departamentos[j].nombre<<endl;
			
			for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
				cout<<"CEDULA EMPLEADO:";
				cout<< v[i].departamentos[j].empleados[k].cedula<<endl;
				cout<<"NOMBRE EMPLEADO:";
				cout<<v[i].departamentos[j].empleados[k].nombres<<endl;
				cout<<"SALARIO EMPLEADO:";
				printf("%.2f",v[i].departamentos[j].empleados[k].salario);
				cout<<endl;
			}
		}
		
	}
}
	
void imprimirT( sede v[], int n, int departamento, int sed ){
	for(int i=0;i<n;i++){
		if(sed == v[i].idsede){
			for(int j=0; j<v[i].ndepartamentos;j++){
				if(departamento == v[i].departamentos[j].idDepartamento){
					cout<<"sede: ";
					cout<<v[i].nombre<<endl;
					for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
						cout<<"cedula del empleado: " ;
						cout<< v[i].departamentos[j].empleados[k].cedula<<endl;
						cout<<"nombre del empleado: " ;
						cout<<v[i].departamentos[j].empleados[k].nombres<<endl;
						cout<<"salario del empleado: " ;
						printf("%.2f",v[i].departamentos[j].empleados[k].salario);
						cout<<endl;
					}
					
				}
			}
			
		}
	}
}
double buscarSM( sede v[],int n,int sede){
	double aux;
	double s= v[0].departamentos[0].empleados[0].salario;
	for(int i=0;i<n;i++){
		if(sede==v[i].idsede){
			for(int j=0; j<v[i].ndepartamentos;j++){
				for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
					aux= v[i].departamentos[j].empleados[k].salario;
					if(s<aux){
						s=aux;
					}
				}
				
			}
		}
	}	
	return s;
}

void imprimirSM(sede v[], int n, int sede){
	double SM= buscarSM(v,n,sede);
	for(int i=0;i<n;i++){
		if(sede==v[i].idsede){
			for(int j=0; j<v[i].ndepartamentos;j++){
				for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
					if(SM=v[i].departamentos[j].empleados[k].salario){
						cout<<"cedula del empleado: " ;
						cout<< v[i].departamentos[j].empleados[k].cedula<<endl;
						cout<<"nombre del empleado: " ;
						cout<<v[i].departamentos[j].empleados[k].nombres<<endl;
						cout<<"salario del empleado: " ;
						
						printf("%.2f",v[i].departamentos[j].empleados[k].salario);
						cout<<endl;
					}
				}
			}
		}
	}	
	
}
double nomina( sede v[], int n){
	double salarioT=0;
	for(int i=0;i<n;i++){
			for(int j=0; j<v[i].ndepartamentos;j++){
				for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
					salarioT= salarioT + v[i].departamentos[j].empleados[k].salario;
				}
			}
	}
	return salarioT;
}

void buscarE( sede v[], int n, int cod){
	for(int i=0;i<n;i++){
		for(int j=0; j<v[i].ndepartamentos;j++){
			for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
				if(cod==v[i].departamentos[j].empleados[k].cedula){
					cout<<"nombre del empleado: ";
					cout<<v[i].departamentos[j].empleados[k].nombres<<endl;
					cout<<"salario del empleado: " ;
					printf("%.2f",v[i].departamentos[j].empleados[k].salario);
					cout<<endl;
					cout<<"sede: ";
					cout<<v[i].nombre<<endl;
					cout<<"departamento: ";
					cout<<v[i].departamentos[j].nombre<<endl;
				}
			}
		}
	}	
}

bool validarsede( sede v[], int n, int sede){
	bool c=false;
	for(int i=0; i<n; i++){
		if(sede==v[i].idsede){
			c= true;
			
		}
	}
	return c;
}
	
bool validardept( sede v[], int n, int dept){
	bool c=false;
	for(int i=0; i<n; i++){
		for(int j=0; j<v[i].ndepartamentos;j++){
		   if(dept==v[i].departamentos[j].idDepartamento){
			c=true;
			
			}
		}	
	}
	return c;
}
bool validarEmpleado(sede v[], int n, int ced){
	bool c=false;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<v[i].ndepartamentos;j++){
		  for(int k=0; k<v[i].departamentos[j].Cempleados;k++){
		  	if(ced==v[i].departamentos[j].empleados[k].cedula){
		  	c=true;	
			}
		  }
		}	
	}
	return c;
}	

int main(int argc, char *argv[]) {
	int cantsedes, menu, dept, sede1, sede2,codE;
	double nomin;
	
	do{
		cout<<"digite cantidad de sedes: ";
		cin>>cantsedes;
	} while(cantsedes<=0);
	
	sede sedes[cantsedes];

	
	llenar(sedes,cantsedes);
	do{
		cout<<"digite la operacion que desea realizar:"<<endl;
		cout<<"1.Mostrar datos"<<endl;
		cout<<"2.Buscar empleados por sede y departamento"<<endl;
		cout<<"3.Buscar empleados que tengan el mayor sueldo"<<endl;
		cout<<"4.Consultar nomina total"<<endl;
		cout<<"5.Buscar informacion de un empleado"<<endl;
		cout<<"6.Salir: "<<endl;
		cin>>menu;
		
	   switch(menu){
	   case 1:
		   imprimir(sedes,cantsedes);
		break;
	   case 2:
		   cout<<"digite codigo de la sede en la cual quiere buscar: ";
		   cin>>sede1;
		   if(validarsede(sedes,cantsedes,sede1)==true){
		   		cout<<"digite codigo del departamento en el cual quiere buscar: ";
		   	     cin>>dept;
		   		if(validardept(sedes,cantsedes,dept)==true){
		   
		   		imprimirT(sedes,cantsedes,dept,sede1);
				}else{
					cout<<"no se encuentra el departamento";
				}
			}else{
				cout<<"no se encuentra la sede";
			}
		break;
	   case 3:
		   cout<<"digite codigo de la sede en la cual quiere buscar: ";
		   cin>>sede2;
		   if(validarsede(sedes,cantsedes,sede2)==true){
		   imprimirSM(sedes,cantsedes,sede2);
			}else{
				cout<<"no se encuentra la sede";
			}
		break;
	   case 4:
		   cout<<"la nomina total es: ";
		   nomin=nomina(sedes,cantsedes);
		   printf("%.2f",nomin);
		   cout<<endl;
		break;
	   case 5:
		   cout<<"digite cedula del empleado que quiere buscar"<<endl;
		   cin>> codE; 
		   if(validarEmpleado(sedes,cantsedes,codE)){
		   		buscarE(sedes,cantsedes,codE);
		   }else{
		   		cout<<"No se ha encontrado el empleado con cedula: "<<codE;
		   }
		   
		   
		break;
	   case 6:
		   exit (0);
		break; 
	   }
		
	}while(menu!=6);
	
	return 0;
}


