#include <stdint.h>
#include <stdio.h>

int main(int argc, char** argv) {

    //읽은 4바이트를 저장
    uint32_t binary;
    uint32_t binary1 = 0;

    //입력받을 파일
    FILE* fp = fopen(argv[1], "rb");
    FILE * file = fopen(argv[2], "wb");

    //파일이 비었으면 리턴
    if (fp == NULL) {
        printf("file is empty");
        return 1;
    }

    //파일이 비지 않았으면 fread를 통해서 파일을 읽어서 binary에 저장
    else {
        fread(&binary, sizeof(uint32_t), 1, fp);
        printf("binary : %x \n", binary);
        binary1 = ((binary&0xFF000000) >> 24) | ((binary&0xFF0000) >> 8) | ((binary&0xFF00) << 8) | ((binary&0xFF) << 24);
        printf("binary1 : %x \n", binary1);


        fwrite(&binary1, sizeof(uint32_t), 1, file);
    }
    fclose(file);
    fclose(fp);
    return 0;
}
