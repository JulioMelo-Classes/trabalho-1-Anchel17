#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../include/forca.hpp"

using namespace std;

bool Forca::geraPalavra(){
    cout<<"Gerando palavra, aguarde..."<<endl;

    int converte, achou;
    unsigned int soma = 0;

    ifstream arq;

    ///Só vai carregar os dados na primeira rodada
    if(rodada == 0){
        arq.open(arqPalavras, ios::out);

        if(arq.is_open()){
            while(!arq.eof()){
                arq >> aux;
                recebe.push_back(aux);
            }
        }   
        else{
            cout<<"Erro ao abrir o arquivo!"<<endl;
            exit(0);
        }

        for(int i = 0; i < recebe.size(); i++){
            if(i % 2 == 0){
                palavras.push_back(recebe[i]);
            }
            else{
                converte = stoi(recebe[i]);
                soma += converte;
                ocorrencias.push_back(converte);
            }
        }
        media = soma/ocorrencias.size();
        rodada++;

        for(int i = 0; i < ocorrencias.size(); i++){
            if(ocorrencias[i] >= media){
                facil++;
            }
            else{
                dificil++;
            }
        }
    }

    jafoi.push_back(-1);

    if(dificuldade == 1){
        while(contAux < facil){
            srand(time(nullptr));
            indice = rand()%facil;
            achou = 0;

            for(int i = 0; i < jafoi.size(); i++){
                if(indice == jafoi[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou == 0){
                jafoi.push_back(indice);
                palavra = palavras[indice];
                cout<<palavra<<endl; //no caso, retorna a palavra gerada no jogo
                contAux++;
                return true;
            }
        }
        return false;
    }
    else if(dificuldade == 2){
        while(contAux < facil){
            srand(time(nullptr));
            indice = rand()%(facil + dificil);

            achou = 0;

            for(int i = 0; i < jafoi.size(); i++){
                if(indice == jafoi[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou == 0){
                jafoi.push_back(indice);
                palavra = palavras[indice];
                cout<<palavra<<endl; //no caso, retorna a palavra gerada no jogo
                if(indice < facil){//isso aqui troca de lugar com a instrução de cima
                    contAux++;
                }
                return true;
            }
        }
        return false;
    }
    else if(dificuldade == 3){
        while(contAux < dificil){
            srand(time(nullptr));
            indice = rand()%dificil;
            
            if(indice < facil){
                indice += dificil;
            }

            achou = 0;

            for(int i = 0; i < jafoi.size(); i++){
                if(indice == jafoi[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou == 0){
                jafoi.push_back(indice);
                palavra = palavras[indice];
                cout<<palavra<<endl; //no caso, retorna a palavra gerada no jogo
                contAux++;
                return true;
            }
        }
        return false;
    }
}

bool Forca::confirma(){
    int conf;

    cout<<"\n\n\nDeseja continuar jogando? "<<endl;
    cout<<"1 - Sim"<<endl;
    cout<<"2 - Nao"<<endl;
    cout<<"Escolha: ";
    cin>>conf;
    cout<<endl;

    if(conf == 1){
        tentativas = 6;
        return true;
    }
    else{
        insereScore();
        return false;
    }
}

int Forca::getDificuldade(){
    return dificuldade;
}

void Forca::setDificuldade(int d){
    this -> dificuldade = d;
}


void Forca::desenhaBoneco(int chance, string boneco[5][5]){
    if(chance == 5){
        boneco[0][1] = " ";
        boneco[0][2] = "O";
    }

    if(chance == 4){
        boneco[1][1] = " ";
        boneco[1][2] = "|";
    }

    if(chance == 3){
        boneco[1][1] = "/";
    }

    if(chance == 2){
        boneco[1][3] = "\\";
    }

    if(chance == 1){
        boneco[2][1] = "/";
    }

    if(chance == 0){
        boneco[2][2] = " ";
        boneco[2][3] = "\\";
    }
}

void Forca::carregaMenu(){
    int op, d;
    
    do{
        cout<<"Bem vindo ao jogo da forca! Por favor, selecione uma opcao:"<<endl;
        cout<<"1 - Iniciar jogo"<<endl;
        cout<<"2 - ver scores"<<endl;
        cout<<"0 - sair do jogo"<<endl;
        cout<<"Escolha: ";
        cin>>op;
    }while(op != 1 && op != 2 && op != 0);

    if(op == 1){
            do{
                cout<<"\n\n\n\n\n";
                cout<<"Por favor, selecione uma dificuldade para iniciar o jogo!"<<endl;
                cout<<"1 - facil"<<endl;
                cout<<"2 - medio"<<endl;
                cout<<"3 - dificil"<<endl;
                
                cout<<"Escolha: ";
                cin>>d;
            }while(d != 1 && d != 2 && d != 3);

            ///seta os valores padrão

            tentativas = 6;         ///Tentativas restantes para o jogador acertar
            pontos = 0;             ///Pontos feitos pelo jogador
            acertadas.clear();      ///Limpa o vector de palavras acertadas
            carac.clear();          ///Limpa o vector de caracteres digitados
            jafoi.clear();          ///Limpa o vector das palavras já utilizadas
            contAux = 0;               ///Zera o contador auxiliar do geraPalavra()

            setDificuldade(d);

            jogo();

        }
        else if(op == 2){
            imprimeScore();
        }
        else{
            cout<<"Obrigado por jogar! Encerrando o jogo..."<<endl;
            exit(1);
        }
}

string Forca:: getNomeArquivoPalavra(){
    return arqPalavras;
}

void Forca::setNomeArquivoPalavra(string nomePalavras){
    this -> arqPalavras = nomePalavras;
}

string Forca::getNomeArquivoScore(){
    return arqScores;
}

void Forca::setNomeArquivoScore(string nomeScore){
    this -> arqScores = nomeScore;
}

void Forca::imprimeScore(){
    ifstream ler;
    int volta;
    cout<<"\n\n\n";

    ler.open(arqScores, ios::out);

    if(ler.is_open()){
        cout<<ler.rdbuf();
    }

    ler.close();

    cout<<"\n";

    do{
    cout<<"Pressione 1 e tecle Enter para voltar ao menu"<<endl;
    cin>>volta;
    }while(volta != 1);

    carregaMenu();
}

void Forca::insereScore(){
    fstream scores;
    cin.ignore();
    cout<<"Digite seu nome para registrar no arquivo de scores: ";
    
    getline(cin, nome);

    scores.open(arqScores, ios::app);

    if(scores.is_open()){
        //insere a dificuldade no arquivo
        if(dificuldade == 1){
            scores<<"Fácil; ";
        }
        else if(dificuldade == 2){
            scores<<"Médio; ";
        }
        else{
            scores<<"Difícil; ";
        }

        //insere o nome do jogador no arquivo
        scores<<nome<<"; ";

        //insere as palavras acertadas pelo jogador no arquivo de score
        if(acertadas.size() == 0){
            scores<<"; ";
        }

        for(int i = 0; i < acertadas.size(); i++){
            if(i == acertadas.size()-1){
                scores<<acertadas[i]<<"; ";
            }
            else{
                scores<<acertadas[i]<<", ";
            }
        }

        //insere a quantidade de pontos que o jogador fez            
        scores<<pontos;
    }
    else{
        cout<<"Erro ao abrir o arquivo!"<<endl;
        exit(0);
    }
    scores<<"\n";

    scores.close();

    carregaMenu();
}
