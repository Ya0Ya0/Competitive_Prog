#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>


#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

using namespace std;



//Funciones Usadas
void gotoxy(int x, int y);
void Date_Wish();
void youLoose1();
void sofia();
void sofiadudosa();
void sofiaAmor();
void sofiaEnojada();
void sofiahermosadudosa();
void sofiahermosa();
void sofiahermosaEnojada();
void caminando();
void camion();
void danielySofia();
void danieltriste();
void daniel();

//Menus
int menu_creador(const char *titulo, const char *opciones[], int n, string parrafo, int print);
int alaEscuela(string parrafo);
int darTarea(string parrafo);
int noTarea(string parrafo);
int bromita(string parrafo);
int responder(string parrafo);
int eleccion(string parrafo);


//Menus 2da parte
int preparacion(string parrafo);
int preparacion2(string parrafo);
int aguacate(string parrafo);
int buenaRespuesta(string parrafo);
int camion(string parrafo);
int confesion(string parrafo);
int disparar(string parrafo);


//Carteles 1ra Parte
void cartel_creador(char parrafo[], int cantLineas);
string cartel1();
string cartel2();
string cartel3();
string cartel4(int bela);
string cartel5();
string cartel6(int bela);
string cartel7(int bela);
string cartel8(int bela);
string cartel9(int bela);
string cartel10();

//Carteles 2da Parte
string cartel11();
string cartel12();
string cartel13();
string cartel14();
string cartel15();
string cartel16();
string cartel17();
string cartel18();

