#include "../fdf.h"

int main(int argc, char *argv[])
{
    t_data  data;

    if (argc != 2)
    {
        perror("Arguments size is invalid");
        return (1);
    }
    if (validate_format(argv) == 0)
        return (1);
    data.map = get_map(argv);
    if (validate_map(data.map) == 0)
      return (1);
    init(&data);
	
}