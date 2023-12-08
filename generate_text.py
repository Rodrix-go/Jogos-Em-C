letra = 'A'
linha1 = f"void on_button_{letra}_clicked(GtkButton *b)"
linha2 = "{"
linha3 = f"  chuta('{letra}');"
linha4 = f"  gtk_widget_destroy(button_{letra});"
linha5 = f"  desenhaforca();"
linha6 = "}"


for letra in range(ord('A'), ord('Z')+1):

    linha1 = f'GtkWidget *button_{chr(letra)};'
    print(linha1)
