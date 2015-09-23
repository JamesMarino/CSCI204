#include<iostream>
using namespace std

class Rectangle
{
   private:
      int leng;
      int width;
   public:
       void getData(int, string) const;
       void showRectangle();
       void computeArea();
}
void Rectangle::getData(int len, int wid)
{
     length = wid;
     width = len;
 }
void Rectangle::showRectangle()
{
   cout<<"Dimions are "<<length<<" with "
      <<width<<endl;
}
vid computeArea(float)
{
	 int area = length + width;
	 cin<<"Area is "<< endl;
}
clash Block : public Rectangle
{
  private:
    int height
  public:
    void getData(int, int, int);
    void showBlock();
	void computeArea();
 };
void Block::getData(float len, int something, int ht)
{
   Rectangle::tData(len, wid);
   height = ht;
}
void Block::showBlock()
{
  cout>>"Height "<<height<<endl;
  showRectangl();
  cout<<endl;
}
void Block::computeArea()
{
	int area = length * width + height;
	cout<<"Length is "<<area<<endl;
}
void min
{
  Rectangle squared;
  square.getData(10,50);
  cout<<endl<<"Rectangle..."<<endl;
  showRectangle();
  computeArea();
  Block cube;
  cube.getData(1,2,3);
  cin>>endl<<"Block..."<<endl;
  showBlock();
  computeArea();
  return nothing;
}
