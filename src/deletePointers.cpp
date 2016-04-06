#ifndef __Assignment_2__DeletePointers__
#define __Assignment_2__DeletePointers__

#include <stdio.h>
#include <iterator>

template <typename Iter>
class DeletePointers
{
public:
    DeletePointers();
    DeletePointers(Iter begin, Iter end);
};

template <typename Iter>
DeletePointers<Iter>::DeletePointers()
{
    
}
template <typename Iter>
DeletePointers<Iter>::DeletePointers(Iter begin, Iter end)
{
    while (begin != end)
    {
        delete *begin;
        begin++;
    }
}
template <typename Iter>
static void Delete_Pointers(Iter begin, Iter end)
{
    while (begin != end)
    {
        delete *begin;
        begin++;
    }
}

#endif /* defined(__Assignment_2__DeletePointers__) */
