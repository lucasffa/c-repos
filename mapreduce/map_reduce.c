#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

// Definir CP_UTF8 manualmente, caso não esteja definido
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif

// Estrutura para armazenar palavras e suas contagens
typedef struct {
    wchar_t word[100]; // Palavras armazenadas como wchar_t
    int count;
} WordCount;

// Função para mapear texto cru em pares (palavra, 1)
WordCount* map_text(const wchar_t* text, int* mapSize) {
    WordCount* mapped = malloc(wcslen(text) * sizeof(WordCount)); // Tamanho máximo possível
    wchar_t* temp = _wcsdup(text); // Fazer uma cópia mutável do texto
    wchar_t* context = NULL; // Para wcstok_s no Windows
    wchar_t* token = wcstok_s(temp, L" \t\n", &context); // Dividir o texto em palavras
    int index = 0;

    while (token) {
        wcsncpy(mapped[index].word, token, 100);
        mapped[index].count = 1;
        index++;
        token = wcstok_s(NULL, L" \t\n", &context);
    }

    *mapSize = index; // Atualiza o tamanho real do mapeamento
    free(temp); // Libera a cópia temporária
    return mapped;
}

// Função para agrupar palavras iguais (Shuffle e Reduce)
WordCount* shuffle_and_reduce(WordCount* mapped, int mapSize, int* reduceSize) {
    WordCount* reduced = malloc(mapSize * sizeof(WordCount)); // Tamanho máximo possível
    int reducedIndex = 0;

    for (int i = 0; i < mapSize; i++) {
        int found = 0;
        for (int j = 0; j < reducedIndex; j++) {
            if (wcscmp(reduced[j].word, mapped[i].word) == 0) {
                reduced[j].count += mapped[i].count; // Incrementa a contagem
                found = 1;
                break;
            }
        }
        if (!found) {
            wcsncpy(reduced[reducedIndex].word, mapped[i].word, 100);
            reduced[reducedIndex].count = mapped[i].count;
            reducedIndex++;
        }
    }
    *reduceSize = reducedIndex;
    free(mapped); // Liberar memória do mapa
    return reduced;
}

// Função para exibir os resultados
void print_results(WordCount* reduced, int reduceSize) {
    for (int i = 0; i < reduceSize; i++) {
        // Imprimir usando wprintf
        wprintf(L"Palavra: %ls, Ocorrências: %d\n", reduced[i].word, reduced[i].count);
    }
}

int main() {
    // Configurar a localidade para UTF-8
    setlocale(LC_ALL, "");

    // Configurar o console para usar UTF-8 no Windows
    SetConsoleOutputCP(CP_UTF8);

    // Texto cru (entrada)
    const wchar_t* rawText = L"De modo geral, HDFS é a espinha dorsal do Hadoop, proporcionando um sistema robusto para armazenar e acessar dados em larga escala. Sua integração com ferramentas como MapReduce, Hive e Spark o torna essencial para aplicações que demandam análise e processamento de grandes volumes de informações.";

    // Map: Transformar texto em pares (palavra, 1)
    int mapSize;
    WordCount* mapped = map_text(rawText, &mapSize);

    // Shuffle e Reduce: Agrupar e somar as contagens
    int reduceSize;
    WordCount* reduced = shuffle_and_reduce(mapped, mapSize, &reduceSize);

    // Exibir resultados
    print_results(reduced, reduceSize);

    // Liberar memória
    free(reduced);
    return 0;
}
