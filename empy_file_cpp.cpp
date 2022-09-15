//! @file

//#define _CRT_SECURE_NO_WARNINGS
#include <sys\stat.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//#include "D:\TX\txlib.h"





//! @brief �������, ������������ ������ ����� � ����, ���� ����� � �����
//!        ��������� �� ����������, �� ������� ���
//!
//! @param array_pointers ������ ����������, ������� ����� ������� � ����
//!
//! @param file_name �������� ����� � ������� ����� ������� ������ ����������
//!
//! @param count_of_symbols ���������� ��������� � ������� ����������, ����� ��� ����� ������
//!
//! @return 0
int ft_file_writer( char ** array_pointers, const char * file_name, const int count_of_symbols);


//! @brief ������� ���������� �������. ����������� ����������. ������ ������� ������� ��������
//!        ������� ����������, ������  ��� ���� ���������� � ������� calloc. ����� �������������
//!        ���������� ������� free. ��������� ������� 0 ��� 1, ����������� ��� �����������
//!
//! @param *my_str_compare ��������� �� ������� ����������
//!
//! @param array_pointers ������ ����������, ��� �������� ����� ��������������
//!
//! @param count_of_strings ���������� ����� � �������� ������, ����� �� ������������� ��������� ������
//!
//! @param  command ������� ��� �����������: 0 ��� ��������� ����� �������; 1 ��� ���������� ����� � �����
//!
//! @return ��������� �� ��������������� � ������ ������
char ** ft_string_sort(int (*my_str_compare)(const char *, const char *, const int ),
                      char ** array_pointers, const int count_of_strings, const int command);


//! @brief ������� ����������. ���� ������ ������������ � ������ ��� ����� (������� �� command).
//!        ���������� ��� ���������� �� ������ �����
//!
//! @param string1 ��������� �� ������ ������
//!
//! @param string2 ��������� �� ������ ������
//!
//! @param  command ������� ��� �����������: 0 ��� ��������� ����� �������; 1 ��� ���������� ����� � �����
//!
//! @return �������� �������� �� ������ ������ � ������ ������ ��� �� ������ ������������
//!         1, ���� command ������� �����������
int ft_my_str_compare(const char * string1, const char * string2, const int command);


//! @brief ������ ������� ����� ��� ������������� � ������� ft_my_str_compare ������ ����������
//!        � ������ ��������, �� ���������� �������
//!
//! @param string ������, � ������� ����� ����������� ����������
//!
//! @param number ����� �� ����� ��������, ������� �������� ������ ������ ( � ����� ��� � ������)
//!
//! @param command 0 ��� 1: 0 ��� ������ � ������, 1 � �����
//!
//! @return 0 ���� ������� ��������� ���� ������, 1 ���� command ������� �����������
int ft_checker_symbols(const char * string, int * number, const int command);


//! @brief ��������� ����, ����������� ������� ������, ��������� ��� ������� �� �����.
//!        ����� ������ ������ ������� ���������� ������������ free
//!
//! @param file_name �������� ����, ������� ����� ���������
//!
//! @return ��������� �� ��������� ������ ��� 1, ���� ������� ����������� ��� �����

char * ft_open_file_create_array_text(const char * file_name);


//!	@brief ����������� ������� ������ ����������, ������ �� ������� ������������� ����� ������, ������, ������ symbol
//!        ���������� �� ������� � array_text. ����� ������ ������ ������� ���������� ������������ free
//!
//! @param count_of_lines ���������� ����� � �������� ������, ����� ��� �������������
//!                       ��������� ������ ��� ������ ����������
//!
//! @param array_text ������, ������� �������� �������� �����
//!
//! @param symbol ��� ������� ������� �������, �� ����� ���������� �� ������� � ����������� �����
//!        ������� ���������� ������� ����������
//!
//! @return ��������� �� ��������� � ����������� ������ ���������  ������������ ������
char ** ft_create_array_pointers(int count_of_lines, char * array_text, const char symbol);