int main()
{




    //Variables a Usar
    string Nada = "Nada";
    int contador = 0;
    int final = 0;
    int contadorAux = 0;
    int pistola = 0;
    int tobillo = 0;
    int matacion = 20;


    //Estadisticas
    int cantAmor = 0;
    int cantAmistad = 0;
    int cantOdio = 0;
    int motivacion = 3;

    //Objetos

    Date_Wish();

    system("cls");

    cartel1();
    cartel2();

    daniel();
    cartel3();

    system("cls");
    cartel_creador("\t\t<<COMO JUGAR>>\n\n\t1) Para moverte entre las decisiones usa las flechas del teclado\n\t2) Para elegir o saltar presiona <ENTER>\n\n\n\n\n",15);

    switch(alaEscuela(Nada)){

    case 1:

        contador = 1;
        break;

    case 2:
        cantAmor++;
        contador = 2;
        break;

    case 3:
        contador = 3;
        break;

    case 4:
        motivacion--;
        contador = 4;
        break;
    }

    contadorAux = contador;

    if(contador != 4){
        cartel4(1);

        cartel6(1);
        if(contador == 1){
            switch(darTarea(Nada)){

            case 1:
                cantAmor++;
                cantAmistad++;
                contador = 1;
                break;

            case 2:
                cantOdio++;
                contador = 2;
                break;

            case 3:
                cantAmistad++;
                contador = 3;
                break;

            }
        } else {
            switch(noTarea(Nada)){

            case 1:
                cantOdio++;
                contador = 2;
                break;

            case 2:
                cantAmistad++;
                contador = 3;
                break;

            }
        }

        if(contadorAux == 3){
            cantAmistad++;
            system("cls");
            sofiaAmor();
            cartel_creador("\tLe das el ramo de margaritas a Sofia\n\t--Awww es muy tierno de tu parte, soy afortunada de tener un amigo como tu", 2);
        }

        if(contadorAux == 2){

            switch(bromita(cartel7(1))){
            case 1:
                motivacion--;
                contador = 2;
                break;

            case 2:
                break;
            }
        }

        cartel8(1);
        switch(responder(Nada)){
        case 1:
            motivacion--;
            contador = 2;
            break;

        case 2:
            cantAmistad++;
            contador = 2;
            break;

        case 3:
            cantAmor++;
            contador = 3;
            break;

        }


    } else {
        cartel5();
        cartel9(0);
        switch(eleccion(Nada)){
        case 1:
            motivacion - 10;
            system("cls");
            cartel_creador("\tEscogiste el camino facil, el camino del fracaso\n\tPasas el resto de tu vida jugando al lol y viendo como Sofia es feliz con otro...\n\tHay mejores finales, vuelve a jugar",15);
            return(0);
            contador = 2;
            break;

        case 2:
            cartel10();
            contador = 2;
            break;
        }
    }

    //PARTE 2

    system("cls");
    cartel11();
    contadorAux = preparacion(Nada);


    system("cls");
    switch(preparacion2(cartel12())){
    case 1:
        pistola = 1;
        contador = 1;
        break;

    case 2:
        contador = 2;
        break;
    }

    system("cls");
    cartel13();

    tobillo = contadorAux;

    system("cls");
    if(contadorAux == 2){
        aguacate(cartel14());
        cantOdio++;
        system("cls");
        cartel15();
    }

    if(contadorAux == 1){
        switch(buenaRespuesta(cartel14())){
        case 1:
            cantOdio++;
            break;

        case 2:
            cantAmor++;
            break;

        case 3:
            cantAmistad++;
            break;
        }
    }

    caminando();
    cartel16();


    switch(camion(cartel17())){
    case 1:
        system("cls");
        cartel_creador("\tSofia Muere", 1);
        final = 1;
        break;

    case 2:
        system("cls");
        cartel_creador("\tTu mueres", 1);
        final = 8;
        break;

    case 3:
        if(contadorAux == 2){
            system("cls");
             cartel_creador("\tSin embargo, como tenias el tobillo mal no lo logras a tiempo y el camion te rompe las piernas", 1);
             system("cls");
             cartel_creador("\tSofia se asusta mucho pero esta bien. Al poco tiempo llaman a una ambulancia\n\t Ella espera junto a ti en el suelo", 2);
             switch(confesion(cartel18())){
             case 1:
                 if(pistola == 1){
                     system("cls");
                     cartel_creador("\tMaldita sea Sofia, me abandono luego de haberla salvado!!",1);
                     matacion = disparar(Nada);
                     switch(matacion){
                     case 1:
                     final = 12;
                     break;
                     case 2:
                         final = 7;
                         break;
                     case 3:

                         final = 8;
                         break;

                     }
                 }
                 break;
             case 2:
                 final = 7;
                 break;
             }
        }

        if(contadorAux == 1){
            cantAmor + 2;
            system("cls");
             cartel_creador("\tAmbos salen sanos y salvos, que alivio", 1);
             final = 5;

        }


        break;

    case 4:
        system("cls");
        cartel_creador("\tAmbos mueren", 1);
        final = 4;
        break;
    }

    if(final == 5){

        system("cls");
        cartel_creador("\tMas tarde en la fiesta te confiesas a Sofia",1);
        if(cantAmor > cantAmistad && cantAmor > cantOdio){
            system("cls");
            danielySofia();
            cartel_creador("\tSofia esta muy agradecida de que la hayas salvado. Confiesa que siempre te habia visto como un\n\tamigo, pero ultimamente no podia evitar sentirse atraida por ti\n\tERES GENIAL, Sofia y tu seran muy felices juntos!!",3);
        final = 8;
        } else{
            if(cantAmistad >= cantAmor && cantAmistad > cantOdio){
                system("cls");
                danieltriste();
                cartel_creador("\tSofia esta muy agradecida de que la hayas salvado\n\tSin embargo dice que siempre te ha visto como un amigo y no puede cambiar eso\n\ttLuego de eso se distancian un poco, no cumpliste tu mision\n\tTe costara mucho curarte de esa herida :(",3);
            final = 8;
            } else {
                if(cantOdio >= cantAmor && cantOdio >= cantAmistad){
                    system("cls");
                    danieltriste();
                    final = 8;
                    cartel_creador("\tSofia te culpa por lo que paso con el camion y de la forma que arriesgaron la vida\n\tConfiesa que siempre has sido su amigo pero ultimamente te has comportado como\n\tun verdadero tonto y jamas estaria contigo. Te sientes fatal y te preguntas...\n\tQue hiciste para merecer tal castigo\n",3);
                }

            }

        }

    }
    if(final == 7){
        system("cls");
        danieltriste();
cartel_creador("\tLa ambulancia no tarda mucho en llegar\n\tPasaste los siguientes meses en el hospital. Al parecer no volveras a caminar\n\tTe enteraste que ese mismo dia, Sofia llego a ir a la fiesta incluso despues del accidente\n\tAl parecer tu mejo amigo se le confeso esa noche y comenzaron a salir. No te sientas traicionado\n\tA el tampoco le contaste nada hacerca de tus sentimientos hacia Sofia. Al menos eres muy\n\tbueno guardando secretos. Ahora eres el amigo Steve de su relacion", 3);
    }

    if(final == 12){
    system("cls");
    danieltriste();
cartel_creador("\tLa ambulancia no tarda mucho en llegar\n\tPasaste los siguientes meses en el hospital. Al parecer no volveras a caminar\n\tY no solo eso, al haber matado a Sofia terminaste en la carcel con una condena de 13 anos y un corazon roto.\n\tJamas superaste a Sofia", 3);
}
    system("cls");

        if(final == 1 || final == 2){
        system("cls");
        danieltriste();
        cartel_creador("\tNunca lograste superar la perdida, terminaste siendo un solteron y jugador profesional del lol", 3);
    }
    if(motivacion <= 0){
        system("cls");
        danieltriste();
        cartel_creador("\tTe despiertas con tu alarma el 15 de febrero\n\tTodo fue un sueno, tu determinacion siempre fue demasiado baja para intentarlo\n\tVuelves a tu patetica vida para ver como Sofia es feliz con otro", 3);
    }

    system("color E5");
    if(final != 0){
        system("cls");
        cout << "\n\n\n\n\t\t\t<<ESTADISTICAS FINALES>>\n\t\t\t************************\n\t\t\tAmor: " << cantAmor << "\n\t\t\tAmistad: " << cantAmistad << "\n\t\t\tOdio: " << cantOdio << "\n\t\t\tDeterminacion: " << motivacion << "\n\n\n";
        system("pause");
        system("cls");
        cout << "\n\n\n\n\t\t\t\t< < FIN > >";
        cartel_creador("\n\n\t Llegaste al fin de la historia Yeiiii\n\tHay varios finales asi que puedes rejugar. Sea cual sea el que conseguiste, espero que te haya gustado y que\n\tnunca tengas que vivir lo mismo que el pobre Daniel\n\n\t\t\tCreditos: Melixsa G-13 UwU",15);


    }

    system("cls");
    system("color 07");
Date_Wish();

    return 0;
}


//Funciones Explicadas

