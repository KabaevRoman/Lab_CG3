#include <glut.h>
#include <conio.h>
#include <iostream> 

double cubematrix[8][4] = { {0,1,0,1}, {0,0,0,1}, {0,1,1,1},{0,0,1,1},{1,1,0,1},{1,0,0,1},{1,1,1,1},{1,0,1,1} };//матрица вершин куба
int edges[12][2] = { {0,1},{0,2},{0,4},{1,3},{1,5},{2,3},{2,6},{3,7},{5,4},{5,7},{4,6},{6,7} };//рёбра между вершинами описанными в матрице
double matrixxx[4][4] = { {1,0,0,0}, {0,1,0,0}, {0,0,0,0},{0,0,0,1} };
void multiplymatrix(double result[8][4], double A[8][4], double B[4][4])//функция для перемножения матриц
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result[i][j] = 0;
            for (int k = 0; k < 4; ++k)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void axis()
{
    double axismatrix[6][3] = { {-1000, 0, 0},{1000, 0, 0},{0, -1000, 0},{0, 1000, 0},{0, 0, -1000},{0, 0, 1000} };//матрица осей
    glBegin(GL_LINES);
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (i == 0)
        {
            r = 1;
        }
        else if (i == 2)
        {
            r = 0;
            g = 1;
        }
        else if (i == 4)
        {
            g = 0;
            b = 1;
        }
        glColor3f(r, g, b);
        glVertex3dv(axismatrix[i]);//связь образуется между двумя точками объявленными последовательно
    }
    glEnd();//закрываем бегин
}

void cubeIsometric()
{
    int camera[3] = { 2, 3, 10 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);//постановка камеры
    axis();//отрисовка осей

    GLdouble resultmatrix[8][4];
    double isometricmatrix[4][4] = { {0.707107, 0.408248, -0.577353,0},{0, 0.816497, 0.577345,0},{0.707107, -0.408248, 0.577353,0},{0,0,0,1} }; //матрица изометрического вида куба по второй лекции
    multiplymatrix(resultmatrix,cubematrix,isometricmatrix);//умножение матриц
    //multiplymatrix(resultmatrix1,resultmatrix,matrixxx);
    glBegin(GL_LINES);//
        glColor3f(0, 0, 0);
        for (int i = 0; i < 12; ++i)
        {   
            glVertex3dv(resultmatrix[edges[i][0]]);// эта функция получает на вход массив из 3-х элементов и ставит точку
            glVertex3dv(resultmatrix[edges[i][1]]);//эта ставит вторую. Индексом является массив связи точек
        }
    glEnd();
    glutSwapBuffers();
}

void cubeDymetric()
{
    int camera[3] = { 2, 3, 10 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);
    axis();

    GLdouble resultmatrix[8][4];
    double dymetricmatrix[4][4] = { {0.92582, 0.133631, -0.353553,0},{0, 0.935414, 0.353553,0},{0.377964, -0.327329, 0.866025,0},{0,0,0,1 } };//матрица диаметрического вида по второй лекции
    multiplymatrix(resultmatrix, cubematrix, dymetricmatrix);//умножение матриц
    glBegin(GL_LINES);//
    glColor3f(0, 0, 0);
    for (int i = 0; i < 12; ++i)
    {
        glVertex3dv(resultmatrix[edges[i][0]]);
        glVertex3dv(resultmatrix[edges[i][1]]);
    }
    glEnd();

    glutSwapBuffers();
}

void cubeIsometric2d()
{
    int camera[3] = { 0, 0, 7 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);//постановка камеры
    axis();//отрисовка осей

    GLdouble resultmatrix[8][4];
    double isometricmatrix[4][4] = { {0.707107, 0.408248, -0.577353,0},{0, 0.816497, 0.577345,0},{0.707107, -0.408248, 0.577353,0},{0,0,0,1} }; //матрица изометрического вида куба по второй лекции
    multiplymatrix(resultmatrix, cubematrix, isometricmatrix);//умножение матриц
    glBegin(GL_LINES);//
    glColor3f(0, 0, 0);
    for (int i = 0; i < 12; ++i)
    {
        glVertex2dv(resultmatrix[edges[i][0]]);// эта функция получает на вход массив из 3-х элементов и ставит точку
        glVertex2dv(resultmatrix[edges[i][1]]);//эта ставит вторую. Индексом является массив связи точек
    }
    glEnd();
    glutSwapBuffers();
}

void cubeDymetric2d()
{
    int camera[3] = { 0, 0, 7 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);
    axis();

    GLdouble resultmatrix[8][4];
    double dymetricmatrix[4][4] = { {0.92582, 0.133631, -0.353553,0},{0, 0.935414, 0.353553,0},{0.377964, -0.327329, 0.866025,0},{0,0,0,1 } };//матрица диаметрического вида по второй лекции
    multiplymatrix(resultmatrix, cubematrix, dymetricmatrix);//умножение матриц
    glBegin(GL_LINES);//
    glColor3f(0, 0, 0);
    for (int i = 0; i < 12; ++i)
    {
        glVertex2dv(resultmatrix[edges[i][0]]);
        glVertex2dv(resultmatrix[edges[i][1]]);
    }
    glEnd();

    glutSwapBuffers();
}

void cubeDefault2d()
{
    int camera[3] = { 0, 0, 7 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);
    axis();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 12; ++i)
    {
        glVertex2dv(cubematrix[edges[i][0]]);
        glVertex2dv(cubematrix[edges[i][1]]);
    }
    glEnd();
    glutSwapBuffers();
}

void cubeDefault()
{
    int camera[3] = { 2, 3, 10 };
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);
    axis();
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    for (int i = 0; i < 12; ++i)
    {
        glVertex3dv(cubematrix[edges[i][0]]);
        glVertex3dv(cubematrix[edges[i][1]]);
    }
    glEnd();
    glutSwapBuffers();
}

void View(void temp());

void keyDown(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    case 49:
        View(cubeIsometric);
        break;
    case 50:
        View(cubeDymetric);
        break;
    case 51:
        View(cubeDefault);
        break;
    case 52:
        View(cubeDefault2d);
        break;
    case 53:
        View(cubeIsometric2d);
        break;
    case 54:
        View(cubeDymetric2d);
        break;
    default:
        break;
    }
}

void View(void temp())//функция для создания окна, вызова отрисовки,
{
    //Установить начальные характеристики окна
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);//размер окна
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Построение изометрической и диметрической проекций");//открыть окно с заголовком
    glutDisplayFunc(temp);
    glutIdleFunc(temp);
    glutKeyboardFunc(keyDown);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    glMatrixMode(GL_PROJECTION); 
    gluPerspective(25.0, float(640) / float(480), 0.0, 1.0);//первый параметр field of view
    glMatrixMode(GL_MODELVIEW);
    
    glutMainLoop();
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    std::cout << "1-для изометрической проекции в трёх измерениях\n"
        "2-для диметрической проекции в трёх измерениях\n"
        "3-для стандартного вида в трёх измерениях\n"
        "4-отображения куба в двумерной плоскости\n"
        "5-для построения изометрической проекции в двух измерениях\n"
        "6-для построения диметрической проекции в двух измерениях\n";
    View(cubeDefault);
    return 0;
}
