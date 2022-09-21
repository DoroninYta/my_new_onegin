#ifndef Onegin_comments
#define Onegin_comments

#include <sys\stat.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

enum return_value {
    Normal_exit = 0,
    Norlmal_exit = 0,     //
    ERROR = -1,
    ERROR_uncorrect_file_name = -1,
    ERROR_uncorrect_command_for_ft_my_str_compare = -1,
    ERROR_problem_ft_ft_file_size_in_stat = -1
};

enum command {
    Straight_sort = 0,
    Revers_sort
};


int ft_files_name(char ** file_name_read, char ** file_name_write, const int argc, char * const argv[]);

//! @brief функция, записывающая массив строк в файл, если файла с таким
//!        названием не существует, то создает его
//!
//! @param array_pointers массив указателей, который будет записан в файл
//!
//! @param file_name название файла в который будет записан массив указателей
//!
//! @param count_of_symbols количество элементов в массиве указателей, нужно для цикла записи
//!
//! @param mode выбор команды для открытия файла
//!
//! @return 0
int ft_file_writer( char ** array_pointers, const char * file_name, const int count_of_symbols, const char * mode);


//! @brief Функция сортировки массива. Пузырьковая сортировка. Данная функция создает дубликат
//!        массива указателей, размер  под него выделяется с помощью calloc. После использования
//!        необходима функция free. Принимает комманду 0 или 1, необходимую для компаратора
//!
//! @param *my_str_compare указатель на функцию компаратор
//!
//! @param array_pointers массив указателей, его дубликат будет переставляться
//!
//! @param count_of_strings количество строк в исходном тексте, нужно длz динамического выделения памяти
//!
//! @param  command команда для компаратора: 0 для сравнение строк сначала; 1 для стравнения строк с конца
//!
//! @return указатель на отсортированную с начала строку
char ** ft_string_sort(int (*my_str_compare)(const char *, const char *, const int ),
                      char ** array_pointers, const int count_of_strings, const int command);


//! @brief функция Компаратор. Ищет первое несовпадение с начала или конца (зависит от command).
//!        Использует revers_comparing straight_comparing
//!        Игнорирует всю пунктуацию до первой буквы
//!
//! @param string1 указатель на первую строку
//!
//! @param string2 указатель на вторую строку
//!
//! @param  command команда для компаратора: Straight_sort(0) для сравнение строк сначала; Revers_sort(1) для стравнения строк с конца
//!
//! @return разность символов из второй строки и первой строки при их первом несовпадении
//!         1, если command введена неправильно
int ft_my_str_compare(const char * string1, const char * string2, const int command);


//! @brief сортировка с начала строки
//!
//! @param первая строка для сравнения
//!
//! @param вторая строка для сравнения
//!
//! @return разность ascii кода первых 2 несовпадающих символов. Из символа второй строки
//!         вычитается символ первой строки
int straight_comparing(const char * string1, const char * string2);


//! @brief Сортировка с конца строки
//!
//! @param первая строка для сравнения
//!
//! @param вторая строка для сравнения
//!
//! @return разность ascii кода первых 2 несовпадающих символов. Из символа второй строки
//!         вычитается символ первой строки
int revers_comparing( const char * string1, const char * string2);


//! @brief Данная функция нужна для игнорирования в функции ft_my_str_compare знаков пунктуации
//!        и прочих символов, не являющихся буквами
//!
//! @param string строка, в которой будет проверяться пунктуация
//!
//! @param number адрес на номер элемента, который является первой буквой ( с конца или с начала)
//!
//! @param command 0 или 1: 0 для поиска с начала, 1 с конца
//!
//! @return 0 если функция выполнила свою работу, 1 если command введена неправильно
int ft_checker_symbols(const char * string, int * number, const int command);


int ft_condition(const char * string, const int number);
//! @brief открывает файл, динамически создает массив, заполняет его текстом из файла.
//!        После вызова данной функции необходимо использовать free
//!
//! @param file_name название файл, который будет обработан
//!
//! @return указатель на созданный массив или 1, если введено некоректное имя файла

char * ft_open_file_create_array_text(const char * file_name);


//!	@brief динамически создает массив указателей, каждый из которых соответствует новой строке, символ, равный symbol
//!        заменяется на нулевой в array_text. После вызова данной функции необходимо использовать free
//!
//! @param count_of_lines количество строк в исходном тексте, нужно для динамического
//!                       выделения памяти под массив указателей
//!
//! @param array_text массив, который содержит исходный текст
//!
//! @param symbol при встрече данного символа, он будет заменяться на нулевой и создаваться новый
//!        элемент созданного массива указателей
//!
//! @return указатель на созданный и заполненный массив указатель  динамическая память
char ** ft_create_array_pointers(int count_of_lines, char * array_text, const char symbol);


//! @brief  функция копирует массив указателей
//!
//! @param new_array новый массив, который будет заполняться
//!
//! @param string старый массив, не изменяется
//!
//! @param count_symbols количество элементов в массиве для более быстрой операции копирования
//!
//! @return 0
int ft_array_copy( char ** new_array, char ** string, const int count_symbols);


//! @brief функция, передающая размер файла с помощью функции stat
//!        Для использования необзодимо подключить библеотеку <sys\stat.h>
//!
//! @param file_name имя файла
//!
//! @return размер файла
int ft_file_size(const char * file_name);        //const


//! @brief подсчитывает количество строк в массиве
//!
//! @param string массив, в котором будет производиться подсчет строк
//!
//! @param symbol символ, при встрече которого счетчик строк будет увеличиваться
//!
//! @return количество строк
int ft_count_string(const char * string, const char symbol);


  //динамическая память
                                                                                            //spell checker

//! @brief данная функция требуется для сортировки массива указателей. Она переставляет
//!        местами 2 элемента из массива
//!
//! @param array_pointers массив указателей, в котором будет производиться замена
//!
//! @param number1 номер первого элемента из массива
//!
//! @param nubmer2 номер второго элемента из массива
//!
//! @return 0
int ft_string_changer(char ** array_pointers, int number1, int number2);      // i поменять название, поменять документацию на i
                                                           // добавить 2 параметр для сортировки

//! @brief распечатывает информацию о создателе программы, а также как данной программой пользоваться
//!        данная функция срабатывает при введении в консоль 2 параметром ( после вызова программы) "--help"
//!
//! @return 0
int ft_print_info(void);

char ** ft_create_array_copy(char ** const array_pointers, const int count_of_string);

#endif //Onegin_comments
