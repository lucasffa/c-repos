# **MapReduce em C**

Este repositório contém uma implementação simples do paradigma **MapReduce** em linguagem C, com suporte a caracteres especiais e acentuações, projetado para processar textos fornecidos pelo usuário e contar as ocorrências de cada palavra.

## **Como Executar**

### **Pré-requisitos**
1. GCC instalado no seu sistema:
   - Para Windows: Recomendamos usar o MinGW ou MSYS2.
   - Para Linux/MacOS: GCC já deve estar disponível ou pode ser instalado via gerenciador de pacotes.

2. Terminal compatível com UTF-8:
   - **Windows:** Use o PowerShell ou o Windows Terminal.
   - **Linux/MacOS:** Qualquer terminal moderno.

### **Passos para Execução**
1. Clone o repositório:
   ```bash
   git clone https://github.com/lucasffa/c-repos/
   cd seu-repositorio
   ```

2. Compile o programa:
   ```bash
   gcc -o map_reduce map_reduce.c
   ```

3. Execute o programa:
   ```bash
   ./map_reduce
   ```

---

## **Personalização**

O programa permite personalizar o texto a ser processado, bastando alterar o valor da variável `rawText` no arquivo `map_reduce.c`.

### **Como Customizar**
1. Abra o arquivo `map_reduce.c` em qualquer editor de texto.
2. Localize a variável `rawText` (dentro da função `main`):
   ```c
   const wchar_t* rawText = L"De modo geral, HDFS é a espinha dorsal do Hadoop...";
   ```
3. Substitua o conteúdo da string `rawText` pelo texto que deseja processar. Por exemplo:
   ```c
   const wchar_t* rawText = L"Olá mundo! MapReduce é uma técnica poderosa.";
   ```

4. Salve o arquivo e recompile o programa:
   ```bash
   gcc -o map_reduce map_reduce.c
   ```

5. Execute novamente:
   ```bash
   ./map_reduce
   ```

---

## **Saídas Esperadas**

O programa conta o número de ocorrências de cada palavra no texto fornecido e exibe o resultado no terminal. A saída segue o formato:

```
Palavra: <palavra>, Ocorrências: <número>
```

### **Exemplo de Entrada**

Se `rawText` for definido como:
```c
const wchar_t* rawText = L"Olá mundo! Olá MapReduce.";
```

### **Exemplo de Saída**

A saída será:
```
Palavra: Olá, Ocorrências: 2
Palavra: mundo!, Ocorrências: 1
Palavra: MapReduce., Ocorrências: 1
```

---

## **Observações**

1. **Acentuações e Caracteres Especiais:**
   - O programa suporta acentuações e caracteres especiais, garantindo que palavras como "análise" e "análise." sejam tratadas separadamente.

2. **Delimitadores:**
   - Palavras são separadas por espaços, tabulações ou quebras de linha. Pontuações são consideradas parte das palavras.

3. **Limitações:**
   - O tamanho máximo de uma palavra é 100 caracteres.
   - Se o texto for muito grande, o programa pode exigir mais memória.

---

README gerado por LLM.