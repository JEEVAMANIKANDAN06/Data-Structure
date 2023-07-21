int* partitionLabels(char * s, int* returnSize){
    int* _partitionLs = 0;
    int count = 0;
    const int n = strlen(s);
    if (n == 1) { _partitionLs = realloc(_partitionLs, sizeof(int)); _partitionLs[0] = 1; *returnSize = 1; return _partitionLs; } 

    int _endMap[26];
    memset(_endMap, 0, sizeof(int) * 26);
    for (int i = 0; i < n; i++) {  
        _endMap[s[i]-'a'] = i;
    }

    int start = 0;
    while (start < n) {
        int s0 = start;
        int end = _endMap[s[s0]-'a'];
        
        while (s0 < end) {
            int end0 = _endMap[s[s0]-'a']; end = fmax(end0, end);
            s0++;
        }
        _partitionLs = realloc(_partitionLs, sizeof(int)*(count+1)); _partitionLs[count++] = end - start + 1;
        start = end + 1;
    }
    *returnSize = count;
    return _partitionLs;

}