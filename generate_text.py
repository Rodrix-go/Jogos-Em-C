# Abre o arquivo no modo de leitura ('r')
left = 0
top = 0


with open('a.txt', 'r') as arquivo:
    # Lê cada linha do arquivo
    linhas = arquivo.readlines()

with open('b.txt', 'w') as arquivo:
    # Itera sobre as linhas e imprime cada uma
    for linha in linhas:
        if 'GtkImage' in linha:
            string = f'GtkImage" id="foge_image{left}x{top}'
            linha = linha.replace('GtkImage', string)
            print(f"GtkWidget foge_image{left}x{top}")

        if 'left-attach' in linha:
            string = f'h">{left}'
            linha = linha.replace(f'h">{linha[45]}', string)

        if 'top-attach' in linha:

            string = f'h">{top}'
            linha = linha.replace(f'h">{linha[44]}', string)

            top += 1
            if top > 5:
                top = 0
                left += 1
        arquivo.write(linha)


# O bloco 'with' garante que o arquivo seja fechado automaticamente após a leitura
