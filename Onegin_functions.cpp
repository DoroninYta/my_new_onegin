#ifndef Onegin_functions
#define Onegin_functions

#include "Onegin_comments.h"
//return norlmal
// func swap
// справить комментарии return 0 1
// enum конкретнее
// вынести из функции сортировки calloc
// enum для command 0/1
// переделать str_compare
// ft_checker_symbols вывести условие в отдельную функцию, исправить первое условие, switch case вместо if



// символы подряд
// структура
// sorted_array_pointers_end убрать, использовать
// ft_string_sort вынести calloc  отдельную функцию



int ft_file_writer( char ** array_pointers, const char * file_name, const int count_of_symbols, const char * mode)
{
	 assert(array_pointers);
     FILE * stream = fopen(file_name, mode);    //!w+ for first func using, after a+
     if (stream == NULL)
     {
        printf("uncorrect file name, %s", file_name);
        return ERROR_uncorrect_file_name;
     }

	 int i = 0;
	 while (i < count_of_symbols)
	 {
		 fprintf(stream, "!<!%s!>!\n", array_pointers[i]);
		 i++;
	 }

	 fprintf(stream, "\n\n-------------------------------\n\n");
	 fclose(stream);

	 return Normal_exit;
 }

 //!  Сортировка идет на увелечение
char ** ft_string_sort(int (*my_str_compare)(const char *, const char *, const int ),
                       char ** array_pointers, const int count_of_strings, const int command)
{
	assert(array_pointers);

	char ** new_array_pointers = (char **)calloc(count_of_strings, sizeof(new_array_pointers[0]));
	assert(new_array_pointers);

	ft_array_copy(new_array_pointers, array_pointers, count_of_strings);

	int count_of_replacement = 1;
	while (count_of_replacement > 0)
	{
		count_of_replacement = 0;
        int i = 0;
		while (i + 1 < count_of_strings)
		{
			if ((*my_str_compare)(new_array_pointers[i], new_array_pointers[i+1], command) < 0)
			{
				count_of_replacement++;
				ft_string_changer(new_array_pointers, i, i + 1);
			}
			i++;
		}
	}

	return new_array_pointers;
}

int straight_comparing(const char * string1, const char * string2)
{
    assert(string1);
    assert(string2);

    int count1 = 0;
    int count2 = 0;

    ft_checker_symbols(string1, &count1, Straight_sort);
    ft_checker_symbols(string2, &count2, Straight_sort);

    while (string1[count1] == string2[count2] && string1[count1] > '\0' && string2[count2] > '\0')
    {
        count1++;
        count2++;
    }

    return (int)string2[count2] - (int)string1[count1];
}


int revers_comparing( const char * string1, const char * string2)
{

        int count1 = strlen(string2);
        int count2 = strlen(string2);

        ft_checker_symbols(string1, &count1, Revers_sort);
        ft_checker_symbols(string2, &count2, Revers_sort);

        while (string1[count1] == string2[count2] && count1 >= 0 && count2 >= 0)
        {
            count1--;
            count2--;
        }
        return (int)string2[count2] - (int)string1[count1];
}


int ft_my_str_compare(const char * string1, const char * string2, const int command) //интервал букв аски[65;122]
{
                                                                                    //! command 1 string compare from the end
                                                                                    //! command 0 string compare from begin
    assert(string1);
    assert(string2);

    if (command == Straight_sort)
        return straight_comparing(string1, string2);

    else if (command == Revers_sort)   //from end
            return revers_comparing(string1, string2);

    printf("uncorrect command");

    return ERROR_uncorrect_command_for_ft_my_str_compare;
}


int ft_checker_symbols(const char * string, int * number, const int command)         //command 0 from begin
{
                                                                                      //command 1 from end
    if (command == 0)
    {
        while ((int)string[*number] <= 64 || (int)string[*number] >= 123)
            (*number)++;

        return 0;
    }
    else if (command == 1)
    {
        while ((int)string[*number] <= 64 || (int)string[*number] >= 123)
        {
            if ((*number) <= 0)
                return Normal_exit;
            (*number)--;
     }
        return 0;
    }
    else
        printf("uncorrect command");

    return 1;

}


char * ft_open_file_create_array_text(const char * file_name)
{
    assert(file_name);

    int file_size = ft_file_size(file_name);

    FILE * ptrFile = fopen(file_name, "r");
	if (ptrFile == NULL)
    {
        printf("uncorrect name of file\n program can't open it");
        return NULL;
    }

	char * array_with_text = (char *)calloc(file_size + 1, sizeof(array_with_text[0]));
	assert(array_with_text);

	int normal_size = fread(array_with_text, sizeof(array_with_text[0]), file_size, ptrFile);	// Доставить нулевой симво

	char * string_checker = (char *)realloc(array_with_text, sizeof(string_checker[0]) * (normal_size + 1));  //
	assert(string_checker);
	array_with_text = string_checker;

	array_with_text[normal_size] = '\0';   //избавление от мусора при печати

	return array_with_text;
}


char ** ft_create_array_pointers(int count_of_lines, char * array_text, const char symbol)
{
	assert(array_text);

	char ** array_pointers = (char **)calloc(count_of_lines, sizeof(array_pointers[0]));
	assert(array_pointers);

	array_pointers[0] = array_text;

    int current_symbol_index = 0;
	int number_of_pointer = 1;
	while (array_text[current_symbol_index] != '\0')
	{
		if (array_text[current_symbol_index] == int(symbol))
		{
			array_text[current_symbol_index] = '\0';
			array_pointers[number_of_pointer] = array_text + current_symbol_index + 1;
			number_of_pointer++;
		}
		current_symbol_index++;
	}

	return array_pointers;
}

              //cdecl reading
int ft_array_copy( char ** new_array, char ** const string, const int count_symbols)  // ДЕД вопрос: почему выдает ошибку, если я делаю второй массив const
{
    int i = 0;
    while (i < count_symbols)
    {
        new_array[i] = string[i];
        i++;
    }
    return Normal_exit;
}


int ft_file_size(const char * file_name)
{
	assert(file_name);

	struct stat buf = {};
	int fb_s = stat(file_name, &buf);
    if (fb_s == -1)
        return ERROR_problem_ft_ft_file_size_in_stat;
    return buf.st_size;
    }


//! подсчет количества строк для динамического выделения памяти под массив указателей
int ft_count_string(const char * string, const char symbol)
{
	assert(string);

	int i = 0;
	int count_of_lines = 1;

	while (string[i] != '\0')
	{
		if (string[i] == (int)symbol)
		{
			count_of_lines++;
		}
		i++;
	}

	return count_of_lines;
}


//! меняет 2 указателя на строки местами
int ft_string_changer(char ** array_pointers, int number1, int number2)   //swap
{
	assert(array_pointers);

	char * adress = array_pointers[number1];
	array_pointers[number1] = array_pointers[number2];
	array_pointers[number2] = adress;

	return Normal_exit;
}


int ft_print_info(void)
{
    printf("\n\n-------------------------------------------------------------------------------------\n\n");
    printf("This program was made by Yuri Doronin.\n It can sort you text file from begin and from the end\n "
           "HOW TO USE:\n In console you need to call up this program,"
           "after that write file, which will be processed.\n If you wouldnt write your file, program will"
           "choose file XXX.txt.\n After that you need to write two files names, where results of program will be");
    return Normal_exit;
}

#endif
