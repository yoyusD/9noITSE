//============================================================================
// Name        : metadato.cpp
// Author      : alex
// Version     :
// Copyright   : Your copyright notice
// Description : Juzgados Metadatos
//============================================================================
//============================================================================
//Indentificaci'on del expediente ejemplo: 20, 40, 62, 67
//Tipo de expediente civil, penal, administrativo, laboral, etc
//Juridicci'on federal, estatal, municipal, internacional
//Juzgado o tribunal asignado: Juzgados Civiles, Federales, Familiares, Judiciales
//recursos interpuestos: amparos, apelaci'on, nulidad, revocaci'on
//============================================================================

//===============Libraries====================================================
#include <iostream> //cout cin << >>
#include <string> // string
#include <cassert> // assert()
#include <cctype> // isdigit()
#include <vector> // vector<>
#include <random>
using namespace std;
//=============================================================================

string info_del_expediente(char x, char y);

int main(){

    int opc,id=0;
    string expediente,validCharC = "IEDA", validCharE = "ESUN",
    	   validCharF = "CFAU", validCharA = "MPUE";
    vector<string> exp_almacenado;
    bool isValid;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 50000); //Random numbers for id


    for(;;){ //Infinite loop
    cout << "=========================================================="
		 << "\n\t         JUZGADOS DE LA CIUDAD DE MEXICO               \n"
		 << "==========================================================\n"
		 << "Introduce una opción \n (1) para crear un expediente \n "
		 << "(2) para buscar expediente \n (3) para salir del programa \n Opcion: ";
    cin >> opc;

    assert(opc == 1 || opc == 2 || opc == 3); //if the condition isn't true, the program will be close.


//--------------------First option-----------------------------//
    if (opc==1){
    cout<< "=========================================================="
	    << "\n\t         CREACION DE EXPEDIENTE               \n"
		<< "==========================================================\n"
        << "Selecciona el tipo de expedinte que quieres crear \n"
        << "en base a los siguientes datos: \n\n"
        << "No. Indentificación del expediente: ## \n"
        << "\t\tTipo de expediente: \nCivil (CI), Penal (CE), Administrativo (CD) o Laboral (CA) \n\n"
        << "\t\tJuridicción: \nFederal (EE), Estatal (ES), Municipal (EU), Internacional (EN) \n\n"
        << "\t\tJuzgados: \nCiviles (FC), Federales (FF), Familiares (FA), Judiciales (FU) \n\n"
        << "\t\tRecurso interpuesto: \nAmparo (AM), Apelación (AP), Nulidad (AU), Revocación (AE) \n\n"
        <<  "Formato de ejemplo : 10CIEEFCAM \n" << "Introduce los datos: ";

    while(1){ //infinite loop to avoid errors
    	cin  >> expediente;

    	isValid = true;

    	    if(!(isdigit(expediente[0]) && isdigit(expediente[1]))){
    	    	cout <<"\n **Introduce un número de indentificación valido**\n";
    	    	isValid = false;
    	    }
    	    if(!((expediente[2] == 'C') && (validCharC.find(expediente[3]) != std::string::npos))){
    	    	cout <<"\n **Introduce un Tipo de expediente valido**\n";
    	    	isValid = false;
    	    }

    	    if(!((expediente[4] == 'E') && (validCharE.find(expediente[5]) != std::string::npos))){
    	    	cout <<"\n **Introduce una Juridicción valida**\n";
    	    	isValid = false;
    	    }
    	    if(!((expediente[6] == 'F') && (validCharF.find(expediente[7]) != std::string::npos))){
    	    	cout <<"\n **Introduce un Juzgado valido**\n";
    	    	isValid = false;
    	    }
    	    if(!((expediente[8] == 'A') && (validCharA.find(expediente[9]) != std::string::npos))){
    	    	cout <<"\n **Introduce un Recurso interpuesto valido**\n";
    	    	isValid = false;
    	    }

    	    else if(isValid){ //Here, there are not errors
    	    	break;
    	    }

    	    cout << " \n **No dejes espacios en blanco \n"
    	         <<  "\nFormato de ejemplo : 10CIEEFCAM \n" << "Introduce los datos: ";
    }

    cout << "\n==========================================================\n"
    	 << "==========================================================\n"
		 << "Su expediente a sido creado con los siguientes datos \n"
		 << "==========================================================\n"
		 << " Clave: " << expediente
		 << " \nID: " << id // we cannot choose our ID
		 << "\n=========================================================="
         << " \n Numero de expediente: " << expediente[0] << expediente[1]
         << " \n Tipo de expediente:   " << info_del_expediente(expediente[2], expediente[3])
         << " \n Juridiccion:          " << info_del_expediente(expediente[4], expediente[5])
         << " \n Juzgado:              " << info_del_expediente(expediente[6], expediente[7])
         << " \n Recurso interpuesto:  " << info_del_expediente(expediente[8], expediente[9])
		 << "\n=========================================================="
		 << "\n\n\n";

   exp_almacenado.push_back(expediente); //Storage each file
   id++;
    }


//------------------------Second option-----------------------//
    	else if (opc == 2){
    	cout<< "=========================================================="
    	    << "\n\t         CONSULTA DE EXPEDIENTE               \n"
    		<< "==========================================================\n"
			<< "Introduce el ID del expediente que deseas consultar\n"
    		<< "ID = ";

    		cin >> id;

    	expediente = exp_almacenado[id]; //Recover the ID file
    	cout<< "\n=========================================================="
    	    << "\n\t         SU EXPEDIENTE ES EL SIGUIENTE               \n"
    	    << "==========================================================\n"
			<< "==========================================================\n"
			<< " Clave: " << expediente
			<< " ID: " << id
			<< "\n=========================================================="
			<< " \n Numero de expediente: " << expediente[0] << expediente[1]
		    << " \n Tipo de expediente:   " << info_del_expediente(expediente[2], expediente[3])
		    << " \n Juridiccion:          " << info_del_expediente(expediente[4], expediente[5])
		    << " \n Juzgado:              " << info_del_expediente(expediente[6], expediente[7])
			<< " \n Recurso interpuesto:  " << info_del_expediente(expediente[8], expediente[9])
		    << "\n==========================================================\n";
		}



//-------------------------Third option----------------------//
    	else if(opc == 3){
    		cout << "\n ===Programa terminado===" ;
    		break; //End of the loop
		}
    }
    return 0;
}

string info_del_expediente(char x,char y){ //Function to get a string
			switch(x){
			case 'C': switch(y){
			case 'I': return "Civil"; //CI
		    case 'E': return "Penal"; //CE
		    case 'D': return "Administrativo"; //CD
		    case 'A': return "Laboral"; //CA
			}
			break;
			case 'E': switch(y){
			case 'E': return "Federal"; //EE
		    case 'S': return "Estatal"; //ES
			case 'U': return "Municipal"; //EU
		    case 'N': return "Internacional"; //EN
			}
			break;
			case 'F': switch(y){
			case 'C': return "Civiles"; //FC
		    case 'F': return "Federales"; //FF
		    case 'A': return "Familiares"; //FA
		    case 'U': return "Judiciales"; //FU
			}
			break;
			case 'A': switch(y){
			case 'M': return "Amparo"; //AM
		    case 'P': return "Apelación"; //AP
		    case 'U': return "Nulidad"; //AU
		    case 'E': return "Revocación"; //AE
			}
			break;
			default: return "Valor desconocido";
		}
			return "";
}
