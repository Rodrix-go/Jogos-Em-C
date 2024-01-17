# Abre o arquivo no modo de leitura ('r')
left = 0
top = 0

for left in range(10):
    print("{", end='')
    for top in range(6):
        if top > 4:
            print(f"foge_image{left}x{top}", end='')
        else:
            print(f"foge_image{left}x{top},", end='')
    print("},", end='\n')

# O bloco 'with' garante que o arquivo seja fechado automaticamente após a leitura
