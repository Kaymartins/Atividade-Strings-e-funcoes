/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ UNIFAL − U ni v e r si d a d e F e d e r al de Al f e n a s .
∗ BACHARELADO EM CIENCIA DA COMPUTACAO.
∗ Trabalho . . : A ti vi d a d e 3
∗ D i s c i p l i n a : Programacao
∗ P r o f e s s o r . : Luiz Eduardo da S i l v a
∗ Aluno . . . . . : Kayan Martins de Freitas
∗ Data . . . . . . : 30/07/2021
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
#include<stdio.h>

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 ∗ Calcula o comprimento do string
 ∗ Recebe o string s
 ∗ Retorna o comprimento de s
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
int strlength(char *s)
{
   int i;
   for (i = 0; s[i]; i++);
   return i;
} 

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ Lê um string
∗ Parametros :
∗ s = stringa a ser lido
∗ len = tamanho maximo da leitura (contar o \0 e \n).
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void strread (char *s, int len)
{
   fgets (s, len, stdin);
   s[strlength (s) - 1] = '\0';
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ Mostra os elementos do vetor string em modo texto
∗ Parametros :
∗ s = string
∗ name = nome do string
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/
void strshow(char *s, char *name)
{
   int i;
   for (i = 0; s[i]; i++)
      printf("%3d ", i);
   printf("%3d\n", i);
   for (i = 0; s[i]; i++)
      printf("+---");
   printf("+---+\n");
   for (i = 0; s[i]; i++)
      printf("| %c ", s[i]);
   printf("| \\0| %s\n", name);
   for (i = 0; s[i]; i++)
      printf("+---");
   printf("+---+\n");
}

/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
* Insere um substring num string na posição específicada
* Parametros :
* pos = posição onde inserir (0 é a primeira posicao)
* sub = sub string que sera inserido em s
* s = string onde inserir sub
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

void strinsert (int pos, char *sub, char *s)
{
   int p=0,i=0, x=0, ultimaP; 
   while(sub[x] != '\0'){x += 1;}//pegando o tamanho do substring;
   while(s[i] != '\0'){i += 1;}//tamanho do string;
   ultimaP = x+i;//ultima posição do novo string

   if (pos>ultimaP){
         x -= 1;
         p = 0;
         while(p<=x){
            s[i] = sub[p];
            i+=1;
            p+=1;
         }
   }else{
      i-=1;//desconsiderando o \0
      while(i>=pos){ //vai fazer a passagem da posição i do atual string até a posição pos para o novo string
         s[i+x] = s[i];
         i -= 1;
      }
   } 
   s[ultimaP] = '\0'; //setando a ultima posição do atual vetor para que a execução anterior nao apareça.

   x = 0;
   while(sub[x] != '\0'){x += 1;}//pegando o tamanho do substring;

   x -= 1; //desconsiderando o \0
   x = pos+x; //até qual posicao o substring será inserido
   i = pos;

   while (i <= x){//implementando o substring no string que ja possui novas posições e pode ter suas posições substituidas   
      s[i] = sub[p];//trocando o string pelo substring
      i += 1;
      p += 1;
   }  

}
/*−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
∗ transforma um literal em inteiro
∗ o literal pode ter sinal (+ ou −) seguido de digitos
∗−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

int str2int (char *s)
{
   int i = 0, result=0;

      if (s[i] == '-'){ 
         i=1;//posição 0 é o sinal
         while (s[i] != '\0'){
            result = result*10 + (s[i] - 48);
            i++;
         }
         result = (result)*(-1); //multiplica pois é negativo
      }else if (s[i] == '+')
      {
         i=1;
         while (s[i] != '\0'){
            result = result*10 + (s[i] - 48);
            i++;
         }
      }else{
         while (s[i] != '\0'){
            result = result*10 + (s[i] - 48);
            i++;
         }
      }
   return result;

}


int main (void)
{
   char string [100] ;// onde o substring sera inserido
   char substring [100]; //string a ser inserida 
   char posstr [4];
   int posicao;
do
  {
    strread (posstr, 4);
    posicao = str2int (posstr);
    printf ( "\nPosição = %d\n ", posicao);
    if (posicao >= 0){
       strread(substring, 30);
       strshow(substring, "substr .");
       strread(string, 70);
       strshow(string, "string");
       strinsert(posicao, substring, string);
       strshow(string, "result .");
    }

  } 
    while (posicao >= 0) ;
}