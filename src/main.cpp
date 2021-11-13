#include <iostream>
#include <fstream>

#include "../include/forca.hpp"

using namespace std;

int main(int argc, char* argv[]){

    Forca play;
    string nomeScore, nomePalavras;

    play.setNomeArquivoPalavra(argv[1]);
    play.setNomeArquivoScore(argv[2]);

    ifstream palavras(play.getNomeArquivoPalavra());
    ifstream scores(play.getNomeArquivoScore());
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"Lendo arquivos de palavras e scores... aguarde"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    if(palavras.is_open() && scores.is_open()){
        cout<<"Arquivos ok!"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        play.carregaMenu();
    }
    else{
        cout<<"Ocorreu um erro na abertura dos arquivos."<<endl;
        exit(0);
    }
    
    palavras.close();
    return 0;
}
