
void jogo_forca(void);

extern char palavrasecreta[20];
extern char chutes[26];
extern int chutesdados;
extern char tema[10];

#define QNTD_DE_ERROS 10
int ganhou();
int enforcou();
int jachutou(char);
void escolhepalavra(void);
void escolhetema(void);
void chuta(char letra);
