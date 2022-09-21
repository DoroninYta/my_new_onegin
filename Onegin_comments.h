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

//! @brief �������, ������������ ������ ����� � ����, ���� ����� � �����
//!        ��������� �� ����������, �� ������� ���
//!
//! @param array_pointers ������ ����������, ������� ����� ������� � ����
//!
//! @param file_name �������� ����� � ������� ����� ������� ������ ����������
//!
//! @param count_of_symbols ���������� ��������� � ������� ����������, ����� ��� ����� ������
//!
//! @param mode ����� ������� ��� �������� �����
//!
//! @return 0
int ft_file_writer( char ** array_pointers, const char * file_name, const int count_of_symbols, const char * mode);


//! @brief ������� ���������� �������. ����������� ����������. ������ ������� ������� ��������
//!        ������� ����������, ������  ��� ���� ���������� � ������� calloc. ����� �������������
//!        ���������� ������� free. ��������� �������� 0 ��� 1, ����������� ��� �����������
//!
//! @param *my_str_compare ��������� �� ������� ����������
//!
//! @param array_pointers ������ ����������, ��� �������� ����� ��������������
//!
//! @param count_of_strings ���������� ����� � �������� ������, ����� ��z ������������� ��������� ������
//!
//! @param  command ������� ��� �����������: 0 ��� ��������� ����� �������; 1 ��� ���������� ����� � �����
//!
//! @return ��������� �� ��������������� � ������ ������
char ** ft_string_sort(int (*my_str_compare)(const char *, const char *, const int ),
                      char ** array_pointers, const int count_of_strings, const int command);


//! @brief ������� ����������. ���� ������ ������������ � ������ ��� ����� (������� �� command).
//!        ���������� revers_comparing straight_comparing
//!        ���������� ��� ���������� �� ������ �����
//!
//! @param string1 ��������� �� ������ ������
//!
//! @param string2 ��������� �� ������ ������
//!
//! @param  command ������� ��� �����������: Straight_sort(0) ��� ��������� ����� �������; Revers_sort(1) ��� ���������� ����� � �����
//!
//! @return �������� �������� �� ������ ������ � ������ ������ ��� �� ������ ������������
//!         1, ���� command ������� �����������
int ft_my_str_compare(const char * string1, const char * string2, const int command);


//! @brief ���������� � ������ ������
//!
//! @param ������ ������ ��� ���������
//!
//! @param ������ ������ ��� ���������
//!
//! @return �������� ascii ���� ������ 2 ������������� ��������. �� ������� ������ ������
//!         ���������� ������ ������ ������
int straight_comparing(const char * string1, const char * string2);


//! @brief ���������� � ����� ������
//!
//! @param ������ ������ ��� ���������
//!
//! @param ������ ������ ��� ���������
//!
//! @return �������� ascii ���� ������ 2 ������������� ��������. �� ������� ������ ������
//!         ���������� ������ ������ ������
int revers_comparing( const char * string1, const char * string2);


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


int ft_condition(const char * string, const int number);
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

char ** ft_create_array_copy(char ** const array_pointers, const int count_of_string);

#endif //Onegin_comments
