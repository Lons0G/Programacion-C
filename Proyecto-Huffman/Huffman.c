#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

#define MAX_TEXT_LENGTH 4096
#define MAX_CODE_LENGTH 100
#define MAX_CHAR 256

typedef struct HuffmanNode {
  char character;
  int frequency;
  struct HuffmanNode *left;
  struct HuffmanNode *right;
} HuffmanNode;

typedef struct PriorityQueue {
  int size;
  int capacity;
  HuffmanNode **array;
} PriorityQueue;

// Función para crear un nuevo nodo de Huffman
HuffmanNode *createNode(char character, int frequency) {
  HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
  node->character = character;
  node->frequency = frequency;
  node->left = node->right = NULL;
  return node;
}

// Función para crear una cola de prioridad
PriorityQueue *createPriorityQueue(int capacity) {
  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  pq->size = 0;
  pq->capacity = capacity;
  pq->array = (HuffmanNode **)malloc(capacity * sizeof(HuffmanNode *));
  return pq;
}

// Función para insertar un nodo en la cola de prioridad
void insertPriorityQueue(PriorityQueue *pq, HuffmanNode *node) {
  int i = pq->size++;
  while (i && node->frequency < pq->array[(i - 1) / 2]->frequency) {
    pq->array[i] = pq->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  pq->array[i] = node;
}

// Función para extraer el nodo con menor frecuencia de la cola de prioridad
HuffmanNode *extractMin(PriorityQueue *pq) {
  HuffmanNode *temp = pq->array[0];
  pq->array[0] = pq->array[--pq->size];
  // Aquí deberías implementar la función para reordenar la cola
  return temp;
}

// Función para construir el árbol de Huffman
HuffmanNode *BuildHuffmanTree(char characters[], int frequencies[], int size) {
  PriorityQueue *pq = createPriorityQueue(size);

  // Insertar todos los nodos en la cola de prioridad
  for (int i = 0; i < size; i++) {
    insertPriorityQueue(pq, createNode(characters[i], frequencies[i]));
  }

  // Construir el árbol de Huffman
  while (pq->size > 1) {
    HuffmanNode *left = extractMin(pq);
    HuffmanNode *right = extractMin(pq);

    // Crear un nuevo nodo que combine los dos nodos extraídos
    HuffmanNode *newNode = createNode('\0', left->frequency + right->frequency);
    newNode->left = left;
    newNode->right = right;

    // Insertar el nuevo nodo en la cola de prioridad
    insertPriorityQueue(pq, newNode);
  }

  // El nodo restante es la raíz del árbol de Huffman
  return extractMin(pq);
}

void getCharactersAndFrequencies(const char *filename, char *characters,
                                 int *frequencies, int *size) {
  int freq[MAX_CHAR] = {0}; // Arreglo para contar frecuencias
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  // Leer el archivo y contar las frecuencias
  char ch;
  while ((ch = fgetc(file)) != EOF) {
    freq[(unsigned char)ch]++;
  }

  fclose(file);

  // Almacenar los caracteres y sus frecuencias
  *size = 0;
  for (int i = 0; i < MAX_CHAR; i++) {
    if (freq[i] > 0) {
      characters[*size] = (char)i;  // Almacenar el carácter
      frequencies[*size] = freq[i]; // Almacenar la frecuencia
      (*size)++;
    }
  }
}

// Función para generar los códigos de Huffman
void generateHuffmanCodes(HuffmanNode *root, char *code, int top,
                          char codes[MAX_CHAR][MAX_CODE_LENGTH]) {
  if (root->left) {
    code[top] = '0';
    generateHuffmanCodes(root->left, code, top + 1, codes);
  }

  if (root->right) {
    code[top] = '1';
    generateHuffmanCodes(root->right, code, top + 1, codes);
  }

  if (!root->left && !root->right) {
    code[top] = '\0'; // Terminar el código
    strcpy(codes[(unsigned char)root->character], code);
  }
}

// Función para codificar el texto
void encodeText(const char *text, char codes[MAX_CHAR][MAX_CODE_LENGTH],
                char *encodedText) {
  encodedText[0] = '\0'; // Inicializar la cadena codificada
  for (int i = 0; text[i] != '\0'; i++) {
    strcat(encodedText, codes[(unsigned char)text[i]]);
  }
}

void writeCompressedFile(const char *filename, const char *encodedText) {
  FILE *file = fopen(filename, "ab");
  if (file == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  // Convertir el texto codificado a bytes
  unsigned char byte = 0;
  int bitCount = 0;

  for (int i = 0; encodedText[i] != '\0'; i++) {
    byte = (byte << 1) | (encodedText[i] - '0');
    bitCount++;

    // Si se han acumulado 8 bits, escribir el byte en el archivo
    if (bitCount == 8) {
      fwrite(&byte, sizeof(unsigned char), 1, file);
      byte = 0;
      bitCount = 0;
    }
  }

  // Si hay bits restantes, escribir el último byte
  if (bitCount > 0) {
    byte <<= (8 - bitCount); // Rellenar con ceros
    fwrite(&byte, sizeof(unsigned char), 1, file);
  }

  fclose(file);
}

char *readCompressedFile(const char *filename, int *bitLength) {
  FILE *file = fopen(filename, "rb"); // Abrir en modo binario
  if (file == NULL) {
    perror("Error al abrir el archivo");
    return NULL;
  }

  // Obtener el tamaño del archivo
  fseek(file, 0, SEEK_END);
  long fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Crear un buffer para almacenar los bits
  char *bitString = (char *)malloc(fileSize * 8 + 1);
  if (bitString == NULL) {
    perror("Error al asignar memoria");
    fclose(file);
    return NULL;
  }

  int index = 0;
  unsigned char byte;
  while (fread(&byte, sizeof(unsigned char), 1, file) == 1) {
    for (int i = 7; i >= 0; i--) {
      if (byte & (1 << i)) {
        bitString[index++] = '1';
      } else {
        bitString[index++] = '0';
      }
    }
  }

  bitString[index] = '\0';
  fclose(file);
  *bitLength = index;
  return bitString;
}

// Función para leer el archivo y codificarlo
void readFileAndEncode(const char *filename, HuffmanNode *root,
                       char codes[MAX_CHAR][MAX_CODE_LENGTH]) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error al abrir el archivo");
    return;
  }

  char line[MAX_LINE_LENGTH];
  char encodedText[MAX_TEXT_LENGTH]; // Suficiente espacio para el texto
                                     // codificado

  // Leer el archivo línea por línea
  while (fgets(line, sizeof(line), file) != NULL) {
    // Eliminar el salto de línea al final, si existe
    line[strcspn(line, "\n")] = 0;

    // Codificar la línea
    encodeText(line, codes, encodedText);

    writeCompressedFile("archivo_comprimido.bin", encodedText);
  }

  fclose(file);
}

