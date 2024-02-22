//螺旋矩阵Ⅱ：给定一个正整数n，生成一个包含1到n^2所有元素，且元素按照顺时针顺序螺旋排列的正方形矩阵
//这是一个二维数组传参的成功案例
#include <stdio.h>
#include <stdlib.h>

int** declare(int n){
    int** arr = (int**) malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i ++){
        arr[i] = (int*) malloc(sizeof(int) * n);
    }
    return arr;
}

void generateMatrix(int** arr, int n){
    int startx = 0;
    int starty = 0;
    int offset = 1;
    int count = 1;
    int loop = n / 2;
    int mid = n / 2;
    while (loop){
        int i = startx;
        int j = starty;
        for (; i < n - offset; i ++){
            arr[starty][i] = count ++;
        }
        for (; j < n - offset; j ++){
            arr[j][i] = count ++;
        }
        for (; i > startx; i --){
            arr[j][i] = count ++;
        }
        for (; j > starty; j --){
            arr[j][i] = count ++;
        }
        startx ++;
        starty ++;
        loop --;
        offset ++;
    }
    if (n % 2){
        arr[mid][mid] = count;
    }
}

int main()
{
    int n;
    scanf ("%d", &n);
    int** arr = declare(n);
    generateMatrix(arr, n);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            printf ("%d\t", arr[i][j]);
        }
        printf ("\n");
    }
    return 0;
}
