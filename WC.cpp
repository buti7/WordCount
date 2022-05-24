#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    // argc 表示参数个数, *argv[]指针数组, 每一个指针指向一个字符串
    FILE *fp;
    int count = 0; 
    if ((fp=fopen(argv[2], "r")) == NULL)//打开末尾的txt文件 
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w') // 统计单词
    {
        char s[512];//若定义为char型会发生内存读写错误 
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            int i;
            for ( i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("单词数=%d\n", count);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char c;
        while ((c = fgetc(fp)) != EOF) count ++;
        printf("字符数=%d", count);
    }
    fclose(fp);
    return 0;
}
