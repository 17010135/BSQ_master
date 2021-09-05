
#include "headers.h"

int	a_to_i(int num, char c)
{
	num *= 10;
	num += (c - 48);
	return (num);
}

list *importinput(char *theMap2)
{
	list	*l;
	int		fd;
	char	buff;
	int		num;

	l = NULL;
	num = 0;
	fd = open(theMap2, O_RDONLY | O_WRONLY);
	if (fd == -1)
	{
		return l;
	}
	while (read(fd, &buff, 1))
	{
		if (buff >= '0' && buff <= '9')
			num = a_to_i(num, buff);
		else
		{
			if (l == NULL)
				l = newnodelines(num);
			l = insertnodeend(buff, l);
		}
	}
	close(fd);
	return (l);
}