void Date_Wish(){
    int tecla;

    cout << "\n\t\t*********      ******   ************* ***********                           ";
    cout << "\n\t\t**      **    **    **  ***   **   ** ***********                           ";
    cout << "\n\t\t**       **  **      **       **      **                                    ";
    cout << "\n\t\t**       **  **      **       **      **                                    ";
    cout << "\n\t\t**       **  **********       **      ******                                ";
    cout << "\n\t\t**       **  **********       **      *****                                 ";
    cout << "\n\t\t**       **  **      **       **      **                                    ";
    cout << "\n\t\t**       **  **      **       **      **       **                           ";
    cout << "\n\t\t**      **   **      **       **      ***      **                           ";
    cout << "\n\t\t*********   ***      **      ****     ***********                           ";
    cout << "\n\t\t                                                                            ";
    cout << "\n\t\t**          ** ************   ********  **       **                         ";
    cout << "\n\t\t**          ** **   **   **  **     *** **       **        ****   ****      ";
    cout << "\n\t\t**          **      **      **          **       **      **   ** **   **    ";
    cout << "\n\t\t**    **    **      **      **          ***********     **     ***     **   ";
    cout << "\n\t\t**    **    **      **       *******    ***********     **      **     **   ";
    cout << "\n\t\t**    **    **      **             ***  **       **     ***           ***   ";
    cout << "\n\t\t**    **    **      **               ** **       **       ***        **     ";
    cout << "\n\t\t **   **   **  **   **   **  **      ** **       **          **    **       ";
    cout << "\n\t\t  **********   ************   ********* **       **            *  *         ";
    cout << "\n\t\t                                                                *           ";

    do{
        for(int i = 0; i <= 21; i++){
            if(kbhit()){
                tecla = _getch();
                if(tecla){
                    i=30;
                    continue;
                }
            }


            usleep(200000);
            switch (i){
            case 1:
                cout << "\n\t\t*********      ******   ************* ***********                           ";
                break;

            case 2:
                cout << "\n\t\t**      **    **    **  ***   **   ** ***********                           ";
                break;

            case 3:
                cout << "\n\t\t**       **  **      **       **      **                                    ";
                break;

            case 4:
                cout << "\n\t\t**       **  **      **       **      **                                    ";
                break;

            case 5:
                cout << "\n\t\t**       **  **********       **      ******                                ";
                break;

            case 6:
                cout << "\n\t\t**       **  **********       **      *****                                 ";
                break;

            case 7:
                cout << "\n\t\t**       **  **      **       **      **                                    ";
                break;

            case 8:
                cout << "\n\t\t**       **  **      **       **      **       **                           ";
                break;

            case 9:
                cout << "\n\t\t**      **   **      **       **      ***      **                           ";
                break;

            case 10:
                cout << "\n\t\t*********   ***      **      ****     ***********                           ";
                break;

            case 11:
                cout << "\n\t\t                                                                            ";
                break;

            case 12:
                cout << "\n\t\t**          ** ************   ********  **       **                         ";
                break;

            case 13:
                cout << "\n\t\t**          ** **   **   **  **     *** **       **        ****   ****      ";
                break;

            case 14:
                cout << "\n\t\t**          **      **      **          **       **      **   ** **   **    ";
                break;

            case 15:
                cout << "\n\t\t**    **    **      **      **          ***********     **     ***     **   ";
                break;

            case 16:
                cout << "\n\t\t**    **    **      **       *******    ***********     **      **     **   ";
                break;

            case 17:
                cout << "\n\t\t**    **    **      **             ***  **       **     ***           ***   ";
                break;

            case 18:
                cout << "\n\t\t**    **    **      **               ** **       **       ***        **     ";
                break;

            case 19:
                cout << "\n\t\t **   **   **  **   **   **  **      ** **       **          **    **       ";
                break;

            case 20:
                cout << "\n\t\t  **********   ************   ********* **       **            *  *         ";
                break;

            case 21:
                cout << "\n\t\t                                                                *           ";
                break;

            }

        }
    }while(tecla == 0);
}

//Menus
int menu_creador(const char *titulo, const char *opciones[], int n, string parrafo, int print){

    int opcionSelect = 1;
    int tecla;
    bool repeticion = true;

    do{
        system("cls");
        if(print == 1){
            sofiadudosa();
        }
        if(print == 2){
            sofiaAmor();
        }
        if(print == 3){
            sofiaEnojada();
        }
        if(print == 4){
            sofiahermosadudosa();
        }
        if(print == 5){
            sofiahermosaEnojada();
        }
        if(print == 6){
            camion();
        }
        if(print == 7){
            daniel();
        }




        if(parrafo != "Nada"){
            gotoxy(5,18); cout << parrafo;
        }


        gotoxy(5,23 + opcionSelect); cout << "<3";

        gotoxy(15,22); cout << titulo;

        for(int i = 0; i<n; i++){
            gotoxy(10,24 + i); cout << i+1 << ") " << opciones[i] << endl;
        }

        do{
            tecla = _getch();
        }while(tecla != TECLA_ABAJO && tecla != TECLA_ARRIBA && tecla != ENTER);

        switch(tecla){

        case TECLA_ABAJO:
            opcionSelect++;
            if(opcionSelect > n){
                opcionSelect = 1;
            }

            break;
        case TECLA_ARRIBA:
            opcionSelect--;
            if(opcionSelect < 1){
                opcionSelect = n;
            }
            break;
        case ENTER:
            repeticion = false;
            break;
        }

    }while (repeticion == true);

    return opcionSelect;

}


