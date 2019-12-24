#include "sequence.h"

vector<int> Triangular::_elems;
Triangular::Triangular(int len, int bp):_name("Triangular"){
    int _length = len > 0? len :1;
    int _beg_pos = bp > 0? bp : 1;
    int _next = _beg_pos - 1;

}

Triangular& Triangular::copy(const Triangular &rhs)
{
    if (this != &rhs){
        _length = rhs._length;
        _beg_pos = rhs._beg_pos;
        _next = rhs._beg_pos-1;
    }
    return *this;
}
bool Triangular::is_elem(int value){
    if(!_elems.size() || _elems[_elems.size()-1] < value)
        gen_elems_to_value(value);

    vector<int>::iterator found_it;
    vector<int>::iterator end_it = _elems.end();
    found_it = find(_elems.begin(), end_it, value);
    return found_it != end_it;
}

void Triangular::gen_elems_to_value(int value){
    int ix = _elems.size();
    if(!ix){
        _elems.push_back(1);
        ix = 1;
    }
    while (_elems[ix-1]<value && ix < _max_elems)
    {
        ++ix;
        _elems.push_back(ix*(ix+1)/2);
    }

    if (ix == _max_elems)
        cerr<<"Triangular Sequence: opps value too  large"
        <<value<<"-- exceeds max size of "
        <<_max_elems<<endl;
}

void Triangular::gen_elements(int length)
{
    if (length < 0 || length > _max_elems)
    {}

    if (_elems.size() < length)
    {
        int ix = _elems.size() ? _elems.size() + 1: 1;
        for(;ix<=length; ++ix)
            _elems.push_back(ix*(ix+1)/2);
    }
}

// 成员初始化列表
Triangular::Triangular(const Triangular &rhs)
:_length(rhs._length), _beg_pos(rhs._beg_pos), _next(rhs._beg_pos-1)
{}


vector<int> TriangularConst::_elems;
int TriangularConst::elem(int pos) const{
    return _elems[pos-1]; 
}


inline bool Triangular_iterator::operator==(const Triangular_iterator &rhs) const{
    return _index == rhs._index;
}

inline int Triangular_iterator::operator*() const{
    check_integrity();
    // return Triangular::_elems[_index];
    return 0;
}

inline void Triangular_iterator::check_integrity() const{
    // if (_index > Triangular::_max_elems)
    //     throw iterator_overflow();
    
    // if (_index >= Triangular::_elems.size())
    //     Triangular::gen_elements(_index + 1);
}

inline Triangular_iterator& Triangular_iterator::
operator++()
{
    ++_index;
    check_integrity();
    return *this;
}

inline Triangular_iterator Triangular_iterator::operator++(int)
{
    Triangular_iterator tmp = *this;
    ++_index;
    check_integrity();
    return tmp;
}

Matrix& Matrix::operator==(const Matrix &rhs)
{
    if (true)
    // if (this != rhs)
    {
        _row = rhs._row;
        _col = rhs._col;
        int elem_cnt = _row *_col;
        delete [] _pmat;
        _pmat = new double[elem_cnt];
        for (int ix =0;ix<elem_cnt; ++ix)
            _pmat[ix] = rhs._pmat[ix];
    }
    return *this;
}

inline bool LessThan::operator()(int value) const{
    return value < _val;
}