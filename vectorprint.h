#ifndef VECTORPRINT_H_INCLUDED
#define VECTORPRINT_H_INCLUDED

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
    os << "[ ";
    for(size_t i=0; i< v.size(); i++)
        os << v.at(i) << " ";
    os << " ]\n";
    return os;
}

#endif // VECTORPRINT_H_INCLUDED
