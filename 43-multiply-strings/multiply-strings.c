char* multiply(char* num1, char* num2) {
    if ((num1[0] == '0' && num1[1] == '\0') || (num2[0] == '0' && num2[1] == '\0')) {
        char *res = (char *)malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *arr = (int *)calloc(len1 + len2, sizeof(int));

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + arr[i + j + 1];

            arr[i + j + 1] = sum % 10;
            arr[i + j] += sum / 10;
        }
    }

    char *result = (char *)malloc(len1 + len2 + 1);
    int k = 0, i = 0;

    while (i < len1 + len2 && arr[i] == 0)
        i++;

    while (i < len1 + len2)
        result[k++] = arr[i++] + '0';

    result[k] = '\0';

    free(arr);
    return result;
}