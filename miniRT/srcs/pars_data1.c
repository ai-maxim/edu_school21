/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdong <qdong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:47:16 by qdong             #+#    #+#             */
/*   Updated: 2021/03/15 19:00:34 by qdong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char 		**create_array(t_list *list, int quantuty)
{
	t_list 	*tmp;
	char 	**arr;
	int i;
//	printf("%d\n", quantuty);
	arr = (char **)malloc(quantuty + 1);
	i = 0;
	tmp = list;
//	write(1, "+\n", 2);
	while (tmp)
	{
		arr[i] = list->content;
//		printf("%s\n", arr[i]);
		tmp = list->next;
		list = list->next;
//		printf("%p\n", tmp);
//		printf("%i\n", i);
		i++;
	}
	arr[i] = NULL;
	return(arr);
}

char		**pars_data1(char *name, t_scena *scena)
{
	char	*line;
	t_list	*list;
	char	**arr;
//	int ret;
	int		fd;
	(void)scena;
	int result;

//	ret = 1;
	fd = open(name, O_RDONLY);
	// while (ret)
	// {
	// 	ret = get_next_line(fd, &line);
	// 	sp = ft_split(line, ' ');
	// 	if (*sp && !ft_strncmp(sp[0], "sp", 9))
//			printf("sp_center = %s", sp[1]);
//			printf("sp_radius = %s", sp[2]);
//			printf("sp_color = %s", sp[3]);
		// while(*sp)
		// 	printf("|%s|", *(sp++));
		// printf("\n");
	//}
	while ((result = get_next_line(fd, &line)))
	{
		if (!result)
			error_exit(1); // ошибка малока
		if(!(ft_lstadd_back(&list, ft_lstnew(line))))
			error_exit(1); //продумать вывод
	}
	if(!(ft_lstadd_back(&list, ft_lstnew(line))))
		error_exit(1); //продумать вывод
	arr = create_array(list, ft_lstsize(list));
	return (arr);
}
