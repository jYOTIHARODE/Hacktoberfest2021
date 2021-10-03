#include<bits/stdc++.h>
using namespace std;

class Box
{
  private:
  int l,b,h;
  public:
  /*
  void setData(int l,int b,int h)
  {
      l=l;  //here all l,b,h are considered as setData function's l,b,h;
      b=b;
      h=h;
  }
  */
  void setData(int l,int b,int h)
  {
      this->l=l;
      this->b=b;    //here all l,b,h are considered as this-> l,b,h means this l,b,h are of caller object
      this->h=h;
  }
  void showData()
  {
      cout<<"length = "<<l<<endl<<"breadth = "<<b<<endl<<"height = "<<h<<endl;
  }
};

int main()
{
    Box smallBox;
    smallBox.setData(10,20,30);
    smallBox.showData();
    return 0;
}
