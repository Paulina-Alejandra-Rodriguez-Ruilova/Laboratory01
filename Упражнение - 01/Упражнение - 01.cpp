/*При выполнении данной задачи вы должны сравнить библиотеки “string.h” или <cstring>(с) и
<string>(с++).
А) перед main() в комментариях ответьте на вопросы и напишите соответствия с – с++ для
следующих функций(причем соответствия необязательно будут в виде функций) :
  1) strlen - string::length
  2) strcpy - аналога нет, поэтому пишем (a = b)
  3) strcmp - аналога нет
  4) strcat - someString.append
  5) somestring[index] - someString.at(index)
  6) не имеет точного аналога (возможно использовать strcat)  - push_back
  7) не имеет аналога - pop_back

  функции могут не иметь точного аналога в библиотеке другого языка.почему ? – объясните главную
  разницу строк в с и с++.

  Строки в C - массив элементов char с null-байтом в окончании
  Строки в C++ - обЪект класса string с динамической памятью

  б) теперь напишите программу на с++, которая будет сортировать буквы в алфавитном порядке в
  веденной пользователем строке.причем программа должна удалять пробелы и пунктуационные
  знаки.
  nb: используйте только библиотеку <string>.
  */

#include <iostream>
#include <string>

  // Функция для удаления пробелов и пунктуационных знаков из строки - Función para eliminar espacios y signos de Puntuación de una cadena
std::string Cleanstring(const std::string& cadena) {
    std::string cleanedstring = "";
    for (char c : cadena) {
        if (std::isalpha(c)) { // Проверяем, является ли символ буквой - Compruebe si el símbolo es una letra
            cleanedstring += std::tolower(c); // Преобразуем символ к нижнему регистру и добавляем к результату
        }
    }
    return cleanedstring;
}

int main() {
    std::string input;
    // Введите строку - Ingresar una cadena 
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    // Удалить пробелы и пунктуационные знаки - Eliminar espacios y signos de Puntuación
    std::string cleanedstring = Cleanstring(input);

    // Сортировать буквы в алфавитном порядке - Ordenar letras en orden alfabético
    for (int i = 0; i < cleanedstring.length() - 1; ++i) {
        for (int j = i + 1; j < cleanedstring.length(); ++j) {
            if (cleanedstring[i] > cleanedstring[j]) {
                // Обмен местами символов - Intercambio de símbolos
                char temp = cleanedstring[i];
                cleanedstring[i] = cleanedstring[j];
                cleanedstring[j] = temp;
            }
        }
    }
    // Результат - Resultado
    std::cout << "Alphabetically order string: " << cleanedstring << std::endl;

    return 0;
}
