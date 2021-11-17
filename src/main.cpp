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

    if(palavras.is_open() && scores.is_open()){
        play.carregaMenu();
    }
    else{
        cout<<"Erro! verifique se digitou o caminho e o nome dos arquivos corretamente."<<endl;
        exit(0);
    }
    
    palavras.close();
    return 0;
}
