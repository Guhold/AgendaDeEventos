# 📅 Agenda de Eventos

Aplicação CLI (Command Line Interface) desenvolvida em **Linguagem C** para gerenciamento dinâmico de compromissos e eventos.

---

### 🧠 Foco Principal

Este projeto foi construído com ênfase na manipulação de memória e estruturas de dados, utilizando:

* **Alocação Dinâmica:** Uso de `malloc`, `realloc` e `free` para gerenciamento otimizado do vetor de eventos.
* **Persistência de Dados:** Carregamento e salvamento dos eventos em arquivo.
* **Estruturas de Dados:** Uso de `structs` aninhadas (`Data`, `Horario` e `Evento`) para organizar o cadastro.
* **Lógica de Inserção:** Manutenção da agenda sempre **ordenada** (por data e horário) e validação de **conflito de horários** para novos eventos.

---

## ✨ Features

* **Cadastro:** Inserção de novos eventos com checagem de sobreposição de horário.
* **Busca:** Consulta de eventos por data ou por descrição (string exata ou substring).
* **Visualização:** Listagem completa ou filtrada dos compromissos.
* **Remoção:** Exclusão de eventos com otimização do vetor (`realloc` para menos).

---

## ⚙️ Tecnologias

### Core
- **Linguagem C** - Linguagem de programação estruturada.
- **`stdio.h`** - Manipulação de entrada/saída (Menu CLI e arquivo).
- **`stdlib.h`** - Funções de alocação dinâmica (`malloc`, `realloc`, `free`).
- **`string.h`** - Manipulação de strings (`strcmp`, `strstr`, etc.).

---

## 📦 Pré-requisitos

Para compilar e executar o programa, você precisará de:

-   Um **Compilador C** (ex: GCC).
-   Um **Sistema Operacional** compatível (Linux, Windows, macOS).

---

## 🔧 Instalação e Compilação

1. **Clone o repositório**
```bash
git clone [link-do-seu-repositório]
cd agenda-de-eventos # Ajuste o nome da pasta, se necessário
``` 

2. **Compile o código Se estiver usando GCC:**
```bash
gcc -o agenda main.c
```

## 🎮 Como Usar

### Execução

Execute o programa compilado:
```bash
./agenda
```

O programa exibirá o menu principal para interagir com a agenda (Cadastrar, Mostrar, Buscar, Remover e Sair).

## 👤 Autores

| Nome | Contato | GitHub |
| :--- | :--- | :--- |
| **Gustavo Holderegger** | gustavoholderegger@gmail.com | https://github.com/Guhold |
| **Arthur Perozin** | perozin.arthur@gmail.com | (https://github.com/artPerozin) |
