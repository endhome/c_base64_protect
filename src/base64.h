#ifndef _BASE64_H_
#define _BASE64_H_

/* 字符串转换为base64编码 */
char *base64_encode( const char *input_str);
/* base64编码转换为字符串 */
char *base64_decode( const char *input_str);

#endif
