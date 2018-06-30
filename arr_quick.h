#define maxsize 50
#define minvalue -999

void initialize(int arr[])
{
	arr[0] = minvalue;
}

int insert(int arr[], int len, int index, int val)
{
	int i;
	if (len == maxsize)
	{
		printf("\tarray bound reached...\n");
		return len;
	}
	if (val == minvalue)
		return len;

	for (i = len;i >= index;i--)
		arr[i + 1] = arr[i];
	arr[index] = val;
	return len + 1;
}

int getvalue(int arr[], int len)
{
	int value;
	if (len == maxsize)
		printf("\nmax size reached\n");
	else
		scanf("%d", &value);
	return value;
}

int arrlength(int arr[])
{
	int len = 0;
	while (arr[len] > minvalue || len > maxsize)
		len++;
	return len;
}

int create(int arr[], int len)
{
	int i = 0, value = 0;
	do {
		if (len == maxsize)
		{
			printf("\nmaxsize is reached\n");
			break;
		}
		else
		{
			printf("Enter the array elements:\n");
			while (value != minvalue)
			{
				value = getvalue(arr, len);
				if (value == minvalue)
					return len;
				else
					len = insert(arr, len, len, value);
			}
		}
	} while (len == maxsize && value != minvalue);
}

void display(int arr[], int len)
{
	int i = 0;
	if (len != 0)
	{
		printf("\nElements of array:\n");
	}
	for (i = 0; i <len; i++)
	{
		if(arr[i]!=minvalue)
		printf("%d ", arr[i]);
	}
	return;
}

void copy_arr(int arr[], int copy[], int len)
{
	int i;
	for (i = 0;i<len;i++)
		copy[i]=arr[i];
	return;

}
