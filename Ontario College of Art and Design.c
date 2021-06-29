#include<windows.h>
#include<gl/glut.h>
#include <stdlib.h>
#include <math.h>

int is_depth;
int i;
int sudut = 0;
#define PI 3.1415926535
bool mouseDown = false;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
void init(void)
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
glEnable(GL_LIGHTING);
glEnable(GL_COLOR_MATERIAL);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST);
is_depth = 1;
glMatrixMode(GL_MODELVIEW);
glPointSize(9.0);
glLineWidth(6.0f);
}

void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_POLYGON);
 for (i=0;i<=360;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  glVertex2f(x,y);
 }
 glEnd();
}
void tampil(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f,1.0f, 0.0f);
glRotatef(xrot, 1.0f, 0.0f, 0.0f);
glRotatef(yrot, 0.0f, 1.0f, 0.0f);
//balok
//belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20,10,-20);//a
    glVertex3f(30,10,-20);//b
    glVertex3f(30,-20,-20);//c
    glVertex3f(-20,-20,-20);//d
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20,-20,20);//e
    glVertex3f(-20,10,20);//f
    glVertex3f(30,10,20);//g
    glVertex3f(30,-20,20);//h
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(30,10,-20);//b
    glVertex3f(30,-20,-20);//c
    glVertex3f(30,-20,20);//h
    glVertex3f(30,10,20);//g
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20,10,-20);//a
    glVertex3f(-20,-20,-20);//d
    glVertex3f(-20,-20,20);//e
    glVertex3f(-20,10,20);//f
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20,10,-20);//a
    glVertex3f(30,10,-20);//b
    glVertex3f(30,10,20);//g
    glVertex3f(-20,10,20);//f
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(30,-20,-20);//c
    glVertex3f(-20,-20,-20);//d
    glVertex3f(-20,-20,20);//e
    glVertex3f(30,-20,20);//h
    glEnd();
    glPopMatrix();

//kubus sedang
    //belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(30, 20, -5);//n
    glVertex3f(20, 20, -5);//m
    glVertex3f(20, 10, -5);//l
    glVertex3f(30, 10, -5);//i
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(20, 20, 5);//p
    glVertex3f(30, 20, 5);//o
    glVertex3f(30, 10, 5);//j
    glVertex3f(20, 10, 5);//k
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(30, 20, -5);//n
    glVertex3f(30, 10, -5);//i
    glVertex3f(30, 10, 5);//j
    glVertex3f(30, 20, 5);//o
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(20, 20, -5);//m
    glVertex3f(20, 20, 5);//p
    glVertex3f(20, 10, 5);//k
    glVertex3f(20, 10, -5);//l
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(20, 20, -5);//m
    glVertex3f(30, 20, -5);//n
    glVertex3f(30, 20, 5);//o
    glVertex3f(20, 20, 5);//p
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(30, 10, -5);//i
    glVertex3f(20, 10, -5);//l
    glVertex3f(20, 10, 5);//k
    glVertex3f(30, 10, 5);//j
    glEnd();
    glPopMatrix();

//kubus kecil
    //belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(15, 15, -5);//n
    glVertex3f(5, 15, -5);//m
    glVertex3f(5, 10, -5);//l
    glVertex3f(15, 10, -5);//i
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(5, 15, 5);//p
    glVertex3f(15, 15, 5);//o
    glVertex3f(15, 10, 5);//j
    glVertex3f(5, 10, 5);//k
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(15, 15, -5);//n
    glVertex3f(15, 10, -5);//i
    glVertex3f(15, 10, 5);//j
    glVertex3f(15, 15, 5);//o
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(5, 15, -5);//m
    glVertex3f(5, 15, 5);//p
    glVertex3f(5, 10, 5);//k
    glVertex3f(5, 10, -5);//l
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(5, 15, -5);//m
    glVertex3f(15, 15, -5);//n
    glVertex3f(15, 15, 5);//o
    glVertex3f(5, 15, 5);//p
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(15, 10, -5);//i
    glVertex3f(5, 10, -5);//l
    glVertex3f(5, 10, 5);//k
    glVertex3f(15, 10, 5);//j
    glEnd();
    glPopMatrix();

