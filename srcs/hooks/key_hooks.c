#include "../../fdf.h"

int key_hooks(int key, void *data)
{
	t_data	*ptr;

	ptr = (t_data *)data;

	if (key == 53)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		system("leaks fdf");
		exit(0);
	}
	return (0);
}