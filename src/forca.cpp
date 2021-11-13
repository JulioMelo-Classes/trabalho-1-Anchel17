#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "../include/forca.hpp"

using namespace std;

int pMedio = 1; //<!Declarei um contador global aqui somente para auxiliar na dificuldade média

bool Forca::geraPalavra(){
    unsigned int  soma = 0, converte, onde, cont = 0;

    ifstream arq;

    arq.open(arqPalavras, ios::out);

    ///Só vai rodar na primeira execução, depois fica salvo.
    if(palOk == 0){
        ///insere o que está no arquivo em uma matriz
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 2; j++){
                arq >> lido[i][j];
            }
        }

        ///Separa os numeros dos nomes em diferentes vetores, mas seus indices coincidem
        for(int i = 0; i < 20; i++){
            converte = stoi(lido[i][1]);
            nums[i] = converte;
            palavras[i] = lido[i][0];
            soma += converte;
        }
        this -> media = soma/20;

        for(int i = 0; nums[i] >= media; i++){
            //conta quantos elementos estão acima da média
            cont++;
        }
        

        ///para o modo dificil
        for(int i = 0; i < 20; i++){
            if(nums[i] < media){
                indices.push_back(i);
            }
        }
    }

    if(dificuldade == 1 || dificuldade == 2){
        onde = nums[palOk];
    }
    else{
        onde = nums[palOkHard];
    }
    
    if(dificuldade == 1){
        if(onde >= media){
            this -> palavra = palavras[palOk];
            return true;
        }
        else{
            return false;
        }
    }

    else if(dificuldade == 2){
        if(onde >= media){
            if(pMedio % 3 == 0){
                this -> palavra = palavras[palOk + 6];
                pMedio++;
            }
            else{
                this -> palavra = palavras[palOk];
                pMedio++;
            }
            return true;
        }
        else{
            return false;
        }
    }
    else if(dificuldade == 3){
        if(onde < media){
            this -> palavra = palavras[palOkHard];
            return true;
        }
        else{
            return false;
        }
    }
    else{
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
            palOk = 0;              ///Palavras acertadas pelo jogador
            palOkHard = 19;         ///Palavras acertadas pelo jogador no modo dificil
            acertadas.clear();      ///Limpa o vector de palavras acertadas
            carac.clear();          ///Limpa o vector de caracteres digitados

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
