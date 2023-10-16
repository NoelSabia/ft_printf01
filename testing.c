#include <unistd.h>
#include <stdlib.h>

void	show_pointeradress(size_t ptr)
{
	char	*base;
	char	*placeholder;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	write (1, "0x", 2);
	if (ptr == 0)
	{
		write (1, "0", 1);
		return ;
	}
	placeholder = (char *)malloc(sizeof(ptr));
	while (ptr != 0)
	{
		placeholder[i] = base[ptr % 16];	
		ptr /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (1, &placeholder[i], 1);
	}
	free(placeholder);
}