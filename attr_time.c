#include "ft_ls.h"

void		put_month_day(char *month, char *day, size_t biggest)
{
	ft_putstr(month);
	ft_putstr(" ");
	if (ft_strlen(day) < biggest)
		ft_putstr(" ");
	ft_putstr(day);
	ft_putstr(" ");
}

void		put_hour(char *h, char *min)
{
	ft_putstr(h);
	ft_putstr(":");
	ft_putstr(min);
}

void		file_time(long mtime, int year_flag, size_t biggest)
{
	char	**tab;
	char	**tab_h;
	long	now;

	tab = 0;
	tab_h = 0;
	now = time(0);
	tab = ft_strsplit(ctime(&mtime), ' ');
	tab_h = ft_strsplit(tab[3], ':');
	put_month_day(tab[1], tab[2], biggest);
	if (now - 15778463 > mtime || mtime > now)
	{
		if (year_flag == 1)
			ft_putstr(" ");
		tab[4][4] = '\0';
		ft_putstr(tab[4]);
	}
	else
		put_hour(tab_h[0], tab_h[1]);
	ft_putstr(" ");
	// ft_strdel(&str);
	// free(tab);
	// free(tab_h);
}