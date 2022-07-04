#ifndef cards_exception_h
#define cards_exception_h

#include <exception>

namespace Cards
{

    class CE : public std::exception
    {
        const char *msg = nullptr;
        CE();

    public:
        CE(const char *s)
        noexcept(true) : msg(s) {}
        const char *what() const noexcept(true) { return msg; }
    };

}

#endif
