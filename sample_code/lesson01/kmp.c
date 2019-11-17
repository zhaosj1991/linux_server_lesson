#include <stdio.h>
#include <memory.h>

void make_next(char *pattern, int *next)
{
    int q, k;
    int m = strlen(pattern);

    next[0] = 0;
    for(q = 1, k = 0; q < m; q++)
    {
        while (k > 0 && pattern[q] != pattern[k])
            k = next[k-1];

        if (pattern[q] == pattern[k])
        {
            k++;
        }

        next[q] = k;
    }
}

int kmp(char *data, char *pattern)
{
    int i, j;
    int n = strlen(data);
    int m = strlen(pattern);

    if (n < m)
    {
        return -1;
    }
    
    int next[100] = {0};
    make_next(pattern, next);

    for (i = 0, j = 0; i < n; i++)
    {
        // 此步骤后，如果没有匹配到，j的值为0，所以下次i循环时，j会从0开始
        // 每一次i循环，都会按照next子串匹配一遍，成功 j==m，跳出循环；
        // 否则继续下次循环，再遍历next子串。
        // 之所以是next[j-1]，是因为 next[j-1]的最长公共子串，
        // 同样也是pattern[j]字符串的公共子串，只是不是最长的而已。（根据对称性很容易得到）
        while (j > 0 && data[i] != pattern[j])
            j = next[j - 1];
        
        if (data[i] == pattern[j])
        {
            j++;
        }

        if (j == m)
            break;  
    }

    if (j == m)
        return i-m+1;
    else
        return -1;
}

int main()
{
    char *data = "ababxbababababcdababcabddcadfdsss";
	char *pattern = "abcabd";

    int ret = kmp(data, pattern);

    printf("kmp ret = %d\n", ret);

    if (ret != -1)
    {
       for (int i = 0; i < strlen(pattern); i++)
        {
            printf("%c ", data[i+ret]);
        }
        printf("\n"); 
    }    
    
    return 0;
}