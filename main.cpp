#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int Z=0,R=0,P=0;


int ComputerMove(){ //funkcja losująca liczbe dla komputera
    srand((unsigned)time(0));
    int los= rand()%(3+1)+0;
    return los;
}

void Check(int player, int los){
        if(player==los){
        cout<<"\nREMIS"<<endl;
        R++;
    }else if(player==0 && los==2|| player==1 && los==0|| player==2 && los==1){
        cout<<"\nWygrywasz"<<endl;
        Z++;
    }else if(player==2 && los==0|| player==0 && los==1|| player==1 && los==2){
        cout<<"\nPrzegrywasz"<<endl;
        P++;
    }
}

void game(){//Funkcja odpalająca grê
    int player,los=ComputerMove();
    cout<<"\n===============GRA===============\n0-ROCK\n1-PAPER\n2-SCISSORS\n";
    cin>>player;
    Check(player,los);
}

void score(){ //Wyświetla wynik
    cout<<"\n========WYNIK========\nWygrane: "<<Z<<"\nPrzegrane: "<<P<<"\nRemis: "<<R<<endl;
}
int main()
{
    cout<<"===============ROCK=PAPER=SCISSOR===============\n";
    string wybor="0";
    while (true){
        cout<<"===============MENU===============\n0-Gra\n1-Wynik\n2-Reset\n3-Koniec\n";
        cin>>wybor;
        if(wybor=="0"){
            game();
        }else if(wybor=="1"){
            score();
        }else if(wybor=="2"){
            Z=0,R=0,P=0;//Resetuje wynik
        }else if(wybor=="3"){
            cout<<"Jestes pewny\n0-Tak\nInne-Nie\n";
            cin>>wybor;
            if(wybor=="0"){
                break;//Przerywa pętle
            }else{}
        }
    }
    return 0;
}