void decodeText(HuffmanNode *root, const char *encodedText,
                char **decodedText) {
  HuffmanNode *current = root;
  int index = 0;
  int decodedIndex = 0;
  int bufferSize = 2048;
  *decodedText = (char *)malloc(bufferSize * sizeof(char));

  if (*decodedText == NULL) {
    perror("Error al asignar memoria");
    return;
  }

  while (encodedText[index] != '\0') {
    if (encodedText[index] == '0') {
      current = current->left;
    } else {
      current = current->right;
    }

    if (!current->left && !current->right) {
      if (decodedIndex >= bufferSize - 1) {
        bufferSize *= 2;
        *decodedText = (char *)realloc(*decodedText, bufferSize * sizeof(char));
        if (*decodedText == NULL) {
          perror("Error al reasignar memoria");
          return;
        }
      }
      (*decodedText)[decodedIndex++] = current->character;
      current = root;
    }

    index++;
  }

  (*decodedText)[decodedIndex] = '\0';
}

// Función para decodificar un archivo
void decodeFile(const char *filename, HuffmanNode *root) {
  int bitLength;
  char *encodedText =
      readCompressedFile(filename, &bitLength); // Leer el archivo comprimido
  if (encodedText == NULL) {
    return;
  }

  char *decodedText;
  decodeText(root, encodedText, &decodedText);

  printf("Texto decodificado: %s\n", decodedText);

  free(encodedText);
  free(decodedText);
}

// Ejemplo de uso
int main() {
  char characters[MAX_CHAR];
  int frequencies[MAX_CHAR];
  int size;

  getCharactersAndFrequencies("texto.txt", characters, frequencies, &size);

  // Imprimir los caracteres y sus frecuencias
  for (int i = 0; i < size; i++) {
    printf("Carácter: '%c', Frecuencia: %d\n", characters[i], frequencies[i]);
  }

  HuffmanNode *root = BuildHuffmanTree(characters, frequencies, size);

  // Generar los códigos de Huffman
  char codes[MAX_CHAR][MAX_CODE_LENGTH];
  char code[MAX_CODE_LENGTH];
  char encodedText[MAX_CHAR * MAX_CODE_LENGTH];
  char text[MAX_TEXT_LENGTH];

  generateHuffmanCodes(root, code, 0, codes);

  readFileAndEncode("texto.txt", root, codes);

  decodeFile("archivo_comprimido.bin", root);

  return 0;
}