int alaEscuela(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Elige que hacer antes de salir corriendo a la escuela>";
    const char *opciones[] = {"Terminar la tarea para hoy que no hiciste",
                              "Ponerte lo mas... presentable de lo que eres capaz",
                              "Tomar un ramo de flores del patio del vecino",
                              "No tomar desiciones desesperadas e ir con calma (No veras a Sofia)",};
    int n = 4;


    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 7);

        char parrafo1[] = "\tTerminas de hacer la tarea lo mas rapido posible, pierdes algo de tiempo. Por suerte no\n\tera tan dificil como esperabas.";
        char parrafo2[] = "\tHaces lo mejor que puedes para ponerte guapo con la esperanza de que Sofia lo note";
        char parrafo3[] = "\tNo lo habias descubierto hasta hoy pero tu vecino arto de ti ahora tiene un nuevo perro.\n\tSu nombre es princesa bolita de algodon y es GIGANTE, al instante de poner un pie en el jardin, sale\n\ty te persigue. Consigues llevarte unas margaritas pero estas hecho un desastre";
        char parrafo4[] = "\tHas pasado todos los dias de tu vida llegando temprano para verla\n\t...Este dia no iba a ser diferente de todos modos, por que esforzarse...?";

    switch(opcion){

    case 1:
        system("cls");
        cartel_creador(parrafo1, 3);
        repeticion = 3;

        break;

    case 2:
        system("cls");
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    case 3:
        system("cls");
        cartel_creador(parrafo3, 3);
        repeticion = 3;
        break;

    case 4:
        system("cls");
        cartel_creador(parrafo4, 3);
        repeticion = 3;
        break;
    }

    }while(repeticion == 1);
    return opcion;

}

int darTarea(string parrafo){
    int repeticion = 1;
    int opcion;

    sofiadudosa();
    const char *titulo = "<Que vas a hacer?>";
    const char *opciones[] = {"Dar la tarea",
                              "No hice la tarea",
                              "Feliz dia del amor para ti tambien (Evadir)",};
    int n = 3;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 1);

        char parrafo1[] = "\tEn cuanto le das la tarea una corriente de alivio recorre su rostro y te abraza\n\t--Gracias Juan, Siempre estas alli cuando lo necesito (^W^)";
        char parrafo2[] = "\t--Demonios! No importa, de todas maneras no eres tan listo. Mejor voy a preguntarle a alguien\n\tmas estudioso";
        char parrafo3[] = "\t--OOOoooh cierto! Se me olvidaba que dia era. Feliz dia del amor y la amistad, querido amigo\n\tLastima que no tenga nada para ti :(";

    switch(opcion){

    case 1:
        system("cls");
        sofiaAmor();
        cartel_creador(parrafo1, 3);
        repeticion = 3;

        break;

    case 2:
        system("cls");
        sofiaEnojada();
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    case 3:
        system("cls");
        sofia();
        cartel_creador(parrafo3, 3);
        repeticion = 3;
        break;

    }

    }while(repeticion == 1);
    return opcion;

}

int noTarea(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Que vas a hacer?>";
    const char *opciones[] = {"No hice la tarea",
                              "Feliz dia del amor para ti tambien (Evadir)",};
    int n = 2;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 1);

        char parrafo1[] = "\t--Demonios! No importa, de todas maneras no eres tan listo. Mejor voy a preguntarle a alguien\n\tmas estudioso";
        char parrafo2[] = "\t--OOOoooh cierto! Se me olvidaba que dia era. Feliz dia del amor y la amistad, querido amigo\n\tLastima que no tenga nada para ti :(";


    switch(opcion){

    case 1:
        system("cls");
        sofiaEnojada();
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        sofia();
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    }

    }while(repeticion == 1);
    return opcion;

}

int bromita(string parrafo){

    int opcion;

    const char *titulo = " ";
    const char *opciones[] = {"Jajaja... muy gracioso :')",
                              "Bueno... soobre eso queria hablarte...",};
    int n = 2;

        opcion = menu_creador(titulo, opciones, n, parrafo, 1);

    return opcion;

}

int responder(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Que vas a hacer?>";
    const char *opciones[] = {"No voy a ir",
                              "Claro que voy!",
                              "De hecho, podriamos ir juntos"};
    int n = 3;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 1);

        char parrafo1[] = "\t--Nonono. Vas a ir porque lo digo yo! Siempre estas solo, tu patetico ser tiene que cambiar\n\tPasame a buscar a las 8pm";
        char parrafo2[] = "\t--Genial, Desde que Brad y yo terminamos no tengo a nadie con quien ir y ya sabes lo\n\tpeligrosa que es esa zona. Pasame a buscar a las 8pm";
        char parrafo3[] = "\tLa respuesta la toma por sorpresa... parecio... SORNROJARSE??!\n\t--Desde cuando te volviste tan decidido?... Perfecto entonces!! Te espero";

    switch(opcion){

    case 1:
        system("cls");
        sofiaEnojada();
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        sofia();
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    case 3:
        system("cls");
        sofiaAmor();
        cartel_creador(parrafo3, 3);
        repeticion = 3;
        break;
    }
    }while(repeticion == 1);
    return opcion;

}
int eleccion(string parrafo){

    int opcion;

    const char *titulo = "<Que vas a hacer>";
    const char *opciones[] = {"\tYa empece mal el dia... que sentido tiene? (Rendirse)",
                              "\tTengo que mantenerme determinado!! Claro que voy",};
    int n = 2;

        opcion = menu_creador(titulo, opciones, n, parrafo, 7);


    return opcion;
}

int preparacion(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Que vas a hacer antes de salir?>";
    const char *opciones[] = {"\tPreparar notas con posibles temas de conversacion para el camino (No querras sonar como un tonto)",
                              "\tPreparar tus pasos de baile para el momento",};
    int n = 2;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 7);

        char parrafo1[] = "\tLa suerte no existe, te praparas para no decir nada estupido por el camino a la fiesta";
        char parrafo2[] = "\tDefinitivamente bailar no es lo tuyo, mientras practticabas te tuerces el tobillo, ahora no\n\tsolo no podras bailar, sino que ademas vas mas lento";

    switch(opcion){

    case 1:
        system("cls");
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    }
    }while(repeticion == 1);
    return opcion;
}

int preparacion2(string parrafo){
    int opcion;

    const char *titulo = "<Vas a tomar la pistola?>";
    const char *opciones[] = {"\tEs completamente necesaria (Tomar)",
                              "\tDecides no hacer caso a tus pensamientos intrusivos",};
    int n = 2;

    //Primera eleccion

        opcion = menu_creador(titulo, opciones, n, parrafo, 7);

    return opcion;
}

