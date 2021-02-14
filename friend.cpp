#include "all.h"

namespace Friend
{

using namespace std;

class Person
{
    friend class Database;

  public:
    Person(string const &name, int const &age) : mName(name), mAge(age)
    {
    }

    string mName;

  private:
    int mAge;
};

class Database
{
  public:
    Database(vector<Person> const &people) : mPeople(people)
    {
        p("----- constructor start -----");
        Show(people);
        p("----- constructor end -----");
    }

    void Show()
    {
        Show(mPeople);
    }

    void Show(vector<Person> const &people)
    {
        cout << "size " << people.size() << endl;
        for (auto person : people)
        {
            cout << person.mName << ":" << person.mAge << endl;
        }
    }

  private:
    const vector<Person> &mPeople;
};

void run()
{
    Person john("john", 22);
    p(john.mName);
    // p(john.mAge);

    // vector<Person> v{john};
    // Database db(v);

    Database db(vector<Person>{john});
    db.Show();
}

} // namespace Friend

int main(int argc, char const *argv[])
{
    Friend::run();
    return 0;
}
