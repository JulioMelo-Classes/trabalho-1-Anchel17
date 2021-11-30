# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

# Documento de Especificação

# Como compilar o projeto

Abra o terminal de sua preferência e execute os seguintes comandos:

- cd trabalho-1-Anchel17
- mkdir build
- cd build
- cmake ../
- make



# Como executar o projeto

Com o projeto compilado, digite a seguinte linha para executar o jogo:

./jogo ../data/palavras.txt ../data/scores.txt

  A partir disso, o programa vai ler os arquivos de palavras e scores, 
em seguida você é levado para o menu principal do jogo.



# Funcionalidades não implementadas

  - Validação completa do arquivo de scores
  - Pontuação extra caso o jogador adivinhe a palavras inteira

# Avaliação

## Código | Funcionalidades
1. Classe forca 10/10
- O unico problema real aqui foi dividir a implementação em 2 arquivos.

2. Interface textual 10/10

3. Execução completa do jogo 10/15
- No nível de dificuldade fácil e média, faltou sortear as letras de "handcap"
- Faltou calcular a pontuação corretamente
- Faltou testar o caso do fim de jogo onde as palavras são todas sorteadas.

4. Validação dos arquivos de texto 5/5

- Mesmo faltando algumas validações vou considerar 100%

5. Arquivos de teste de validação dos casos de erro 0/5
- A ideia aqui era vc colocar arquivos de teste que mostrassem os casos de erro de validação

6. Arquivos de teste de validação dos níveis de dificuldade 1/5
- Vou considerar o arquivo de palavras enviado como sendo um arquivo de teste, porém vc poderia ter
criado mais arquivos com palavras para testar especialmente o fim de jogo.

7. Observações gerais
- você não precisa usar srand toda vez que vai chamar rand, chamar srand com time
apenas uma vez é suficiente para garantir que toda execução será diferente
- Como eu te falei na entrevista, a leitura dos arquivos está feita de uma forma que causa
problema quando o arquivo tem um "enter" no fim.

## Código | Boas práticas

1. Documentação do código e readme 10/10

2. Organização e indentação 5/10
- Vou tirar pontos neste quesito pela forma como foi feito o include no main e também a divisão da implementação
do forca hpp em 2 arquivos. Nesse caso, você precisava modularizar mais, se achou que os méotodos ficaram muito
grandes.

3. Compilação automatizada 5/5