//balok  berdiri
    //belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(0, 10, -5);//t
    glVertex3f(-10, 10, -5);//q
    glVertex3f(-10, 60, -5);//u
    glVertex3f(0, 60, -5);//z
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(0, 10, 5);//s
    glVertex3f(-10, 10, 5);//r
    glVertex3f(-10, 60, 5);//v
    glVertex3f(0, 60, 5);//w
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(0, 10, 5);//s
    glVertex3f(0, 10, -5);//t
    glVertex3f(0, 60, -5);//z
    glVertex3f(0, 60, 5);//w
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-10, 10, -5);//q
    glVertex3f(-10, 10, 5);//r
    glVertex3f(-10, 60, 5);//v
    glVertex3f(-10, 60, -5);//u
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-10, 60, -5);//u
    glVertex3f(-10, 60, 5);//v
    glVertex3f(0, 60, 5);//w
    glVertex3f(0, 60, -5);//z
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-10, 10, -5);//q
    glVertex3f(-10, 10, 5);//r
    glVertex3f(0, 10, 5);//s
    glVertex3f(0, 10, -5);//t
    glEnd();
    glPopMatrix();

//balok miring
//belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(60, 30, -5);//b1
    glVertex3f(45, 30, -5);//c1
    glVertex3f(30, 20, -5);//n
    glVertex3f(30, 10, -5);//i
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(60, 30, 5);//a1
    glVertex3f(45, 30, 5);//d1
    glVertex3f(30, 20, 5);//o
    glVertex3f(30, 10, 5);//j
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(60, 30, 5);//a1
    glVertex3f(60, 30, -5);//b1
    glVertex3f(45, 30, -5);//c1
    glVertex3f(45, 30, 5);//d1
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(30, 20, -5);//n
    glVertex3f(30, 10, -5);//i
    glVertex3f(30, 10, 5);//j
    glVertex3f(30, 20, 5);//o
    glEnd();
//atas
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(45, 30, -5);//c1
    glVertex3f(45, 30, 5);//d1
    glVertex3f(30, 20, 5);//o
    glVertex3f(30, 20, -5);//n
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex3f(60, 30, 5);//a1
    glVertex3f(60, 30, -5);//b1
    glVertex3f(30, 10, -5);//i
    glVertex3f(30, 10, 5);//j
    glEnd();
    glPopMatrix();

//trapezium
//belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 0, -20);//l1
    glVertex3f(-20, 10, 0);//h1
    glVertex3f(-50, 10, 0);//g1
    glVertex3f(-50, 0, -20);//n1
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 10, 0);//h1
    glVertex3f(-50, 10, 0);//g1
    glVertex3f(-50, 0, 20);//m1
    glVertex3f(-20, 0, 20);//k1
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 0, 20);//k1
    glVertex3f(-20, 0, -20);//l1
    glVertex3f(-20, 10, 0);//h1
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-50, 0, 20);//m1
    glVertex3f(-50, 0, -20);//n1
    glVertex3f(-50, 10, 0);//g1
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 0, -20);//l1
    glVertex3f(-20, 0, 20);//k1
    glVertex3f(-50, 0, 20);//m1
    glVertex3f(-50, 0, -20);//n1
    glEnd();
    glPopMatrix();

//balok bawah 2
    //belakang
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20, 0, -20);//l1
    glVertex3f(-50, 0, -20);//n1
    glVertex3f(-50, -20, -20);//j1
    glVertex3f(-20, -20, -20);//d
    glEnd();
//depan
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20, -20, 20);//e
    glVertex3f(-50, -20, 20);//i1
    glVertex3f(-50, 0, 20);//m1
    glVertex3f(-20, 0, 20);//k1
    glEnd();
//kanan
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-20, 0, 20);//k1
    glVertex3f(-20, 0, -20);//l1
    glVertex3f(-20, -20, -20);//d
    glVertex3f(-20, -20, 20);//e
    glEnd();
//kiri
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -20, 20);//i1
    glVertex3f(-50, -20, -20);//j1
    glVertex3f(-50, 0, -20);//n1
    glVertex3f(-50, 0, 20);//m1
    glEnd();
//bawah
    glBegin(GL_QUADS);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -20, 20);//i1
    glVertex3f(-50, -20, -20);//j1
    glVertex3f(-20, -20, -20);//d
    glVertex3f(-20, -20, 20);//e
    glEnd();
    glPopMatrix();

//segitiga
//depan
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex3f(-35, 10, 20);//q1
    glVertex3f(-25, 0, 20);//p1
    glVertex3f(-45, 0, 20);//o1
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex3f(-35, 10, 20);//q1
    glVertex3f(-25, 0, 20);//p1
    glVertex3f(-35, 10, 0);//e1
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(0, 0.5, 0);
    glVertex3f(-35, 10, 20);//q1
    glVertex3f(-45, 0, 20);//o1
    glVertex3f(-35, 10, 0);//e1
    glEnd();
    glPopMatrix();

