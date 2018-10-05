#pragma once
#include <map>
#include <string>
#include <sstream>
#include <iomanip>

#include "xt_quick_cast.h"
#include "xt_any_value.h"

namespace DS
{
class ParameterParse
{
  private:
    std::map<std::string, int> msi;
    std::map<int, std::string> mis;
    std::map<std::string, std::string> default_value;

  public:
    ParameterParse(int argc, char **argv)
    {
        Init(argc, argv);
    }
    ParameterParse() {}

    template <class T>
    void RegValue(const std::string &key, const T &t)
    {
        default_value[key] = QCast<std::string>(t);
    }

    void Init(int argc, char **argv)
    {
        for (int index = 1; index < argc; index++)
        {
            auto key = std::string(argv[index]);
            msi[key] = index;
            mis[index] = key;
        }
    }

    template <class T>
    T GetValue(const std::string &key)
    {
        T result;

        auto msi_it = msi.find(key);
        if (msi_it != msi.end())
        {
            auto mis_it = mis.find(msi_it->second + 1);
            if (mis_it != mis.end())
            {
                result = QCast<T>(mis_it->second);
            }
            else
            {
                auto default_value_it = default_value.find(key);
                if (default_value_it != default_value.end())
                {
                    result = QCast<T>(default_value_it->second);
                }
                else
                {
                }
            }
        }
        else
        {
            auto default_value_it = default_value.find(key);
            if (default_value_it != default_value.end())
            {
                result = QCast<T>(default_value_it->second);
            }
            else
            {
            }
        }
        return result;
    }
    XT::AnyValue GetAnyValue(const std::string &key)
    {
        return this->GetValue<std::string>(key);
    }
    void ShowDefault(std::ostream &os)
    {
        os << FixedWidth("key", 40);
        os << FixedWidth("default value", 40) << "\n";
        for (auto &&data : default_value)
        {
            os << FixedWidth(data.first, 40);
            os << FixedWidth(data.second, 40) << "\n";
        }
    }
};
extern ParameterParse global_config;
} // namespace DS
