#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

#define Task 1

#if Task == 1
void RemoveLastLine(FILE* inputFile, FILE* outputFile) {\

    const unsigned short MAX_SIZE = 300;
    char currentLine[MAX_SIZE];   //массив для хранения текущей строки
    char previousLine[MAX_SIZE] = "";  //массив для хранения предыдущей строки инициализирован пустой строкой

    //чтение строк из входного файла
    while (fgets(currentLine, sizeof(currentLine), inputFile) != NULL) {

        if (previousLine[0] != '\0') {

            //если предыдущая строка не пуста (не первая итерация), записываем ее в выходной файл
            fputs(previousLine, outputFile);
        }
        strcpy(previousLine, currentLine);  //сохранение текущей строки перед чтением следующей
    }
}

int main() {
    const char* outputFilePath = "OutPut.txt";
    const char* inputFilePath = "InPut.txt";

    FILE* inputFile, * outputFile;


    if (fopen_s(&inputFile, inputFilePath, "r") != 0) {

        cout << "The file " << inputFilePath << " cannot be opened for reading\n";
        return 1;  // Завершаем программу с ошибкой
    }

    if (fopen_s(&outputFile, outputFilePath, "w") != 0) {
        cout << "The file " << outputFilePath << " cannot be opened for writing\n";

        fclose(inputFile);  // Закрываем входной файл
        return 1; 
    }

    RemoveLastLine(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

#endif


#if Task == 2

//EvenLines
void RemoveEvenLines(FILE* inputFile, FILE* evenLinesFile) {

    const unsigned short MAX_SIZE = 128;
    char currentLine[MAX_SIZE];   //массив для хранения текущей строки
    int lineCount = 1; //счетчик строк

    //чтение строк из входного файла
    while (fgets(currentLine, sizeof(currentLine), inputFile) != NULL) {

        if (lineCount % 2 != 0) {
            //если строка нечётная, записываем ее в выходной файл
            fputs(currentLine, evenLinesFile);
        }
        lineCount++;
    }
}

int main() {
    const char* evenLinesFilePath = "EvenLines.txt";
    const char* inputFilePath = "Input.txt";

    FILE* inputFile, * evenLinesFile;

    if (fopen_s(&inputFile, inputFilePath, "r") != 0) {
        cout << "The file " << inputFilePath << " cannot be opened for reading\n";
        return 1;  // Завершаем программу с ошибкой
    }

    if (fopen_s(&evenLinesFile, evenLinesFilePath, "w") != 0) {

        cout << "The file " << evenLinesFilePath << " cannot be opened for writing\n";
        fclose(inputFile);  // Закрываем входной файл
        return 1;
    }

    RemoveEvenLines(inputFile, evenLinesFile);

    fclose(inputFile);
    fclose(evenLinesFile);

    return 0;
}


#endif