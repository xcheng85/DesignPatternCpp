#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
const int N = 4;

// Prototype
class Document
{
  public:
    virtual Document *clone() const = 0;
    virtual void store() const = 0;
    virtual ~Document() {}
};

// Concrete prototypes : xmlDoc, plainDoc, spreadsheetDoc

class xmlDoc : public Document
{
  public:
    Document *clone() const { return new xmlDoc; }
    void store() const { cout << "xmlDoc\n"; }
};

class plainDoc : public Document
{
  public:
    Document *clone() const { return new plainDoc; }
    void store() const { cout << "plainDoc\n"; }
};

class spreadsheetDoc : public Document
{
  public:
    Document *clone() const { return new spreadsheetDoc; }
    void store() const { cout << "spreadsheetDoc\n"; }
};

// makeDocument() calls Concrete Portotype's clone() method
// inherited from Prototype
class DocumentManager
{
  public:
    static Document *makeDocument(int choice);
    ~DocumentManager() {}

  private:
    static Document *mDocTypes[N];
};

Document *DocumentManager::mDocTypes[] =
    {
        0, new xmlDoc, new plainDoc, new spreadsheetDoc};

Document *DocumentManager::makeDocument(int choice)
{
    return mDocTypes[choice]->clone();
}

// for_each op ()
struct Destruct
{
    void operator()(Document *a) const
    {
        delete a;
    }
};

// Client
int main()
{
    vector<Document *> docs(N);
    int choice;
    cout << "quit(0), xml(1), plain(2), spreadsheet(3): \n";
    while (true)
    {
        cout << "Type in your choice (0-3)\n";
        cin >> choice;
        if (choice <= 0 || choice >= N)
            break;
        docs[choice] = DocumentManager::makeDocument(choice);
    }

    for (int i = 1; i < docs.size(); ++i)
        if (docs[i])
            docs[i]->store();

    Destruct d;
    // this calls Destruct::operator()
    for_each(docs.begin(), docs.end(), d);

    return 0;
}