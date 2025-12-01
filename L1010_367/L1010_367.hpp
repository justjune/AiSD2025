#ifndef L1010_367_HPP
#define L1010_367_HPP

#define MAXLEN 100  // Максимальная длина строки

// Типы операций
#define MATCH 0     // Совпадение символов
#define INSERT 1    // Вставка символа
#define DELETE 2    // Удаление символа

// Структура ячейки таблицы
typedef struct {
    int cost;      // Стоимость попадания в эту ячейку
    int parent;    // Родительская ячейка (тип операции)
} cell;

// Объявление таблицы
extern cell m[MAXLEN + 1][MAXLEN + 1];

// Процедуры инициализации
void row_init(int i);
void column_init(int i);

#endif // EDIT_DISTANCE_HPP