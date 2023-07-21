int removeDuplicates(int* nums, int numsSize){
    int k = 1;

    int* ptr_insert = nums;
    int* ptr_scanner = nums;
    int* ptr_end = nums + numsSize - 1;

    while (ptr_scanner < ptr_end) {
        while (*ptr_scanner == *ptr_insert && ptr_scanner < ptr_end) {
            ptr_scanner++;
        }

        if (*ptr_scanner != *ptr_insert) {
            ptr_insert++;
            *ptr_insert = *ptr_scanner;
            k++;
        }
    }

    return k;
}