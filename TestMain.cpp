#include <iostream>
#include <vector>
#include <string>
#include "kun.h"
#include "arena.h"
#include "trainer.h"
using namespace std;

int main(){
  string name1, name2;
  cout<<"name of first kun";
  cin>>name1;
  cout<<"name of second kun";
  cin>>name2;
  Kun* kun1=new Kun(name1);
  Kun* kun2=new Kun(name2);
  kun1->gainExperience(500);
  cout<<kun1->getName()<<"\t"<<kun1->getHP()<<"\t"<<kun1->getAttack()<<"\t"<<
    kun1->getDefense()<<"\t"kin1->getLevel()<<endl;
  
  kun2->gainExperience(600);  
  cout<<kun1->getName()<<"\t"<<kun1->getHP()<<"\t"<<kun1->getAttack()<<"\t"<<
    kun1->getDefense()<<"\t"kin1->getLevel()<<endl;
  
  Kun* baby=kun1+kun2;
  //print kun details
  return 0;
  
}
