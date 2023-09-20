#include<iostream>
using namespace std;
struct Programador{
	char nombre[50];
	char puesto[80];
	int anyosExp;
	char area[80];
	double bono;
};
void Menu(int *&opc);
void IngresarDatos();
void Reporte();
int main(){
	int *op = new int;
	do{
		Menu(op);
		switch(*op){
			case 1:{
				IngresarDatos();
			}break;
			case 2:{
				Reporte();	
			}break;
			case 3:{
				cout<<"Gracias.......Vuelva pronto"<<endl;
			}break;
		}
	}while(*op!=3);
	delete op;
	return 0;
}
void Menu(int *&opc){
	do{
		cout<<"===== MENU ====="<<endl;
		cout<<"1. Ingresar Datos"<<endl;
		cout<<"2. Reporte"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Ingrese opcion"<<endl;
		cin>>*opc;
		if(*opc<1 || *opc>3)
			cout<<"Error.......Volver a ingresar"<<endl;
	}while(*opc<1 || *opc>3);
	return;
}
void IngresarDatos(){
	Programador *pro = new Programador[10];
	cout<<"===== INGRESAR DATOS ====="<<endl;
	for(int i=0;i<10;i++){
		cout<<i+1<<".- Ingrese nombre: ";
		cin.get();
		cin.getline(pro[i].nombre,50);
		cout<<i+1<<".- Ingrese puesto: ";
		cin.get();
		cin.getline(pro[i].puesto,80);
		cout<<i+1<<".- Ingrese Área de Trabajo: ";
		cin.get();
		cin.getline(pro[i].puesto,80);
		do{
			cout<<i+1<<".- Ingrese años de trabajo: ";
			cin>>pro[i].anyosExp;
			if(pro[i].anyosExp<0)
				cout<<"Error.....Vuelva a ingresar"<<endl;
		}while(pro[i].anyosExp<0);
		if(pro[i].anyosExp>5)
			pro[i].bono = 200;
		else{
			if(pro[i].anyosExp>=1)
				pro[i].bono = 100;
			else
				pro[i].bono = 0;
		}
	}
	delete [] pro;
	return;
}
void Reporte(){
	Programador *pro = new Programador[10];
	int cantConBono = 0;
	int cantSinBono = 0;
	double importeTotalBono = 0;
	for(int i=0;i<10;i++){
		if(pro[i].bono>0){
			cantConBono++;
			importeTotalBono += pro[i].bono;
		}
		else
			cantSinBono++;
	}
	cout<<"Total Cantidad de Programadores sin Bono: "<<cantSinBono<<endl;
	cout<<"Total Cantidad de Programadores con Bono: "<<cantConBono<<endl;
	cout<<"Importe Total de los Bonos: "<<importeTotalBono<<endl;
	delete [] pro;
	return;
}