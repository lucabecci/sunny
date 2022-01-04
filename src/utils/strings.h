#include<cstring>

class strings
{
    public:
        std::string lowercase(std::string str);
        std::string first_word(std::string str);
};

std::string strings::lowercase(std::string str)
{
    std::for_each(str.begin(), str.end(), [](char & c)
    {
        c = ::tolower(c);
    });
    return str;
};

std::string strings::first_word(std::string str)
{
  std::string word = "";
  for(auto x : str)
  {
    if(x == ' ')
    {
      break;
    }
    else
    {
      word += x;
    }
  }
  return word;
}