//balok kecil
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -10, -5);//t1
    glVertex3f(-60, -10, -5);//a2
    glVertex3f(-60, -20, -5);//z1
    glVertex3f(-50, -20, -5);//s1
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -10, 5);//u1
    glVertex3f(-60, -10, 5);//w1
    glVertex3f(-60, -20, 5);//v1
    glVertex3f(-50, -20, 5);//r1
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-60, -10, -5);//a2
    glVertex3f(-60, -10, 5);//w1
    glVertex3f(-60, -20, 5);//v1
    glVertex3f(-60, -20, -5);//z1
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -10, -5);//t1
    glVertex3f(-60, -10, -5);//a2
    glVertex3f(-60, -10, 5);//w1
     glVertex3f(-50, -10, 5);//u1
    glEnd();
//bawah
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5, 0);
    glVertex3f(-50, -20, -5);//s1
    glVertex3f(-50, -20, 5);//r1
    glVertex3f(-60, -20, 5);//v1
    glVertex3f(-60, -20, -5);//z1
    glEnd();
    glPopMatrix();
//pintu
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 0);
    glVertex3f(-40,-5,20);//b2
    glVertex3f(-30,-5,20);//c2
    glVertex3f(-30,-20,20);//d2
    glVertex3f(-40,-20,20);//e2
    glEnd();
    glPopMatrix();

//balok atas
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(60, 50, -30);//m2
    glVertex3f(60, 30, -30);//k2
    glVertex3f(-20, 30, -30);//f2
    glVertex3f(-20, 50, -30);//i2
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(60, 30, 10);//j2
    glVertex3f(60, 50, 10);//l2
    glVertex3f(-20, 50, 10);//h2
    glVertex3f(-20, 30, 10);//g2
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(60, 50, 10);//l2
    glVertex3f(60, 50, -30);//m2
    glVertex3f(60, 30, -30);//k2
    glVertex3f(60, 30, 10);//j2
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(-20, 30, -30);//f2
    glVertex3f(-20, 30, 10);//g2
    glVertex3f(-20, 50, 10);//h2
    glVertex3f(-20, 50, -30);//i2
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(-20, 50, 10);//h2
    glVertex3f(-20, 50, -30);//i2
    glVertex3f(60, 50, -30);//m2
    glVertex3f(60, 50, 10);//l2
    glEnd();
//bawah
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(60, 30, -30);//k2
    glVertex3f(60, 30, 10);//j2
    glVertex3f(-20, 30, 10);//g2
    glVertex3f(-20, 30, -30);//f2
    glEnd();
    glPopMatrix();


//tiang
    glPushMatrix();
    glBegin(GL_LINES);
    glColor3f(1, 1, 0);
    glVertex3f(50, -20, 0);//r2
    glVertex3f(45, 30, -20);//n2
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(50, -20, -40);//s2
    glVertex3f(45, 30, -20);//n2
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex3f(10, 30, -20);//o2
    glVertex3f(10, 10, 0);//p2
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1, 1, 0);
    glVertex3f(10, 30, -20);//o2
    glVertex3f(10, -20, -40);//q2
    glEnd();
    glPopMatrix();

//balok tengah kecil
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-15, 20, -3);//c3
    glVertex3f(-20, 20, -3);//b3
    glVertex3f(-20, 10, -3);//w2
    glVertex3f(-15, 10, -3);//u2
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 20, 3);//a3
    glVertex3f(-15, 20, 3);//z2
    glVertex3f(-15, 10, 3);//t2
    glVertex3f(-20, 10, 3);//v2
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-15, 20, 3);//z2
    glVertex3f(-15, 10, 3);//t2
    glVertex3f(-15, 10, -3);//u2
    glVertex3f(-15, 20, -3);//c3
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 20, 3);//a3
    glVertex3f(-20, 20, -3);//b3
    glVertex3f(-20, 10, -3);//w2
    glVertex3f(-20, 10, 3);//v2
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-20, 20, 3);//a3
    glVertex3f(-15, 20, 3);//z2
    glVertex3f(-15, 20, -3);//c3
    glVertex3f(-20, 20, -3);//b3
    glEnd();
    glPopMatrix();
