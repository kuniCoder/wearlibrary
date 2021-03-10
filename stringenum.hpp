#pragma once
#include <map>

namespace wear {
    template < typename typecontent > class wEnum
    {
    public:
        void insert(std::string key, typecontent safeContent)
        {
            _DATA[key] = safeContent;
        }

        typecontent operator[](std::string key) const
        {
            return _DATA[key];
        }
        typecontent& operator[](std::string key)
        {
            return _DATA[key];
        }

    private:
        std::map< std::string, typecontent > _DATA;
    };
} // namespace wear