//JUEGO3.PONG.

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<iostream>

using namespace std;

#include<ocultarcursor.h>
#include<gotoxy.h>
#include<bordes_esquinas.h>
//////////////////////////////////////////////////////////////////////////////////////////////////////
int opcion;
int puntos_A=0, puntos_B=0;
//////////////////////////////////////////////////////////////////////////////////////////////////////
class JUGADOR
{
      int x,y;
      public:
             JUGADOR(int _x, int _y); //constructor.
             void pintar() const;
             void borrar() const;
             void mover_IA(int _x, int _y, int _dx);
             void Y(int _y) {y+=_y;}
             int RY() {return y;}
             int RX() {return x;}
      };//class JUGADOR.
      
      JUGADOR::JUGADOR(int _x, int _y)
      {
                           x=_x; y=_y;
                           }//JUGADOR::JUGADOR.
                           
      void JUGADOR::pintar() const
      {
           gotoxy(x,y-1); printf("%c",219);
           gotoxy(x,y); printf("%c",219);
           gotoxy(x,y+1); printf("%c",219);                   
           }//void JUGADOR::pintar() const.
      
      void JUGADOR::borrar() const
      {
           gotoxy(x,y-1); printf(" ");
           gotoxy(x,y); printf(" ");
           gotoxy(x,y+1); printf(" ");
           }//void JUGADOR::borrar() const.
           
      void JUGADOR::mover_IA(int _x, int _y, int _dx)
      {
	   	   if(_x>65 && _x>0)
	   	   {
	   	   	borrar();
	   	   	if(_y>y && y+1<22) y++;
	   	   	if(_y<y && y-1>3) y--;
	   	   	pintar();
	   	   }//if(_x>65 && >0)}.
  	   }//void JUGADOR::mover_IA(int _x, int _y, int _dx).
//////////////////////////////////////////////////////////////////////////////////////////////////////
class PELOTA
{
      int x,y;
      int dx,dy;
      public:
             PELOTA(int _x, int _y, int _dx, int _dy);
             void pintar() const;
             void borrar() const;
             void mover(JUGADOR A, JUGADOR B);
             void asignar(int _x, int _y);
             int PX() {return x;}
             int PY() {return y;}
             int DX() {return dx;}
             void contador();
      };//CLASS PELOTA.
      
      PELOTA::PELOTA(int _x, int _y, int _dx, int _dy)
      {
                         x=_x; y=_y; dx=_dx; dy=_dy;
                         }//PELOTA::PELOTA
      
      void PELOTA::pintar() const
      {
           gotoxy(x,y); printf("%c",64);
           }//void PELOTA::pintar() const.
           
      void PELOTA::borrar() const
      {
           gotoxy(x,y); printf(" ");
           }//void PELOTA::pintar() const.

      void PELOTA::asignar(int _x, int _y)
      {
      	   x=_x;
      	   y=_y;
      }//voidPELOTA::asignar(int _x, int _y).
      
       void PELOTA::contador()
		   {  		  
			   gotoxy(2,2); cout<<"PUNTOS A = "<<puntos_A;
			   gotoxy(65,2); cout<<"PUNTOS B = "<<puntos_B;  
			   }
      
      void PELOTA::mover(JUGADOR A, JUGADOR B)
      {
           borrar();
           x+=dx; y+=dy;
           pintar();
           if(x+dx==2 || x+dx==77)
           {
          	
                      borrar();
                      asignar(38,14);
                      dx= -dx;
                      }//if(x+dx==2 || x+dx==77).
           if(y+dy==3 || y*dy==22) dy= -dy;
           if(x+dx==A.RX() && y>=A.RY()-2 && y<=A.RY()+2) {dx= -dx;}
           if(x+dx==B.RX() && y>=B.RY()-2 && y<=B.RY()+2) {dx= -dx;}
           if(x==4) puntos_B++;                   //contador
           if(x==75) puntos_A++;                  //contador
           }//void PELOTA::mover().
		   
		  
//////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SetConsoleTitle("JUEGO 3:PONG");
    
    gotoxy(3,0); printf("LAMOS INDUSTRIES %c. COPYRIGHT %c 2014-1015.",169,184);
    gotoxy(70,0); printf("V 1.0.0");
    
    gotoxy(2,2); cout<<"1 JUGADOR"<<endl;
    gotoxy(2,3);cout<<"2 JUGADORES"<<endl;
    gotoxy(2,4);cout<<"ELIJE EL NUMERO DE JUGADORES: ";
    cin>>opcion;
    
    system("cls");
    
    ocultarcursor();
    
    if(opcion==1)
    {
    	gotoxy(2,0); printf("JUGADOR 1: W ARRIBA, S ABAJO");
    	gotoxy(75,0); printf("IA.");
    }//if(opcion==1).
    
    if(opcion==2) 
	{
	 gotoxy(2,0); printf("JUGADOR 1: W ARRIBA  S ABAJO");
	 gotoxy(50,0); printf("JUGADOR 2: O ARRIBA  L ABAJO");
	 }//if(opcion==2).
    
    pintar_borde_x_superior();
    pintar_borde_x_inferior();
    pintar_borde_y_izquierdo();
    pintar_borde_y_derecho();
    pintar_esquina_superior_izquierda();
    pintar_esquina_superior_derecha();
    pintar_esquina_inferior_izquierda();
    pintar_esquina_inferior_derecha();    
	
    gotoxy(3,24); printf("LAMOS INDUSTRIES %c. COPYRIGHT %c 2014-1015.",169,184);
    gotoxy(70,24); printf("V 1.0.0");
    
    JUGADOR A(6,13); A.pintar();
    JUGADOR B(73,13); B.pintar();
    PELOTA P(38,14,1,1);
    
    char tecla;
    int cont=0;
    
    while(1)
    {       
			P.contador();     
            if(kbhit())
            {
             A.borrar(); B.borrar();
             tecla=getch();
             if((tecla=='W' && A.RY()>5)||(tecla=='w' && A.RY()>5)) A.Y(-1); 
             else if((tecla=='S' && A.RY()<21)||(tecla=='s' && A.RY()<21)) A.Y(1);
             
             if(opcion==2)
             {
             if((tecla=='O' && B.RY()>5)||(tecla=='o' && B.RY()>5)) B.Y(-1);
             else if((tecla=='L' && B.RY()<21)||(tecla=='l' && B.RY()<21)) B.Y(1);
        	  }//if(opcion=1).
             A.pintar(); B.pintar();
             }//IF(KBHIT()).
             else if(opcion==1 && !cont)
             {
             	B.mover_IA(P.PX(), P.PY(), P.DX());
             }//if(opcion=2).
             
             if(!cont++) P.mover(A, B);
             if(cont>5) cont=0;
             Sleep(10);
             
    }
    
    getch();
}//int main().
