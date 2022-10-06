#include <iostream>
#include <vector>

class Tree {
    public:
    std::string Data;
    std::vector<Tree*>children_po;
    public:
    Tree() : Data{NULL} {}
    Tree(std::string data) : Data{data} {}
    Tree* AddSub(std::string data);
    void print(int init_indent);
};

Tree* Tree::AddSub(std::string data) {
    Tree* new_tree = new Tree;
    new_tree->Data = data;
    this->children_po.push_back(new_tree);
    return new_tree;
}

void Tree::print(int init_indent) {
    if(this != NULL) {
        for(int i{} ; i < init_indent ; i++) { std::cout<<" "; }
        std::cout << this -> Data << std::endl;
                        
        for(int i{} ; i < this -> children_po.size() ; ++i) {
            static std::vector<int>path;
            path.push_back(i+1);
            for(int i{} ; i < init_indent+2 ; i++) {std::cout<<"  ";}
            for(auto it:path) { std::cout<<it<<"."; }
            this -> children_po.at(i) -> print(init_indent+1);
            if(children_po.size() != 0) { path.erase(path.end()-1); }
            else{ path.clear(); }
        }
    }    
}

int main() {
    Tree* root = new Tree("tree name");
    Tree* galaz1 = root -> AddSub("galaz 1");
    Tree* galaz2 = root -> AddSub("galaz 2");
    Tree* galaz3 = root -> AddSub("galaz 3");
    Tree* galaz1_1 = galaz1 -> AddSub("galaz 1.1");
    Tree* galaz2_1 = galaz2 -> AddSub("galaz 2.1");
    Tree* galaz2_2 = galaz2 -> AddSub("galaz 2.2");
    Tree* galaz2_1_1 = galaz2_1 -> AddSub("galaz 2.1.1");
    Tree* galaz2_1_2 = galaz2_1 -> AddSub("galaz 2.1.2");
    root -> print(0);
 
}