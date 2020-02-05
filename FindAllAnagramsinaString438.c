int isSame(int *a, int *b)
{
    int i;
    for(i=0; i<26; i++)
    {
        if(a[i] != b[i])
        return (0);
    }
    return(1);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize)
{
    int s_len = strlen(s);
    int p_len = strlen(p);
    int i;
    int j;

    if(p_len > s_len) return;
    int p_alphabet[26] = {0};
    int s_alphabet[26] = {0};
    int *ans = (int*)malloc(sizeof(int)*s_len);
    (*returnSize) = 0;
    for(i=0; i<p_len; i++)
    {
        if(i != 0)
            s_alphabet[s[i+p_len-1]-'a']++;
        if(isSame(p_alphabet, s_alphabet))
        {
            ans[*returnSize] = i;
            (*returnSize)++;

        }   
        s_alphabet[s[i]-'a']--;
    }
    return ans;
}