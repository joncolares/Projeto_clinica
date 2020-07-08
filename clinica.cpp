#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
//declaracao de registro
		typedef struct login{
		char login[15],senha[20];
		}login;
		
		typedef struct contato{
			char email[30];
			int tel1,tel2;
		}contato;
		
		typedef struct endereco{
			char rua[15], bairro[15];
			int casa;
		}endereco;
		
		typedef struct medico{
			char nome[30],cpf[16],rg[10], nomeespecialidade[15],ufcrm[4];
			int crm;
			float valor;
			login log;
		}medico;
		
		typedef struct atendente{
			char nome[30],cpf[16];
			login log;
		}atendente;
		
		typedef struct funcionario{
		atendente ate;
		contato cont;
		endereco end;
		medico med;
		
		}funcionario;
		 
		typedef struct convenio{
			char nome[20];
			int nmatricula;
			
		}convenio; 
		 
		typedef struct cliente{
		char nome[30],cpf[16],rg[10];
		endereco end;
		contato cont;
		convenio cv;
		}cliente;
		
		typedef struct consulta{
			char nomecliente[30],nomemedico[30],nomeatendente[30],esp[15],status[20];
			float valor;			
			convenio cv;
		}consulta;
		
		//declaracao de arquivos
		FILE *fp;
		FILE *fe;
		FILE *fm;
		FILE *fc;//consultas
		FILE *fa;//atendentes
		//declaracao procedimentos
		void loginPrincipal();
		
		//menus
		void MenuAdm();
		void MenuAtendentes();
		void MenuMedicos();
		void MenuClientes();
		void MenuConvenio();
		void MenuConsulta(char lcomp[15]);
		void MenuRelatorio();
		//telas
		void TelaAtendente(char lcomp[15]);
		void TelaMedico(char lcomp[15]);
	
	
		//cadastros
		void CadastroAtendentes();
		void CadastroMedicos();
		void CadastroClientes();
		void CadastroConvenio();
		//Listar
		void ListarAtendentes();
		void ListarMedicos();
		void ListarClientes();
		void ListarConvenio();
		//pesquisar
		void PesquisarAtendentes();
		void PesquisarMedicos();
		void PesquisarClientes();
		void PesquisarConvenio();
		//Excluir
		void ExcluirAtendentes();
		void ExcluirMedicos();
		void ExcluirClientes();
		void ExcluirConvenio();
		//Alterar
		void AlterarAtendentes();
		void AlterarMedicos();
		void AlterarClientes();
		void AlterarConvenio();
		//Procedimentos Médicos
		void RealizarConsulta();
		void VisualizarConsulta(char lcomp[15]);
		//Procedimentos Atendente
		void MarcarConsulta(char lcomp[15]);
		void RemarcarConsulta();
		void ListarConsulta();
		void PesquisarConsulta();
		void CancelarConsulta();
		
		//Relatorios
		void RelatorioAtendimento();
		void RelatorioConsulta();
		
		// funcao principal
		main(){
		system("Title Clinica_Medica");
		
		loginPrincipal();
		
		system("pause");
		}
		
		void loginPrincipal(){
		int at,contf=0; 
		int tempo;    
		char loginadm[10],senhaadm[10],cp=0,lcomp[15],nomep[30];
		funcionario func;
		
		fp = fopen("Atendentes.txt","rb");
		fm = fopen("Medicos.txt","rb");
		
		//inicializacao administrador
		strcpy(loginadm,"adm");
		strcpy(senhaadm,"master");
		     
		//declaracao variaveis
		char loginpesq[10],senhapesq[10];
		int op;     
		
		system("color f0");
		do{
		
		
		system("cls");
		printf("\t\t\t\tSIS Clinica Medica\n ");             
		printf("\t\t\t\t\t\t\t");
		system("time/t");
		printf("\t\t\t\t\t\t\t");
		system("date/t");
		printf("\t\tLogin: ");
		fflush(stdin);
		gets(loginpesq);
		printf("\t\tSenha: ");
		fflush(stdin);
		gets(senhapesq);
		 
		if(strlen(loginpesq)>0 && strlen(senhapesq)>0 ){
		if(strcmp(strlwr(loginpesq),loginadm)==0 && strcmp(strlwr(senhapesq),senhaadm)==0){
			
				
					tempo=3;
					while(tempo>=0){
					Sleep(1000);
					system("cls");
					printf("\t\tSistema Inciando: %i\n",tempo);
					tempo=tempo-1;
					}
					
		  MenuAdm();
		 cp=1;       
		}
		
		rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
		 if(strcmp(strlwr(loginpesq),strlwr(func.ate.log.login))==0 && strcmp(strlwr(senhapesq),strlwr(func.ate.log.senha))==0){
		 	system("cls");
		 	tempo=3;
					while(tempo>=0){
					Sleep(1000);
					system("cls");
					printf("\t\tSistema Inciando: %i\n",tempo);
					tempo=tempo-1;
					}
					strcpy(lcomp,func.ate.nome);
					
		TelaAtendente(lcomp);
		  cp=1;   
		 }
	}//if feof
	}//while feof
		  fclose(fp);
		  // fm
		 rewind(fm);
			while(!feof(fm)){
				fread(&func,sizeof(funcionario),1,fm);
				if(!feof(fm)){
		 if(strcmp(strlwr(loginpesq),strlwr(func.med.log.login))==0 && strcmp(strlwr(senhapesq),strlwr(func.med.log.senha))==0){
		 	system("cls");
		 	tempo=3;
					while(tempo>=0){
					Sleep(1000);
					system("cls");
					printf("\t\tSistema Inciando: %i\n",tempo);
					tempo=tempo-1;
					}
					strcpy(lcomp,func.med.nome);
		TelaMedico(lcomp);
		  cp=1;   
		 }
	}//if feof fm
	}//while feof fm
		      fclose(fm);
		}//fim condicao if tamanho strlen.               
		
		if(cp==0){//inicio ct perfil
		printf("\t__________________________________________\n");
			system("cls");
		printf("\t\tSenha e login invalido\n");      
		printf("\tDesejar Continuar\n");
		printf("\t1-Voltar ao Login\n");
		printf("\t0-Sair do Sistema\n");
		printf("\tEscolha: ");
		scanf("%i",&op);
		
		if(op==0){
		exit(0);          
		}//fim exit 0
		}//fim ct perfil
		/*if(cp!=0){
			printf("\t__________________________________________\n");
			system("cls");
		printf("\t\tDigite\n");
		printf("\t1-Voltar ao Login\n");
		printf("\t0-Sair do Sistema\n");
		printf("\tEscolha: ");
		scanf("%i",&op);
		}
		*/ 	    
		}while(op!=0);//fim loop login
 
		}//fim procedimento login
	//menus	
		void MenuAdm(){
		int at;
		int op1;
			system("color c0");	
		
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo a Clinica Medica \n");                                   
		   printf("\t1-Atendentes\n");                                   
		   printf("\t2-Medicos\n");
		   printf("\t3-Clientes\n");  
		   printf("\t4-Relatorio\n");  
		   printf("\t5-Convenio\n");
		   printf("\t0-Sair\n");
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op1);
		   switch(op1){
		   		case 1:
			MenuAtendentes();
			break;
			
		        case 2:
			MenuMedicos();
			break;
			
		        case 3:
			MenuClientes();
			 break;
		        case 4:
			MenuRelatorio();
		        break;
		        case 5:
		        	MenuConvenio();
		        	break;
		    case 0:
		    	loginPrincipal();
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op1!=0);//fim menu adm  

		}//fim menu principal
		
		void MenuAtendentes(){
			int op2;
		do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Atendentes \n");                                   
		   printf("\t1-Cadastrar\n");                                   
		   printf("\t2-Pesquisar\n");
		   printf("\t3-Listar\n");  
		   printf("\t4-Alterar\n");  
		   printf("\t5-Excluir\n");  
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op2);
		   switch(op2){
		   		case 1:
			CadastroAtendentes();
		        break;
		        
		        case 2:
			PesquisarAtendentes();
		        break;
		        
		        case 3:
			ListarAtendentes();
		        break;
		        
		        case 4:
			AlterarAtendentes();
		        	break;
		        	
		        case 5:
					ExcluirAtendentes();
		        	break;
		        	
		    case 0:
		        op2=0;
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op2!=0);//fim menu adm 
	}//menu Aten
	
		void MenuMedicos(){
			int op3;
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Medicos\n");                                   
		   printf("\t1-Cadastrar\n");                                   
		   printf("\t2-Pesquisar\n");
		   printf("\t3-Listar\n");  
		   printf("\t4-Alterar\n");  
		   printf("\t5-Excluir\n");  
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op3);
		   switch(op3){
		   		case 1:
			CadastroMedicos();
		        break;
		        
		        case 2:
		        PesquisarMedicos();
		        break;
		        
		        case 3:
				ListarMedicos();
		        break;
		        
		        case 4:
				AlterarMedicos();
		        	break;
		        	
		        case 5:
			ExcluirMedicos();
		        	break;
		        	
		    case 0:
		        op3=0;
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op3!=0);//fim menu adm 
		        
		}
	
		void MenuClientes(){
			int op4;
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Clientes \n");                                   
		   printf("\t1-Cadastrar\n");                                   
		   printf("\t2-Pesquisar\n");
		   printf("\t3-Listar\n");  
		   printf("\t4-Alterar\n");  
		   printf("\t5-Excluir\n");  
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op4);
		   switch(op4){
		   		case 1:
			CadastroClientes();
		        break;
		       
		        case 2:
			 PesquisarClientes();
		        break;
		        
		        case 3:
			 ListarClientes();
		        break;
		        
		        case 4:
			 AlterarClientes();
		        	break;
		        	
		        case 5:
			 ExcluirClientes();
		        	break;
		    case 0:
		    op4=0;
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op4!=0);//fim menu adm 
		       
		}

		void MenuConvenio(){
			int op4;
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Convenio \n");                                   
		   printf("\t1-Cadastrar\n");                                   
		   printf("\t2-Pesquisar\n");
		   printf("\t3-Listar\n");  
		   printf("\t4-Alterar\n");  
		   printf("\t5-Excluir\n");  
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op4);
		   switch(op4){
		   		case 1:
			CadastroConvenio();
		        break;
		       
		        case 2:
			 PesquisarConvenio();
		        break;
		        
		        case 3:
			 ListarConvenio();
		        break;
		        
		        case 4:
			 AlterarConvenio();
		        	break;
		        	
		        case 5:
			 ExcluirConvenio();
		        	break;
		    case 0:
		    	op4=0;
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op4!=0);//fim menu adm 
		  system("cls");     
		}

		void MenuConsulta(char lcomp[15]){
			int op4;
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Consulta \n");                                   
		   printf("\t1-Marcar Consulta\n");                                   
		   printf("\t2-Remarcar Consulta\n");
		   printf("\t3-Pesquisar Consulta\n");
		   printf("\t4-Listar Consultas\n");   
		   printf("\t5-Cancelar Consulta\n");  
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op4);
		   switch(op4){
		   		case 1:
				MarcarConsulta(lcomp);
		        break;
		       
		        case 2:
				RemarcarConsulta();
		        break;
		        
		        case 3:
				PesquisarConsulta();
		        break;
		        
		        case 4:
				 ListarConsulta();
		        	break;
		        	case 5:
		        CancelarConsulta();
		        		break;
		    case 0:
		    	op4=0;
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op4!=0);//fim menu adm 
		  system("cls");     
		}

		void MenuRelatorio(){
			int op4;
			do{
					
				system("cls");
		   printf("\t\t\t\tBem vindo ao Menu Consulta \n");                                   
		   printf("\t1-Relatorio de Atendimentos\n");                                   
		   printf("\t2-Relatorio de Consultas\n");
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op4);
		   switch(op4){
		   		case 1:
				RelatorioAtendimento();
		        break;
		       
		        case 2:
				RelatorioConsulta();
		        break;
		    case 0:
		    	MenuAdm();
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }
		  }while(op4!=0);//fim menu adm 
		  system("cls");     
		}

		
	//fim Menus
	
	//Telas
		void TelaAtendente(char lcomp[15]){
			char loginpesq[15];
			int op2;
			funcionario func;
		fp = fopen("Atendentes.txt","rb");
		
			rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
		 if(strcmp(strlwr(lcomp),strlwr(func.ate.log.login))==0){
		do{
		system("cls");
		   printf("\t\t\t\tBem vindo Atendente: %s \n",func.ate.nome);                                   
		   printf("\t1-Clientes\n");                                  
		   printf("\t2-Consultas\n"); 
		   printf("\t3-Convênio\n");
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op2);
		   switch(op2){
		   		case 1:
		   			system("cls");
			MenuClientes();
		        break;
		        
		        case 2:
		        	system("cls");
			MenuConsulta(lcomp);
		        break;
		        case 3:
		        	system("cls");
		       MenuConvenio();	
		        	break;
		    case 0:
		        loginPrincipal();
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }

		  }while(op2!=0);//fim menu adm 	

	}
}
}
	
		}
	
		void TelaMedico(char lcomp[15]){
			int op2;
		
		do{
				system("cls");
			
		   printf("\t\t\t\tBem vindo Medico \n");                                   
		   printf("\t1-Visualizar Consulta\n");                                   
		   printf("\t2-Realizar Consulta\n"); 
		   printf("\t0-Sair\n");  
		   printf("\tEscolha: ");                                 
		   scanf("%d",&op2);
		   switch(op2){
		   		case 1:
				VisualizarConsulta(lcomp);
		        break;
		        
		        case 2:
				RealizarConsulta();
		        break;
		    case 0:
		        loginPrincipal();
		         break;         
		   default:
		   printf("Opcao invalida\n");         
		   }

		  }while(op2!=0);//fim menu adm 
	
		}
	
	
	//crud Atendentes	
		void CadastroAtendentes(){
		int op;
			
			funcionario func;
			fp = fopen("Atendentes.txt","ab+");
			setlocale(LC_ALL,"portuguese");
			system("cls");
			do{
			
					printf("\t\t\t\tCadastro de Atendentes\n\n");
					printf("\tNome: ");
					fflush(stdin);
					gets(func.ate.nome);
					printf("\tCPF: ");
					fflush(stdin);
					gets(func.ate.cpf);
					printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(func.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(func.end.rua);
					printf("\tCasa: ");
					scanf("%i",&func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: ");
					scanf("%i",&func.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&func.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(func.cont.email);
					printf("\n\n");
					printf("\tLogin: ");	
					fflush(stdin);
					gets(func.ate.log.login);
					printf("\tSenha: ");
					fflush(stdin);
					gets(func.ate.log.senha);
			
			fwrite(&func,sizeof(funcionario),1,fp);
			
			 printf("\t\t__________________________________________\n");
			 printf("\t\tDeseja continuar cadastrando Atendente?\n");   
			 printf("\t1-Sim\n");   
			 printf("\t0-Nao\n");   
			 printf("\tEscolha: ");
			 scanf("%i",&op);
			 system("cls");
			}while(op!=0);
		
			fclose(fp);
		}//fim menu principal
	
		void ListarAtendentes(){
			int op;
			funcionario func;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Atendentes.txt","rb+");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&func,sizeof(funcionario),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tAtendente\n");
				printf("\tNome: %s\n",func.ate.nome);
				printf("\tCPF: %s\n\n",func.ate.cpf);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.ate.log.login);	
					printf("\tSenha: %s\n",func.ate.log.senha);
					printf("\n\n");
					
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		}
		
		void PesquisarAtendentes(){
			char nomepesq[30];
			int i,aux=0;
			funcionario func;
			setlocale(LC_ALL,"portuguese");
		system("cls");
		fp = fopen("Atendentes.txt","rb");
			printf("\t\t\t\tPesquisa de Atendentes\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(func.ate.nome),strlwr(nomepesq))==0){
					printf("\t\tAtendente\n");
				printf("\tNome: %s\n",func.ate.nome);
				printf("\tCPF: %s\n\n",func.ate.cpf);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.ate.log.login);	
					printf("\tSenha: %s\n",func.ate.log.senha);
					printf("\n\n");
					
					
				aux=1;	
				}//fim comparacao
				
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
				}
			fclose(fp);

		system("pause");
		
		}//fim pesquisarpessoa
		
		void ExcluirAtendentes(){
		char nomepesq[30];
		int aux=0,cont=0,op, i=0;
		funcionario pes, *vetpessoa;
	
			
		setlocale(LC_ALL,"portuguese");
		
		vetpessoa = (funcionario *) malloc(1000*sizeof(funcionario));
		fp = fopen("Atendentes.txt","rb+");
		system("cls");
		printf("\t\t\t\tExcluir Dados Atendentes\n");
		printf("digite o nome: ");
		fflush(stdin);
		gets(nomepesq);
		
			rewind(fp);
			while(!feof(fp)){
				fread(&pes,sizeof(funcionario),1,fp);
				if(!feof(fp)){
			
					if(strcmp(strlwr(pes.ate.nome),strlwr(nomepesq))==0){
				printf("\t\tAtendente\n");
				printf("\tNome: %s\n",pes.ate.nome);
				printf("\tCPF: %s\n\n",pes.ate.cpf);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",pes.end.bairro);
					printf("\tRua: %s\n",pes.end.rua);
					printf("\tCasa: %i\n\n",pes.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",pes.cont.tel1);
					printf("\tTelefone 2: %i\n",pes.cont.tel2);
					printf("\tEmail: %s\n\n",pes.cont.email);
					printf("\tLogin: %s\n",pes.ate.log.login);	
					printf("\tSenha: %s\n",pes.ate.log.senha);
					printf("\n\n");
					
					fe = fopen("AtendentesExcluidos.txt","ab+");
					fwrite(&pes,sizeof(funcionario),1,fe);
					fclose(fe);
					printf("Dados Excluidos com Sucesso\n");
					system("pause");	
				}else{

					strcpy(vetpessoa[i].ate.nome,pes.ate.nome);
					strcpy(vetpessoa[i].ate.cpf,pes.ate.cpf);
					strcpy(vetpessoa[i].end.bairro,pes.end.bairro);
					strcpy(vetpessoa[i].end.rua,pes.end.rua);
					vetpessoa[i].end.casa=pes.end.casa;
					vetpessoa[i].cont.tel1=pes.cont.tel1;
					vetpessoa[i].cont.tel2=pes.cont.tel2;
					strcpy(vetpessoa[i].cont.email,pes.cont.email);
					strcpy(vetpessoa[i].ate.log.login,pes.ate.log.login);
					strcpy(vetpessoa[i].ate.log.senha,pes.ate.log.senha);
					
					i++;
			
		
			}// fim comparação
			
	}//if feof
	}//while feof
			fclose(fp);
			fp=fopen("Atendentes.txt","wb");
			
			fwrite(vetpessoa,sizeof(funcionario),i,fp);
			fclose(fp);
			free(vetpessoa);
	}// fim procedimento excluir

		void AlterarAtendentes(){
		char nomepesq[30];
		int aux=0,cont=0,i=0,op;
		funcionario func;
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Atendentes.txt","rb+");
		system("cls");
		printf("\t\t\t\tAlteracao Dados Atendente\n");
		printf("digite o nome para alterar: ");
		fflush(stdin);
		gets(nomepesq);
	
		
		rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
					if(strcmp(strlwr(func.ate.nome),strlwr(nomepesq))==0){
					printf("\t\tAtendente\n");
				printf("\tNome: %s\n",func.ate.nome);
				printf("\tCPF: %s\n\n",func.ate.cpf);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.ate.log.login);	
					printf("\tSenha: %s\n",func.ate.log.senha);
					printf("\n\n");
					
			printf("-------------------------------------\n");
			printf("\tO que deseja alterar?\n");
			printf("\t1-CPF\n");
			printf("\t2-ENDEREÇO\n");
			printf("\t3-CONTATO\n");
			printf("\t4-Login\n");
			printf("\t0-Sair\n");
			printf("\tEscolha: ");
			
			scanf("%i",&op);
			switch(op){
				case 1:
					system("cls");
		printf("\t\t\t\tAlteracao Dados Atendente\n");
			printf("digite novo CPF:");
			fflush(stdin);
			gets(func.ate.cpf);
					printf("\tDados Alterados com Sucesso\n\n");
					break;
					case 2:
						system("cls");
			printf("\t\t\t\tAlteracao Dados Atendente\n");
					printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(func.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(func.end.rua);
					printf("\tCasa: ");
					scanf("%i",&func.end.casa);
				printf("\tDados Alterados com Sucesso\n\n");
						break;
						case 3:
							system("cls");
		printf("\t\t\t\tAlteracao Dados Atendente\n");
					printf("\tContato");
					printf("\tTelefone 1: ");
					scanf("%i",&func.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&func.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(func.cont.email);
					printf("\tDados Alterados com Sucesso\n\n");
							break;
							case 4:
								system("cls");
		printf("\t\t\t\tAlteracao Dados Atendente\n");
					printf("\tLogin: ");	
					fflush(stdin);
					gets(func.ate.log.login);
					printf("\tSenha: ");
					fflush(stdin);
					gets(func.ate.log.senha);
					printf("\tDados Alterados com Sucesso\n\n");
								break;
							case 0:
								break;
					
					default:
						printf("Opcao invalida\n");
			}
			
			
					aux=1;
				fseek(fp,cont*sizeof(funcionario),SEEK_SET);
				fwrite(&func,sizeof(funcionario),1,fp);			
			break;
			}// fim comparação
				cont++;
			}//fim eof
			}//fim while
			
			
		if(aux==0) {
			printf("Pessoa nao encontrada\n");
			system("pause");
		}	
		system("pause");
			fclose(fp);
		}//fim condição alterar
		
	//Crud Medicos	
		void CadastroMedicos(){
		int op;
			
			funcionario func;
			setlocale(LC_ALL,"portuguese");
			fp = fopen("Medicos.txt","ab+");
			system("cls");
			do{
			
					printf("\t\t\t\tCadastro de Medicos\n\n");
					printf("\tNome: ");
					fflush(stdin);
					gets(func.med.nome);
					printf("\tCPF: ");
					fflush(stdin);
					gets(func.med.cpf);
					printf("\tRG: ");
					fflush(stdin);
					gets(func.med.rg);
					printf("\tCRM: ");
					scanf("%i",&func.med.crm);
					printf("\tUF CRM: ");
					fflush(stdin);
					gets(func.med.ufcrm);
					printf("\tEspecialidade: ");
					fflush(stdin);
					gets(func.med.nomeespecialidade);
					printf("\tValor Cobrado: ");
					scanf("%f",&func.med.valor);
					printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(func.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(func.end.rua);
					printf("\tCasa: ");
					scanf("%i",&func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: ");
					scanf("%i",&func.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&func.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(func.cont.email);
					printf("\n\n");
					printf("\tLogin: ");	
					fflush(stdin);
					gets(func.med.log.login);
					printf("\tSenha: ");
					fflush(stdin);
					gets(func.med.log.senha);
								
			fwrite(&func,sizeof(funcionario),1,fp);
			
			 printf("\t\t__________________________________________\n");
			 printf("\t\tDeseja continuar cadastrando Medico?\n");   
			 printf("\t1-Sim\n");   
			 printf("\t0-Nao\n");   
			 printf("\tEscolha: ");
			 scanf("%i",&op);
			 system("cls");
			}while(op!=0);
		
			fclose(fp);
		}//fim menu principal
	
		void ListarMedicos(){
			int op;
			funcionario func;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Medicos.txt","rb+");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&func,sizeof(funcionario),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tMedico\n");
				printf("\tNome: %s\n",func.med.nome);
				printf("\tCPF: %s\n",func.med.cpf);
				printf("\tRG: %s\n",func.med.rg);
				printf("\tCRM: %i\n",func.med.crm);
				printf("\tUF CRM: %s\n",func.med.ufcrm);
				printf("\tEspecialidade: %s\n\n",func.med.nomeespecialidade);
				printf("\tValor: %.2f\n",func.med.valor);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.med.log.login);	
					printf("\tSenha: %s\n",func.med.log.senha);
					printf("\n\n");
					break;
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		}
		
		void PesquisarMedicos(){
			char nomepesq[30];
			int i,aux=0;
			funcionario func;
			setlocale(LC_ALL,"portuguese");
		system("cls");
		fp = fopen("Medicos.txt","rb");
			printf("\t\t\t\tPesquisa de Medicos\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(func.med.nome),strlwr(nomepesq))==0){
					printf("\t\tMedico\n");
						printf("\tNome: %s\n",func.med.nome);
						printf("\tCPF: %s\n",func.med.cpf);
						printf("\tRG: %s\n",func.med.rg);
						printf("\tCRM: %i\n",func.med.crm);
						printf("\tUF CRM: %s\n",func.med.ufcrm);
						printf("\tEspecialidade: %s\n\n",func.med.nomeespecialidade);
						printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.med.log.login);	
					printf("\tSenha: %s\n",func.med.log.senha);
					printf("\n\n");
					
					
				aux=1;	
				}//fim comparacao
				
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
				}
			fclose(fp);

		system("pause");
		
		}//fim pesquisarpessoa
		
		void ExcluirMedicos(){
		char nomepesq[30];
		int aux=0,cont=0,op, i=0;
		funcionario pes, *vetpessoa;
	
			
		setlocale(LC_ALL,"portuguese");
		
		vetpessoa = (funcionario *) malloc(1000*sizeof(funcionario));
		fp = fopen("Medicos.txt","rb+");
		system("cls");
		printf("\t\t\t\tExcluir Dados Medicos\n");
		printf("digite o nome: ");
		fflush(stdin);
		gets(nomepesq);
		
			rewind(fp);
			while(!feof(fp)){
				fread(&pes,sizeof(funcionario),1,fp);
				if(!feof(fp)){
			
					if(strcmp(strlwr(pes.med.nome),strlwr(nomepesq))==0){
				printf("\t\tMedico\n");
				printf("\tNome: %s\n",pes.med.nome);
				printf("\tCPF: %s\n",pes.med.cpf);
				printf("\tRG: %s\n",pes.med.rg);
				printf("\tCRM: %i\n",pes.med.crm);
				printf("\tUF CRM: %s\n",pes.med.ufcrm);
				printf("\tEspecialidade: %s\n\n",pes.med.nomeespecialidade);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",pes.end.bairro);
					printf("\tRua: %s\n",pes.end.rua);
					printf("\tCasa: %i\n\n",pes.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",pes.cont.tel1);
					printf("\tTelefone 2: %i\n",pes.cont.tel2);
					printf("\tEmail: %s\n\n",pes.cont.email);
					printf("\tLogin: %s\n",pes.med.log.login);	
					printf("\tSenha: %s\n",pes.med.log.senha);
					printf("\n\n");
					
					fe = fopen("MedicosExcluidos.txt","ab+");
					fwrite(&pes,sizeof(funcionario),1,fe);
					fclose(fe);
					printf("Dados Excluidos com Sucesso\n");
					system("pause");	
				}else{

					strcpy(vetpessoa[i].med.nome,pes.med.nome);
					strcpy(vetpessoa[i].med.cpf,pes.med.cpf);
					strcpy(vetpessoa[i].med.rg,pes.med.rg);
					vetpessoa[i].med.crm=pes.med.crm;
					strcpy(vetpessoa[i].med.ufcrm,pes.med.ufcrm);
					strcpy(vetpessoa[i].med.nomeespecialidade,pes.med.nomeespecialidade);
					
					strcpy(vetpessoa[i].end.bairro,pes.end.bairro);
					strcpy(vetpessoa[i].end.rua,pes.end.rua);
					vetpessoa[i].end.casa=pes.end.casa;
					vetpessoa[i].cont.tel1=pes.cont.tel1;
					vetpessoa[i].cont.tel2=pes.cont.tel2;
					strcpy(vetpessoa[i].cont.email,pes.cont.email);
					strcpy(vetpessoa[i].ate.log.login,pes.ate.log.login);
					strcpy(vetpessoa[i].ate.log.senha,pes.ate.log.senha);
					
					i++;
			
		
			}// fim comparação
			
	}//if feof
	}//while feof
			fclose(fp);
			fp=fopen("Medicos.txt","wb");
			
			fwrite(vetpessoa,sizeof(funcionario),i,fp);
			fclose(fp);
			free(vetpessoa);
	}// fim procedimento excluir

		void AlterarMedicos(){
		char nomepesq[30];
		int aux=0,cont=0,i=0,op;
		funcionario func;
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Medicos.txt","rb+");
		system("cls");
		printf("\t\t\t\tAlteracao Dados Medicos\n");
		printf("digite o nome para alterar: ");
		fflush(stdin);
		gets(nomepesq);
	
		
		rewind(fp);
			while(!feof(fp)){
				fread(&func,sizeof(funcionario),1,fp);
				if(!feof(fp)){
					if(strcmp(strlwr(func.med.nome),strlwr(nomepesq))==0){
					printf("\t\tMedico\n");
				printf("\tNome: %s\n",func.med.nome);
				printf("\tCPF: %s\n",func.med.cpf);
				printf("\tRG: %s\n",func.med.rg);
				printf("\tCRM: %i\n",func.med.crm);
				printf("\tUF CRM: %s\n",func.med.ufcrm);
				printf("\tEspecialidade: %s\n\n",func.med.nomeespecialidade);
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",func.end.bairro);
					printf("\tRua: %s\n",func.end.rua);
					printf("\tCasa: %i\n\n",func.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",func.cont.tel1);
					printf("\tTelefone 2: %i\n",func.cont.tel2);
					printf("\tEmail: %s\n\n",func.cont.email);
					printf("\tLogin: %s\n",func.med.log.login);	
					printf("\tSenha: %s\n",func.med.log.senha);
					printf("\n\n");
			
			printf("-------------------------------------\n");
			printf("\tO que deseja alterar?\n");
			printf("\t1-Atributos como (CPF,RG,CRM,UFCRM e Especialidade)\n");
			printf("\t2-Endereco\n");
			printf("\t3-Contanto\n");
			printf("\t4-Login\n");
			printf("\t0-Sair\n");
			printf("\tEscolha: ");
			scanf("%i",&op);
			switch(op){
				case 1:
					system("cls");
		printf("\t\t\t\tAlteracao Dados Medicos\n");
					printf("\tCPF: ");
					fflush(stdin);
					gets(func.med.cpf);
					printf("\tRG: ");
					fflush(stdin);
					gets(func.med.rg);
					printf("\tCRM: ");
					scanf("%i",&func.med.crm);
					printf("\tUF CRM: ");
					fflush(stdin);
					gets(func.med.ufcrm);
					printf("\tEspecialidade: ");
					fflush(stdin);
					gets(func.med.nomeespecialidade);
					printf("\tDados Alterados com Sucesso\n\n");
					break;
					case 2:
			system("cls");
		printf("\t\t\t\tAlteracao Dados Medicos\n");
			printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(func.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(func.end.rua);
					printf("\tCasa: ");
					scanf("%i",&func.end.casa);
			printf("\tDados Alterados com Sucesso\n\n");
						break;
						
						case 3:
							system("cls");
		printf("\t\t\t\tAlteracao Dados Medicos\n");
							printf("\tContato\n");
					printf("\tTelefone 1: ");
					scanf("%i",&func.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&func.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(func.cont.email);
					printf("\tDados Alterados com Sucesso\n\n");
							break;
							case 4:
							system("cls");
					printf("\t\t\t\tAlteracao Dados Medicos\n");
					printf("\tLogin: ");	
					fflush(stdin);
					gets(func.med.log.login);
					printf("\tSenha: ");
					fflush(stdin);
					gets(func.med.log.senha);
					printf("\tDados Alterados com Sucesso\n\n");
								break;
							case 0:
								break;
					
					default:
						printf("Opcao invalida\n");
			}
			
			
					aux=1;
				fseek(fp,cont*sizeof(funcionario),SEEK_SET);
				fwrite(&func,sizeof(funcionario),1,fp);			
			break;
			}// fim comparação
				cont++;
			}//fim eof
			}//fim while
			
			
		if(aux==0) {
			printf("Pessoa nao encontrada\n");
			system("pause");
		}	
		system("pause");
			fclose(fp);
		}//fim condição alterar
		
		//crud Clientes
		
		void CadastroClientes(){
		int op,op1,aux=0;
		char nomepesq[20];
			cliente cli;
			setlocale(LC_ALL,"portuguese");
			fp = fopen("Clientes.txt","ab+");
			system("cls");
			do{
			
					printf("\t\t\t\tCadastro de Clientes\n\n");
					printf("\tNome: ");
					fflush(stdin);
					gets(cli.nome);
					printf("\tCPF: ");
					fflush(stdin);
					gets(cli.cpf);
					printf("\tRG: ");
					fflush(stdin);
					gets(cli.rg);
					
					printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(cli.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(cli.end.rua);
					printf("\tCasa: ");
					scanf("%i",&cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: ");
					scanf("%i",&cli.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&cli.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(cli.cont.email);
					printf("\n\n");
					
				printf("\t\t__________________________________________\n");
			 printf("\t\tPossui Convenio?\n");   
			 printf("\t1-Sim\n");   
			 printf("\t0-Nao\n");   
			 printf("\tEscolha: ");
			 scanf("%i",&op1);
			 if(op1==1){
			 	fc = fopen("Convenio.txt","rb");
			 	convenio cv;
			 	printf("\t\tCadastro de Convenio\n");
					rewind(fc);
					while(!feof(fc)){
					fread(&cv,sizeof(convenio),1,fc);
					if(!feof(fc)){
					printf("Convenio: %s\n",cv.nome);
					printf("\tNumero da Matricula do Convenio: %i",cv.nmatricula);
					printf("\n\n");
				}//if
			}//while
			printf("\tNome do Convenio: ");
					fflush(stdin);
					gets(cli.cv.nome);
					printf("\tNumero da Matricula do Convenio: ");
					scanf("%i",&cli.cv.nmatricula);
			 }else{
			 	strcpy(cli.cv.nome,"");
			 	cli.cv.nmatricula=0;
			 }			
								
			fwrite(&cli,sizeof(cliente),1,fp);
			
			 printf("\t\t__________________________________________\n");
			 printf("\t\tDeseja continuar cadastrando Cliente?\n");   
			 printf("\t1-Sim\n");   
			 printf("\t0-Nao\n");   
			 printf("\tEscolha: ");
			 scanf("%i",&op);
			 system("cls");
			}while(op!=0);
		
	system("cls");
			fclose(fp);
		}//fim menu principal
	
		void ListarClientes(){
			int op;
			cliente cli;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Clientes.txt","rb+");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&cli,sizeof(cliente),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tCliente\n");
				printf("\tNome: %s\n",cli.nome);
				printf("\tCPF: %s\n",cli.cpf);
				printf("\tRG: %s\n",cli.rg);
				
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",cli.end.bairro);
					printf("\tRua: %s\n",cli.end.rua);
					printf("\tCasa: %i\n\n",cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",cli.cont.tel1);
					printf("\tTelefone 2: %i\n",cli.cont.tel2);
					printf("\tEmail: %s\n\n",cli.cont.email);
					printf("\n\n");
					printf("\tConvenio\n");
					if(cli.cv.nome && cli.cv.nmatricula != NULL){
					printf("\tNome: %s\n\n",cli.cv.nome);
					printf("\tNumero da Matricula: %i\n\n",cli.cv.nmatricula);
				}else{
					printf("Cliente não possui convenio\n\n");
				}
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		system("cls");
		}
		
		void PesquisarClientes(){
			char nomepesq[30];
			int i,aux=0;
			cliente cli;
		system("cls");
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Clientes.txt","rb");
			printf("\t\t\t\tPesquisa de Clientes\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&cli,sizeof(cliente),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(cli.nome),strlwr(nomepesq))==0){
				printf("\t\tCliente\n");
				printf("\tNome: %s\n",cli.nome);
				printf("\tCPF: %s\n",cli.cpf);
				printf("\tRG: %s\n",cli.rg);
				
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",cli.end.bairro);
					printf("\tRua: %s\n",cli.end.rua);
					printf("\tCasa: %i\n\n",cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",cli.cont.tel1);
					printf("\tTelefone 2: %i\n",cli.cont.tel2);
					printf("\tEmail: %s\n\n",cli.cont.email);
					printf("\n\n");
					printf("\tConvenio\n");
					if(cli.cv.nome && cli.cv.nmatricula != NULL){
					printf("\tNome: %s\n\n",cli.cv.nome);
					printf("\tNumero da Matricula: %i\n\n",cli.cv.nmatricula);
				}else{
					printf("Cliente não possui convenio\n");
				}
					
					
				aux=1;	
				}//fim comparacao
				
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
				}
			fclose(fp);

		system("pause");
		
		}//fim pesquisarpessoa
		
		void ExcluirClientes(){
		char nomepesq[30];
		int aux=0,cont=0,op, i=0;
		cliente cli, *vetcli;
	
			
		setlocale(LC_ALL,"portuguese");
		
		vetcli = (cliente *) malloc(1000*sizeof(cliente));
		fp = fopen("Clientes.txt","rb+");
		system("cls");
		printf("\t\t\t\tExcluir Dados Clientes\n");
		printf("digite o nome: ");
		fflush(stdin);
		gets(nomepesq);
		
			rewind(fp);
			while(!feof(fp)){
				fread(&cli,sizeof(cliente),1,fp);
				if(!feof(fp)){
			
					if(strcmp(strlwr(cli.nome),strlwr(nomepesq))==0){
				printf("\t\tCliente\n");
				printf("\tNome: %s\n",cli.nome);
				printf("\tCPF: %s\n",cli.cpf);
				printf("\tRG: %s\n",cli.rg);
				
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",cli.end.bairro);
					printf("\tRua: %s\n",cli.end.rua);
					printf("\tCasa: %i\n\n",cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",cli.cont.tel1);
					printf("\tTelefone 2: %i\n",cli.cont.tel2);
					printf("\tEmail: %s\n\n",cli.cont.email);
					printf("\n\n");
					printf("\tConvenio\n");
					if(cli.cv.nome && cli.cv.nmatricula != NULL){
					printf("\tNome: %s\n\n",cli.cv.nome);
					printf("\tNumero da Matricula: %i\n\n",cli.cv.nmatricula);
					}else{
					printf("Cliente não possui convenio\n");
					}
				aux=1;
					
					fe = fopen("ClientesExcluidos.txt","ab+");
					fwrite(&cli,sizeof(cliente),1,fe);
					fclose(fe);
					printf("Dados Excluidos com Sucesso\n");
					system("pause");	
				}else{

					strcpy(vetcli[i].nome,cli.nome);
					strcpy(vetcli[i].cpf,cli.cpf);
					strcpy(vetcli[i].rg,cli.rg);
					
					strcpy(vetcli[i].end.bairro,cli.end.bairro);
					strcpy(vetcli[i].end.rua,cli.end.rua);
					vetcli[i].end.casa=cli.end.casa;
					vetcli[i].cont.tel1=cli.cont.tel1;
					vetcli[i].cont.tel2=cli.cont.tel2;
					strcpy(vetcli[i].cont.email,cli.cont.email);
					if(cli.cv.nome && cli.cv.nmatricula !=NULL){
						strcpy(vetcli[i].cv.nome,cli.cv.nome);
						vetcli[i].cv.nmatricula=cli.cv.nmatricula;
					}
					
					i++;
			
		
			}// fim comparação
			
	}//if feof
	}//while feof
	if(aux==0){
		printf("Cliente não Encontrado\n");
		system("pause");
	}
			fclose(fp);
			fp=fopen("Clientes.txt","wb");
			
			fwrite(vetcli,sizeof(cliente),i,fp);
			fclose(fp);
			free(vetcli);
	}// fim procedimento excluir

		void AlterarClientes(){
		char nomepesq[30];
		int aux=0,cont=0,i=0,op;
		cliente cli;
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Clientes.txt","rb+");
		system("cls");
		printf("\t\t\t\tAlteracao Dados Cliente\n");
		printf("digite o nome para alterar: ");
		fflush(stdin);
		gets(nomepesq);
	
		
		rewind(fp);
			while(!feof(fp)){
				fread(&cli,sizeof(cliente),1,fp);
				if(!feof(fp)){
					if(strcmp(strlwr(cli.nome),strlwr(nomepesq))==0){
					printf("\t\tCliente\n");
				printf("\tNome: %s\n",cli.nome);
				printf("\tCPF: %s\n",cli.cpf);
				printf("\tRG: %s\n",cli.rg);
				
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",cli.end.bairro);
					printf("\tRua: %s\n",cli.end.rua);
					printf("\tCasa: %i\n\n",cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",cli.cont.tel1);
					printf("\tTelefone 2: %i\n",cli.cont.tel2);
					printf("\tEmail: %s\n\n",cli.cont.email);
					printf("\n\n");
					printf("\tConvenio\n");
					if(cli.cv.nome && cli.cv.nmatricula != NULL){
					printf("\tNome: %s\n\n",cli.cv.nome);
					printf("\tNumero da Matricula: %i\n\n",cli.cv.nmatricula);
				}else{
					printf("Cliente não possui convenio\n\n");
				}
			
			printf("-------------------------------------\n");
			printf("\tO que deseja alterar?\n ");
			printf("1-Atributos como (CPF,RG)\n2-Endereco\n3-Contanto\n4-Convenio\n0-Sair\nEscolha: ");
			scanf("%i",&op);
			switch(op){
				case 1:
					system("cls");
		printf("\t\t\t\tAlteracao Dados Cliente\n");
					printf("\tNome: ");
					fflush(stdin);
					gets(cli.nome);
					printf("\tCPF: ");
					fflush(stdin);
					gets(cli.cpf);
					printf("\tRG: ");
					fflush(stdin);
					gets(cli.rg);
					printf("\tDados Alterados com Sucesso\n\n");
					break;
					case 2:
			system("cls");
		printf("\t\t\t\tAlteracao Dados Cliente\n");
		printf("\tEndereco\n");
					printf("\tBairro: ");
					fflush(stdin);
					gets(cli.end.bairro);
					printf("\tRua: ");
					fflush(stdin);
					gets(cli.end.rua);
					printf("\tCasa: ");
					scanf("%i",&cli.end.casa);
		printf("\tDados Alterados com Sucesso\n\n");
						break;
						
						case 3:
							system("cls");
		printf("\t\t\t\tAlteracao Dados Medicos\n");
						printf("\tContato\n");
					printf("\tTelefone 1: ");
					scanf("%i",&cli.cont.tel1);
					printf("\tTelefone 2: ");
					scanf("%i",&cli.cont.tel2);
					printf("\tEmail: ");
					fflush(stdin);
					gets(cli.cont.email);
					printf("\tDados Alterados com Sucesso\n\n");
							break;
							case 4:
							system("cls");
					printf("\t\t\t\tAlteracao Dados Cliente\n");
					printf("\tNome do Convenio: ");
					fflush(stdin);
					gets(cli.cv.nome);
					printf("\tNumero da Matricula do Convenio: ");
					scanf("%i",&cli.cv.nmatricula);
					
					printf("\tDados Alterados com Sucesso\n\n");
								break;
							case 0:
								break;
					
					default:
						printf("Opcao invalida\n");
			}
			
			
					aux=1;
				fseek(fp,cont*sizeof(cliente),SEEK_SET);
				fwrite(&cli,sizeof(cliente),1,fp);			
			break;
			}// fim comparação
				cont++;
			}//fim eof
			}//fim while
			
			
		if(aux==0) {
			printf("Cliente não encontrada\n");
			system("pause");
		}	
			system("pause");
			fclose(fp);
		}//fim condição alterar
		
		//crud Convenio
		
		void CadastroConvenio(){
		int op,op1;
			
			convenio cv;
			setlocale(LC_ALL,"portuguese");
			fp = fopen("Convenio.txt","ab+");
			system("cls");
			do{
			
					printf("\t\t\t\tCadastro de Convenio\n\n");
					printf("\tNome: ");
					fflush(stdin);
					gets(cv.nome);
					printf("\tNumero da Matricula: ");
					scanf("%i",&cv.nmatricula);
		
								
			fwrite(&cv,sizeof(convenio),1,fp);
			
			 printf("\t\t__________________________________________\n");
			 printf("\t\tDeseja continuar cadastrando Convenio?\n");   
			 printf("\t1-Sim\n");   
			 printf("\t0-Nao\n");   
			 printf("\tEscolha: ");
			 scanf("%i",&op);
			 system("cls");
			}while(op!=0);
		
			fclose(fp);
		}//fim menu principal
	
		void ListarConvenio(){
			int op;
			convenio cv;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Convenio.txt","rb");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&cv,sizeof(convenio),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tConvenio\n");
				printf("\tNome: %s\n",cv.nome);
				printf("\tNumero da Matricula: %i\n",cv.nmatricula);	
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		system("cls");
		}
		
		void PesquisarConvenio(){
			char nomepesq[30];
			int i,aux=0;
			convenio cv;
		system("cls");
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Convenio.txt","rb");
			printf("\t\t\t\tPesquisa de Convenio\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&cv,sizeof(convenio),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(cv.nome),strlwr(nomepesq))==0){
				printf("\t\tConvenio\n");
				printf("\tNome: %s\n",cv.nome);
				printf("\tNumero da Matricula: %i\n",cv.nmatricula);
					
				aux=1;	
				}//fim comparacao
				
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
				}
			fclose(fp);

		system("pause");
		
		}//fim pesquisarpessoa
		
		void ExcluirConvenio(){
		char nomepesq[30];
		int aux=0,cont=0,op, i=0;
		convenio cv, *vetcv;
	
			
		setlocale(LC_ALL,"portuguese");
		
		vetcv = (convenio *) malloc(1000*sizeof(convenio));
		fp = fopen("Convenio.txt","rb+");
		system("cls");
		printf("\t\t\t\tExcluir Dados Convenio\n");
		printf("digite o nome: ");
		fflush(stdin);
		gets(nomepesq);
		
			rewind(fp);
			while(!feof(fp)){
				fread(&cv,sizeof(convenio),1,fp);
				if(!feof(fp)){
			
					if(strcmp(strlwr(cv.nome),strlwr(nomepesq))==0){
				printf("\t\tConvenio\n");
				printf("\tNome: %s\n",cv.nome);
				printf("\tNumero da Matricula: %i\n",cv.nmatricula);
				
				aux=1;
					
					fe = fopen("ConvenioExcluidos.txt","ab+");
					fwrite(&cv,sizeof(convenio),1,fe);
					fclose(fe);
					printf("Dados Excluidos com Sucesso\n");
					system("pause");	
				}else{

					strcpy(vetcv[i].nome,cv.nome);
					vetcv[i].nmatricula=cv.nmatricula;

					i++;
			
		
			}// fim comparação
			
	}//if feof
	}//while feof
	if(aux==0){
		printf("Convenio não Encontrado\n");
		system("pause");
	}
			fclose(fp);
			fp=fopen("Convenio.txt","wb");
			
			fwrite(vetcv,sizeof(convenio),i,fp);
			fclose(fp);
			free(vetcv);
	}// fim procedimento excluir

		void AlterarConvenio(){
		char nomepesq[30];
		int aux=0,cont=0,i=0,op;
		convenio cv;
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Convenio.txt","rb+");
		system("cls");
		printf("\t\t\t\tAlteracao Dados Convenio\n");
		printf("digite o nome para alterar: ");
		fflush(stdin);
		gets(nomepesq);
	
		
		rewind(fp);
			while(!feof(fp)){
				fread(&cv,sizeof(convenio),1,fp);
				if(!feof(fp)){
					if(strcmp(strlwr(cv.nome),strlwr(nomepesq))==0){
					printf("\t\tCliente\n");
				printf("\tNome: %s\n",cv.nome);
				printf("\tNumero da Matricula: %i\n",cv.nmatricula);
			
				
			
			printf("-------------------------------------\n");
			printf("\tO que deseja alterar?\n");
			printf("1-Numero da Matricula\n2-Data De Vencimento\n0-Sair\nEscolha: ");
			scanf("%i",&op);
			switch(op){
				case 1:
					system("cls");
		printf("\t\t\t\tAlteracao Dados Convenio\n");
					printf("\tNumero da Matricula: ");
					scanf("%i",&cv.nmatricula);
				printf("\tDados Alterados com Sucesso\n\n");
					break;
					case 2:
			system("cls");
		printf("\t\t\t\tAlteracao Dados Cliente\n");
					printf("\tDados Alterados com Sucesso\n\n");
		
						break;
							case 0:
								break;
					
					default:
						printf("Opcao invalida\n");
			}
			
			
					aux=1;
				fseek(fp,cont*sizeof(convenio),SEEK_SET);
				fwrite(&cv,sizeof(convenio),1,fp);			
			break;
			}// fim comparação
				cont++;
			}//fim eof
			}//fim while
			
			
		if(aux==0) {
			printf("Convenio não encontrada\n");
			system("pause");
		}	
			system("pause");
			fclose(fp);
		}//fim condição alterar
		
		
		
		// Procedimentos Médico
		void RealizarConsulta(){//terminar
	
		consulta con, *vetcon;
		char nomepesq[30];
		int aux=0,op,tempo=3,i=0;
		
			vetcon = (consulta *) malloc(1000*sizeof(consulta));
			fp=fopen("Consultas.txt","rb");
			system("cls");
			
			printf("\t\t\t\tPesquisa de Clientes\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			
				rewind(fp);
				while(!feof(fp)){
					fread(&con,sizeof(consulta),1,fp);
					if(!feof(fp)){
						if(strcmp(strlwr(nomepesq),strlwr(con.nomecliente))==0){
					printf("\tConsultas\n");
		   			printf("\tCliente: %s\n",con.nomecliente); 
		   			printf("\tAtendente: %s\n", con.nomeatendente);
		   			strcpy(con.status,"Em Andamento");
		   			printf("\tStatus: %s\n",con.status);
				
				int tempo;
				
					tempo=5;
					while(tempo>=0){
					Sleep(1000);
					printf("\t\t%i\n",tempo);
					tempo=tempo-1;
					}
					
					printf("\tFinalizar Consulta\n");
					getchar();
						strcpy(con.status,"Finalizado\n");
				
					printf("\tStatus: %s",con.status);
					system("pause");
					
					fc=fopen("ConsultasRealizadas.txt","ab+");
						fwrite(&con,sizeof(consulta),1,fc);
						fclose(fc);
						aux=1;
				}else {
				strcpy(vetcon[i].nomecliente,con.nomecliente);
				strcpy(vetcon[i].nomeatendente,con.nomeatendente);
				strcpy(vetcon[i].esp,con.esp);
				strcpy(vetcon[i].status,con.status);
				i++;
				
				}//if comp
		}//fim if
	}//fim while
				if(aux==0){
					printf("Nao encontrado\n");
				}
				
				fclose(fp);
				fp=fopen("Consultas.txt","wb");
			
			fwrite(vetcon,sizeof(consulta),i,fp);
			fclose(fp);
			free(vetcon);
			//	TelaMedico();
	
}

		void VisualizarConsulta(char lcomp[15]){
		consulta con;

		int aux=0,op;
		
			fp=fopen("Consultas.txt","rb");
			system("cls");
			
				rewind(fp);
				while(!feof(fp)){
					fread(&con,sizeof(consulta),1,fp);
					if(!feof(fp)){
						if(strcmp(strlwr(lcomp),strlwr(con.nomemedico))==0){
					printf("\tConsultas\n");
		   			printf("\t Cliente: %s\n",con.nomecliente); 
		   			printf("\t Atendente: %s\n", con.nomeatendente);
					
					aux=1;
			}
		}//fim if
	}//fim while
		if(aux==0){
			printf("Nenhuma Consulta Marcada\n");
		}
		system("pause");
		TelaMedico(lcomp);
		}
		

		//Procedimento Atendente
		void MarcarConsulta(char lcomp[15]){//colocar mais funcoes
			funcionario func;
			cliente cli;
			consulta con;
			int op,aux=0;
			char nomepesq[30],nomepesqmed[30];
			
			fp= fopen("Clientes.txt","rb");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			setlocale(LC_ALL,"portuguese");
					system("cls");
					
			printf("\t\t\t\tPesquisa de Clientes para Consulta\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&cli,sizeof(cliente),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(cli.nome),strlwr(nomepesq))==0){
				printf("\t\tCliente\n");
				printf("\tNome: %s\n",cli.nome);
				printf("\tCPF: %s\n",cli.cpf);
				printf("\tRG: %s\n",cli.rg);
				
				printf("\tEndereco\n");
					printf("\tBairro: %s\n",cli.end.bairro);
					printf("\tRua: %s\n",cli.end.rua);
					printf("\tCasa: %i\n\n",cli.end.casa);
					printf("\tContato\n");
					printf("\tTelefone 1: %i\n",cli.cont.tel1);
					printf("\tTelefone 2: %i\n",cli.cont.tel2);
					printf("\tEmail: %s\n\n",cli.cont.email);
					printf("\n\n");
					printf("\tConvenio\n");
					if(cli.cv.nome && cli.cv.nmatricula != NULL){
					printf("\tNome: %s\n\n",cli.cv.nome);
					printf("\tNumero da Matricula: %i\n\n",cli.cv.nmatricula);
				}else{
					printf("Cliente não possui convenio\n\n");
				}
				
				fm = fopen("Medicos.txt","rb");
				fa = fopen("Atendentes.txt","rb");
				fc = fopen("Consultas.txt","ab+");
	
			
					system("pause");
				system("cls");
					
					printf("\t\t\tMarcar Consulta\n");
					strcpy(con.nomecliente,cli.nome);
					strcpy(con.nomeatendente,func.ate.nome);
					printf("\tPaciente: %s\n",con.nomecliente);
					printf("------------------------------------------------\n\n");
					rewind(fa);
					while(!feof(fa)){
						fread(&func,sizeof(funcionario),1,fa);
					if(!feof(fa)){
						if(strcmp(strlwr(lcomp),strlwr(func.ate.nome))==0){
						strcpy(con.nomeatendente,func.ate.nome);
						}
							}//if2
							}//while2
							printf("\n");
					printf("\tAtendimento Realizado por: %s\n",con.nomeatendente);
					printf("Pressione qualquer tecla para Listagem de Medicos\n");
					getchar();
						printf("------------------------------------------------\n\n");				
				rewind(fm);
				while(!feof(fm)){
					fread(&func,sizeof(funcionario),1,fm);
					if(!feof(fm)){
						printf("\tMedico Disponivel\n");
						printf("\tNome: %s\n",func.med.nome);
						printf("\tCPF: %s\n",func.med.cpf);
						printf("\tRG: %s\n",func.med.rg);
						printf("\tCRM: %i\n",func.med.crm);
						printf("\tUF CRM: %s\n",func.med.ufcrm);
						printf("\tEspecialidade: %s\n\n",func.med.nomeespecialidade);
						printf("\tValor: %.2f\n\n",func.med.valor);
							}//if2
							}//while2
							
						printf("\tMarcado para o Medico: ");
						fflush(stdin);
						gets(con.nomemedico);
						strcpy(con.esp,func.med.nomeespecialidade);
						printf("\tEspecialidade: %s\n",con.esp);
						
						if(cli.cv.nome && cli.cv.nmatricula != NULL){
							strcpy(con.cv.nome,cli.cv.nome);
					printf("\tConvênio: %s\n\n",con.cv.nome);
						}else{
							con.valor=func.med.valor;
						printf("\tValor da Consulta: %.2f \n\n",con.valor);
						}
						printf("\tConsulta Marcada com Sucesso\n");
						printf("Pressione qualquer tecla para finalizar.\n");
						getchar();
				
					fwrite(&con,sizeof(consulta),1,fc);
				aux=1;	
		
				}//fim comparacao
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
					system("pause");
				}
				
			fclose(fp);
			fclose(fc);
			fclose(fa);
			fclose(fm);

		system("cls");
			
		}
		
		void RemarcarConsulta(){
		char nomepesq[30];
		int aux=0,cont=0,i=0,op;
		funcionario func;
			cliente cli;
			consulta con;
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Consultas.txt","rb+");
		system("cls");
		printf("\t\t\t\tRemarcar Consulta\n");
		printf("digite o nome para alterar: ");
		fflush(stdin);
		gets(nomepesq);
	
		
		rewind(fp);
			while(!feof(fp)){
				fread(&con,sizeof(consulta),1,fp);
				if(!feof(fp)){
					if(strcmp(strlwr(con.nomecliente),strlwr(nomepesq))==0){
					printf("\t\tCliente\n");
				printf("\tNome: %s\n",con.nomecliente);
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tMedico: %s\n",con.nomemedico);
				printf("\tEspecialidade: %s\n",con.esp);
			
				
			
			printf("-------------------------------------\n");
			printf("\tO que deseja alterar?\n");
			printf("1-Atendente\n2-Data da Consulta\n0-Sair\nEscolha: ");
			scanf("%i",&op);
			switch(op){
				case 1:
					system("cls");
		printf("\t\t\t\tAlteracao Dados Consulta\n");
				printf("\tAtendente: ");
				fflush(stdin);
				gets(con.nomeatendente);
				printf("\tDados Alterados com Sucesso\n\n");
					break;
					case 2:
			system("cls");
		printf("\t\t\t\tAlteracao Nova Data da Cosulta\n");
					printf("\tDados Alterados com Sucesso\n\n");
		
						break;
							case 0:
								break;
					
					default:
						printf("Opcao invalida\n");
			}
			
			
					aux=1;
				fseek(fp,cont*sizeof(consulta),SEEK_SET);
				fwrite(&con,sizeof(consulta),1,fp);			
			break;
			}// fim comparação
				cont++;
			}//fim eof
			}//fim while
			
			
		if(aux==0) {
			printf("Paciente não encontrada\n");
			system("pause");
		}	
			system("pause");
			fclose(fp);
		}//fim condição alterar
		
		void ListarConsulta(){
			int op;
			consulta con;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Consultas.txt","rb");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&con,sizeof(consulta),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tConsulta\n");
				printf("\tNome: %s\n",con.nomecliente);
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tMedico: %s\n",con.nomemedico);
				printf("\tEspecialidade: %s\n",con.esp);
			
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		system("cls");
		}
		
		void PesquisarConsulta(){
			char nomepesq[30];
			int i,aux=0;
			consulta con;
		system("cls");
		setlocale(LC_ALL,"portuguese");
		fp = fopen("Consultas.txt","rb");
			printf("\t\t\t\tPesquisa de Consultas\n\n");
			printf("\tNome para Pesquisa: ");
			fflush(stdin);
			gets(nomepesq);
			rewind(fp);
			while(!feof(fp)){
				fread(&con,sizeof(consulta),1,fp);
				if(!feof(fp)){
				if(strcmp(strlwr(con.nomecliente),strlwr(nomepesq))==0){
				printf("\t\tConsulta\n");
				printf("\tNome: %s\n",con.nomecliente);
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tMedico: %s\n",con.nomemedico);
				printf("\tEspecialidade: %s\n",con.esp);
				
				aux=1;	
				}//fim comparacao
				
			}//fim eof
			}//fim while
			
				if(aux==0){
					printf("Nao encontrado\n");
				}
			fclose(fp);

		system("pause");
		
		}//fim pesquisarpessoa
		
		void CancelarConsulta(){
		char nomepesq[30];
		int aux=0,cont=0,op, i=0;
		consulta con, *vetcon;
	
			
		setlocale(LC_ALL,"portuguese");
		
		vetcon = (consulta *) malloc(1000*sizeof(consulta));
		fp = fopen("Consultas.txt","rb+");
		system("cls");
		printf("\t\t\t\tCancelar Consultas\n");
		printf("digite o nome: ");
		fflush(stdin);
		gets(nomepesq);
		
			rewind(fp);
			while(!feof(fp)){
				fread(&con,sizeof(consulta),1,fp);
				if(!feof(fp)){
			
					if(strcmp(strlwr(con.nomecliente),strlwr(nomepesq))==0){
				printf("\t\tConsulta\n");
				printf("\tNome: %s\n",con.nomecliente);
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tMedico: %s\n",con.nomemedico);
				printf("\tEspecialidade: %s\n",con.esp);
				
				aux=1;
					
					fe = fopen("ConsultasCanceladas.txt","ab+");
					fwrite(&con,sizeof(consulta),1,fe);
					fclose(fe);
					printf("Consulta Cancelada com Sucesso\n");
					system("pause");
					break;	
				}else{

					strcpy(vetcon[i].nomecliente,con.nomecliente);
					strcpy(vetcon[i].nomeatendente,con.nomeatendente);
					strcpy(vetcon[i].nomemedico,con.nomemedico);
					strcpy(vetcon[i].esp,con.esp);

					i++;
			
		
			}// fim comparação
			
	}//if feof
	}//while feof
	if(aux==0){
		printf("Convenio não Encontrado\n");
		system("pause");
	}
			fclose(fp);
			fp=fopen("Consultas.txt","wb");
			
			fwrite(vetcon,sizeof(consulta),i,fp);
			fclose(fp);
			free(vetcon);
	}// fim procedimento excluir

		// relatorios
		void RelatorioAtendimento(){
			int op;
			consulta con;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("Consultas.txt","rb");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&con,sizeof(consulta),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tConsulta\n");
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tAtendeu Paciente: %s\n",con.nomeatendente);
			
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		system("cls");
		}
		
		void RelatorioConsulta(){
			int op;
			consulta con;
			setlocale(LC_ALL,"portuguese");
			system("cls");
			fp = fopen("ConsultasRealizadas.txt","rb");
			if(fp == NULL){
				printf("Arquivo nao encontrado\n");
				getchar();
			}
			rewind(fp);
			while(!feof(fp)){
			fread(&con,sizeof(consulta),1,fp);
			if(!feof(fp)){
			fflush(stdin);
			printf("\t\tConsulta\n");
				printf("\tNome: %s\n",con.nomecliente);
				printf("\tAtendente: %s\n",con.nomeatendente);
				printf("\tMedico: %s\n",con.nomemedico);
				printf("\tEspecialidade: %s\n",con.esp);
				printf("\tStatus: %s\n",con.status);
			}//decição feof
		}//fim while feof
			fclose(fp);
		system("pause");
		system("cls");
		}
		
		

		
