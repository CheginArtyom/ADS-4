// Copyright 2021 CheginArtyom
int countPairs1(int* arr, int len, int value) {
int c = 0;
for (int i = 0; i < len; i++) {
for (int j = 0; j < len; j++) {
if (arr[i] + arr[j] == value && i !=j)
c++;
}
}
return c / 2;
}
int countPairs2(int* arr, int len, int value) {
int i = 0;
int j = len - 1;
int c = 0;
for (i = 0; i < len; i++) {
for (j = len - 1; j > i; j--) {
if (arr[i] + arr[j] == value)
c++;
}
}
return c;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; i++) {
        int low = i;
        int top = len;
        while (low < top-1) {
            int mid = (low + top) / 2;
            if (arr[i] + arr[mid] == value) {
                ++count;
                int j = mid + 1;
                while (arr[i] + arr[j] == value && j < top) {
                    ++count;
                    ++j;
                }
                j = mid - 1;
                while (arr[i] + arr[j] == value && j > low) {
                    ++count;
                    --j;
                }
                break;
            }
            if (arr[i] + arr[mid] < value)
                low = mid;
            if (arr[i] + arr[mid] > value)
                top = mid;
        }
    }
    if (count != 0)
        return count;
    return 0;
}
