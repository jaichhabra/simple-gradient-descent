#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED


float round(float f,int t=3)
{
    int v = pow(10,t);
    float value = (int)(f * v + .5);
    return (float)value / v;
}


template <class T>
std::vector<float> minmaxstandard(std::vector<T> v)
{
    if(v.size()==1) throw std::runtime_error("Not a range");

    std::vector<float> v1(v.begin(),v.end());

    std::sort(v.begin(),v.end());

    float min = v.front();
    float max = v.back();


    for(size_t i=0; i<v1.size(); i++)
    {
        v1[i] = (v1[i]-min)/(max-min)*(1-0)+0;
        v1[i] = round(v1[i]);
    }

    return v1;
}

template <class T, class S>
void minmaxprint(std::vector<T> v, std::vector<S> standard)
{
    std::cout << std::fixed << std::setprecision(2);

    if(v.size()!=standard.size()) throw std::runtime_error("Not equal sizes");
    for(size_t i=0;i<v.size();i++)
    {
        std::cout << v[i] << "\t|\t" << standard[i] << "\n";
    }
    std::endl(std::cout);
}

template <class T, class S>
void maxprint(std::vector<T> v, std::vector<S> standard)
{
    if(v.size()!=standard.size()) throw std::runtime_error("Not equal sizes");
    for(size_t i=0;i<v.size();i++)
    {
        std::cout << v[i] << "\t|\t" << standard[i] << "\n";
    }
    std::endl(std::cout);
}


template <class T, class S>
void print(std::vector<T> one, std::vector<S> two, std::vector<T> three, std::vector<T> four)
{
    if(one.size()!=two.size()
        ||
       two.size()!=three.size()
        ||
       three.size()!=four.size()) throw std::runtime_error("Not equal sizes");
    for(size_t i=0;i<one.size();i++)
    {
        std::cout << one[i] << "\t|\t"
                  << two[i] << "\t|\t"
                  << three[i] << "\t|\t"
                  << four[i] << "\n";
    }
    std::endl(std::cout);
}

#endif // MINMAX_H_INCLUDED
