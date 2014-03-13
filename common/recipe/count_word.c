/*
 * =====================================================================================
 *
 *       Filename:  count_word.c
 *
 *    Description:  统计英文文章中的单词个数，使用有穷状态机来处理
 *
 *        Version:  1.0
 *        Created:  07/29/2013 10:03:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <string.h>

#define IS_WORD_CHAR(p)  (((p>'A')&&(p<'Z'))||((p>'a')&&(p<'z'))) 

static int count_word(const char *text)
{
    enum _State{
            STAT_INIT=0,
            STAT_IN_WORD,
            STAT_OUT_WORD,
    }state = STAT_INIT;

    int count = 0;
    char *p = text;
    for(p;p!='0';p++)
    {
        switch(state)
        {
            case STAT_INIT:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        state = STAT_IN_WORD;
                    }
                    else{
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_IN_WORD:
                {
                    if(!IS_WORD_CHAR(*p))
                    {
                        count++;
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_OUT_WORD:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        count++;
                        state = STAT_IN_WORD;
                    }
                    break;
                }
            default:
                break;
        }
    }

    if(state == STAT_IN_WORD)
        count++;
    return count;
}
/*分离出里面的每个单词 , 分离出来的单词的作用由回调函数决定*/
static int word_segmentation(const char *text, OnWordFunc on_word, void *ctx)
{
    enum _State{
            STAT_INIT=0,
            STAT_IN_WORD,
            STAT_OUT_WORD,
    }state = STAT_INIT;

    int count = 0;
    char *copy_text = strdup(text);
    char *p = copy_text;
    char *word = NULL;
    for(p;p!='0';p++)
    {
        switch(state)
        {
            case STAT_INIT:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        state = STAT_IN_WORD;
                        word = p;
                    }
                    else{
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_IN_WORD:
                {
                    if(!IS_WORD_CHAR(*p))
                    {
                        count++;
                        p = '0';
                        on_word(ctx, word)
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_OUT_WORD:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        count++;
                        word = p;
                        state = STAT_IN_WORD;
                    }
                    break;
                }
            default:
                break;
        }
    }

    if(state == STAT_IN_WORD)
    {
        count++;
        on_word(ctx, word);
    }

    free(copy_text);
    return count;
}

/*文本数据，这些数据由分隔符分开，token，我们要把这些token分离出来*/

typedef void (*OnTokenFunc)(void *ctx, int index, const char *token);

int parse_token(const char *text, const char *delims, OnTokenFunc on_token, void *ctx)
{
    enum _State{
            STAT_INIT=0,
            STAT_IN_WORD,
            STAT_OUT_WORD,
    }state = STAT_INIT;

    int count = 0;
    char *p = text;
    for(p;p!='0';p++)
    {
        switch(state)
        {
            case STAT_INIT:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        state = STAT_IN_WORD;
                    }
                    else{
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_IN_WORD:
                {
                    if(!IS_WORD_CHAR(*p))
                    {
                        count++;
                        state = STAT_OUT_WORD;
                    }
                    break;
                }
            case STAT_OUT_WORD:
                {
                    if(IS_WORD_CHAR(*p))
                    {
                        count++;
                        state = STAT_IN_WORD;
                    }
                    break;
                }
            default:
                break;
        }
    }

    if(state == STAT_IN_WORD)
        count++;
    return count;

}

/*解析ini文件的状态机*/

/*
   * 状态集合 
   * 1.分组的组名状态 
   * 2.注释状态
   * 3.配置项的名称状态
   * 4.配置项的值状态
   * 5.空白状态
   *
*/
static void ini_parse(char *buffer, char comment_char, char delim_char, onIniParse call_func)
{

    char *p = NULL;
    char *ckey = NULL;
    char *cvalue = NULL;
    char *comment ;
    enum _State
    {
        STAT_NONE = 0 ,
        STAT_GROUP ,
        STAT_COMMENT,
        STAT_KEY,
        STAT_VALUE
    }state = STAT_NONE;

    for()
    {
        switch(state)
        {
            case STAT_NONE:
                {
                    if(p == ';')
                    {
                        state = STAT_COMMENT;
                        //处理注释    
                        comment = p+1;
                        printf("comment:%s \n", comment);
                    }
                    else if(p == '[')
                    {
                        state = STAT_GROUP;
                        //处理组的名称
                    }
                    else if(IS_WORD_CHAR(p)) 
                    {
                        ckey = p;
                        state = STAT_KEY;
                    }else if (p == '\0'){
                    }
                    break;
                }
            case STAT_GROUP:
                {
                    if(p == ']')
                    {
                        state = STAT_NONE;
                    }
                    break;
                }
            case STAT_COMMENT:
                {
                    if(p == '\n')
                    {
                        state = STAT_NONE;
                    }
                    break;
                }
            case STAT_KEY:
                {
                    if(*p == delim_char || (delim_char == ' ' && *p == '\t'))
                    {
                        *p = '\0';
                        cvalue = p+1;
                        state = STAT_VALUE;
                    }
                    break;
                }
            case STAT_VALUE:
                {
                    if(*p == '\n' || *p == '\r')
                    {
                        state = STAT_NONE;
                        *p = '\0';
                        call_func(ckey,cvalue);
                    }
                    break;
                }
            default:
                break;
        }

    }
    if (state == STAT_VALUE)
    {
        state = STAT_NONE;
        call_func(ckey, cvalue);
    }

    return ;
}
