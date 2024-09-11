# Simulação de Rede de Dispositivos em C

Este projeto é uma implementação simples em C que simula uma rede de dispositivos. O código permite adicionar dispositivos a uma rede e enviar mensagens entre eles.

## Descrição do Código

O código consiste nas seguintes partes principais:

### Estruturas de Dados

1. **Definições de Constantes**

    ```c
    #define MAX_DISPOSITIVOS 10
    #define TAMANHO_MAX_MENSAGEM 256
    ```

    - `MAX_DISPOSITIVOS`: Define o número máximo de dispositivos que podem ser adicionados à rede.
    - `TAMANHO_MAX_MENSAGEM`: Define o tamanho máximo da mensagem que pode ser enviada. (Não utilizado diretamente no código.)

2. **Estruturas**

    ```c
    // representa um dispositivo
    typedef struct {
        char nome[50];
    } Dispositivo;

    // representa a rede
    typedef struct {
        Dispositivo dispositivos[MAX_DISPOSITIVOS];
        int quantidade_dispositivos;
    } Rede;
    ```

    - **`Dispositivo`**: Representa um dispositivo na rede, com um campo `nome` para armazenar o nome do dispositivo.
    - **`Rede`**: Representa a rede de dispositivos, contendo um array de `Dispositivo` e uma variável `quantidade_dispositivos` para armazenar o número atual de dispositivos.

### Funções

1. **Adicionar Dispositivo**

    ```c
    void adicionarDispositivo(Rede *rede, const char *nome) {
        if (rede->quantidade_dispositivos < MAX_DISPOSITIVOS) {
            strcpy(rede->dispositivos[rede->quantidade_dispositivos].nome, nome);
            rede->quantidade_dispositivos++;
            const char *green = "\033[32m";
            const char *reset = "\033[0m";
            printf("%sDispositivo %s adicionado à rede. %s\n", green, nome, reset);
        } else {
            printf("Limite máximo de dispositivos na rede atingido.\n");
        }
    }
    ```

    - Adiciona um novo dispositivo à rede e exibe uma mensagem verde indicando a adição. Se o limite de dispositivos for atingido, exibe uma mensagem de erro.

2. **Enviar Mensagem**

    ```c
    void enviarMensagem(Rede *rede, const char *remetente, const char *destinatario, const char *mensagem) {
        int remetente_encontrado = 0, destinatario_encontrado = 0;

        for (int i = 0; i < rede->quantidade_dispositivos; i++) {
            if (strcmp(rede->dispositivos[i].nome, remetente) == 0) {
                remetente_encontrado = 1;
            }
            if (strcmp(rede->dispositivos[i].nome, destinatario) == 0) {
                destinatario_encontrado = 1;
            }
        }

        if (remetente_encontrado && destinatario_encontrado) {
            printf("%s enviou para %s: %s\n", remetente, destinatario, mensagem);
        } else if (!remetente_encontrado) {
            printf("Dispositivo remetente %s não encontrado.\n", remetente);
        } else {
            printf("Dispositivo destinatário %s não encontrado.\n", destinatario);
        }
    }
    ```

    - Envia uma mensagem de um dispositivo para outro, verificando se ambos os dispositivos existem na rede. Exibe mensagens apropriadas para o sucesso ou falha da operação.

### Função Principal

```c
int main() {
    system("chcp 65001 > nul"); // Configura o código de página do console para UTF-8 (somente no Windows)
    Rede rede;
    rede.quantidade_dispositivos = 0;

    // Adiciona dispositivos à rede
    adicionarDispositivo(&rede, "Dispositivo1");
    adicionarDispositivo(&rede, "Dispositivo2");
    adicionarDispositivo(&rede, "Dispositivo3");

    // Dispositivos enviando mensagens entre si
    enviarMensagem(&rede, "Dispositivo1", "Dispositivo2", "Olá, tudo bem?");
    enviarMensagem(&rede, "Dispositivo2", "Dispositivo1", "Tudo ótimo, e você?");
    enviarMensagem(&rede, "Dispositivo3", "Dispositivo1", "Bom dia!");

    return 0;
}
```
 - Inicializa a rede, adiciona dispositivos e simula o envio de mensagens entre eles. A configuração do console para UTF-8 é feita para garantir que caracteres especiais sejam exibidos corretamente no Windows.
Contato

Sinta-se à vontade para testar, modificar ou melhorar o código. Se tiver alguma dúvida ou sugestão, entre em contato!




<table align="center">
  <tr>
    <td align="center">
      <img src="https://img.icons8.com/?size=100&id=11835&format=png&color=000000" alt="Ícone" width="30">
      <br>
      <a href="tel:+5584996133693">(84) 99613-3693</a>
    </td>
  </tr>
</table>

<table align="center">
  <tr>
    <td align="center">
      <img src="https://img.icons8.com/?size=100&id=X0mEIh0RyDdL&format=png&color=000000" alt="Ícone" width="30">
      <br>
      <a href="mailto:matheuseduandrade@gmail.com">matheuseduandrade@gmail.com</a>
    </td>
  </tr>
</table>



