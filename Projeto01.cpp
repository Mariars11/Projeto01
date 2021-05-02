//Nome Completo: Maria Clara Rodrigues Silva  Matr�cula: UC21100014  Curso: Engenharia de Software
#include <stdio.h> //biblioteca para uso de printf e scanf
#include <locale.h> //biblioteca que permite a acentua��o dentro do printf
#include <string.h> //biblioteca para (strlen-Determina o tamanho de uma string) 
#include <stdlib.h> //biblioteca respons�vel pelo comando system();
#include <ctype.h> //biblioteca para o uso do toupper

/*Os coment�rios desse c�digo tem como fun��o ser informativo e explicar a inten��o, como recomenda o livro codigo limpo, por outro lado
 mesmo o livro recomendando o n�o uso de coment�rios ruidosos, os deixei para cumprir o que foi solicitado*/
int main () //fun��o main
{
	setlocale(LC_ALL, "Portuguese"); //ligada a biblioteca <locale.h> habilita a acentua��o em portugu�s
	//declara��o de variav�is com nomes significativos (CL)
	int sessoes, numPessoas, idade, feminino, masculino, crianca, adolescente, adulto, idoso, maiorFem, maiorMasc; //variaveis com nomes que revelam prop�sitos (CL)
	char filme[40], sexo; //nome do filme, sexo de cada pessoa
	 
	printf("SER�O SOLICITADAS ALGUMAS INFORMA��ES, RESPONDA CORRETAMENTE!\n"); //contextualiza��o para o usu�rio
	printf ("\n"); //pular linha para organizar o prompt
	//ENTRADA E PROCESSAMENTO
	do{
		do{ //o primeiro dado � o n�mero de sess�es, que dever� ser validado, deve aceitar exatamente 2 sess�es
			printf("Ol�, informe a quantidade de sess�es que foram realizadas: "); //apresenta texto na tela
		    scanf ("%d", &sessoes); //salvar sessoes na variavel
		    fflush(stdin); //limpa o buffer de mem�ria
			if (sessoes == 2) //restri��o do numero de sessoes para que seja valido
				printf("Certo, vamos para a pr�xima informa��o!\n"); 
			else printf("N�mero de sess�es inv�lidas, a quantidade de sess�es � 2.\n"); //apresenta na tela que o usuario devera apresentar um novo valor
		} while (sessoes != 2); //repeti��o quando o sess�es for diferente de 2
	    do{ //o segundo dado � o nome do filme, que dever� ser validado, n�o deve aceitar nome vazio
	    	printf ("Qual o nome do filme? "); //apresenta texto no tela
			fgets(filme, 40, stdin); //recebe string com espa�o em branco. fgtes("nome da vari�vel", "tamanho da vari�vel", stdin)
	    	fflush(stdin); //limpa o buffer de mem�ria
	    	if (strlen(filme) < 2) //strlen: verifica o tamanho da string, se n�o for digitado o nome do filme, apresenta o erro. (igual a 0, n�o funcionou)
	    	    printf("Por favor, digite o nome do filme.\n"); 
	    	else printf ("Obrigado, pr�xima informa��o!\n");    
		} while (strlen(filme) < 2); //repeti��o quando o nome do filme estiver vazio
		do{ //o terceiro dado � a quantidade de pessoas que assistiram o flime, que dever� ser validado, n�o pode aceitar valor inferior a 10
	    	printf ("Quantas pessoas assistiram o filme? "); //apresenta texto no tela
			scanf("%d", &numPessoas); //recebe string com espa�o em branco. fgtes("nome da vari�vel", "tamanho da vari�vel", stdin)
	    	fflush(stdin); //limpa o buffer de mem�ria
	    	if (numPessoas < 10) //strlen: verifica o tamanho da string, se n�o for digitado o nome do filme, apresenta o erro. (igual a 0, n�o funcionou)
	    	    printf("Desculpa esse n�mero de pessoas � inferior do que o esperado, tente novamente!\n"); 
	    	else printf ("Obrigado!\n");    
		} while (numPessoas < 10); //repeti��o quando o nome do filme estiver vazio
	break; //loop finito
    } while (true); //true loop infinito

	printf ("Agora, ser�o solicitadas informa��es espec�ficas sobre as pessoas que assistiram o filme!\n"); //contextualiza��o do proximo passo

    feminino = 0; //inicializa em 0, n�o interfere na soma
	masculino = 0; //inicializa em 0, n�o interfere na soma
	maiorMasc = 0; //inicializa em 0, n�o interfere na soma
	maiorFem = 0; //inicializa em 0, n�o interfere na soma
	crianca = 0; //inicializa em 0, n�o interfere na soma
	adolescente = 0; //inicializa em 0, n�o interfere na soma
	adulto = 0; //inicializa em 0, n�o interfere na soma
	idoso = 0; //inicializa em 0, n�o interfere na soma

	for (int i = 1; i <= numPessoas; i++) //declara��o da variavel de contagem dentro do for, repeti��o dos printf de acordo com o numero de pessoas 
	{
	  do{ 
		  printf("Informe a idade da pessoa %d: \n", i); //impress�o na tela, %d referente a cada pessoa
		  scanf("%d", &idade); //imprimir na tela
		  fflush(stdin); //limpa o buffer de mem�ria
		} while (idade < 3 || idade > 100); //restri��o de idade de 3 a 100 anos, se invalidada, usuario ter� que digitar novamente 
		   if (idade >= 3 && idade <= 13){ //restri��o da variavel crian�a
	  	   crianca = crianca + 1; //somar a variavel cada vez a condi��o for validada 
	        }
	       else if (idade >= 14 && idade <= 17){  //restri��o da variavel adolescente
	     	adolescente = adolescente + 1;  //somar a variavel cada vez a condi��o for validada 
	        }
	       else if (idade >= 18 && idade <= 64){  //restri��o da variavel adulto
	    	 adulto = adulto + 1;  //somar a variavel cada vez a condi��o for validada 
		    }
	       else if (idade >= 65 && idade <= 100){  //restri��o da variavel idoso
	     	 idoso = idoso + 1; //somar a variavel cada vez a condi��o for validada 
		    } 
		do{
		    printf("Informe o sexo da pessoa %d, lembrando que m � para o sexo masculino e f para o sexo feminino: \n", i); //imprimir na tela
    	    scanf("%c", &sexo); ////salvar sexo na variavel
    	    fflush(stdin);//limpa o buffer de mem�ria
	    	sexo = toupper(sexo); //transforma em maiuscula 
	     }while (sexo !='F' && sexo !='M'); // se invalidada, usuario ter� que digitar novamente 
		   if (sexo == 'F'){ //identificar o sexo atraves da resposta do usuario
	    	feminino = feminino + 1; //permite a contagem do numeros de pessoas do sexo feminino
		    }
		   else if (sexo == 'M'){ //identificar o sexo atraves da resposta do usuario
	       masculino = masculino + 1;  //permite a contagem do numeros de pessoas do sexo masculino
	        }   
	
           if (idade >=18 && sexo == 'F'){ //identificar se � do sexo feminino e maior de idade
		     maiorFem = maiorFem + 1; //somar a variavel cada vez a condi��o for validada 
	         }
	       else if (idade >= 18 && sexo == 'M'){ //identificar se � do sexo masculino e maior de idade
	     	maiorMasc = maiorMasc + 1; //somar a variavel cada vez a condi��o for validada 
	        }
	}
	//SAIDA
	//Primeira apresenta��o dos dados em uma janela limpa
	  system ("cls"); //limpeza da janela
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf ("ESSES FORAM OS DADOS DE CADA SESS�O: "); //contextualiza��o para o usuario
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("O nome do filme �: %s\n", filme); // dado do filme
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Assistiram ao filme %d pessoas do sexo feminino!\n", feminino); //dado do sexo feminino
	  printf("Assistiram ao filme %d pessoas do sexo masculino!\n", masculino); //dado do sexo masculino
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Quantidade de crian�as que assistiram esse filme: %d\n", crianca); //dado da idade crian�a
	  printf("Quantidade de adolescentes que assistiram esse filme: %d\n", adolescente); //dado da idade adolescente
	  printf("Quantidade de adultos que assistiram esse filme: %d\n", adulto); //dado da idade adulto
	  printf("Quantidade de idosos que assistiram esse filme: %d\n", idoso); //dado da idade idoso
	  //Segunda apresenta��o dos dados, para que n�o fosse automatizada a limpeza da janela, utilizei o system ("pause");
	  system("pause"); //far� o usuario pressionar uma tecla para prosseguir, de forma que a tela n�o ser� limpa automaticamente
	  system ("cls");  //limpeza da janela
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Maiores de idade do sexo masculino s�o %d\n", maiorMasc); //dado de pessoas maiores de idade e do sexo masculino
	  printf("Maiores de idade do sexo feminino s�o %d\n", maiorFem); //dado de pessoas maiores de idade e do sexo feminino
	  printf("Muito obrigado pela colabora��o!"); //contextualiza��o 
	
	return 0; //Apresenta se o algoritmo compilou com sucesso. Seu resultado poder� ser utilizado em outras fun��es.
} //finaliza o programa

