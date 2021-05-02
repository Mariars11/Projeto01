//Nome Completo: Maria Clara Rodrigues Silva  Matrícula: UC21100014  Curso: Engenharia de Software
#include <stdio.h> //biblioteca para uso de printf e scanf
#include <locale.h> //biblioteca que permite a acentuação dentro do printf
#include <string.h> //biblioteca para (strlen-Determina o tamanho de uma string) 
#include <stdlib.h> //biblioteca responsável pelo comando system();
#include <ctype.h> //biblioteca para o uso do toupper

/*Os comentários desse código tem como função ser informativo e explicar a intenção, como recomenda o livro codigo limpo, por outro lado
 mesmo o livro recomendando o não uso de comentários ruidosos, os deixei para cumprir o que foi solicitado*/
int main () //função main
{
	setlocale(LC_ALL, "Portuguese"); //ligada a biblioteca <locale.h> habilita a acentuação em português
	//declaração de variavéis com nomes significativos (CL)
	int sessoes, numPessoas, idade, feminino, masculino, crianca, adolescente, adulto, idoso, maiorFem, maiorMasc; //variaveis com nomes que revelam propósitos (CL)
	char filme[40], sexo; //nome do filme, sexo de cada pessoa
	 
	printf("SERÃO SOLICITADAS ALGUMAS INFORMAÇÕES, RESPONDA CORRETAMENTE!\n"); //contextualização para o usuário
	printf ("\n"); //pular linha para organizar o prompt
	//ENTRADA E PROCESSAMENTO
	do{
		do{ //o primeiro dado é o número de sessões, que deverá ser validado, deve aceitar exatamente 2 sessões
			printf("Olá, informe a quantidade de sessões que foram realizadas: "); //apresenta texto na tela
		    scanf ("%d", &sessoes); //salvar sessoes na variavel
		    fflush(stdin); //limpa o buffer de memória
			if (sessoes == 2) //restrição do numero de sessoes para que seja valido
				printf("Certo, vamos para a próxima informação!\n"); 
			else printf("Número de sessões inválidas, a quantidade de sessões é 2.\n"); //apresenta na tela que o usuario devera apresentar um novo valor
		} while (sessoes != 2); //repetição quando o sessões for diferente de 2
	    do{ //o segundo dado é o nome do filme, que deverá ser validado, não deve aceitar nome vazio
	    	printf ("Qual o nome do filme? "); //apresenta texto no tela
			fgets(filme, 40, stdin); //recebe string com espaço em branco. fgtes("nome da variável", "tamanho da variável", stdin)
	    	fflush(stdin); //limpa o buffer de memória
	    	if (strlen(filme) < 2) //strlen: verifica o tamanho da string, se não for digitado o nome do filme, apresenta o erro. (igual a 0, não funcionou)
	    	    printf("Por favor, digite o nome do filme.\n"); 
	    	else printf ("Obrigado, próxima informação!\n");    
		} while (strlen(filme) < 2); //repetição quando o nome do filme estiver vazio
		do{ //o terceiro dado é a quantidade de pessoas que assistiram o flime, que deverá ser validado, não pode aceitar valor inferior a 10
	    	printf ("Quantas pessoas assistiram o filme? "); //apresenta texto no tela
			scanf("%d", &numPessoas); //recebe string com espaço em branco. fgtes("nome da variável", "tamanho da variável", stdin)
	    	fflush(stdin); //limpa o buffer de memória
	    	if (numPessoas < 10) //strlen: verifica o tamanho da string, se não for digitado o nome do filme, apresenta o erro. (igual a 0, não funcionou)
	    	    printf("Desculpa esse número de pessoas é inferior do que o esperado, tente novamente!\n"); 
	    	else printf ("Obrigado!\n");    
		} while (numPessoas < 10); //repetição quando o nome do filme estiver vazio
	break; //loop finito
    } while (true); //true loop infinito

	printf ("Agora, serão solicitadas informações específicas sobre as pessoas que assistiram o filme!\n"); //contextualização do proximo passo

    feminino = 0; //inicializa em 0, não interfere na soma
	masculino = 0; //inicializa em 0, não interfere na soma
	maiorMasc = 0; //inicializa em 0, não interfere na soma
	maiorFem = 0; //inicializa em 0, não interfere na soma
	crianca = 0; //inicializa em 0, não interfere na soma
	adolescente = 0; //inicializa em 0, não interfere na soma
	adulto = 0; //inicializa em 0, não interfere na soma
	idoso = 0; //inicializa em 0, não interfere na soma

	for (int i = 1; i <= numPessoas; i++) //declaração da variavel de contagem dentro do for, repetição dos printf de acordo com o numero de pessoas 
	{
	  do{ 
		  printf("Informe a idade da pessoa %d: \n", i); //impressão na tela, %d referente a cada pessoa
		  scanf("%d", &idade); //imprimir na tela
		  fflush(stdin); //limpa o buffer de memória
		} while (idade < 3 || idade > 100); //restrição de idade de 3 a 100 anos, se invalidada, usuario terá que digitar novamente 
		   if (idade >= 3 && idade <= 13){ //restrição da variavel criança
	  	   crianca = crianca + 1; //somar a variavel cada vez a condição for validada 
	        }
	       else if (idade >= 14 && idade <= 17){  //restrição da variavel adolescente
	     	adolescente = adolescente + 1;  //somar a variavel cada vez a condição for validada 
	        }
	       else if (idade >= 18 && idade <= 64){  //restrição da variavel adulto
	    	 adulto = adulto + 1;  //somar a variavel cada vez a condição for validada 
		    }
	       else if (idade >= 65 && idade <= 100){  //restrição da variavel idoso
	     	 idoso = idoso + 1; //somar a variavel cada vez a condição for validada 
		    } 
		do{
		    printf("Informe o sexo da pessoa %d, lembrando que m é para o sexo masculino e f para o sexo feminino: \n", i); //imprimir na tela
    	    scanf("%c", &sexo); ////salvar sexo na variavel
    	    fflush(stdin);//limpa o buffer de memória
	    	sexo = toupper(sexo); //transforma em maiuscula 
	     }while (sexo !='F' && sexo !='M'); // se invalidada, usuario terá que digitar novamente 
		   if (sexo == 'F'){ //identificar o sexo atraves da resposta do usuario
	    	feminino = feminino + 1; //permite a contagem do numeros de pessoas do sexo feminino
		    }
		   else if (sexo == 'M'){ //identificar o sexo atraves da resposta do usuario
	       masculino = masculino + 1;  //permite a contagem do numeros de pessoas do sexo masculino
	        }   
	
           if (idade >=18 && sexo == 'F'){ //identificar se é do sexo feminino e maior de idade
		     maiorFem = maiorFem + 1; //somar a variavel cada vez a condição for validada 
	         }
	       else if (idade >= 18 && sexo == 'M'){ //identificar se é do sexo masculino e maior de idade
	     	maiorMasc = maiorMasc + 1; //somar a variavel cada vez a condição for validada 
	        }
	}
	//SAIDA
	//Primeira apresentação dos dados em uma janela limpa
	  system ("cls"); //limpeza da janela
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf ("ESSES FORAM OS DADOS DE CADA SESSÃO: "); //contextualização para o usuario
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("O nome do filme é: %s\n", filme); // dado do filme
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Assistiram ao filme %d pessoas do sexo feminino!\n", feminino); //dado do sexo feminino
	  printf("Assistiram ao filme %d pessoas do sexo masculino!\n", masculino); //dado do sexo masculino
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Quantidade de crianças que assistiram esse filme: %d\n", crianca); //dado da idade criança
	  printf("Quantidade de adolescentes que assistiram esse filme: %d\n", adolescente); //dado da idade adolescente
	  printf("Quantidade de adultos que assistiram esse filme: %d\n", adulto); //dado da idade adulto
	  printf("Quantidade de idosos que assistiram esse filme: %d\n", idoso); //dado da idade idoso
	  //Segunda apresentação dos dados, para que não fosse automatizada a limpeza da janela, utilizei o system ("pause");
	  system("pause"); //fará o usuario pressionar uma tecla para prosseguir, de forma que a tela não será limpa automaticamente
	  system ("cls");  //limpeza da janela
	  printf("\n"); //pular uma linha para organizar o prompt
	  printf("Maiores de idade do sexo masculino são %d\n", maiorMasc); //dado de pessoas maiores de idade e do sexo masculino
	  printf("Maiores de idade do sexo feminino são %d\n", maiorFem); //dado de pessoas maiores de idade e do sexo feminino
	  printf("Muito obrigado pela colaboração!"); //contextualização 
	
	return 0; //Apresenta se o algoritmo compilou com sucesso. Seu resultado poderá ser utilizado em outras funções.
} //finaliza o programa