//! @brief  ������� �������� ������ ����������
//!
//! @param new_array ����� ������, ������� ����� �����������
//!
//! @param string ������ ������, �� ����������
//!
//! @param count_symbols ���������� ��������� � ������� ��� ����� ������� �������� �����������
//!
//! @return 0
int ft_array_copy( char ** new_array, char ** string, const int count_symbols);


//! @brief �������, ���������� ������ ����� � ������� ������� stat
//!        ��� ������������� ���������� ���������� ���������� <sys\stat.h>
//!
//! @param file_name ��� �����
//!
//! @return ������ �����
int ft_file_size(const char * file_name);        //const


//! @brief ������������ ���������� ����� � �������
//!
//! @param string ������, � ������� ����� ������������� ������� �����
//!
//! @param symbol ������, ��� ������� �������� ������� ����� ����� �������������
//!
//! @return ���������� �����
int ft_count_string(const char * string, const char symbol);


  //������������ ������
                                                                                            //spell checker

//! @brief ������ ������� ��������� ��� ���������� ������� ����������. ��� ������������
//!        ������� 2 �������� �� �������
//!
//! @param array_pointers ������ ����������, � ������� ����� ������������� ������
//!
//! @param number1 ����� ������� �������� �� �������
//!
//! @param nubmer2 ����� ������� �������� �� �������
//!
//! @return 0
int ft_string_changer(char ** array_pointers, int number1, int number2);      // i �������� ��������, �������� ������������ �� i
                                                           // �������� 2 �������� ��� ����������

//! @brief ������������� ���������� � ��������� ���������, � ����� ��� ������ ���������� ������������
//!        ������ ������� ����������� ��� �������� � ������� 2 ���������� ( ����� ������ ���������) "--help"
//!
//! @return 0
int ft_print_info(void);




//! @brief
//!
//! @param
//!
//! @param
//!
//! @param
//!
//! @return                                                                                          //1 �������




                                              //������ ��� � ���� ����������


                                            // argc argv
                                            // a.out abc.txt
                                            // ./a.out          (xxx.txt)
                                            // a.out --help    (����� ��� �� ��������, ������� ������, �������� ������ ����, ������) strcmp






                                             //������� ��������� ������ ������� ����������














int main (int argc, char * argv[])
{
    char standart_file_name[] = "XXX.txt";
    char * adress = standart_file_name;
    if (argc != 1)
    {
        if (strcmp(argv[1], "--help") == 0)
        {
            ft_print_info();
            return 0;
        }
        adress = argv[1];
    }


    char * text = ft_open_file_create_array_text(adress);

    int count_of_strings = ft_count_string( text, '\n');

    char ** array_pointers = ft_create_array_pointers(count_of_strings, text, '\n');

    char ** sorted_array_pointers_begin = ft_string_sort(ft_my_str_compare, array_pointers,
                                                         count_of_strings, 0);

    char ** sorted_array_pointers_end   = ft_string_sort(ft_my_str_compare, array_pointers,
                                                         count_of_strings, 1);

    if (argc >3)
    {
        ft_file_writer(sorted_array_pointers_begin, argv[2], count_of_strings);
        ft_file_writer(sorted_array_pointers_end,   argv[3], count_of_strings);
    }
    else
    {
        ft_file_writer(sorted_array_pointers_begin, "text_sorted_from_begin.txt", count_of_strings);
        ft_file_writer(sorted_array_pointers_end,   "text_sorted_from_end.txt",   count_of_strings);
    }

    free(text);
    free(array_pointers);
    free(sorted_array_pointers_begin);
    free(sorted_array_pointers_end);

    return 0;
}

int ft_file_writer( char ** array_pointers, const char * file_name, const int count_of_symbols)
{
	 assert(array_pointers);
     FILE * stream = fopen(file_name, "w+");    //w+
     if (stream == NULL)
     {
        printf("uncorrect file name, %s", file_name);
        return 1;
     }

	 int i = 0;
	 while (i < count_of_symbols)
	 {
		 fprintf(stream, "!<!%s!>!\n", array_pointers[i]);
		 i++;
	 }

	 return 0;
 }

 //!  ���������� ���� �� ����������
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
		while (i+1 < count_of_strings)
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


