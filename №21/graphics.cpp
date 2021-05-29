#include "graphics.h"
#include "ui_graphics.h"
#include "functional"
#include <queue>
#include <vector>

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int V = 6;
const int start = 0;
const int MAX = 999990;

int adjacensyMatrix[V][V] =
{
    { 0, 28, 13, 15, 0, 18 },
    { 28,  0, 0,  20,  21, 0 },
    { 13,   0,  0, 0,  30, 0 },
    { 15,   20,   0,   0, 39, 31},
    { 30,   21,   0,   39, 0, 0 },
    { 18,   0,    0,   31,   0, 0 }
};

void Dijkstra(int GR[V][V])//алгоритм Дейкстры
{
    int from[V];
    int distance[V], count, index = 0, i, u = 0, m = start + 1;
    bool visited[V];

    for (i = 0; i < V; i++)
    {
        distance[i] = MAX;
        visited[i] = false;
        from[i] = -1;
    }

    distance[start] = 0;

    for (count = 0; count < V - 1; count++)
    {
        int min = MAX;

        for (i = 0; i < V; i++)
        {
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i];
                index = i;
            }
        }
        cout << endl;

        u = index;
        visited[u] = true;
        //cout << "min=" << min << "; index=" << index << endl << endl;
        //cout << "u=" << u << endl;

        for (i = 0; i < V; i++)
        {
            if (!visited[i] && GR[u][i] && distance[u] != MAX && distance[u] + GR[u][i] < distance[i])
            {
                from[i] = u;
                distance[i] = distance[u] + GR[u][i];
                //cout << "distance[u](" << distance[u] << ")+GR[u][i](" << GR[u][i] << ")=" << distance[i] << endl;

            }
        }

        cout << endl;
        for (i = 0; i < V; i++)
        {
            //cout << " " << distance[i];
        }
        cout << endl;
    }

    for (int i = 1; i < V; ++i)
    {
        int j = i;
        cout << "Path to point No." << i + 1 << ": ";
        while (from[j] != -1)
        {
            std::cout << from[j] + 1 << " ";
            j = from[j];
        }
        std::cout << std::endl;
    }

    cout << "\nTotal distance between nodes:\n";
    for (i = 1; i < V; i++)
    {
        if (distance[i] != MAX)
        {
            cout << m << " > " << i + 1 << " = " << distance[i] << endl;
        }
        else
            cout << m << " > " << i + 1 << " = " << "Path unavailable!";
    }

}

int final_min;
QString final_path;
bool was_drawn;

Graphics::Graphics(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Graphics)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    draw = new MyPoint;
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setScene(scene);
    scene->addItem(draw);
    ui->path->hide();

}

MyPoint::MyPoint(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

}

MyPoint::~MyPoint()
{

}

QRectF MyPoint::boundingRect() const
{
    return QRectF(0,0,100,100);
}



void MyPoint::paint(QPainter *draw, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int x1 = 20, y1 = 160,
        x2 = -40, y2 = -230,
        x3 = 60, y3 = 0,
        x4 = -200, y4 = -50,
        x5 = 170, y5 = -170,
        x6 = -260, y6 = 210,
        d = 75;
    draw->setBrush(Qt::green);
    draw->setPen(Qt::black);
    draw->drawLine(x4+d/2-5, y4+d/2-5, x5+d/2-5, y5+d/2-5);
    draw->drawLine(x1+d/2-5, y1+d/2-5, x4+d/2-5, y4+d/2-5);
    draw->drawLine(x2+d/2-5, y2+d/2-5, x1+d/2-5, y1+d/2-5);
    draw->drawLine(x1+d/2-5, y1+d/2-5, x3+d/2-5, y3+d/2-5);
    draw->drawLine(x3+d/2-5, y3+d/2-5, x5+d/2-5, y5+d/2-5);
    draw->drawLine(x5+d/2-5, y5+d/2-5, x2+d/2-5, y2+d/2-5);
    draw->drawLine(x2+d/2-5, y2+d/2-5, x4+d/2-5, y4+d/2-5);
    draw->drawLine(x4+d/2-5, y4+d/2-5, x6+d/2-5, y6+d/2-5);
    draw->drawLine(x6+d/2-5, y6+d/2-5, x1+d/2-5, y1+d/2-5);
    if (was_drawn==true)  {
        draw->setPen(Qt::red);
        draw->drawLine(x1+d/2-5, y1+d/2-5, x3+d/2-5, y3+d/2-5);
        draw->drawLine(x3+d/2-5, y3+d/2-5, x5+d/2-5, y5+d/2-5);
        draw->drawLine(x5+d/2-5, y5+d/2-5, x2+d/2-5, y2+d/2-5);
        draw->drawLine(x2+d/2-5, y2+d/2-5, x4+d/2-5, y4+d/2-5);
        draw->drawLine(x4+d/2-5, y4+d/2-5, x6+d/2-5, y6+d/2-5);
        draw->drawLine(x6+d/2-5, y6+d/2-5, x1+d/2-5, y1+d/2-5);
    }
    draw->setPen(Qt::black);
    draw->drawEllipse(QRectF(x1, y1, d, d));
    draw->drawEllipse(QRectF(x2, y2, d, d));
    draw->drawEllipse(QRectF(x3, y3, d, d));
    draw->drawEllipse(QRectF(x4, y4, d, d));
    draw->drawEllipse(QRectF(x5, y5, d, d));
    draw->drawEllipse(QRectF(x6, y6, d, d));
    draw->drawText(x1+d/2-2, y1+d/2+5, "1");
    draw->drawText(x2+d/2-2, y2+d/2+5, "2");
    draw->drawText(x3+d/2-2, y3+d/2+5, "3");
    draw->drawText(x4+d/2-2, y4+d/2+5, "4");
    draw->drawText(x5+d/2-2, y5+d/2+5, "5");
    draw->drawText(x6+d/2-2, y6+d/2+5, "6");
           Q_UNUSED(option);
           Q_UNUSED(widget);
}

void Graphics::on_pushButton_clicked()
{
    Dijkstra(adjacensyMatrix);
    final_path.clear();
    was_drawn = true;
}

Graphics::~Graphics()
{
    delete ui;
}