int aguacate(string parrafo){
    int opcion;

    const char *titulo = "<Oh no, quizas la lista si era una buena idea>";
    const char *opciones[] = {"Aguacate",
                              "Bob esponja, te tiraste una pila e' quimico",
                              "Desayuna con huevo",};
    int n = 3;


        opcion = menu_creador(titulo, opciones, n, parrafo, 4);

    return opcion;
}

int buenaRespuesta(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Que vas a decirle?>";
    const char *opciones[] = {"Si me permite decirle, esta usted verdaderamente hermosa senorita Sofia",
                              "No me hace falta ver al resto para estar seguro de que eres la chica mas hermosa de la ciudad",
                              "Te queda muy bien",};
    int n = 3;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 4);

        //Respuestas
        char parrafo1[] = "\t--Eh... eso fue extranamente incomodo... Mejor vamonos";
        char parrafo2[] = "\tSofia desvia la mirada. Parece que tu alago tuvo algun efecto en ella!\n\t--Gra-gracias, tu tambien te ves bien. Vamonos";
        char parrafo3[] = "\t--Gracias :D";

    switch(opcion){

    case 1:
        system("cls");
        sofiaEnojada();
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        sofiaAmor();
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    case 3:
        system("cls");
        sofia();
        cartel_creador(parrafo3, 3);
        repeticion = 3;
        break;
    }

    }while(repeticion == 1);
    return opcion;
}

int camion(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Como vas a actuar?>";
    const char *opciones[] = {"Salvarte tu mismo",
                              "Salvar a Sofia",
                              "Intentar salvar a los 2",
                              "Detener el camion poniendote en frente",};
    int n = 4;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 6);

        char parrafo1[] = "\tSofia se percata del camion un instante despues de ti, agarra tu brazo con fuerza buscando\n\tproteccion. Pero las situaciones extremas descubren la verdadera naturaleza de los hombres\n\tCon un empujon te safas de Sofia y saltas fuera del alcance del camion\n\n\tMiras tus manos... Estas vivo";
        char parrafo2[] = "\tTe das cuenta de que si no haces algo rapido los dos van a morir. Entonces sacas tu lado mas heroico\n\tuna parte de ti que no sabias que tenias. Sin Sofia tu vida no tendria sentido de todos modos\n\tEn un acto de amor verdadero la empujas fuera del alcance del camion\n\tAntes del impacto ambos se miran y tus ojos mejor que las palabras le revelan tus sentimientos... Sofia vive";
        char parrafo3[] = "\tTus reflejos son mas rapidos de lo que imaginabas\n\tAgarras a Sofia con fuerza y saltan fuera de la direccion del camion\n\tCaen bruscamente contra el suelo pero ambos viven";
        char parrafo4[] = "\tNo se en que momento pensaste que seria prudente detener un camion a toda velocidad poniendote\n\tfrente a el. En fin, digamos que la adrenalina a veces puede hacerte hacer cosas tontas\n\tAmbos murieron";

    switch(opcion){

    case 1:
        system("cls");
        sofiahermosa();
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    case 3:
        system("cls");
        cartel_creador(parrafo3, 3);
        repeticion = 3;
        break;

    case 4:
        system("cls");
        cartel_creador(parrafo4, 3);
        repeticion = 3;
        break;
    }

    }while(repeticion == 1);
    return opcion;
}

int confesion(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Te vas a confesar AHORA?>";
    const char *opciones[] = {"Sisis, claro, parece lo mas logico",
                              "Algo me hace pensar que no es el momento",};
    int n = 2;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 0);

        char parrafo1[] = "\tCuando le confiesas tus sentimientos a sofia ella se queda pensattiva\n\t--Agradezco que me salvaras y en realidad a mi tambien me gustabas pero esta situacion es un poco...\n\t(Parece ser que Sofia no quiere comprometerse con la situacion)";
        char parrafo2[] = "\tLa ambulancia no tarda mucho en llegar\n\tPasaste los siguientes meses en el hospital. Al parecer no volveras a caminar\n\tTe enteraste que ese mismo dia, Sofia llego a ir a la fiesta incluso despues del accidente\n\tAl parecer tu mejo amigo se le confeso esa noche y comenzaron a salir. No te sientas traicionado\n\tA el tampoco le contaste nada hacerca de tus sentimientos hacia Sofia. Al menos eres muy\n\tbueno guardando secretos. Ahora eres el amigo Steve de su relacion";

        switch(opcion){
    case 1:
        system("cls");
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

    }

    }while(repeticion == 1);
    return opcion;
}

int disparar(string parrafo){
    int repeticion = 1;
    int opcion;

    const char *titulo = "<Tocas la pistola en tu bolsillo NO COMETAS UN ERROR>";
    const char *opciones[] = {"Disparar a Sofia",
                              "No hacerle caso a tus pensamientos intrusivos",
                              "Dispararte a ti mismo",};
    int n = 3;

    do{

        opcion = menu_creador(titulo, opciones, n, parrafo, 0);

        char parrafo1[] = "Idiota!! HAS MATADO A SOFIA!!";
        char parrafo2[] = "Buen chico, manten la cordura";
        char parrafo3[] = "Nunca pense que harias eso, wtf\n\tTe moriste";

        switch(opcion){
    case 1:
        system("cls");
        cartel_creador(parrafo1, 3);
        repeticion = 3;
        break;

    case 2:
        system("cls");
        cartel_creador(parrafo2, 3);
        repeticion = 3;
        break;

        case 3:
            system("cls");
            cartel_creador(parrafo3, 3);
            repeticion = 3;
            break;

    }
    }while(repeticion == 1);
    return opcion;
}

