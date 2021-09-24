#include <SFML/Graphics.hpp>
#include <fstream>

using namespace sf;

int main(){
//defino ancho y alto de la vetana
int ancho_ventana=1080,alto_ventana=720;
//defino las coordenadas de donde va a aparecer el rectangulo (en el medio de la pantalla por eso "ancho_ventana/2;" Y "y_coord=alto_ventana/2;")
int x_coord=ancho_ventana/2;

int y_coord=alto_ventana/2;
//defino la ventana
RenderWindow ventana(VideoMode(ancho_ventana,alto_ventana), "TrabajoPractico");
//defino el rectángulo movil
RectangleShape rect(Vector2f(80,50));

rect.setPosition(x_coord,y_coord);

rect.setFillColor(Color::Magenta);
//defino el circulo estatico
CircleShape pup(80, 60);
//
pup.setFillColor(Color::Cyan);
//
while (ventana.isOpen())
    {
        Event evento;
        //cierre opcional
        while(ventana.pollEvent(evento))
            {
                if(evento.type==Event::Closed)
                    ventana.close();
            }
          //Asignando las teclas para mover el rectángulo
          if ((Keyboard::isKeyPressed(Keyboard::Right)) && (x_coord < ancho_ventana))
              x_coord  += 1;
          if ((Keyboard::isKeyPressed(Keyboard::Left)) && (x_coord > 0))
              x_coord  -= 1;
          if ((Keyboard::isKeyPressed(Keyboard::Up)) && (y_coord > 0))
             y_coord  -= 1;
          if ((Keyboard::isKeyPressed(Keyboard::Down)) && (y_coord < alto_ventana))
             y_coord  += 1;

          //obtengo los limites del circulo y de el rectángulo
          FloatRect rectu=rect.getGlobalBounds();
          FloatRect pip=pup.getGlobalBounds();
          //el circulo cambia de color solo si el rectángulo lo toca
          if(rectu.intersects(pip))
            {
                pup.setFillColor(Color::White);
            }
            else
            {
                pup.setFillColor(Color::Cyan);
            }
        //limpio ventana
        ventana.clear(Color::Blue);
        //posición actual del rectángulo
        rect.setPosition(x_coord,y_coord);
        //dibujo el rectangulo movil
        ventana.draw(rect);
        //dinujo el circulo
        ventana.draw(pup);
        //muestro la ventana en pantalla
        ventana.display();
    }

return 0;
}

