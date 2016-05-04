///libraries
#include <iostream> ///cpp library
#include <SFML/Graphics.hpp> ///library that open window
using namespace std;
///Global variables , function , Classes
int main ()
{
///creation window
sf::RenderWindow window(sf::VideoMode(700,800),"RAGE RACE");///let resize your window that will u game apply and choose it's name
window.setFramerateLimit(60);///the game only run smoothly at this frame otherwise game will be too slow or very fast
window.setKeyRepeatEnabled(false);///let u press the key much longer until you released

///variable that keeps the game running
///event  object holding all events
sf::Event event; ///object
///states for button event
bool play =true;
bool apressed = false;
bool areleased = false;
bool space = false;
bool leftclick = false;
bool rightclick = false;
bool leftarrow = false;
bool rightarrow = false;
bool enter = false;
///variables
int nclick = 0 ;// number of clicks
int mousex =0, mousey=0;
////////////////////////////////
int rectxpostion = 0;
// /////////////////////////////
///TEXTURE
sf::Texture g;
sf::Texture r;
if (g.loadFromFile("data/g.png")== -1){return 1;}
if (r.loadFromFile("data/r.png")== -1){return 1;}
///RENDER SHAPES
sf::Clock clock;///time
sf::RectangleShape rectr;//object name rect type rectangle shape
rectr.setSize(sf::Vector2f(150,800));//size of object
rectr.setPosition(550,0);//place of object
//rectr.setFillColor(sf::Color::Green);//color of the object
rectr.setTexture(&g);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
sf::RectangleShape rect;//object name rect type rectangle shape
rect.setSize(sf::Vector2f(400,800));//size of object
rect.setPosition(150,600);//place of object
//rect.setFillColor(sf::Color::Blue);//color of the object
rect.setTexture(&r);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
sf::RectangleShape rectl;//object name rect type rectangle shape
rectl.setSize(sf::Vector2f(150,800));//size of object
rectl.setPosition(0,0);//place of object
//rectl.setFillColor(sf::Color::Green);//color of the object
rectl.setTexture(&g);
/*sf::CircleShape crc;
crc.setRadius(100);
crc.setPosition(356,265);
crc.setFillColor(sf::Color::Red);*/
///GAME LOOP
while (play == (true)) /// program wont stop until play == false
{
///EVENT
/// here we check what button we press on keyboard , mouse , etc
while(window.pollEvent(event))
{
///arrows
if(event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Right){rightarrow = true;}
if(event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Right){rightarrow = false;}
if(event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Left){leftarrow = true;}
if(event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Left){leftarrow = false;}
///A Button
if(event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::A){apressed = true;}
if(event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::A){areleased = true;}
///enter Button///////////////////////////////////////////////////////
//if(event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Return){enter = true;}
if(event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Return){enter = true;}
///space button//////////////////////////////////////////////////////
if(event.type == sf::Event::KeyPressed&&event.key.code== sf::Keyboard::Space){space = true;}
if(event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Space){space = false;}
///mouse buttons/////////////////////////////////////////////////////
if(event.type == sf::Event::MouseButtonPressed&&event.mouseButton.button == sf::Mouse::Left){leftclick = true;}
if(event.type == sf::Event::MouseButtonReleased&&event.mouseButton.button == sf::Mouse::Right){rightclick = true;}
if(event.type == sf::Event::MouseMoved)
{
mousex=event.mouseMove.x ;
mousey=event.mouseMove.y;
}
//if(mousex < 200 ){return 0;}///if mousex less then zero program will shutdown
/// /////////////////////////////////////////////////////////////////////////////////////////////////////
if(event.type == sf::Event::Closed) ///When you press exit button on file.exe the program will closed
{
    play = false;
  }
   }
///LOGIC
if(apressed == true)
{
///print in the console
cout << "the A key has been pressed"<<endl;
apressed = false;
}
if(areleased == true){
    cout << "the A key has been Released"<<endl;
 areleased = false;
}
/// //////arrows logic ////////
//if(leftarrow == true){cout << "the leftarrow key has been pressed"<<endl;leftarrow = false;}
//if(rightarrow == true){cout << "the rightarrow key has been pressed"<<endl;rightarrow= false;}
if(rightarrow == true && leftarrow == true){cout<<"left and right pressed\n";}
/// ///////space logic///////////
if(space == true){/*cout << "space"<<endl;*/}
if(space == false){/*cout << "not space"<<endl;*/}
/// ///////enter logic//////////
if(enter == true)
{ cout<< "enter/Return released"<<endl;enter = false;}
//if(enter == false){/*cout << "not enter"<<endl;*/}
/// ///////mouse logic//////////
if(leftclick == true){
nclick++;
cout<<"left mouse pressed "<<nclick<<endl;
leftclick = false;
//if(mousex < 200){return 0; }
}
if(rightclick == true){
nclick--;
cout<<"right mouse pressed"<<nclick<<endl;
rightclick = false;
}
//cout<<"Mouse x "<<mousex <<" Mouse y " <<mousey<<endl;
 cout<<"\n"<<clock.getElapsedTime().asSeconds();
rectxpostion++;
rect.setPosition(150,rectxpostion);


///RENDERING
window.clear();


window.draw(rect);
window.draw(rectr);
window.draw(rectl);
//window.draw(crc);
window.display();
}


/// clean up and close the window
window.close();
///close program
return 0;
}
