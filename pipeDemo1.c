//
// Created by Wen on 2018/3/6.
//
#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 为什么 pipe不能将标准输出重定向到pipe[0]上？这样管道输入端直接输入，就直接输出了
 *
 * 关闭pi[0], 发送数据，会触发EPIPE信号,程序退出。啊哈哈
 *
 *
 */
/**
 * pipe的Demo
 */
void main(){


    int pi[2], len;

    char  inputs[100], gets;


    if (pipe(pi) != 0) {

        perror("管道创建失败!");
        exit(1);
    }

    printf("当前管道文件描述符分别是: %d --%d \n", pi[0], pi[1]);


//    close(1);
//
//    dup(pi[0]);
//    close(pi[0]);


    while ((fgets(inputs, 100, stdin)) != NULL){

        len = strlen(inputs);

        printf("当前输入为:%s", inputs);
        printf("当前len为:%d", len);

        /**
         * pipe管道发送数据
         */
        write(pi[1], inputs, len);
        for (int i= 0; i < len; ++i) {

            inputs[i] = 'X';
        }

//        /**
//         * 读取管道数据
//         */
        read(pi[0], inputs, len);
//
//        /**
//         * 发送给标准输出
//         */
        write(1, inputs, len);

    }


}