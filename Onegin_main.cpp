//! @file

#include "Onegin_functions.cpp"










                                             //fb_s
                                             //ENUM
                                             //3 files
                                             //\n in printf

int main (int argc, char * argv[])
{
    char standard_file_name[] = "XXX.txt";         //
    char * adress = standard_file_name;
    if (argc != 1)                                 //!TODO move into other function
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
        ft_file_writer(sorted_array_pointers_begin, argv[2], count_of_strings, "w");
        ft_file_writer(sorted_array_pointers_end,   argv[2], count_of_strings, "a+");
        ft_file_writer(array_pointers,              argv[2], count_of_strings, "a+");
    }
    else
    {
        ft_file_writer(sorted_array_pointers_begin, "Onegin_sorted.txt", count_of_strings, "w+");
        ft_file_writer(sorted_array_pointers_end,   "Onegin_sorted.txt", count_of_strings, "a+");
        ft_file_writer(array_pointers,              "Onegin_sorted.txt", count_of_strings, "a+");
    }



    free(text);
    free(array_pointers);
    free(sorted_array_pointers_begin);
    free(sorted_array_pointers_end);

    return 0;
}