int ft_my_str_compare(const char * string1, const char * string2, const int command) //�������� ���� ����[65;122]
{                                                                                    //! command 0 string compare from begin
                                                                                     //! command 1 string compare from the end
	assert(string1);
	assert(string2);

    int count1 = 0;
    int count2 = 0;
    if (command == 0)  //from begin
    {

        ft_checker_symbols(string1, &count1, command);
        ft_checker_symbols(string2, &count2, command);

        while (string1[count1] == string2[count2] && string1[count1] > '\0' && string2[count2] > '\0')
        {
            count1++;
            count2++;
        }

        return (int)string2[count1] - (int)string1[count1];
    }
    else if (command == 1)   //from end
    {

        count1 = strlen(string1);
        count2 = strlen(string2);

        ft_checker_symbols(string1, &count1, command);
        ft_checker_symbols(string2, &count2, command);

        while (string1[count1] == string2[count2] && count1 >= 0 && count2 >= 0)
        {
            count1--;
            count2--;
        }
        return (int)string2[count2] - (int)string1[count1];
    }

    printf("uncorrect command");

    return 1;
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
        while (((int)string[*number] <= 64 || (int)string[*number] >= 123) && (*number) >= 0)
            (*number)--;

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
        printf("uncorrect name of file\n program can't open it");

	char * array_with_text = (char *)calloc(file_size + 1 , sizeof(array_with_text[0]));
	assert(array_with_text);

	int normal_size = fread(array_with_text, sizeof(array_with_text[0]), file_size, ptrFile);	// ��������� ������� �����

	char * string_checker = (char *)realloc(array_with_text, sizeof(string_checker[0]) * (normal_size + 1));  //
	assert(string_checker);
	array_with_text = string_checker;

	array_with_text[normal_size] = '\0';   //���������� �� ������ ��� ������

	return array_with_text;
}


char ** ft_create_array_pointers(int count_of_lines, char * array_text, const char symbol)
{
	assert(array_text);

	char ** array_pointers = (char **)calloc(count_of_lines, sizeof(array_pointers[0]));
	assert(array_pointers);

	array_pointers[0] = array_text;

    int i = 0;
	int number_of_pointer = 1;
	while (array_text[i] != '\0')
	{
		if (array_text[i] == int(symbol))
		{
			array_text[i] = '\0';
			array_pointers[number_of_pointer] = array_text + i + 1;
			number_of_pointer++;
		}
		i++;
	}

	return array_pointers;
}


int ft_array_copy( char ** new_array, char ** string, const int count_symbols)  // ��� ������: ������ ������ ������, ���� � ����� ������ ������ const
{
    int i = 0;
    while (i < count_symbols)
    {
        new_array[i] = string[i];
        i++;
    }
    return 0;
}


int ft_file_size(const char * file_name)
{
	assert(file_name);

	struct stat buf = {};
	int fb_s = stat(file_name, &buf);

    return buf.st_size;
    }

// ������ assert ��������� if � � calloc ���� �����, ��������� � ������������� ������������ ��������, ���� �� �����������

//! ������� ���������� ����� ��� ������������� ��������� ������ ��� ������ ����������
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


//! ������ 2 ��������� �� ������ �������
int ft_string_changer(char ** array_pointers, int number1, int number2)
{
	assert(array_pointers);

	char * adress = array_pointers[number1];
	array_pointers[number1] = array_pointers[number2];
	array_pointers[number2] = adress;

	return 0;
}


int ft_print_info(void)
{
    printf("\n\n-------------------------------------------------------------------------------------\n\n");
    printf("This program was made by Yuri Doronin.\n It can sort you text file from begin and from the end\n "
           "HOW TO USE:\n In console you need to call up this program,"
           "after that write file, which will be processed.\n If you wouldnt write your file, program will"
           "choose file XXX.txt.\n After that you need to write two files names, where results of program will be");
    return 0;
}