//balok atas kecil kiri
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(1, 58, -30);//i3
    glVertex3f(1, 50, -30);//e3
    glVertex3f(-20, 50, -30);//l2
    glVertex3f(-20, 55, -30);//g3
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(1, 58, -12);//j3
    glVertex3f(1, 50, -12);//f3
    glVertex3f(-20, 50, -12);//d3
    glVertex3f(-20, 55, -12);//h3
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(1, 58, -30);//i3
    glVertex3f(1, 50, -30);//e3
    glVertex3f(1, 50, -12);//f3
    glVertex3f(1, 58, -12);//j3
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(-20, 55, -12);//h3
    glVertex3f(-20, 55, -30);//g3
    glVertex3f(-20, 50, -30);//l2
    glVertex3f(-20, 50, -12);//d3
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(1, 58, -30);//i3
    glVertex3f(1, 58, -12);//j3
    glVertex3f(-20, 55, -12);//h3
    glVertex3f(-20, 55, -30);//g3
    glEnd();
    glPopMatrix();

//balok atas kecil tengah
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(31, 55, -30);//r3
    glVertex3f(11, 58, -30);//o3
    glVertex3f(11, 50, -30);//l3
    glVertex3f(31, 50, -30);//n3
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(11, 58, -12);//p3
    glVertex3f(31, 55, -12);//q3
    glVertex3f(31, 50, -12);//m3
    glVertex3f(11, 50, -12);//k3
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(31, 50, -12);//m3
    glVertex3f(31, 55, -12);//q3
    glVertex3f(31, 55, -30);//r3
    glVertex3f(31, 50, -30);//n3
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(11, 58, -30);//o3
    glVertex3f(11, 58, -12);//p3
    glVertex3f(11, 50, -12);//k3
    glVertex3f(11, 50, -30);//l3
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(11, 58, -30);//o3
    glVertex3f(11, 58, -12);//p3
    glVertex3f(31, 55, -12);//q3
    glVertex3f(31, 55, -30);//r3
    glEnd();
    glPopMatrix();

//balok atas kecil kanan
//belakang
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(60, 58, -30);//z3
    glVertex3f(41, 55, -30);//w3
    glVertex3f(41, 50, -30);//t3
    glVertex3f(60, 50, -30);//m2
    glEnd();
//depan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(60, 58, -12);//a4
    glVertex3f(60, 50, -12);//u3
    glVertex3f(41, 50, -12);//s3
    glVertex3f(41, 55, -12);//v3
    glEnd();
//kanan
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(60, 58, -12);//a4
    glVertex3f(60, 58, -30);//z3
    glVertex3f(60, 50, -30);//m2
    glVertex3f(60, 50, -12);//u3
    glEnd();
//kiri
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(41, 55, -30);//w3
    glVertex3f(41, 55, -12);//v3
    glVertex3f(41, 50, -12);//s3
    glVertex3f(41, 50, -30);//t3
    glEnd();
//atas
    glBegin(GL_POLYGON);
    glColor3f(1, 0.5,0 );
    glVertex3f(60, 58, -12);//a4
    glVertex3f(60, 58, -30);//z3
    glVertex3f(41, 55, -30);//w3
    glVertex3f(41, 55, -12);//v3
    glEnd();
    glPopMatrix();

//lingkaran jam
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-35, 5, 20.1);
    lingkaran(3,100,0,0);
    glPopMatrix();

//polkadot depan
//polkadot1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-15, 45, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-10, 35, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot3
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(0, 42, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot4
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(17, 46, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot5
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(25, 38, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot6
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(10, 36, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot7
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(35, 45, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot8
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(40, 35, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot9
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(55, 40, 10.1);
    lingkaran(1,100,0,0);
    glPopMatrix();

//polkadot belakang
//polkadot1
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-15, 45, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot2
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-10, 35, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot3
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(0, 42, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot4
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(17, 46, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot5
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(25, 38, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot6
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(10, 36, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot7
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(35, 45, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot8
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(40, 35, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
//polkadot9
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(55, 40, -30.1);
    lingkaran(1,100,0,0);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'i':
    case 'I':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'l':
    case 'L':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'k':
    case 'K':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'j':
    case 'J':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'w':
    case 'W':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case 's':
    case 'S':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case 'a':
    case 'A':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case 'd':
    case 'D':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case 'q':
    case 'Q':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case 'e':
    case 'E':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;

    }
    tampil();
}
void mouse(int button, int state, int x, int y)

{
if(button == GLUT_LEFT_BUTTON && state
== GLUT_DOWN)
{
mouseDown = true;
xdiff = x - yrot;
ydiff = -y - xrot;
}
else
mouseDown = false;
}

void mouseMotion(int x, int y)
{
if (mouseDown)
{
xrot = x - xdiff;
yrot = y + ydiff;
glLoadIdentity();
glutPostRedisplay();
}
}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Ontario College of Art and Design");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);

    glutMainLoop();
    return 0;
}

