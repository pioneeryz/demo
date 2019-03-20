#include <iostream>
#include <stdio.h>
using namespace std;

int convert(unsigned char *dst,unsigned char *src,int len){

    for(int i=0;i<len;i++){
        dst[i]=src[i]^0xFF;
    }
    return 0;
}
//十六进制转十进制
unsigned long HextoDec(const unsigned char *hex, int length)
{
    int i;
    unsigned long rslt = 0;
    for (i = 0; i < length; i++)
    {
        rslt += (unsigned long)(hex[i]) << (8 * (length - 1 - i));

    }
    return rslt;
}
//十进制转十六进制
int DectoHex(int dec, unsigned char *hex, int length)
{
    int i;
    for (i = length - 1; i >= 0; i--)
    {
        hex[i] = (dec % 256) & 0xFF;
        dec /= 256;
    }
    return 0;
}
//求权
unsigned long power(int base, int times)
{
    int i;
    unsigned long rslt = 1;
    for (i = 0; i < times; i++)
        rslt *= base;
    return rslt;
}
//BCD转十进制
unsigned long  BCDtoDec(const unsigned char *bcd, int length)
{
    int i, tmp;
    unsigned long dec = 0;
    for (i = 0; i < length; i++)
    {
        tmp = ((bcd[i] >> 4) & 0x0F) * 10 + (bcd[i] & 0x0F);
        dec += tmp * power(100, length - 1 - i);
    }
    return dec;
}
//十进制转BCD
int DectoBCD(int Dec, unsigned char *Bcd, int length)
{
    int i;
    int temp;
    for (i = length - 1; i >= 0; i--)
    {
        temp = Dec % 100;
        Bcd[i] = ((temp / 10) << 4) + ((temp % 10) & 0x0F);
        Dec /= 100;
    }
    return 0;
}
int main()
{
    //BCD转十进制
    unsigned char BCD[1] = {0x53};
    int dec_bcd = BCDtoDec(BCD, 1);
    cout << "dec_bcd : " << dec_bcd << endl;

    //十进制转BCD
    unsigned char tmp_bff[3] = "";
    DectoBCD(dec_bcd, tmp_bff, 3);
    for (int i = 0; i < 3; ++i)
    {
        //cout << "tmp_buff[" << i << "]: " << tmp_bff[i] << endl;
        printf("tmp_bff[%d] = 0x%02X\n", i, tmp_bff[i]);
    }

    cout << endl << endl;
    //十六进制转十进制
    //unsigned char Hex[3] = { 0x00, 0x53, 0x20 };
    unsigned char Hex[2] = {0x53,0x20};
    int dec_hex = HextoDec(Hex, 2);
    cout << "dec_hex: " << dec_hex << endl;

    //十进制转十六进制
    unsigned char hex_bff[3] = "";
    DectoHex(dec_hex, hex_bff, 3);
    for (int i = 0; i < 3; ++i)
    {
        printf("hex_bff[%d] = 0x%02X\n", i, hex_bff[i]);
    }
    return 0;
}
