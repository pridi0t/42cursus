int partition(int *arr, int start, int end)
{
    int pivot;
    int tmp;

    pivot = arr[(start + end) / 2];
    while (start <= end)
    {
        while (arr[start] < pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start <= end)
        {
            tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }
    return start;
}

void quick_sort(int *arr, int start, int end)
{
    int midx;
    int i;

    i = 0;
    midx = partition(arr, start, end);
    if (start < midx - 1)
        quick_sort(arr, start, midx - 1);
    if (end > midx)
        quick_sort(arr, midx, end);
}