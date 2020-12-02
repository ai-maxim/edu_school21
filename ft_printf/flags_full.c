
void printing(t_struct data)
{
  if (data->type == 's')
    print_s(data);
  if (data->type == 'c')
    print_c(data);
  if (data->type == 'd' || data->type == 'i')
    print_di(data);
  if (data->type == 'u')
      print_u(data);
  if (data->type == 'p')
      print_p(data);
  if (data->type == 'x')
      print_x(data);
  if (data->type == 'X')
      print_xx(data);
  if (data->type == '%')
      print_perc(data);
}
