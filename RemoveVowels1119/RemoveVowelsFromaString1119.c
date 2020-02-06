char * removeVowels(char * S) {
    int len = strlen(S);
    char noVowels[len];
    int i = 0;
    int j = 0;
    while (S[i] != '\0')
    {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
            i++;
            continue;
        } else {
            noVowels[j] = S[i];
            j++;
            i++;
        }
    }
    strcpy(S, noVowels);
    S[j] = '\0';
    return S;
}