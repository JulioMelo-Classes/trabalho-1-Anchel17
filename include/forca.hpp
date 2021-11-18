#ifndef FORCA_HPP
#define FORCA_HPP

#include <iostream>
#include <string>
#include <vector>

/**
 * Implementação da classe Forca, para um jogo da forca
 */
class Forca{
    private:

        std::string boneco[5][5];   //<!Boneco representando quantos erros o jogador cometeu
        
        std::vector<std::string> recebe; //<! Vector que recebe os dados do arquivo

        std::vector<std::string> palavras; //<!Vector que recebe as palavras do arquivo

        std::vector<unsigned int> ocorrencias; //<!Vector que recebe as ocorrencias das palavras

        std::vector<int> jafoi; //<!Vector que marca quais palavras já foram utilizadas
        
        std::string aux;             //<!auxiliar que recebe dados do arquivo e passa para o vector recebe

        std::string palavra;        //<!Palavra no jogo

        std::string nome;           //<!Nome do jogador

        std::string arqPalavras;    //<!Nome recebido pela main do arquivo palavras

        std::string arqScores;      //<!Nome recebido pela main do arquivo scores

        std::vector<char> carac;  //<!Vector de caracteres já digitados

        std::vector<std::string> acertadas; //<!vector que guarda as palavras que foram acertadas pelo jogador

        int dificuldade;            //<!Dificuldade do jogo

        int tentativas = 6;         //<!Tentativas restantes para o jogador acertar

        int pontos = 0;             //<!Pontos feitos pelo jogador

        bool conf = true;           //<!variavel que confirma se o jogador deseja continuar jogando

        unsigned int media;                  //<!Media de ocorrencia das palavras

        int facil = 0;               //<!Contador de palavras faceis

        int dificil = 0;            //<!Contador de palavras dificeis

        int indice;                 //<!Indice da palavra gerada

        int rodada = 0;             //<!Contador de rodadas

        int contAux = 0;               //<!Contador auxiliar no geraPalavra()
        
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

        /**
         * Método para validar o arquivo de scores
         */
        void validaScore();
};

#endif
