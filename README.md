# Jogos em C

Este projeto contém jogos desenvolvidos durante a formação em C oferecida pela empresa Alura. Para ir além, também foi implementada uma interface gráfica utilizando o toolkit GTK em conjunto com o Glade e um pouquinho de CSS.

Ao todo, o repositório inclui três jogos:

- Adivinhação: Tente descobrir o número gerado aleatoriamente pelo sistema.

- Forca: O tradicional jogo da forca, onde você precisa adivinhar a palavra oculta antes que o desenho do boneco na forca seja completado.

- Foge-Foge: Inspirado no Pac-Man, este jogo desafia você a derrotar todos os fantasmas usando bombinhas enquanto foge deles.

Para executar a aplicação, execute as linhas de código no seu terminal:

1. Clone o projeto em seu repositório
    ```
    git clone https://github.com/Rodrix-go/Jogos-em-C.git
    ```
2. Compile todos os arquivos:
    ```
    gcc Menu/menu.c Foge/fogefoge.c Foge/mapa.c Foge/ui.c Adivinha/jogoadivin.c Forca/JogoForca.c Forca/JogoForcaGUI.c  -o exe `pkg-config --cflags --libs gtk+-3.0`  -rdynamic
    ```

3. Execute o programa
    ```
    ./exe
    ```

Certifique-se de ter as dependências necessárias instaladas antes de compilar e executar os jogos. Que nesse caso é somente  o gtk. 

Qualquer dúvida estou a disposição !!




