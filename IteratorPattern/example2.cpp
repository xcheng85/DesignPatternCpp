#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Container
{

  public:
    Container(istream &s) : m_stream(s), m_nIndex(0)
    {
        FillData();
    }

    class iterator
    {
        const Container &sln;
        size_t m_Index;

      public:
        iterator(const Container &s) : sln(s), m_Index(0)
        {
        }
        iterator(const Container &s, size_t nSize) : sln(s), m_Index(nSize)
        {
        }
        iterator(const iterator &other) : sln(other.sln), m_Index(other.m_Index)
        {
        }
        void operator++()
        {
            m_Index++;
        }

        void operator--()
        {
            m_Index++;
        }

        bool operator!=(const iterator &other)
        {
            return m_Index != other.m_Index;
        }

        int operator*()
        {
            return sln.m_Elements[m_Index];
        }
    };

    iterator begin()
    {
        iterator it(*this);
        return it;
    }

    iterator end()
    {
        iterator it(*this, m_Elements.size());
        return it;
    }

  private:
    void FillData()
    {
        std::ifstream &in_stream = dynamic_cast<ifstream &>(m_stream);
        string line;
        vector<string> list;
        while (std::getline(in_stream, line))
        {
            //in_stream >> line;
            list.push_back(line);
            TrimLeadingSpace(line);
            bool bValid = IsValidInteger(line);
            if (bValid)
                m_Elements.push_back(atoi(line.c_str()));
        }
        in_stream.close();
    }

    void TrimLeadingSpace(string &sNum)
    {
        const char *ws = " \t\n\r\f\v";
        sNum.erase(0, sNum.find_first_not_of(ws));
    }

    bool IsValidInteger(const string &sNum)
    {
        const int MAX_LIMIT = 1000000000;
        const int MIN_LIMIT = -1000000000;
        bool bflag = false;
        auto startIt = sNum.begin();
        if (sNum[0] == '+' || (sNum[0] == '-'))
            startIt = sNum.begin() + 1;

        for (auto it = startIt; it != sNum.end(); ++it)
        {
            bflag = true;
            char nChar = *it;
            if (!isdigit(nChar))
                return false;
        }

        int nNum = atoi(sNum.c_str());
        bool bMaxCheck = nNum < MAX_LIMIT && nNum > MIN_LIMIT; //limit check

        return (bMaxCheck && bflag);
    }

    istream &m_stream;
    int m_nIndex;
    vector<int> m_Elements;
};

int main()
{
    std::ifstream file("Test.txt");
    Container sobj(file);

    for (Container::iterator it = sobj.begin(); it != sobj.end(); ++it)
    {
        int x = *it;
        cout << x << endl;
    }

    return 0;
}