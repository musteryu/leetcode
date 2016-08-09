void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void reverse(char *s, int start, int end) {
    while (start < end) swap(&s[start++], &s[--end]);
}
void reverseWords(char *s) {
    int slen = 0;
    
    while (s[slen] != '\0') slen++;
    if (slen == 0) return;
    
    while (s[slen-1] == ' ') slen--;
    s[slen] = '\0'; // trim tailing space

    int slow = -1, fast = slow + 1;
    while (s[fast] == ' ') fast++;
    if (s[fast] == '\0') {
        s[0] = '\0';
        return;
    }
    while (fast < slen) {
        if (slow >= 0 && s[slow] == ' ' && s[fast] == ' ') fast++;
        else s[++slow] = s[fast++];
    
    }
    
    s[++slow] = '\0';
    slen = slow;
    reverse(s, 0, slen);
    slow = 0;
    fast = 0;
    while (fast < slen) {
        if (s[fast] != ' ') fast++;
        else {
            reverse(s, slow, fast);
            slow = fast + 1;
            fast = slow;
        }
    }
    reverse(s, slow, fast);
}