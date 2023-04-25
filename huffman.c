/*
    Algorithm
    n = |c|
    make a min heap Q with c 
    for (i = 1 to n- 1)
    create a new node z
    z.left = x = extract min(Q)
    z.right = y = extract min(Q)

    z.freq = x.freq + y.freq
    insert(Q to Z)
    return extract min(Q)
*/

//huffman coding

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNode, *HuffmanTree;

typedef char **HuffmanCode;


void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
    int i;
    int min1, min2;
    min1 = min2 = 32767;
    for (i = 1; i <= n; i++)
    {
        if (HT[i].weight < min1 && HT[i].parent == 0)
        {
            min2 = min1;
            *s2 = *s1;
            min1 = HT[i].weight;
            *s1 = i;
        }
        else if (HT[i].weight < min2 && HT[i].parent == 0)
        {
            min2 = HT[i].weight;
            *s2 = i;
        }
    }
}

void CreateHuffmanTree(HuffmanTree *HT, int *w, int n)
{
    int m, s1, s2, i;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for (i = 1; i <= n; i++)
    {
        (*HT)[i].weight = w[i - 1];
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    for (; i <= m; i++)
    {
        (*HT)[i].weight = 0;
        (*HT)[i].parent = 0;
        (*HT)[i].lchild = 0;
        (*HT)[i].rchild = 0;
    }
    for (i = n + 1; i <= m; i++)
    {
        Select(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
}


void HuffmanCoding(HuffmanTree HT, HuffmanCode *HC, int n)
{
    int i, c, p;
    char *cd;
    int start;
    *HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n; i++)
    {
        start = n - 1;
        for (c = i, p = HT[i].parent; p != 0; c = p, p = HT[p].parent)
        {
            if (HT[p].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        (*HC)[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy((*HC)[i], &cd[start]);
    }
    free(cd);
}


int main()
{
    int i, n;
    HuffmanTree HT;
    HuffmanCode HC;
    int w[MAX];
    printf("Please input the number of the characters:");
    scanf("%d", &n);
    printf("Please input the weight of the characters:");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);
    CreateHuffmanTree(&HT, w, n);
    HuffmanCoding(HT, &HC, n);
    for (i = 1; i <= n; i++)
        printf("%s ", HC[i]);
    printf(" ");
    return 0;
}

