#include <iostream>
#include <string>
#include <fstream>

#include "../include/forca.hpp"

using namespace std;

int Forca::contaConsoantes(){
    int consoantes = 0;

    for(int i = 0; i < palavra.size(); i++){
        if(palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i'
        && palavra[i] != 'o' && palavra[i] != 'u'){
            consoantes++;
        }
    }
    return consoantes;
}

void Forca::jogo(){
    /*Dependendo da dificuldade, faz as coisas previamente setadas*/
    bool roda = true;
    char c;
    int cont = 0, achou, qtd, consoantes, achouCarac;

    while(conf == true){
        roda = geraPalavra();
        carac.clear();
        carac.push_back(' ');   ///só para inicializar o vector logo
        
        //VITÓRIA NO MODO FÁCIL.
        if(roda == false && dificuldade == 1){
            cout<<"Parabéns! você acertou todas as palavras do modo fácil!"<<endl;
            cout<<"-----Obrigado por jogar-----"<<endl;

            insereScore();
        }
        //VITÓRIA NO MODO MÉDIO
        else if(roda == false && dificuldade == 2){
            cout<<"Parabéns! você acertou todas as palavras do modo médio!"<<endl;
            cout<<"-----Obrigado por jogar-----"<<endl;

            insereScore();
        }
        //VITÓRIA NO MODO DIFÍCIL
        else if(roda == false && dificuldade == 3){
            cout<<"Parabéns! você acertou todas as palavras do modo difícil!"<<endl;
            cout<<"-----Obrigado por jogar-----"<<endl;

            insereScore();
        }
        string vec[palavra.size()]; //<!String que esconde os caracteres e vai mostrando se acertar
        
        //inicializa o boneco sem desenho
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                boneco[i][j] = " ";
            }
        }
        //jogo no modo facil
        if(dificuldade == 1){
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"iniciando jogo fácil!"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
            
            srand(time(nullptr));
            consoantes = contaConsoantes();
            //determinar quantas consoantes serão substituidas
            qtd = rand()%consoantes;
            cont = 0;

            cout<<"Iniciando o jogo com "<<qtd<<" consoante(s) descoberta(s)"<<endl;
            
            for(int i = 0; i < palavra.size(); i++){
                vec[i] = "_";
            }

            if(qtd > 0){
                for(int i = 0; i < palavra.size(); i++){
                    if(palavra[i] != 'a' && palavra[i] != 'e' && palavra[i] != 'i'
                    && palavra[i] != 'o' && palavra[i] != 'u'){
                        vec[i] = palavra[i];
                        qtd--; //<!Quantidade de consoantes restantes para substituir
                        cont++; //<!Quantidade de consoantes substituidas

                        if(qtd == 0){
                            break;
                        }
                    }
                }
                pontos += cont;
            }
        }
        //jogo no modo medio
        else if(dificuldade == 2){
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Iniciando jogo medio!"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;
            
            cont = 0;
            for(int i = 0; i < palavra.size(); i++){
                vec[i] = "_";
            }
        }
        //jogo no modo dificil
        else{
            cout<<"--------------------------------------------------------------"<<endl;
            cout<<"Iniciando jogo dificil!"<<endl;
            cout<<"--------------------------------------------------------------"<<endl;

            cont = 0;
            for(int i = 0; i < palavra.size(); i++){
                vec[i] = "_";
            }
        }

        /*Esqueleto do jogo, aqui já vai estar rodando configurado de acordo com a dificuldade.*/
        while(cont < palavra.size() && tentativas > 0){
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    cout<<boneco[i][j];
                }
                cout<<endl;
            }

            for(int i = 0; i < palavra.size(); i++){
                cout<<vec[i];
            }
            cout<<endl;
            cout<<"Chances: "<<tentativas<<endl;
            cout<<"Pontos: "<<pontos<<endl;
            cout<<"Letra: ";
            cin>>c;

            cout<<endl;
            achou = 0;
            achouCarac = 0;

             for(int j = 0; j < carac.size(); j++){
                    if(c == carac[j]){
                        achouCarac = 1;
                        achou++;
                        cout<<"Você já digitou a letra "<<c<<endl;
                    }
                }

            for(int i = 0; i < palavra.size(); i++){  
                if(achouCarac == 1){
                    break;
                }
                
                if(c == palavra[i] && vec[i] == "_"){
                    carac.push_back(c);
                    achou++;
                    vec[i] = c;
                    cont++;
                    pontos++;
                }
            }

            //se nao achou nenhuma letra igual, diminue a chance e chama a funcao para desenhar o boneco
            if(achou == 0){
                tentativas--;
                pontos--;
                desenhaBoneco(tentativas, boneco);
            }

        }

        //se acertou todas as letras, vence
        //PODE TRANSFORMAR EM UMA FUNCAO RECEBENDO O CONTADOR E IMPRIMINDO SE O PLAYER GANHOU OU NAO
        if(cont == palavra.size()){
            for(int i = 0; i < palavra.size(); i++){
                cout<<vec[i];
            }
            cout<<endl;
            cout<<"Parabéns! você acertou a palavra!"<<endl;
            acertadas.push_back(palavra);

            if(dificuldade == 1 || dificuldade == 2){
                palOk++;
            }
            else{
                palOkHard--;
            }
        }
        else{
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    cout<<boneco[i][j];
                }
                cout<<endl;
            }
            for(int i = 0; i < palavra.size(); i++){
                cout<<vec[i];
            }
                cout<<endl;
                cout<<"-----GAME OVER-----"<<endl;
                cout<<"A palavra era: "<<palavra<<endl;

                insereScore();
        }
        conf = confirma();
    }
}
