/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <samuelnocita@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 08:45:35 by snocita           #+#    #+#             */
/*   Updated: 2023/07/29 23:17:13 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int error_message(int num)
{
    if (num == 1)
        printf("ERROR!\nWrong Amount of Arguments!\n");
    if (num == 2)
        printf("ERROR!\nInput file format is not compliant\n");
    if (num == 3)
        printf("ERROR!\nError found while validating map\n");
    return (num);
}

int check_format(char *map_file_name)
{
    size_t filename_len;
    int ret;

    ret = SUCCESS;
    filename_len = ft_strlen(map_file_name);
    if (filename_len < 5 || (ft_strchr(map_file_name, '.') == NULL))
        ret = error_message(2);
    while (*map_file_name != '.')
        map_file_name++;
    if ((*(map_file_name + 1) != 'c') || (*(map_file_name + 2) != 'u') || (*(map_file_name + 3) != 'b'))
        ret = error_message(2);
    printf("Passed this test\n");
    return (ret);
}

int get_length(char *path)
{
    int i;

    i = 0;
    while (*path)
    {
        if (*path == 32 || *path == 9 || *path == '\n')
            break;
        path++;
        i++;
    }
    return (i);
}

char *get_path(char *element, int mode)
{
    element++;
    while (*element == 32 || *element == 9)
        element++;
    if (*element != '.' && mode != 1)
        return (NULL);
    if ((*element < '0' && *element > '9') && mode != 0)
        return (NULL);
    return (ft_substr(element, 0, get_length(element)));
}

void register_in_struct(t_gen *gen, char *buf, char letter, int mode)
{
    printf("LETTER IS: %c\n", letter);
    gen->elements[gen->el_num].id = letter;
    gen->elements[gen->el_num].path = get_path(buf, mode);
    printf("New Element found! %c\n", gen->elements[gen->el_num].id);
    printf("PATH: %s\n", gen->elements[gen->el_num].path);
    gen->el_num++;
    printf("NUMBER: %d\n", gen->el_num);
}

int check_element(t_gen *gen, char *buf)
{
    int ret;
    int i;

    i = 0;
    ret = SUCCESS;
    if (*buf == 'N')
    {
        buf++;
        if (*buf == 'O' && *(buf + 1) == ' ')
        {
            register_in_struct(gen, buf, 'N', 0);
            ret++;
        }
    }
    else if (*buf == 'S')
    {
        buf++;
        if (*buf == 'O' && *(buf + 1) == ' ')
        {
            register_in_struct(gen, buf, 'S', 0);
            ret++;
        }
    }
    else if (*buf == 'E')
    {
        buf++;
        if (*buf == 'A' && *(buf + 1) == ' ')
        {
            register_in_struct(gen, buf, 'E', 0);
            ret++;
        }
    }
    else if (*buf == 'W')
    {
        buf++;
        if (*buf == 'E' && *(buf + 1) == ' ')
        {
            register_in_struct(gen, buf, 'W', 0);
            ret++;
        }
    }
    else if (*buf == 'F')
    {
        buf++;
        if (*buf == ' ')
        {
            register_in_struct(gen, buf, 'F', 1);
            ret++;
        }
    }
    else if (*buf == 'C')
    {
        buf++;
        if (*buf == ' ')
        {
            register_in_struct(gen, buf, 'C', 1);
            ret++;
        }
    }
    gen->buffered_map = buf;
    if (gen->el_num == 6)
        return (ret * 0);
    else
        return (FAILURE);
}

int parse(t_gen *gen, char *buf)
{
    int ret;

    ret = SUCCESS;
    while (*buf)
    {
        if (check_element(gen, buf) == FAILURE)
            ret = FAILURE;
        buf++;
    }
    return (ret);
}

int check_file_content(char *map, t_gen *gen)
{
    int fd;
    char buf[999];
    fd = open(map, O_RDONLY);
    read(fd, buf, 999);
    parse(gen, buf);
    gen->buffered_map = ft_strdup(buf);
    // printf("!!LETTER: %c\n", gen->buffered_map[1]);
    printf("Parsing completed!\n");
    close(fd);
}

int compliancy_check(int ac, char **av, t_gen *gen)
{
    int i;
    int ret;

    ret = SUCCESS;
    if (ac != 2)
        ret = error_message(1);
    else if (check_format(av[1]) != SUCCESS)
    {
        printf("hello\n");
        ret = FAILURE;
    }
    check_file_content(av[1], gen);
    return (ret);
}

void free_struct(t_gen *gen)
{
    free(gen->elements[0].path);
    free(gen->elements[1].path);
    free(gen->elements[2].path);
    free(gen->elements[3].path);
    free(gen->elements[4].path);
    free(gen->elements[5].path);
}

int perimeter_check(t_gen   *gen)
{
    int ret;

    ret = SUCCESS;
    int i;

    i = 0;
    while (gen->buffered_map[i])
    if (!gen->buffered_map || ft_strchr(gen->buffered_map, 'N') == NULL
        || ft_strchr(gen->buffered_map, 'S') == NULL
        || ft_strchr(gen->buffered_map, 'E') == NULL
        || ft_strchr(gen->buffered_map, 'W') == NULL)
        ret = error_message(3);
    
    return (ret);
}

// TODO:
//  MAP VALIDATION
//       - file must be *.cub
//       - CHAR-type must be: 3
//             -> 0 for walking space, 1 for wall
//             -> AND (N or S or E or W)
//             -> Map must be fullly brodered by 1s
//  CLEAN EXIT
//  ERROR HANDLING
//       - should return "Error\n" + CHOSEN message if anything is not compliant
//       - input -> NO SO WE  EA F C and ultimately MAP
//  TEXTURE SETUP
int main(int ac, char **av)
{
    t_gen gen;
    void *mlx_ptr;
    int i;

    i = 0;
    gen.el_num = 0;
    gen.buffered_map = NULL;
    while (i < 6)
        gen.elements[i++].path = NULL;
    if (compliancy_check(ac, av, &gen) != SUCCESS)
        return (1);
    if (perimeter_check(&gen) != SUCCESS)
        return (FAILURE);
    else
        printf("Good to go!\n");
    // mlx_ptr = mlx_init();
    // mlx_destroy_display(mlx_ptr);
    // free(mlx_ptr);
    free_struct(&gen);
    return (SUCCESS);
}