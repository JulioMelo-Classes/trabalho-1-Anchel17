#ifndef FORCA_HPP
#define FORCA_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * Documentacao Doxygen
 */
class Forca{
    private:

        std::string boneco[5][5];   //<!Boneco representando quantos erros o jogador cometeu

        std::string lido[20][2];    //<!Matriz que recebe os dados do arquivo

        std::string palavras[20];   //<!Vetor com as palavras do arquivo

        std::string palavra;        //<!String temporária só pra testar

        std::string nome;           //<!Nome do jogador

        std::string arqPalavras;    //<!Nome recebido pela main do arquivo palavras

        std::string arqScores;      //<!Nome recebido pela main do arquivo scores

        std::vector<int> indices;   //<!Indices de palavras com ocorrência abaixo da média.

        std::vector<char> carac;  //<!Vector de caracteres já digitados

        std::vector<std::string> acertadas; //<!vector que guarda as palavras que foram acertadas pelo jogador

        int nums[20];               //<!Vetor com a ocorrência das palavras

        int dificuldade;            //<!Dificuldade do jogo

        int tentativas = 6;         //<!Tentativas restantes para o jogador acertar

        int pontos = 0;             //<!Pontos feitos pelo jogador

        int palOk = 0;              //<!Palavras acertadas pelo jogador

        int palOkHard = 19;         //<!Contador para auxiliar o funcionamento no modo dificil

        bool conf = true;           //<!variavel que confirma se o jogador deseja continuar jogando

        int media;                  //<!Media de ocorrencia das palavras
        
    public:

        /**
         * Metodo Getter da dificuldade do jogo
         */
        int getDificuldade();

        /**
         * Metodo para setar a dificuldade do jogo
         * @param d dificuldade recebida
         */
        void setDificuldade(int d);

        /**
         * Metodo getter do nome do arquivo de scores
         * @return nome do arquivo de score
         */
        std::string getNomeArquivoScore();

        /**
         * Método para receber o arquivo score passado pela main
         */
        void setNomeArquivoScore(std::string arqScores);

        /**
         * Metodo getter do nome do arquivo de palavras
         * @return nome do arquivo de palavras
         */
        std::string getNomeArquivoPalavra();

        /**
         * Método para receber o arquivo de palavras passado pela main
         */
        void setNomeArquivoPalavra(std::string arqPalavras);

        /**
         * função que carrega o menu principal do jogo
         */
        void carregaMenu();

        /**
         * Metodo para iniciar o jogo
         * @param dif dificuldade para startar o jogo
         */
        void jogo();

        /**
         * Metodo para desenhar o boneco representando os erros do jogador
         * @param tentativas Quantas chances o jogador ainda tem de acertar
         * @param boneco Matriz para desenhar o boneco
         */
        void desenhaBoneco(int tentativas, std::string boneco[5][5]);

        /**
         * Metodo que verifica se o jogador deseja continuar jogando 
         */
        bool confirma();

        /**
         * Metodo que gera uma palavra para o jogador adivinhar
         * @param dificuldade para gerar a palavra de acordo com a dificuldade
         * @param pal indice da palavra na matriz de strings
         */
        bool geraPalavra();
        
        /**
         * Metodo que conta quantas consoantes existem na palavra
         * @return quantas consoantes tem a palavra
         */
        int contaConsoantes();

        /**
         * Método para inserir dados no arquivo de score
         */
        void insereScore();

        /**
         * Método para imprimir scores
         */
        void imprimeScore();
};

#endif
