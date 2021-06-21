#include "base64.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{

    char *in = "dfgfjgkj2344";
    char *en_out;
    char *de_out;
    char sbuf[2048+1];

    FILE *fp = NULL;
    FILE *fp_out = NULL;

    FILE *fp_out1 = NULL;
    FILE *fp_de = NULL;

#if 0
    printf("res string    :\t[%s]\n",in);
    en_out = base64_encode(in);
    printf("base64_encode :\t[%s]\n",en_out);
    de_out = base64_decode(en_out);
    printf("base64_decode :\t[%s]\n",de_out);
#endif

    /*********************************************************************/
    /*原始文件*/
    fp = fopen("../test.txt","r");
    if(NULL == fp)
    {
        printf("open in_file is err\n");
        exit(-1);
    }
    /*原始文件base64转码后的文件*/
    if( NULL == (fp_out = fopen("../test_out.txt","w+")))
    {
        printf("open out_file is err\n");
        fclose(fp);
        fp = NULL;
        exit(-1);
    }
    /*文件转为base64保存到文件*/
    memset(sbuf, 0x00, sizeof(sbuf));
    while(NULL != fgets(sbuf, 1024, fp))
    {
        en_out = base64_encode(sbuf);
        fprintf(fp_out, "%s\n",en_out);
        memset(sbuf, 0x00, sizeof(sbuf));
    }
    fclose(fp);
    fclose(fp_out);
    fp = NULL;
    fp_out = NULL;
    /*********************************************************************/
    /*base64格式文件进行解码保存到另外一个文件*/
    if( NULL == (fp_out1= fopen("../test_out.txt","r")))
    {
        printf("open fp_out1 is err\n");
        exit(-1);
    }
    if( NULL == (fp_de= fopen("../test_out_base64_decode.txt","w+")))
    {
        printf("open fp_de is err\n");
        fclose(fp_out1);
        fp_out1 = NULL;
        exit(-1);
    }
    memset(sbuf, 0x00, sizeof(sbuf));
    while(NULL != fgets(sbuf, 1024, fp_out1))
    {
        en_out = base64_decode(sbuf);
        fprintf(fp_de, "%s",en_out);
        memset(sbuf, 0x00, sizeof(sbuf));
    }
    fclose(fp_out1);
    fclose(fp_de);
    fp_de = NULL;
    fp_out1 = NULL;
    /*********************************************************************/

    return 0;
}
