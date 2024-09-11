#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_DISPOSITIVOS 10
#define TAMANHO_MAX_MENSAGEM 256

// representa um dispositivo
typedef struct {
    char nome[50];
} Dispositivo;

// representa a rede
typedef struct {
    Dispositivo dispositivos[MAX_DISPOSITIVOS];
    int quantidade_dispositivos;
} Rede;

// Função para adicionar um dispositivo a rede
void adicionarDispositivo(Rede *rede, const char *nome){
	if (rede->quantidade_dispositivos < MAX_DISPOSITIVOS){
		strcpy(rede->dispositivos[rede->quantidade_dispositivos].nome, nome);
		rede->quantidade_dispositivos++;
		const char *green = "\033[32m";
		const char *reset = "\033[0m";
			printf("%sDispositivo %s adicionado à rede. %s\n", green, nome, reset);
	}else {
		printf("Limite máximo de dispositivos na rede atingido.\n");
	}
}

/* Função para enviar uma mensagem de um dispositivo para outro*/
void enviarMensagem(Rede *rede, const char *remetente, const char *destinatario, const char *mensagem){
	int remetente_encontrado = 0, destinatario_encontrado = 0;
	
	for (int i = 0; i < rede->quantidade_dispositivos; i++){
		if (strcmp(rede->dispositivos[i].nome, remetente) == 0){
			remetente_encontrado = 1;
		}
		if (strcmp(rede->dispositivos[i].nome, destinatario) == 0){
			destinatario_encontrado = 1;
		}
	}
	
	if (remetente_encontrado && destinatario_encontrado){
		printf("%s enviou para %s: %s\n", remetente, destinatario, mensagem);
	}else if (!remetente_encontrado){
		printf("Dispositivo remetente %s não encontrado.\n", remetente);
	}else {
		printf("Dispositivo destinatário %s não encontrado.\n", destinatario);
	}
}

int main(){
	
	system ("chcp 65001 > nul");
	Rede rede;
	rede.quantidade_dispositivos = 0;
	
	// Adiciona dispositivo à rede
	adicionarDispositivo(&rede, "Dispositivo1");
	adicionarDispositivo(&rede, "Dispositivo2");
	adicionarDispositivo(&rede, "Dispositivo3");
	
	// Dispositivos enviando mensagens entre si
	enviarMensagem(&rede, "Dispositivo1", "Dispositivo2", "Olá, tudo bem?");
  	enviarMensagem(&rede, "Dispositivo2", "Dispositivo1", "Tudo ótimo, e você?");
	enviarMensagem(&rede, "Dispositivo3", "Dispositivo1", "Bom dia!");
	
return 0;
}
