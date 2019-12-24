
// 定义各种常用结构

struct base {
    int type;
};

struct string{
    struct base info;
    int len;
    char *data[0];
};

struct number{
    int len;
    double num;
};

// 使用union来将所有数据包进来

typedef struct string{
    int len;
    char *data[0];
}string;

typedef struct number{
    double num;
}number;

struct value{
    int type;
    union {
        string str;
        number num;
    } value;
};