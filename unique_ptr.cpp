#include "all.h"

using namespace std;

namespace UniquePtr {

class Entry;
class File;
class Directory;

class IVisitor {
 public:
  virtual void visit(Entry &e) = 0;
  virtual void visit(File &e) = 0;
  virtual void visit(Directory &e) = 0;
};

class PaddingVisitor : public IVisitor {
 public:
  virtual void visit(Entry &e) override;
  virtual void visit(File &e) override;
  virtual void visit(Directory &e) override;

  void padding() const {
    for (int i = 0; i < depth_; i++) cout << " ";
  }
  int depth_ = 0;
};

struct Entry {
  void padding(int depth) const {
    for (int i = 0; i < depth; i++) cout << " ";
  }

  virtual void accept(IVisitor &v) = 0;
};

struct File : public Entry {
  File(int id, const string &name) : id(id), name(name) {}

  void accept(IVisitor &v) override { v.visit(*this); }

  int id;
  string name;
};

struct Directory : public Entry {
  Directory(int id, const string &name) : id(id), name(name) {}

  void addEntry(unique_ptr<Entry> &&e) { childs.push_back(move(e)); }

  void accept(IVisitor &v) override { v.visit(*this); }

  int id;
  string name;
  vector<unique_ptr<Entry>> childs;
};

unique_ptr<File> file(int id, string name) {
  return make_unique<File>(id, name);
}

/* PaddingVisitor */
void PaddingVisitor::visit(Entry &e) { e.accept(*this); }

void PaddingVisitor::visit(File &e) {
  padding();
  cout << "file " << e.id << ":" << e.name << endl;
}

void PaddingVisitor::visit(Directory &e) {
  padding();
  cout << "[Directory " << e.id << "]" << endl;
  depth_ += 2;
  for (auto &child : e.childs) child->accept(*this);
  depth_ -= 2;
}

void run() {
  auto root = make_unique<Directory>(0, "/");
  root->addEntry(file(1, "foo"));
  root->addEntry(file(2, "bar"));

  auto d1 = make_unique<Directory>(10, "usr");
  d1->addEntry(file(11, "hoge"));
  d1->addEntry(file(12, "fuga"));

  auto d2 = make_unique<Directory>(20, "opt");
  d2->addEntry(file(21, "fizz"));

  d1->addEntry(move(d2));

  root->addEntry(move(d1));

  root->addEntry(file(3, "bal"));

  PaddingVisitor v;
  v.visit(*root);
}

}  // namespace UniquePtr

int main(int argc, char const *argv[]) {
  UniquePtr::run();
  return 0;
}
