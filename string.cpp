#include "all.h"

using namespace std;

namespace String
{

class Foo
{
  public:
    Foo(const string &msg) : mMsg(msg) {}
    const string mMsg;
};

void run1()
{
    // string s1 = "abc";
    // cout << s1 + " def" << endl;

    // Foo("a");
    // Foo(s1 + "a");
    // // Foo("a" + "a"); NG
    // Foo(string("a") + "a");
    // Foo("a" + string("a"));

    string s1 = "a";
    printf("%p\n", s1.data());

    printf("same string but different variable\n");
    string s2 = "a";
    printf("%p\n", s2.data());

    printf("copy\n");
    string s3 = s1;
    printf("%p\n", s3.data());

    printf("reference\n");
    string &s4 = s1;
    printf("%p\n", s4.data());
}

void printStrVec(const vector<string> &v)
{
    for (auto &s : v) printf("%p\n", s.data());
}

void run2()
{
    vector<string> v{"a", "b"};
    printStrVec(v);

    vector<string> &v2 = v;
    printStrVec(v2);

    vector<string> v3 = move(v);
    printStrVec(v3);
}

void genStringVector(int count)
{
    vector<string> v;
    for (size_t i = 0; i < count; i++) { v.push_back(to_string(i)); }
}

void printp(string s)
{
    printf("%p\n", s.c_str());
}

void printp(shared_ptr<string> sp)
{
    printf("%p\n", sp->c_str());
}

void printp(unique_ptr<string> sp)
{
    printf("%p\n", sp->c_str());
}

void run3()
{
    // while (true)
    // {
    //     genStringVector(100000);
    //     sleep(1);
    //     cout << "-----" << endl;
    // }

    // cout << sizeof(string) << endl;
    // cout << sizeof(string *) << endl;

    // string s =
    //   "adk;jgn;aisgn;iodrng'okrng'kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'"
    //   "sdflkhsd'flkn'sdlfkns'dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'"
    //   "sodihn'sdoifhn'sdihn'sdfioh'dsfijs;dfnh'sdfikh'sodifadk;jgn;aisgn;"
    //   "iodrng'okrng'kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'sdflkhsd'flkn'"
    //   "sdlfkns'dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'sodihn'sdoifhn'"
    //   "sdihn'sdfioh'dsfijs;dfnh'sdfikh'sodifadk;jgn;aisgn;iodrng'okrng'"
    //   "kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'sdflkhsd'flkn'sdlfkns'"
    //   "dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'sodihn'sdoifhn'sdihn'"
    //   "sdfioh'dsfijs;dfnh'sdfikh'sodifadk;jgn;aisgn;iodrng'okrng'"
    //   "kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'sdflkhsd'flkn'sdlfkns'"
    //   "dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'sodihn'sdoifhn'sdihn'"
    //   "sdfioh'dsfijs;dfnh'sdfikh'sodifadk;jgn;aisgn;iodrng'okrng'"
    //   "kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'sdflkhsd'flkn'sdlfkns'"
    //   "dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'sodihn'sdoifhn'sdihn'"
    //   "sdfioh'dsfijs;dfnh'sdfikh'sodifadk;jgn;aisgn;iodrng'okrng'"
    //   "kfgjksdlfkjnbk;sdjfgns;dkfjhn;dsklhndslkhn'sdflkhsd'flkn'sdlfkns'"
    //   "dflkhnsdjhnsdkljhnskldjhns;d'oihns;difnh'sodfnh'sodihn'sdoifhn'sdihn'"
    //   "sdfioh'dsfijs;dfnh'sdfikh'sodif";

    // shared_ptr<string> s = make_shared<string>("aaa");
    // printf("%p\n", s->c_str());
    // printp(s);

    unique_ptr<string> s = make_unique<string>("aaa");
    printf("%p\n", s->c_str());
    printp(move(s));

    printf("%d\n", sizeof(uintptr_t));
    printf("%d\n", sizeof(uint64_t));
}

char *copyStr(const string &s)
{
    int len = std::strlen(s.c_str()) + 1;
    char *mem = (char *)malloc(sizeof(char) * len);
    std::strncpy(mem, s.c_str(), len);
    return mem;
}

string makeString()
{
    return "aaa";
}

void run4()
{
    // string s = "abc";

    // char *c = copyStr(s);
    // cout << c << endl;

    cout << makeString() << endl;
}

} // namespace String

int main(int argc, char const *argv[])
{
    String::run4();
    return 0;
}
