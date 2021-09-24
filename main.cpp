#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;

int main(){

int ancho_ventana=1080,alto_ventana=720;

int x_coord=ancho_ventana/2;

int y_coord=alto_ventana/2;

RenderWindow ventana(VideoMode(ancho_ventana,alto_ventana), "TrabajoPractico");

RectangleShape rect(Vector2f(80,50));

rect.setPosition(x_coord,y_coord);

rect.setFillColor(Color::Magenta);

CircleShape pup(80, 60);

pup.setFillColor(Color::Cyan);

while (ventana.isOpen())
    {
        Event evento;

        while(ventana.pollEvent(evento))
            {
                if(evento.type==Event::Closed)
                    ventana.close();
            }

          if ((Keyboard::isKeyPressed(Keyboard::Right)) && (x_coord < ancho_ventana))
              x_coord  += 1;
          if ((Keyboard::isKeyPressed(Keyboard::Left)) && (x_coord > 0))
              x_coord  -= 1;
          if ((Keyboard::isKeyPressed(Keyboard::Up)) && (y_coord > 0))
             y_coord  -= 1;
          if ((Keyboard::isKeyPressed(Keyboard::Down)) && (y_coord < alto_ventana))
             y_coord  += 1;


          FloatRect rectu=rect.getGlobalBounds();
          FloatRect pip=pup.getGlobalBounds();

          if(rectu.intersects(pip))
            {
                pup.setFillColor(Color::White);
            }
            else
            {
                pup.setFillColor(Color::Cyan);
            }

        ventana.clear(Color::Blue);

        rect.setPosition(x_coord,y_coord);

        ventana.draw(rect);

        ventana.draw(pup);

        ventana.display();
    }

return 0;
}