//Carteles

void cartel_creador(char parrafo[], int cantLineas){

    int i;
    gotoxy(5,21-cantLineas);
    for(i = 0; parrafo[i] != '\0'; i++){
            putchar(parrafo[i]);
            fflush(stdout);
            usleep(50000);

            fflush(stdin);
            if(kbhit()){

                gotoxy(5,21-cantLineas); cout << parrafo;
                break;
            }
    }
    cout << "\n\n\n";
    system("pause");

}


string cartel1(){
    char parrafo[] = "\tQuerido diario:\n\n\tSabes que desde que tengo memoria siempre he estado enamorado de esta misma chica\n\tEs perfecta. La conozco bien, es inteligente, graciosa y la chica mas hermosa del mundo\n\tSu nombre es Sofia. Vive justo al frente y por ahora somos amigos. Me he guardado el secreto\n\tpara no romper nuestra amistad... Pero eso va a cambiar este 14 de febrero!!\n\tHARE QUE SOFIA SE ENAMORE DE MI!!\n\n\n\n\n";
    int cantLineas = 15;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
}
string cartel2(){
    system("cls");
char parrafo[] = "\t<<ATENCION>>\n\n\tA partir de ahora controlas las decisiones de Daniel. Tu mision? Hacer que sofia se enamore\n\tperdidamente de el.\n\t<<NO LE FALLES!!>>\n\tTus decisiones determinaran el final de la historia";
int cantLineas = 15;
cartel_creador(parrafo, cantLineas);

return parrafo;
}
string cartel3(){
    system("cls");

        daniel();
char parrafo[] = "\t( 14 Febrero 8:30am )\n\n\tOh no!! Voy a llegar tarde a la escuela. Sofia y yo estamos en clases diferentes y solo\n\tantes de comenzar puedo fingir que me encuentro con ella accidentalmente\n\tNO PUEDO PERDER ESA OPORTUNIDAD HOY!!";
int cantLineas = 2;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel4(int bela){
system("cls");
if(bela == 1){
    sofia();
}
char parrafo[] = "\tTe encuentras con Sofia en la escuela, esta tan hermosa como siempre. En un momento sus miradas\n\tse cruzan entre la multitud. VA HACIA TI!!! Preparate";
int cantLineas = 3;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel5(){
    system("cls");
char parrafo[] = "\tEfectivamente, no vi a Sofia";
int cantLineas = 1;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel6(int bela){
    system("cls");
    if(bela == 1){
        sofia();
    }
char parrafo[] = "\t--Ho-hola Daniel, que bueno que has llegado\n\tHas hecho la tarea de matematicas??!!! \n\tSe me ha olvidado y es MUY IMPORTANTE";
int cantLineas = 3;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel7(int bela){
    system("cls");
    if(bela == 1){
        sofia();
    }
char parrafo[] = "\tEspera un segundo, si estas mas guapo!! No me habia dado cuenta. No sera que estas esperando\n\tuna cita para hoy verdad? Recuerda que tu eres mio\n\tJajajajaja es broma";
int cantLineas = 3;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel8(int bela){
    system("cls");
    if(bela == 1){
        sofia();
    }
char parrafo[] = "\t--Por cierto, antes de que lo olvide. Vas a ir a la fiesta de Angelica verdad?\n\t(Angelica es la amiga de sofia, vive al otro lado de la ciudad pero hace fiestas asombrosas)\n\tPodria ser una oportunidad";
int cantLineas = 3;
cartel_creador(parrafo, cantLineas);

return parrafo;
}

string cartel9(int bela){
    system("cls");
    if(bela == 1){
        sofia();
    }
    char parrafo[] = "\tMas tarde te enteras de que angelica (la amiga de Sofia) esta haciendo una fiesta\n\tPodria ser tu ultima oportunidad para declararte";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }
string cartel10(){
    system("cls");
    char parrafo[] = "\tTe armas de valor y llamas a Sofia, le preguntas si va a ir a la fiesta\n\t(De otra forma no tendria sentido ir) Ella te dice que no se lo perderia, parece emocionada\n\tTE PIDE QUE LA PASES A RECOGER A LAS 8pm\n\tAhora eres el chico mas feliz del mundo, debes prepararte para impresionarla\n";
    int cantLineas = 5;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

//Carteles 2da Parte
string cartel11(){
    char parrafo[] = "\t( 14 febrero 7:15pm )\n\tPasaste toda la tarde preparandote para este momento. Estas presentable, con la ropa adecuada, te\n\tpreocupaste especialmente porque tu boca no oliese a muerto y viste 2 tutoriales de como\n\tbesar bien en youtube";
    int cantLineas = 4;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

string cartel12(){
    char parrafo[] = "\tAntes de salir por la puerta ves la pistola de tu padre sobre la mesa...\n\tAngelica vive en la parrte mas pelirosa de la ciudad...\n\tquizas necesites un poco de proteccion extra...";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

string cartel13(){
    sofiahermosa();
    char parrafo[] = "\tCon todo listo sales, cruzas la calle y tocas el timbre en la casa de Sofia\n\tAl instante abre la puerta, ESTA PRECIOSA. Tu corazon no deja de latir a gran velocidad\n\n\tCUIDADO CON LO QUE DICES EN ESTE ESTADO";
    int cantLineas = 4;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }
string cartel14(){
    sofiahermosa();
    char parrafo[] = "\t--que te parece mi vestido?-- Le escuchaste decir. \n\tRAPIDO DILE ALGO";
    int cantLineas = 1;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }
string cartel15(){
    sofiahermosaEnojada();
    char parrafo[] = "\t--Que estas diciendo? Te ries de mi?!! Sabes que tengo inseguridades con mi cuerpo\n\tComo sea vamonos de aqui, no tengo a mas nadie con quien ir";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

string cartel16(){
    system("cls");
    caminando();
    char parrafo[] = "\tAmbos salen juntos, el camino era largo. Luego del nerviosismo del primer momento te sientes mas\n\tconfiado. Ambos hablan, rien, juegan... estas mas enamorado que nunca\n\tEra el momento perfecto, estabas preparandote para confesarte cuando...";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

string cartel17(){
    system("cls");
    camion();
    char parrafo[] = "\tOh no! Estaban tan distraidos que no vieron cuando un camion se acercaba a alta velocidad\n\tTe diste cuenta en el momento justo para actuar";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

string cartel18(){
    system("cls");
    char parrafo[] = "\tSeria este un buen momento para confesarte antes de que acabe el dia?";
    int cantLineas = 3;
    cartel_creador(parrafo, cantLineas);

    return parrafo;
    }

//SISTEMA
void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void sofia(){
    cout << "                                                                      ";
    cout << "\n                        ***************                             ";
    cout << "\n                      ********************                          ";
    cout << "\n                    ***********************                         ";
    cout << "\n                   ******* *****************                        ";
    cout << "\n                   *******  ****************                        ";
    cout << "\n                   ***                   **                         ";
    cout << "\n                   ***    **       **     **                        ";
    cout << "\n                   *      **       **     **                        ";
    cout << "\n                   *                     **                         ";
    cout << "\n                   ***       *****       **                         ";
    cout << "\n                   ***                   **                         ";
    cout << "\n                   *****               ****                         ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void sofiaEnojada(){
    cout << "                                                                      ";
    cout << "\n                        ***************                             ";
    cout << "\n                      ********************                          ";
    cout << "\n                    ***********************                         ";
    cout << "\n                   ******* *****************                        ";
    cout << "\n                   *******  ****************     **     **          ";
    cout << "\n                   ***                   **       **   **           ";
    cout << "\n                   ***   ****     ****   **        ** **            ";
    cout << "\n                   *      **       **     **        ***             ";
    cout << "\n                   *                      **       *****            ";
    cout << "\n                   ***       *****       **       **   **           ";
    cout << "\n                   ***                   **      **     **          ";
    cout << "\n                   *****               ****                         ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void sofiadudosa(){
    cout << "                                                                      ";
    cout << "\n                        ***************                             ";
    cout << "\n                      ********************                          ";
    cout << "\n                    ***********************        *******          ";
    cout << "\n                   ******* *****************      **     **         ";
    cout << "\n                   *******  ****************     **       **        ";
    cout << "\n                   ***                   **      **      **         ";
    cout << "\n                   ***    **       **     **           ***          ";
    cout << "\n                   *      **       **     **          ***           ";
    cout << "\n                   *                     **           **            ";
    cout << "\n                   ***       *****       **           **            ";
    cout << "\n                   ***                   **                         ";
    cout << "\n                   *****               ****           **            ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void sofiaAmor(){
    cout << "                                                                      ";
    cout << "\n                        ***************                             ";
    cout << "\n                      ********************                          ";
    cout << "\n                    ***********************                         ";
    cout << "\n                   ******* *****************                        ";
    cout << "\n                   *******  ****************       ****  ***        ";
    cout << "\n                   ***                   **       **  ***   *       ";
    cout << "\n                   ***    **       **     **      **   *    *       ";
    cout << "\n                   *      **       **     **       **     **        ";
    cout << "\n                   *                     **         **  **          ";
    cout << "\n                   ***       *****       **           * *           ";
    cout << "\n                   ***                   **            *            ";
    cout << "\n                   *****               ****                         ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void sofiahermosadudosa(){
    cout << "                       ****                                           ";
    cout << "\n                    *    **************                             ";
    cout << "\n                    *     ***************                           ";
    cout << "\n                   * *********************         *******          ";
    cout << "\n                *   ***** *****************       **     **         ";
    cout << "\n               *     ****  ****************      **       **        ";
    cout << "\n                 *****                   **      **      **         ";
    cout << "\n                   ***    **       **     **           ***          ";
    cout << "\n                   *      **       **     **          ***           ";
    cout << "\n                   *                     **           **            ";
    cout << "\n                   ***       *****       **           **            ";
    cout << "\n                   ***                   **                         ";
    cout << "\n                   *****               ****           **            ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}
void sofiahermosa(){
    cout << "                       ****                                           ";
    cout << "\n                    *    **************                             ";
    cout << "\n                    *     ***************                           ";
    cout << "\n                   * *********************                          ";
    cout << "\n                *   ***** *****************                         ";
    cout << "\n               *     ****  ****************                         ";
    cout << "\n                 *****                   **                         ";
    cout << "\n                   ***    **       **     **                        ";
    cout << "\n                   *      **       **     **                        ";
    cout << "\n                   *                     **                         ";
    cout << "\n                   ***       *****       **                         ";
    cout << "\n                   ***                   **                         ";
    cout << "\n                   *****               ****                         ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void sofiahermosaEnojada(){
    cout << "                       ****                                           ";
    cout << "\n                    *    **************                             ";
    cout << "\n                    *     ***************                           ";
    cout << "\n                   * *********************                          ";
    cout << "\n                *   ***** *****************                         ";
    cout << "\n               *      ***  ****************      **     **          ";
    cout << "\n                 *****                   **       **   **           ";
    cout << "\n                   ***   ****     ****   **        ** **            ";
    cout << "\n                   *      **       **     **        ***             ";
    cout << "\n                   *                      **       *****            ";
    cout << "\n                   ***       *****       **       **   **           ";
    cout << "\n                   ***                   **      **     **          ";
    cout << "\n                   *****               ****                         ";
    cout << "\n                   *********      *********                         ";
    cout << "\n                   *********      ***********                       ";
    cout << "\n                   ****                ******                       ";
    cout << "\n                  ****                   ****                       ";
    cout << "\n                 *****                   ****                       ";
}

void daniel(){
    cout << "                                                                      ";
    cout << "\n                       ****************                             ";
    cout << "\n                      ********************                          ";
    cout << "\n                   *************************                        ";
    cout << "\n                   ******* *******************                      ";
    cout << "\n                 *******       ***************                      ";
    cout << "\n                 *****          **   ** ****                        ";
    cout << "\n                 *****    **       **     **                        ";
    cout << "\n                  **      **       **     **                        ";
    cout << "\n                  **                     *                          ";
    cout << "\n                   ***          ***      *                          ";
    cout << "\n                     *                   *                          ";
    cout << "\n                     ***               **                           ";
    cout << "\n                       ******      *****                            ";
    cout << "\n                        *****      **                               ";
    cout << "\n                      **            *****                           ";
    cout << "\n                     *                   *                          ";
    cout << "\n                     *                   *                          ";
}

void caminando(){
    cout << "                                                                      ";
    cout << "\n                                                                    ";
    cout << "\n              ******                  ******                        ";
    cout << "\n              ******       ** **      ******                        ";
    cout << "\n              ******       *****      ******                        ";
    cout << "\n              ******        ***       ******                        ";
    cout << "\n                **           *        ******                        ";
    cout << "\n           ************            ************                     ";
    cout << "\n           ********* **            ** ****** **                     ";
    cout << "\n           ** ****** **            ** ****** **                     ";
    cout << "\n           ** ****** **           **   ****  **                     ";
    cout << "\n           ** ****** **           *   ******  **                    ";
    cout << "\n              ******                 ********  **                   ";
    cout << "\n              **  **                 ********                       ";
    cout << "\n              **  **                 ********                       ";
    cout << "\n              **  **                  **  **                        ";
    cout << "\n              **  **                  **  **                        ";
    cout << "\n              **  **                  **  **                        ";
}

void camion(){
    cout << "                                                                      ";
    cout << "\n                 ******************************                     ";
    cout << "\n                 **            **            **                     ";
    cout << "\n                 **            **            **        ****         ";
    cout << "\n                 **            **            **        ****         ";
    cout << "\n                 **            **            **        ****         ";
    cout << "\n                 **            **            **        ****         ";
    cout << "\n                 **            **            **         **          ";
    cout << "\n               **********************************       **          ";
    cout << "\n              **                                **                  ";
    cout << "\n              **                                **      **          ";
    cout << "\n              **                                **      **          ";
    cout << "\n              **                                **                  ";
    cout << "\n              *****                          *****                  ";
    cout << "\n              ************************************                  ";
    cout << "\n                  ***                     ***                       ";
    cout << "\n                  ***                     ***                       ";
    cout << "\n                                                                    ";
}



void danielySofia(){
    cout << "                                                                   ****                                           ";
    cout << "\n                       ****************                         *    **************                             ";
    cout << "\n                      ********************                      *     ***************                           ";
    cout << "\n                   *************************                   * *********************                          ";
    cout << "\n                   ******* *******************              *   ***** *****************                         ";
    cout << "\n                 *******       ***************             *     ****  ****************                         ";
    cout << "\n                 *****          **   ** ****                 *****                   **                         ";
    cout << "\n                 *****    **       **     **                   ***    **       **     **                        ";
    cout << "\n                  **      **       **     **    ***  ***       *      **       **     **                        ";
    cout << "\n                  **                     *      ********       *                     **                         ";
    cout << "\n                   ***         ****      *       ******        ***       *   *       **                         ";
    cout << "\n                     *                   *        ****         ***        ***        **                         ";
    cout << "\n                     ***               **          **          *****               ****                         ";
    cout << "\n                       ******      *****                       *********      *********                         ";
    cout << "\n                        *****      **                          *********      ***********                       ";
    cout << "\n                      **            *****                      ****                ******                       ";
    cout << "\n                     *                   *                    ****                   ****                       ";
    cout << "\n                     *                   *                   *****                   ****                       ";
}

void danieltriste(){
    cout << "                                                                                                                   ";
    cout << "\n                     ****************                                                                            ";
    cout << "\n                    ********************                                                                         ";
    cout << "\n                 *************************                    ********        ********                           ";
    cout << "\n                 ******* *******************                ************     ***********                         ";
    cout << "\n               *******       ***************               ************    *************                         ";
    cout << "\n               *****          **   ** ****                 *************   **************                        ";
    cout << "\n               *****   ****     ****    **                 ************    **************                        ";
    cout << "\n                **      **       **    **                   ***********   ************                           ";
    cout << "\n                **      **       **    *                       *******      *********                            ";
    cout << "\n                 ***         ***       *                        *******    ********                              ";
    cout << "\n                   *                   *                          ****   *******                                 ";
    cout << "\n                   ***               **                             ****   ****                                  ";
    cout << "\n                     ******      *****                               **   **                                     ";
    cout << "\n                      *****      **                                     **                                       ";
    cout << "\n                    **            *****                                                                          ";
    cout << "\n                   *                   *                                                                         ";
    cout << "\n                   *                   *                                                                         ";
}

void blanco(){
    cout << "                                                                      ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
    cout << "\n                                                                    ";
}
/*
 Su nombre es Sofia. Vive justo al frente y por ahora somos amigos. Me he guardado el secreto
 ********************************************************************************************
 */
