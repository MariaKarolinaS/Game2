#include <iostream>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <new>
#include <string.h>
#include <time.h>

using namespace std;

void MenuInicial();

void LimpaTela(){
    system("CLS");
}

void IniciaTabuleiro(char Tabuleiro[10][10], char Mascara[10][10]){
    int Linha,Coluna;

    for (Linha = 0; Linha < 10; Linha++) {
        for (Coluna = 0; Coluna < 10; Coluna++) {
            Tabuleiro[Linha][Coluna] = 'A';
            Mascara[Linha][Coluna] = '*';
        }
    }
}

void ExibeMapa(){
    int cont;
    for(cont =0; cont < 10; cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";
    for(cont =0; cont < 10; cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout  << "| ";
    }
    cout << "\n";
}

void ExibeTabuleiro(char Tabuleiro[10][10], char Mascara[10][10], bool MostraGabarito) {

    char blue[] = {0x1b, '[', '1',';', '3', '4', 'm', 0};
    char green[] = {0x1b, '[', '1',';', '3', '2', 'm', 0};
    char normal[] = {0x1b, '[', '1',';', '3', '9', 'm', 0};



    int Linha, Coluna;

    for (Linha = 0; Linha < 10; Linha++) {
        cout << Linha << " - ";
        for (Coluna = 0; Coluna < 10; Coluna++) {

            switch(Mascara[Linha][Coluna]){
                case 'A':
                    cout << blue  << " " << Mascara[Linha][Coluna] << normal;
                    break;
                case 'P':
                    cout << green  << " " << Mascara[Linha][Coluna] << normal;
                    break;

                default:
                    cout << " " << Mascara[Linha][Coluna];
                    break;
            }



        }

        cout << "\n";

    }
    if (MostraGabarito == true) {
        for (Linha = 0; Linha < 10; Linha++) {
            for (Coluna = 0; Coluna < 10; Coluna++) {
                cout << " " << Tabuleiro[Linha][Coluna];
            }
            cout << "\n";
        }
    }

    }

void PosicionaBarcos(char Tabuleiro[10][10]){
    int cont;
    int quantidade = 10;
    int QuantidadePosicionada = 0;

    while(QuantidadePosicionada < quantidade){
            int LinhaBarco = rand()%10;
            int ColunaBarco = rand()%10;
            if(Tabuleiro[LinhaBarco][ColunaBarco] == 'A'){
                Tabuleiro[LinhaBarco][ColunaBarco] = 'P';
                QuantidadePosicionada++;
            }


    }



}

void VerificaTiro(char Tabuleiro[10][10], int LinhaJogada, int ColunaJogada, int *Pontos, string *Mensagem){


    switch(Tabuleiro[LinhaJogada][ColunaJogada]){
        case 'P':
            *Pontos = *Pontos +10;
            *Mensagem = "Voce acertou um barco pequeno! (10 pontos) , ";
            break;
        case 'A':
            *Mensagem = "Bleh... Voce acertou a agua... ";

            break;
    }
}

[[noreturn]] void Jogo(string NomeDoJogador) {
    ///variaveis gerais
    char Tabuleiro[10][10], Mascara[10][10];
    int Linha, Coluna;
    int LinhaJogada, ColunaJogada;
    int EstadoDeJogo = 1;             ///1 = jogo acontecendo, 0 = fim de jogo
    int Pontos = 0;
    int Tentativas = 0;
    int MaximoTentativas = 5;
    int Opcao;
    string Mensagem = "\nBem vindo ao jogo\n";



    IniciaTabuleiro(Tabuleiro, Mascara);

    PosicionaBarcos(Tabuleiro);

    while(Tentativas  < MaximoTentativas){
        LimpaTela();

        ExibeMapa();

        ExibeTabuleiro(Tabuleiro, Mascara, false);
        cout << "\nPontos:\n" << Pontos << ", Tentativas restantes: " << MaximoTentativas - Tentativas;
        cout << "\n" << Mensagem;

        LinhaJogada = -1;
        ColunaJogada = -1;
        while(  (LinhaJogada < 0 || ColunaJogada < 0)  || LinhaJogada > 9 || ColunaJogada > 9  ){
            cout << NomeDoJogador << ", Digite uma linha:\n ";
            cin >> LinhaJogada;
            cout <<NomeDoJogador << ", Digite uma coluna:\n ";
            cin >> ColunaJogada;
        }



        VerificaTiro(Tabuleiro,LinhaJogada,ColunaJogada, &Pontos, &Mensagem);


        Mascara[LinhaJogada][ColunaJogada] = Tabuleiro[LinhaJogada][ColunaJogada];
        Tentativas++;
    }
    cout << "Fim de jogo!\nO que deseja fazer?\n";
    cout << "1 - Jogar novamente.\n";
    cout << "2 - Voltar ao menu inicial.\n";
    cout << "3 - Sair.\n";
    cin >> Opcao;

    switch(Opcao){
        case 1:
            Jogo(NomeDoJogador);
            break;

        case 2:
            MenuInicial();

            break;

    }

}



void MenuInicial(){

    int Opcao;

        string NomeDoJogador;


        while (Opcao < 1 || Opcao > 3) {
            LimpaTela();

            cout << "-------------------------------------------------------";
            cout << "\n";
            cout << "\n>>>>>>>>>>BEM-VINDO AO JOGO DA BATALHA NAVAL!<<<<<<<<<\n";
            cout << "\n";
            cout << "-------------------------------------------------------";

            cout << "\n1 - Jogar: ";
            cout << "\n2 - Sobre o jogo: ";
            cout << "\n3 - Sair do jogo: ";
            cout << "\n\nESCOLHA UMA OPCAO E TECLE ENTER!\n\n";
            cin >> Opcao;

            switch (Opcao) {

                case 1:
                    cout << "\nOla! Qual o seu nome? :)";
                    cin >> NomeDoJogador;
                    cout << "\nVoce selecionou:\nOpcao 1 -> Jogar!\nJogo iniciado, boa sorte! :)\n";
                    Jogo(NomeDoJogador);
                    break;

                case 2:
                    cout << "\nVoce selecionou: \nOpcao 2 -> Sobre o jogo:\n";
                    cout
                            << "\nO jogo eh o classico batalha naval!\n\nCriado por Maria Karolina em projeto da Udemy para o curso de C++ no ano de 2022!\nEspero que se divirta! Beijinhos :)!\n";


                    break;

                case 3:
                    cout << "\nVoce selecionou: \nOpcao 3 -> Sair.\n\nAte a proxima! :)\n";


                    break;
            }
        }


    }


    int main(){

    srand((unsigned) time(NULL));

    cout << "Bem vindo ao jogo!\n";
    MenuInicial();

    return 0;
}
