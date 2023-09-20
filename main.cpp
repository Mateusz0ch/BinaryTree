#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
    public:
    Node(int d):data(d){};
    int data;
    Node*left;
    Node*right;
    void newLeft(int d){
        left = new Node{d};
        std::cout<<"Created left"<<std::endl;
    };
    void newRight(int d){
        right = new Node{d};
        std::cout<<"Created right"<<std::endl;
    }
    Node*getLeft(){
        return left;
    }
    Node*getRight(){
        return right;
    }
    int getData(){
        return data;
    }
};
void addNum(Node*n,int num){
  if(n->getData()>num){
    if(n->getLeft()==NULL){
        n->newLeft(num);
    }else{
        addNum(n->getLeft(),num);
    }
  }
  if(n->getData()<num){
    if(n->getRight()==NULL){
        n->newRight(num);
    }else{
        addNum(n->getRight(),num);
    }
  }
}
int tab[]{25,10,27,26,87,46,31,55,71,76};
int main(){
    Node*node = new Node{30};
    std::cout<<(node->left==NULL)<<std::endl;
    for(int i=0;i<10;i++){
        addNum(node,tab[i]);
    }
    std::cout<<node->getRight()->getLeft()->getData()<<std::endl;
}
