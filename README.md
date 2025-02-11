# Controle de Servomotor por PWM no RP2040

## 📌 Descrição
Este projeto tem como objetivo simular o controle de um **servomotor** utilizando o **módulo PWM** do **microcontrolador RP2040**, através da ferramenta **Pico SDK**. A simulação é realizada no **Wokwi**, que permite testar o comportamento do motor micro servo padrão sem a necessidade de circuitos físicos. Além disso, um LED RGB, conectado à GPIO 12, será utilizado para observar efeitos secundários da variação do sinal PWM.

## 🛠️ Componentes Utilizados
- **Microcontrolador:** Raspberry Pi Pico W (Simulado no Wokwi)
- **Servomotor:** Motor micro servo padrão (Simulado no Wokwi)
- **LED RGB:** Controlado pela GPIO 12

## 🔥 Funcionalidades
- ✅ Configuração do PWM na **GPIO 22** com frequência de **50Hz** (período de 20ms).
- ✅ Ajuste do ciclo de trabalho para:
  - **2.400µs** (Duty Cycle 0,12%) → **180 graus** (Aguarda 5s)
  - **1.470µs** (Duty Cycle 0,0735%) → **90 graus** (Aguarda 5s)
  - **500µs** (Duty Cycle 0,025%) → **0 graus** (Aguarda 5s)
- ✅ Implementação de **movimentação periódica** do servomotor entre **0 e 180 graus**, com ajustes suaves (+/- 5µs) e **atraso de 10ms**.
- ✅ Experimento com **LED RGB** na GPIO 12 para observar os efeitos do sinal PWM.

## 📄 Estrutura do Projeto
- `main.c` → Implementação principal do controle PWM do servomotor.
- `CMakeLists.txt` → Configuração do CMake para compilação do projeto.

## 🖥️ Como Executar o Projeto

### Passo 1: Clone o repositório do projeto e abra-o no VS Code.
```sh
git clone <URL_DO_REPOSITORIO>
cd <NOME_DO_PROJETO>
```

### Passo 2: Configurar o Ambiente
Garanta que o **Pico SDK** está instalado corretamente e que o **Wokwi** está integrado ao **VS Code**.

### Passo 3: Compilar o Código
Compile o projeto no VS Code utilizando a extensão **Raspberry Pi Pico**.

### Passo 4: Executar a Simulação no Wokwi
1. Abra o Wokwi e carregue o código-fonte.
2. Execute a simulação e observe o movimento do servomotor.
3. Analise o comportamento do **LED RGB** durante a execução.

## 📌 Observações sobre o LED RGB
Durante a execução do código, observa-se que o LED RGB apresenta **variações de brilho e intensidade**, possivelmente devido à modulação do sinal PWM aplicado ao servomotor.

# Link para o vídeo de demonstração



## 📌 Autor
Projeto desenvolvido por **Jeová Pinheiro** para a fase 1 do ***EmbarcaTech***.

