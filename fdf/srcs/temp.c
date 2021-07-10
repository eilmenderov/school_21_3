#include "head_fdf.h"

void	ft_print_map(t_data *data)
{
	int	i;
	int	j;

	printf("height = %d  widtgh = %d  fl = %d\n", data->height,
		data->width, data->erfl);
	printf("max = %d min = %d\n", data->maxz, data->minz);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		printf("fl-[%d]\t", i);
		while (j < data->width)
		{
			printf("%3d", data->arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
