#include <vector>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

class Triangular {
    public:
        // 一组重载的constructor
        // Tirangular(int len=1, int bp=1);
        Triangular(int len);
        Triangular(const Triangular &rhs);
        Triangular(int len, int beg_pos);
        Triangular& copy(const Triangular &rhs);

        static bool is_elem(int);
        static void gen_elements(int length);
        static void gen_elems_to_value(int value);
        static void display(int length, int beg_pos, ostream &os=cout);

    private:
        string _name;
        static const int _buf_size = 1024;
        static const int _max_elems = 1024;
        int _next, _length, _beg_pos;
        static vector<int> _elems;
};

class TriangularConst{
    public:
        // 以下是const member function 
        int length() const {return _length;}
        int beg_pos() const {return _beg_pos;}
        int elem(int pos) const;

        // 以下是non-const member function
        bool next(int &val);
        void next_reset() const{
            _next = _beg_pos - 1;
        }

    private:
        int _length;
        int _beg_pos;
        // 在C++中，mutable 是为了突破 const 的限制而设置的。可以用来修饰一个类的成员变量。
        // 被 mutable 修饰的变量，将永远处于可变的状态，即使是 const 函数中也可以改变这个变量的值
        mutable int _next;

        static vector<int> _elems; 
};

class Matrix {
    public:
        Matrix(int row, int col)
                :_row(row), _col(col)
        {
            // constructor 进行资源的分配

            _pmat = new double[row * col];
        }

        // 成员逐一初始化
        Matrix(const Matrix &rhs)
            :_row(rhs._row), _col(rhs._col)
            {
                int elem_cnt = _row * _col;
                _pmat = new double[elem_cnt];

                for (int ix =0; ix < elem_cnt; ++ix)
                    _pmat[ix] = rhs._pmat[ix];

            }

        Matrix& operator==(const Matrix &rhs);

        ~Matrix()
        {
            // destructor 进行资源的释放
            delete [] _pmat;
        }
    private:
    int _row, _col;
    double* _pmat;
};

class Triangular_iterator{
    public:
    Triangular_iterator(int index): _index(index-1) {}
    bool operator==(const Triangular_iterator& ) const;
    bool operator!=(const Triangular_iterator& )  const;
    int operator*() const;
    Triangular_iterator& operator++();
    Triangular_iterator operator++(int);
    private:
    void check_integrity() const;
    int _index;
};

class LessThan
{
    public:
        LessThan(int val): _val(val){}
        int comp_val() const {return _val;}
        void comp_val(int nval) {_val = nval;}

        bool operator()(int _value) const;
    private:
        int _val;

};