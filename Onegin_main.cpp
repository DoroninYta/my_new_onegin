//! @file



#include "Onegin_functions.cpp"










                                             //fb_s
                                             //ENUM
                                            //3 files
                                             //\n in printf

int main (int argc, char * argv[])
{

    char * file_name_read = NULL;
    char * file_name_write = NULL;

    ft_files_name(&file_name_read, &file_name_write, argc, argv);

    FILE * stream = ft_open_file(file_name_read);

    char * text = ft_create_array_text(stream, file_name_read);

    int count_of_strings = ft_count_string( text, '\n');

    char ** array_pointers = ft_create_array_pointers(count_of_strings, text, '\n');

    //char ** sorted_array_pointers = ft_string_sort(ft_my_str_compare, array_pointers,
     //                                                    count_of_strings, 0);

    ft_q_sort(array_pointers, count_of_strings, Straight_sort);
    ft_file_writer(array_pointers, file_name_write, count_of_strings, "w");

    ft_q_sort(array_pointers, count_of_strings, Revers_sort);
    ft_file_writer(array_pointers, file_name_write, count_of_strings, "a+");

    ft_file_writer_text(file_name_write, text, count_of_strings, "a+");

    free(text);
    free(array_pointers);
//    free(sorted_array_pointers);

    return 0;
}

